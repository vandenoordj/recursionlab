template < class DT >         // Forward declaration of the List class
class List;

template < class DT >
class ListNode                // Facilitator class for the List class
{
  private:

    // Constructor
    ListNode ( const DT &initData, ListNode *nextPtr );

    // Data members
    DT dataItem;        // List data item
    ListNode *next;    // Pointer to the next list node

  friend class List<DT>;
};

//--------------------------------------------------------------------

template < class DT >
class List
{
  public:

    // Constructor
    List ( int ignored = 0 );

    // Destructor
    ~List ();

    // List manipulation functions
    void insert ( const DT &newData );         // Insert after cursor
    void clear ();                             // Clear list

    // Output the list structure -- used in testing/debugging
    void showStructure () const;


    void write () const;                       // Output list data items
    void insertEnd ( const DT &newData );      // Insert at end
    void writeBackward () const;               // Output list from back to front
    void reverse ();                           // Reverse list
    int getLength () const;                    // Length of list

  private:
    // Recursive partners of the above functions
    void writeSub ( ListNode<DT> *p ) const;
    void insertEndSub ( ListNode<DT> *&p, const DT &newElement );
    void writeBackwardSub ( ListNode<DT> *p ) const;
    void reverseSub ( ListNode<DT> *p, ListNode<DT> *nextP );
    int getLengthSub ( ListNode<DT> *p ) const;



  private:

    // Data members
    ListNode<DT> *head,     // Pointer to the beginning of the list
                 *cursor;   // Cursor pointer
};
