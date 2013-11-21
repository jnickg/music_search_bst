#ifndef JNICKG_ADT_TREESET
#define JNICKG_ADT_TREESET

#include <cstdlib>

/* TREE SET (BINARY SEARCH TREE)
TreeSet.h
jnickg (jnickg83@gmail.com)
Created 16 Nov 2013

See description below

*/

namespace jnickg { namespace adt {

#ifndef JNICKG_ADT_BSTSTRUCT
#define JNICKG_ADT_BSTSTRUCT
template <class T> struct node
{
	T data;
	node<T>* left;
	node<T>* right;
};
#endif // JNICKG_ADT_BSTSTRUCT

/*	TreeSet (Binary Search Tree)
	
	Description

	Requires that class T has the following
	implementations:

	operator<
	operator>
	operator=
	operator<<
	operator==

*/

template <class T> class TreeSet
{
 public:
	TreeSet(void);
	~TreeSet(void);
	

	/* Primary functions */
	
	// Adds data to the instance
	int add(T data);

	// Sets rtn to the lowest T in the instance,
	// or NULL if not present
	int getfirst(T& rtn);

	// Sets rtn to the highest T in the instance,
	// or NULL if not present
	int getlast(T& rtn);

	// Sets rtn to the first value greater than or equal to t,
	// or NULL if not present
	int getceil(T t, T& rtn);

	// Sets rtn to the first value less than or equal to t,
	// or NULL if not present
	int getflr(T t, T& rtn);

	// Sets rtn to the first value strictly greater than t,
	// or NULL if not present
	int gethigher(T t, T& rtn);

	// Sets rtn to the first value strictly less than t,
	// or NULL if not present
	int getlower(T t, T& rtn);


	/* Utility functions */

	// Counts the number of nodes in the set
	int count(void);

	// Counts the number of nodes with no children
	int countleaves(void);

	// Gets the current maximal depth of the set
	int height(void);

	// Copies src in its entirety into this instance
	int copyfrom(const TreeSet<T> & src);

	// Purges data from this instance
	int clear(void);

private:
	node<T>* root;

	/* Primary wrapped functions */

	// Adds data appropriately below root
	int add(T data, node<T> * root);
	// Sets rtn to the leftmost data under root
	int getfirst(T& rtn, node<T> * root);
	// Sets rtn to the rightmost data under root
	int getfirst(T& rtn, node<T> * root);

	int getceil(T t, T& rtn, node<T> * root);

	int getflr(T t, T& rtn, node<T> * root);

	int gethigher(T t, T& rtn, node<T> * root);

	int getlower(T t, T& rtn, node<T> * root);

	/* Utility wrapped functions */

	// Returns number of leaves below root
	int countleaves (node<T> * root);
	// Returns depth of the tree from root
	int height (node<T> * root);
	// Copies all data from source down, to destination down
	int copyfrom (node<T> * & destination, node<T> * source);
	// Removes data from root down
	int removeall(node<T> * & root);
};

#include "TreeSet.cpp" // Fantian inclusion

}} // End namespace

#endif
