#ifndef JNICKG_ADT_TREESET
#define JNICKG_ADT_TREESET

#include <cstdlib>
#include <ostream>
#include "List.h"

/* TREE SET (BINARY SEARCH TREE)
TreeSet.h
jnickg (jnickg83@gmail.com)
Created 16 Nov 2013

See description below

*/

namespace jnickg { namespace adt {

#ifndef JNICKG_ADT_BSTSTRUCT
#define JNICKG_ADT_BSTSTRUCT
template <class T> struct bst_node
{
	T data;
	bst_node<T>* left;
	bst_node<T>* right;
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
	int add(T& data);

	// Adds data regardless of whether something was already there
	int put(T& data);

	// Checks if the TreeSet contains item and sets item to it
	bool contains(T& item) const;

	// Sets rtn to the lowest T in the instance,
	// or NULL if not present
	int getfirst(T& rtn) const;

	// Sets rtn to the highest T in the instance,
	// or NULL if not present
	int getlast(T& rtn) const;

	// Sets rtn to the first value greater than or equal to t,
	// or NULL if not present
	int getceil(const T& t, T& rtn) const;

	// Sets rtn to the first value less than or equal to t,
	// or NULL if not present
	int getflr(const T& t, T& rtn) const;

	// Sets rtn to the first value strictly greater than t,
	// or NULL if not present
	int gethigher(const T& t, T& rtn) const;

	// Sets rtn to the first value strictly less than t,
	// or NULL if not present
	int getlower(const T& t, T& rtn) const;


	/* Utility functions */

	// Counts the number of bst_nodes in the set
	int count(void) const;

	// Counts the number of bst_nodes with no children
	int countleaves(void) const;

	// Gets the current maximal depth of the set
	int height(void) const;

	// Copies src in its entirety into this instance
	int copyfrom(const TreeSet<T> & src);

	// Purges data from this instance
	int clear(void);

	// Translates the TreeSet to a List, with elements in their natural order
	int toList(List<T> & rtn) const;

	std::ostream& print(std::ostream& out) const;
	
	TreeSet<T>& operator=(const TreeSet<T> & right);

private:
	bst_node<T>* root;

	/* Primary wrapped functions */

	// Adds data appropriately below root
	int add(T& data, bst_node<T> * root);
	// Adds data regardless of whether something was already there
	int put(T& data, bst_node<T> * root);
	// Checks if the TreeSet contains item and sets item to it
	bool contains(T& item, bst_node<T> * root) const;
	// Sets rtn to the leftmost data under root
	int getfirst(T& rtn, bst_node<T> * root) const;
	// Sets rtn to the rightmost data under root
	int getfirst(T& rtn, bst_node<T> * root) const;

	int getceil(const T& t, T& rtn, bst_node<T> * root) const;

	int getflr(const T& t, T& rtn, bst_node<T> * root) const;

	int gethigher(const T& t, T& rtn, bst_node<T> * root) const;

	int getlower(const T& t, T& rtn, bst_node<T> * root) const;

	/* Utility wrapped functions */

	// Returns number of leaves below root
	int countleaves (bst_node<T> * root) const;
	// Returns depth of the tree from root
	int height (bst_node<T> * root) const;
	// Copies all data from source down, to destination down
	int copyfrom (bst_node<T> * & destination, bst_node<T> * source);
	// Removes data from root down
	int removeall(bst_node<T> * & root);
	// Translates the TreeSet to a List, with elements in their natural order
	int toList(List<T> & rtn, bst_node<T> * root) const;

	std::ostream& print(std::ostream& out, bst_node<T> * root) const;
};

#include "TreeSet.cpp" // Fantian inclusion

}} // End namespace

#endif
