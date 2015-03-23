//--------------------------------------------------------------------
//
//
//  Test program for a set of recursive linked list functions
//
//--------------------------------------------------------------------

// Reads a list of characters and calls the specified recursive
// routine.

#include <iostream>
#include "list-recursion.cpp"

int main()
{
    List<char> testList;   // Test list
    char testData;         // List data element

    cout << endl << "Enter a list of characters : ";
    cin.get(testData);
    while ( testData != '\n' )
    {
        testList.insert(testData);
        cin.get(testData);
    }
    testList.showStructure();

    // Call a recursive routine by uncommenting the call you wish to execute
  testList.write();
    testList.insertEnd('!');
  testList.writeBackward();
 testList.reverse();
  cout << "length = " <<  testList.getLength() << endl;


    testList.showStructure();

    return 0;
}
