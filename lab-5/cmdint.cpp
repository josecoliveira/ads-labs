// cmdint.cpp - command interpreter program to test Red-Black Tree module

#include "rbtree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string comment;
    char choice;
    KeyType key, newKey;
    NodePtr x;
    NodePtr y;
    RBTree T;
    //  The following would test the constructor
    //  cout << "RB tree root = " << T.root << endl ;
    //  cout << "RB tree nil = " << T.nil << endl ;

    bool interact = false;

    if (interact)
        cout << "Choose: (c)onstruct, (i)nsert, (d)elete, "
             << "(s)earch, (S)how, P(rint), (l)eft rot, (r)ight rot ";
    cin >> choice;
    while (!cin.eof())
    {
        switch (choice)
        {
        case 'c':
            // This has already been done above.
            // Calling a constructor within a switch causes problems.
            break;
        case 'i':
            if (interact)
                cout << "Enter key value to insert: ";
            cin >> newKey;
            {
                NodePtr z = new Node;
                z->key = newKey;
                T.RBinsert(z);
            }
            break;
        case 'd':
            if (interact)
                cout << "Enter key value to delete: ";
            cin >> key;
            x = T.RBsearch(T.root, key);
            if (x != T.nil)
            {
                T.RBdelete(x);
            }
            else
            {
                cout << "No " << key << " key, can't delete"
                     << "\n\n";
            }
            break;
        case 's':
            if (interact)
                cout << "Enter key value to search for: ";
            cin >> key;
            x = T.RBsearch(T.root, key);
            if (x != T.nil)
            {
                cout << "key, " << key << ", found"
                     << "\n\n";
            }
            else
            {
                cout << "key, " << key << ", not found"
                     << "\n\n";
            }
            break;
        case 'l':
            if (interact)
                cout << "Enter key value to left rotate on: ";
            cin >> key;
            x = T.RBsearch(T.root, key);
            T.leftRotate(x);
            break;
        case 'r':
            if (interact)
                cout << "Enter key value to right rotate on: ";
            cin >> key;
            x = T.RBsearch(T.root, key);
            T.rightRotate(x);
            break;

            /*			This is not used directly in the tests
                  case 'm':
                            z = T.minimum() ;
                            cout << "Minimum = " << z->key << "\n\n" ;
                            break ;
            */
        case 'S':
            cout << "Structure of tree (rotated 90 degrees to left):\n\n";
            T.ShowTree(T.root, 0);
            cout << "\n\n";
            break;
        case 'P':
            T.PrintTree();
            break;
        case '#':
            cout << '#';
            getline(cin, comment);
            cout << comment << "\n\n";
            break;
        default:
            cout << "Illegal choice: " << choice << endl;
        }
        if (interact)
            cout << "Choose: (c)onstruct, (i)nsert, (d)elete, "
                 << "(s)earch, (S)how, P(rint), (l)eft rot, (r)ight rot ";
        //	  << "(m)inimum, (e)extract min, decrease (k)ey, "
        //	  << "+/- turns extract print on/off: " ;
        cin >> choice;
    }
    cout << endl;

    return 0;
}
