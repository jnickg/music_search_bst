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

template <class T> int TreeSet<T>::add(T data)
{
	return add(data, root);
}

template <class T> int TreeSet<T>::getfirst(T& rtn)
{
	return getfirst(rtn, root);
}

template <class T> int TreeSet<T>::getlast(T& rtn)
{
	return getlast(rtn, root);
}

template <class T> int TreeSet<T>::getceil(T t, T& rtn)
{
	return getceil(t, rtn, root);
}

template <class T> int TreeSet<T>::getflr(T t, T& rtn)
{
	return getflr(t, rtn, root);
}

template <class T> int TreeSet<T>::gethigher(T t, T& rtn)
{
	return gethigher(t, rtn, root);
}

template <class T> int TreeSet<T>::getlower(T t, T& rtn)
{
	return getlower(t, rtn, root);
}


/* Utility functions (wrappers) */

template <class T> int TreeSet<T>::count(void)
{
	return count(root);
}

template <class T> int TreeSet<T>::countleaves(void)
{
	return countleaves(root);
}

template <class T> int TreeSet<T>::height(void)
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




/* Private wrapped functions */

template <class T> int TreeSet<T>::add(T data, node<T> * root)
{
	if(NULL==root) // Case 1: root is a leaf
	{
		root = new node<T>;
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

template <class T> int TreeSet<T>::getfirst(T& rtn, node<T> * root)
{
	// Case 1: no root
	if(NULL==root) return 0;
	// Case 2: at the leftmost node
	else if(NULL==root->left)
	{
		rtn = root->data;
		return 1;

	}
	// Case 3: continue traversing
	else getfirst(rtn, root->left);
}

template <class T> int TreeSet<T>::getlast(T& rtn, node<T> * root)
{
	// Case 1: no root
	if(NULL==root) return 0;
	// Case 2: at the leftmost node
	else if(NULL==root->right)
	{
		rtn = root->data;
		return 1;
	}
	// Case 3: continue traversing
	else getfirst(rtn, root->left);
}

template <class T> int TreeSet<T>::getceil(T t, T& rtn, node<T> * root)
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

template <class T> int TreeSet<T>::getflr(T t, T& rtn node<T> * root)
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

template <class T> int TreeSet<T>::gethigher(T t, T& rtn, node<T> * root)
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

template <class T> int TreeSet<T>::getlower(T t, T& rtn node<T> * root)
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

template <class T> int TreeSet<T>::count(node<T> * root)
{
	if(NULL==root) return 0; // Case 1: no root
	else return (1 + count(root->left) + count(root->right));
}

template <class T> int TreeSet<T>::countleaves(node<T> * root)
{
	if(NULL==root) return 0; // Case 1: no root
	else if(((root->left)==NULL) && ((root->right)==NULL))
		return 1;
	else return (count(root->left) + count(root->right));
}

template <class T> int TreeSet<T>::height(node<T> * root)
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

template <class T> int TreeSet<T>::copyfrom(node<T> * & dest, node<T> * src)
{
	if(NULL==source)
	{
		destination=NULL;
		return 0;
	}
	else
	{
		if(destination) delete destination;
		destination = new node;
		destination->data = source->data;
		int cpy = copy(destination->left, source->left) + copy(destination->right, source->right);
		return 1 + cpy;
	}
}

template <class T> int TreeSet<T>::removeall(node<T> * & root)
{
	if(NULL==root) return 0;
	else
	{
		int del = remove_all(root->left) + remove_all(root->right);
		delete root;
		root = NULL;
		return 1 + del;
	}
}
