template <class T> List<T>::List(void)
{
	head = 	NULL;
	head = NULL;
	last = NULL;
	cur = NULL;
	count = 0;
	name = new char[5];
	strcpy(name, "list");
}

template <class T> List<T>::List(char* n)
{
	head = 	NULL;
	head = NULL;
	last = NULL;
	cur = NULL;
	count = 0;
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

template <class T> List<T>::~List(void)
{
	// If there is a head
	if(head)
	{
		node<T>* it = head;
		node<T>* tmp;
		while(it)
		{
			tmp = it;
			it = it->next;
			delete tmp;
		}
		tmp = NULL;
		it = NULL;
	}
}

template <class T> int List<T>::setName(char* n)
{
	if(name) delete name;
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	return 1;
}

template <class T> int List<T>::add_to_head(const T & item)
{
	// Create new node with T
	node<T>* tmp = new node<T>;
	tmp->data = item;
	
	// If no items in list, it's both last and head
	if (NULL==head)
	{
		head = tmp;
		last = tmp;

		// Set iterator to the head, and make sure LLL terminates
		cur = head;
		last->next = NULL;
	}
	// One-item List needs to disconnect head and last
	else if(NULL==head->next)
	{
		tmp->next = head;
		head = tmp;

		// set iterator to the head
		cur = head;
		// last is already the correct node
	}
	// Otherwise it's just the new head
	else
	{ 
		tmp->next = head;
		head = tmp;
		cur = head;
	}

	count++;
	return 1;
}

template <class T> int List<T>::add_to_end(const T & item)
{
	// Create new node with T
	node<T>* tmp = new node<T>;
	tmp->data = item;

	// If no items in list, it's both last and head
	if (NULL==head)
	{
		last = tmp;
		head = tmp;
		cur = tmp;
		tmp->next = NULL;
	}
	// One-item List needs to disconnect head and last
	else if(NULL==head->next)
	{
		head->next = tmp;
		last = tmp;
		last->next = NULL;
	}
	// Otherwise it's just the new last
	else
	{ 
		last->next = tmp;
		if(cur == last)
		{
			cur = tmp;
		}
		last = tmp;
		last->next = NULL;
	}

	count++;
	return 1;	
}

template <class T> int List<T>::remove_last()
{
	// Empty List
	if (head == NULL)
		return 0;
		
	// One-item List
	else if (head->next == NULL)
	{
		delete head;
		head = NULL;
		count--;
		return 1;
	}
		
	// Multi-item List
	else {
		remove_last(head->next);
		return 1;
	}
}

template <class T> int List<T>::remove_first()
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		node<T>* tmp = head;
		head = head->next;
		delete tmp;
		tmp = NULL;

		count--;
		return 1;
	}
}

template <class T> int List<T>::get_head(T & data)
{
	if(head)
	{
		data = head->data;
		return 1;
	}
	else return 0;
}

template <class T> int List<T>::get_last(T & data)
{
	if(last)
	{
		data = last->data;
		return 1;
	}
	else return 0;
}

template <class T> int List<T>::it_init() const
{
	if(!(head==NULL))
	{
		cur = head;
		return 1;
	}
	else return 0;
}

template <class T> int List<T>::it_adv() const
{
	if(cur->next == NULL)
		return 0;
	else 
	{
		cur = cur->next;
		return 1;
	}
}

template <class T> int List<T>::it_cur(T & data) const
{
	data = cur->data;
	return 1;
}

template <class T> int List<T>::it_comp(T & item) const
{
	T c = cur->data;
	if(c < item) return 1;
	else if(c > item) return -1;
	else return 0;
}

template <class T> std::ostream& List<T>::print(std::ostream& out) const
{
	//out << "Attempting to print List \'" << name << "\'" << std::endl;
	int i = 0;
	node<T>* tmp = head;
	while(tmp)
	{
		out << "Item " << ++i << " - ";
		out << &(tmp->data) << std::endl;
		tmp = tmp->next;
	}
	return out;
}

template <class T> bool List<T>::isname(char* n)
{
	if(0==strcmp(name, n)) return true;
	else return false;
}

template <class T> int List<T>::get_count()
{
	return count;
}

template <class T> int List<T>::fget_count()
{
	return fget_count(head);
}

template <class T> int List<T>::fget_count(node<T>* strt)
{
	if(NULL == strt) return 0;
	return (fget_count(strt->next) +1);
}

template <class T> List<T>& List<T>::operator=(const List<T> & right)
{
	// Clear all of this
	this->clear();

	// Get data from right for ever of ITS nodes
	T data;
	if(right.it_init())
	{
		right.it_cur(data);
		head = new node<T>;
		head->data = data;
		node<T>* tmp = head;
		while(right.it_adv())
		{
			right.it_cur(data);
			tmp->next = new node<T>;
			tmp = tmp->next;
			tmp->data = data;
		}
		last = tmp;
		tmp->next = NULL;
	}
	else head = NULL;
	return *this;
}

template <class T> void List<T>::clear(void)
{
	node<T>* it = head;
	node<T>* tmp;
	while(it)
	{
		tmp = it;
		it = it->next;
		delete tmp;
	}
	head = NULL;
	last = NULL;
	cur = NULL;
}
