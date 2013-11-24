template <class T> TreeSet<T>::TreeSet(void)
{
	root = NULL;
}

template <class T> TreeSet<T>::~TreeSet(void)
{
	clear();
	root = NULL;
}




/* Primary functions */

template <class T> int TreeSet<T>::add(const T& data)
{
	return add(data, root);
}

template <class T> int TreeSet<T>::put(T& data)
{
	return put(data, root);
}

template <class T> bool TreeSet<T>::contains(T& item) const
{
	return contains(item, root);
}

template <class T> int TreeSet<T>::retrieve(char* srch, jnickg::adt::List<T>& rtn) const
{
	return retrieve(srch, rtn, root);
}

template <class T> int TreeSet<T>::getfirst(T& rtn) const
{
	return getfirst(rtn, root);
}

template <class T> int TreeSet<T>::getlast(T& rtn) const
{
	return getlast(rtn, root);
}

template <class T> int TreeSet<T>::getceil(const T& t, T& rtn) const
{
	return getceil(t, rtn, root);
}

template <class T> int TreeSet<T>::getflr(const T& t, T& rtn) const
{
	return getflr(t, rtn, root);
}

template <class T> int TreeSet<T>::gethigher(const T& t, T& rtn) const
{
	return gethigher(t, rtn, root);
}

template <class T> int TreeSet<T>::getlower(const T& t, T& rtn) const
{
	return getlower(t, rtn, root);
}


/* Utility functions (wrappers) */

template <class T> int TreeSet<T>::count(void) const
{
	return count(root);
}

template <class T> int TreeSet<T>::countleaves(void) const
{
	return countleaves(root);
}

template <class T> int TreeSet<T>::height(void) const
{
	return height(root);
}

template <class T> int TreeSet<T>::copyfrom(const TreeSet<T> & src)
{
	clear(); // Prevent old data from lingering
	return copyfrom(root, src.root);
}

template <class T> int TreeSet<T>::clear(void)
{
	return removeall(root);
}

template <class T> int TreeSet<T>::toList(List<T> & rtn)  const
{
	rtn.clear(true);
	return toList(rtn, root);
}

// Prints each element in the set, in their natural order
template <class T> std::ostream& TreeSet<T>::print(std::ostream& out) const
{
	return print(out, root);
}

template <class T> TreeSet<T>& TreeSet<T>::operator=(const TreeSet<T> & right)
{
	copyfrom(right);
	return *this;
}



/* Private wrapped functions */

template <class T> int TreeSet<T>::add(const T& data, bst_node<T> *& root)
{
	if(NULL==root) // Case 1: root is a leaf
	{
		root = new bst_node<T>;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return 1;
	}
	else // Case 2: root contains data
	{
		// Add to the left of root
		if(data<(root->data)) return add(data, root->left);
		// Add to the right of root
		else if(data>(root->data)) return add(data, root->right);
		// Already here; do not add to the set
		else if(data==(root->data)) return 0;
	}
}

template <class T> int TreeSet<T>::put(T& data, bst_node<T> *& root)
{
	if(NULL==root) // Case 1: root is a leaf
	{
		root = new bst_node<T>;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return 1;
	}
	else // Case 2: root contains data
	{
		// Add to the left of root
		if(data<(root->data)) return put(data, root->left);
		// Add to the right of root
		else if(data>(root->data)) return put(data, root->right);
		// Already here; do not add to the set
		else if(data==(root->data))
		{
			root->data = data;
			return 0;
		}
	}
}


template <class T> bool TreeSet<T>::contains(T& item, bst_node<T> * root) const
{
	if(NULL == root) return false;
	else
	{
		if(item < root->data) return contains(item, root->left);
		else if(item > root->data) return contains(item, root->right);
		else
		{
			item = root->data;
			return true;
		}
	}
}

template <class T> int TreeSet<T>::retrieve(char* srch, jnickg::adt::List<T>& rtn, bst_node<T> * root) const
{
	if(NULL==root) return 0;
	else
	{
		int num = retrieve(srch, rtn, root->left) + retrieve(srch, rtn, root->right);
		T tmp;
		if ((root->data).retrieve(srch, tmp))
		{
			rtn.add_to_end(tmp);
			num++;
		}
		return num;
	}
}

template <class T> int TreeSet<T>::getfirst(T& rtn, bst_node<T> * root) const
{
	// Case 1: no root
	if(NULL==root) return 0;
	// Case 2: at the leftmost bst_node
	else if(NULL==root->left)
	{
		rtn = root->data;
		return 1;
	}
	// Case 3: continue traversing
	else getfirst(rtn, root->left);
}

template <class T> int TreeSet<T>::getlast(T& rtn, bst_node<T> * root) const
{
	// Case 1: no root
	if(NULL==root) return 0;
	// Case 2: at the leftmost bst_node
	else if(NULL==root->right)
	{
		rtn = root->data;
		return 1;
	}
	// Case 3: continue traversing
	else getfirst(rtn, root->left);
}

template <class T> int TreeSet<T>::getceil(const T& t, T& rtn, bst_node<T> * root) const
{
	// Case 1: no root
	if(NULL==root) return 0;
	// Case 2: root exists and is larger than t
	else if(t < (root->data))
	{
		// This might be the ceiling
		rtn = root->data;
		// Go left until t is larger than the data
		getceil(t, rtn, root->left);
		// getceil grabbed something
		return 1;
	}
	// Case 3: root exists and is less than t
	else if(t > (root->data))
	{
		// Go right until t is smaller than the data
		getceil(t, rtn, root->right);
		// getceil didn't grab anything
		return 0;
	}
	// Case 4: root and t are equal
	else
	{
		// Definitely ceiling
		rtn = root->data;
		// Grabbed it
		return 1;
	}
}

template <class T> int TreeSet<T>::getflr(const T& t, T& rtn, bst_node<T> * root) const
{
	// Case 1: no root
	if(NULL==root) return 0;
	// Case 2: root exists and is larger than t
	else if(t < (root->data))
	{
		// Go left until t is larger than the data
		getceil(t, rtn, root->left);
		// getflr didn't grab anything
		return 0;
	}
	// Case 3: root exists and is less than t
	else if(t > (root->data))
	{
		// This might be the floor
		rtn = root->data;
		// Go right until t is smaller than the data
		getceil(t, rtn, root->right);
		// getflr grabbed something
		return 1;
	}
	// Case 4: root and t are equal
	else
	{
		// Definitely floor
		rtn = root->data;
		// Grabbed it
		return 1;
	}
}

template <class T> int TreeSet<T>::gethigher(const T& t, T& rtn, bst_node<T> * root) const
{
	// Case 1: no root
	if(NULL==root) return 0;
	// Case 2: root exists and is larger than t
	else if(t < (root->data))
	{
		// This might be the higher
		rtn = root->data;
		// Go left until t is larger than the data
		getceil(t, rtn, root->left);
		// getceil grabbed something
		return 1;
	}
	// Case 3: root exists and is less than t
	else
	{
		// Go right until t is smaller than the data
		getceil(t, rtn, root->right);
		// getceil didn't grab anything
		return 0;
	}
}

template <class T> int TreeSet<T>::getlower(const T& t, T& rtn, bst_node<T> * root) const
{
	// Case 1: no root
	if(NULL==root) return 0;
	// Case 2: root exists and is less than t
	else if(t > (root->data))
	{
		// This might be the lower
		rtn = root->data;
		// Go right until t is smaller than the data
		getceil(t, rtn, root->right);
		// getflr grabbed something
		return 1;
	}
	// Case 3: root exists and is larger than t
	else
	{
		// Go left until t is larger than the data
		getceil(t, rtn, root->left);
		// getflr didn't grab anything
		return 0;
	}
}

template <class T> int TreeSet<T>::count(bst_node<T> * root) const
{
	if(NULL==root) return 0; // Case 1: no root
	else return (1 + count(root->left) + count(root->right));
}

template <class T> int TreeSet<T>::countleaves(bst_node<T> * root) const
{
	if(NULL==root) return 0; // Case 1: no root
	else if(((root->left)==NULL) && ((root->right)==NULL))
		return 1;
	else return (count(root->left) + count(root->right));
}

template <class T> int TreeSet<T>::height(bst_node<T> * root) const
{
	if(NULL==root) return 0; // Case 1: no root
	else // Case 2: at least a left or right exists
	{
		int hl = height(root->left);
		int hr = height(root->right);
		if(hl>hr) return (1+hl);
		else return (1+hr);
	}
}

template <class T> int TreeSet<T>::copyfrom(bst_node<T> * & destination, bst_node<T> * source)
{
	if(NULL==source)
	{
		destination=NULL;
		return 0;
	}
	else
	{
		destination = new bst_node<T>;
		destination->data = source->data;
		int cpy = copyfrom(destination->left, source->left) + copyfrom(destination->right, source->right);
		return 1 + cpy;
	}
}

template <class T> int TreeSet<T>::removeall(bst_node<T> * & root)
{
	if(NULL==root) return 0;
	else
	{
		int del = removeall(root->left) + removeall(root->right);
		delete root;
		root = NULL;
		return 1 + del;
	}
}

template <class T> int TreeSet<T>::toList(List<T> & rtn, bst_node<T> * root) const
{
	if(NULL==root) return 0;
	else
	{
		int adds = 0;
		adds += toList(rtn, root->left);
		rtn.add_to_end(root->data);
		adds += toList(rtn, root->right);
		return 1 + adds;
	}
}

template <class T> std::ostream& TreeSet<T>::print(std::ostream& out, bst_node<T> * root) const
{
	if(NULL==root) return out;
	else
	{
		print(out, root->left);
		out << &(root->data) << std::endl;
		print(out, root->right);
	}
}
