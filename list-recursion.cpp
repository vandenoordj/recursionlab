#include <iostream>
#include "list-recursion.h"

using namespace std;
// John Vande Noord and Pacis BanaP

template < class DT >
ListNode<DT>:: ListNode ( const DT &nodeDataItem, ListNode<DT> *nextPtr )

// Creates a list node containing item elem and next pointer
// nextPtr.

: dataItem(nodeDataItem),
  next(nextPtr)
  {}

//--------------------------------------------------------------------

template < class DT >
List<DT>:: List ( int ignored )

// Creates an empty list. The argument is included for compatibility
// with the array implementation and is ignored.

: head(0),
  cursor(0)
  {}

//--------------------------------------------------------------------

template < class DT >
List<DT>:: ~List ()

// Frees the memory used by a list.

{
	clear ();
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: insert ( const DT &newDataItem )

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data item in the
// list. In either case, moves the cursor to newDataItem.

{
	if ( head == 0 )             // Empty list
	{
		head = new ListNode<DT>(newDataItem,0);
		cursor = head;
	}
	else                         // After cursor
	{
		cursor->next = new ListNode<DT>(newDataItem,cursor->next);
		cursor = cursor->next;
	}
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: clear ()

// Removes all the data items from a list.

{
	ListNode<DT> *p,      // Points to successive nodes
	*nextP;  // Points to next node
	p = head;
	while ( p != 0 )
	{
		nextP = p->next;
		delete p;
		p = nextP;
	}

	head = 0;
	cursor = 0;
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: showStructure () const

// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
	ListNode<DT> *p;   // Iterates through the list

	if ( head == 0 )
		cout << "Empty list" << endl;
	else
	{
		for ( p = head ; p != 0 ; p = p->next )
			if ( p == cursor )
				cout << "[" << p->dataItem << "] ";
			else
				cout << p->dataItem << " ";
		cout << endl;
	}
}











template < class DT >
void List<DT>:: write () const

// Outputs the data items in a list from beginning to end. Assumes that
// objects of type DT can be output to the cout stream.

{
	cout << "List : ";
	writeSub(head);
	cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: writeSub ( ListNode<DT> *p ) const

// Recursive partner of the write() function. Processes the sublist
// that begins with the node pointed to by p.

{
	// YOUR CODE HERE
	if(p!=0){
		cout<<p->dataItem<<" ";
		writeSub(p->next);
	}
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: insertEnd ( const DT &newDataItem )

// Inserts newDataItem at the end of a list. Moves the cursor to
// newDataItem.

{
	insertEndSub(head,newDataItem);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: insertEndSub ( ListNode<DT> *&p,
		const DT &newDataItem )

		// Recursive partner of the insertEnd() function. Processes the
		// sublist that begins with the node pointed to by p.

		{
	// YOUR CODE HERE
	if(p!=0){
		insertEndSub(p->next, newDataItem);
		//cout<<"insert after"<<p->next<<" ";
	}else{
		p=new ListNode<DT>(newDataItem,0);
		cursor=p;
	}
		}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: writeBackward () const

// Outputs the data items in a list from beginning to end and back
// again. Assumes that objects of type DT can be output to the cout
// stream.

{
	cout << "Mirror : ";
	writeBackwardSub(head);
	cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: writeBackwardSub ( ListNode<DT> *p ) const

// Recursive partner of the writeMirror() function. Processes the
// sublist that begins with the node pointed to by p.

{
	// YOUR CODE HERE
	if(p!=0){
		cout<<p->dataItem<<" ";
		writeBackwardSub(p->next);
		cout<<p->dataItem<<" ";
	}
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: reverse ()

// Reverses the order of the data items in a list.

{
	reverseSub(0,head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: reverseSub ( ListNode<DT> *p, ListNode<DT> *nextP )

// Recursive partner of the reverse() function. Processes the sublist
// that begins with the node pointed to by nextP.

{
	if ( nextP == NULL) // base case
		head = p; // move head to end of list
	else // recursive case
	{
		// YOUR CODE HERE

		reverseSub(nextP, nextP->next);
		nextP->next=p;

	}
}





//--------------------------------------------------------------------

template < class DT >
int List<DT>:: getLength () const

// Returns the number of data items in a list.

{
	return getLengthSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
int List<DT>:: getLengthSub ( ListNode<DT> *p ) const

// Recursive partner of the getLength() function. Processes the sublist
// that begins with the node pointed to by p.

{
	// YOUR CODE HERE
	if(p!=0){
		return 1+getLengthSub(p->next);
	}else
		return 0;
}












