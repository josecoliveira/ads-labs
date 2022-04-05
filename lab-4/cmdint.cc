// cmdint.cc - command interpreter to test Fibonacci Heap module

#include "fibheap.h"
#include <iostream>
#include <string>

// using namespace std ;

int main()
{
   string comment;
   char choice;
   KeyType key, newKey;
   FibHeap H[10];
   int c = 0;
   int i, j, h; // indices of heaps to be merged and output
   NodePtr x;

   bool interact = false;
   bool xprint = true;

   if (interact)
      cout << "Ten Fibonacci heaps have been set up for "
           << "use in testing: H[0], H[1], ..., H[9].\n"
           << "Initially it is H[0].  To switch to a new "
           << "one, use the C (for Choose) command.\n"
           << "To exit, press Control-D at a prompt.\n\n";
   if (interact)
      cout << "Choose: (i)nsert, (m)inimum, (e)extract min, "
           << "(u)nion, decrease (k)ey, (d)elete,\n (s)earch, "
           << "(S)how, (C)hoose heap, "
           << "or +/- to turn extract print on/off: ";
   cin >> choice;
   while (!cin.eof())
   {
      switch (choice)
      {
      case 'c':
         // This is done above with the constructor
         break;
      case 'i':
         if (interact)
            cout << "Enter key value to insert: ";
         cin >> newKey;
         {
            NodePtr x = new FibHeapNode(newKey);
            H[c].FHinsert(x);
         }
         break;
      case 'm':
         x = H[c].FHminimum();
         cout << "Minimum = " << x->key << "\n";
         break;
      case 'e':
         x = H[c].FHextractMin();
         if (x != NIL)
         {
            if (xprint)
               cout << "Minimum extracted = " << x->key << "\n";
         }
         else
         {
            cout << "Heap empty, can't extract minimum.\n\n";
         }
         break;
      case 'u':
         if (interact)
            cout << "Enter the indices of the two heaps "
                 << "that you want to union\n and the "
                 << "index of the combined heap: ";
         cin >> i >> j >> h;
         H[h] = FHunion(H[i], H[j]);
         break;
      case 'k':
         if (interact)
            cout << "Enter key to decrease and new key: ";
         cin >> key >> newKey;
         x = H[c].search(key);
         if (x != NIL)
         {
            H[c].FHdecreaseKey(x, newKey);
         }
         else
         {
            cout << "Originaly key = " << key << "not in heap.\n\n";
         }
         break;
      case 'd':
         if (interact)
            cout << "Enter key value to delete: ";
         cin >> key;
         x = H[c].search(key);
         if (x != NIL)
         {
            H[c].FHdelete(x);
         }
         else
         {
            cout << "Originaly key = " << key << "not in heap.\n\n";
         }
         break;
      case 's':
         if (interact)
            cout << "Enter key value to search for: ";
         cin >> key;
         if (H[c].min == NIL)
         {
            cout << "Searching an empty heap."
                 << "\n\n";
         }
         else
         {
            x = H[c].search(key);
            if (x == NIL)
            {
               cout << "key, " << key << ", not found"
                    << "\n\n";
            }
            else
            {
               cout << "key, " << key << ", found"
                    << "\n\n";
               if (x->p == NIL)
               {
                  cout << "key's node is in the root list\n\n";
               }
               else
               {
                  cout << "Parent's key is " << x->p->key << "\n\n";
               }
               cout << "The tree rooted at the node is: \n\n";
               showTree(x);
            }
         }
         break;
      case 'S':
         cout << "Structure of Fibonacci Heap H[" << c << "]"
              << " (rotated 90 degrees to the left):\n";
         if (H[c].min == NIL)
         {
            cout << "\nH[" << c << "] is an empty heap\n\n";
         }
         else
         {
            cout << "\n";
            H[c].ShowHeap();
         }
         break;
      case 'C':
         if (interact)
            cout << "Enter new index of heap: ";
         cin >> c;
         break;
      case '+':
         xprint = true;
         break;
      case '-':
         xprint = false;
         break;
      case '#':
         cout << '#';
         getline(cin, comment);
         cout << comment << "\n\n";
         break;
      case '\n':
         cout << "end of line encountered\n";
         break;
      default:
         cout << "Illegal choice: " << choice << endl;
      }
      if (interact)
         cout << "Choose: (i)nsert, (m)inimum, (e)extract min, "
              << "(u)nion, decrease (k)ey, (d)elete,\n (s)earch, "
              << "(S)how, (C)hoose heap, "
              << "or +/- to turn extract print on/off: ";
      cin >> choice;
   }
   cout << endl;

   return 0;
}
