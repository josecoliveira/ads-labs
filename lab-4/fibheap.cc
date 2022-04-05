// fibheap.cc skeleton implementation file for Fibonacci heaps

#include "fibheap.h"
#include <iostream>
#include <iomanip>

#define MAX_DEG 10

// Constructor - done in fibheap.h

// Utility routines to show structure and search
void showChildren(NodePtr x, int depth)
{
    if (x != NIL)
    {
        NodePtr y = x;
        cout << setw(6) << y->key << (y->mark ? "M" : " ");
        showChildren(y->child, depth + 1);
        y = y->left;
        while (y != x)
        {
            cout << "\n\n";
            cout << setw(depth * 7 - 1) << y->key << (y->mark ? "M" : " ");
            showChildren(y->child, depth + 1);
            y = y->left;
        }
    }
}

void showTree(NodePtr x)
{
    if (x != NIL)
    {
        cout << setw(6) << x->key << (x->mark ? "M" : " ");
        showChildren(x->child, 2);
        cout << "\n\n";
    }
}

void FibHeap ::ShowHeap()
{
    if (min != NIL)
    {
        NodePtr x = min;
        do
        {
            showTree(x);
            x = x->left;
        } while (x != min);
    }
    else
    {
        cout << "Heap is empty.\n\n";
    }
}

// showA() can be used for debugging consolidate()
void showA(NodePtr A[])
{
    cout << "Array A:\n";
    for (int i = 0; i <= MAX_DEG; i++)
    {
        if (A[i] != NIL)
        {
            cout << "A[" << i << "] =\n";
            showTree(A[i]);
        }
        else
        {
            cout << "A[" << i << "] = NIL\n";
        }
    }
}

// Helper routine for search() routine
NodePtr searchSibs(NodePtr x, KeyType k)
{
    NodePtr y;
    NodePtr result;
    if (x != NIL)
    {
        y = x;
        do
        {
            if (y->key == k)
                return y;
            if (y->child != NIL)
            {
                result = searchSibs(y->child, k);
                if (result != NIL)
                    return result;
            }
            y = y->left;
        } while (y != x);
    }
    return NIL;
}

// Routine to search for a node with a given key value
NodePtr FibHeap ::search(KeyType k)
{
    if (min != NIL)
    {
        return searchSibs(min, k);
    }
    else
    {
        cout << "Heap is empty.\n\n";
        return NIL;
    }
}

void FibHeap ::FHinsert(NodePtr x)
{
    x->degree = 0;
    x->p = NIL;
    x->child = NIL;
    x->mark = false;
    if (min == NIL)
    {
        x->left = x->right = x;
        min = x;
    }
    else
    {
        x->left = min->left;
        x->right = min;
        min->left->right = x;
        min->left = x;
        if (x->key < min->key)
            min = x;
    }
    n++;
}

NodePtr FibHeap ::FHminimum(void)
{
    return min;
}

// Utility routine to splice together two doubly linked lists.
NodePtr spliceIn(NodePtr x, NodePtr y)
{
    if (x == NIL)
        return y;
    else if (y == NIL)
        return x;
    else
    {
        NodePtr xPred = x->left;
        NodePtr yTail = y->left;

        x->left = yTail;
        yTail->right = x;
        y->left = xPred;
        xPred->right = y;
        return x;
    }
}

void FHlink(NodePtr y, NodePtr x)
{
    // Link out y - root list should not be empty since x is in it
    y->left->right = y->right;
    y->right->left = y->left;

    // Make y a child of x, incrementing degree x.
    y->p = x;
    if (x->child == NIL)
    {
        y->left = y->right = y;
        x->child = y;
    }
    else
    {
        NodePtr z = x->child;
        y->left = z->left;
        y->right = z;
        z->left->right = y;
        z->left = y;
    }
    x->degree = x->degree + 1;

    // Erase the mark on x
    x->mark = false;
}

// Consolidates the root list of this Fibonacci heap.
// Implements the Consolidate procedure on page 516.
void consolidate(NodePtr &min)
{
    NodePtr A[MAX_DEG + 1];
    int i;
    for (i = 0; i <= MAX_DEG; i++)
    {
        A[i] = NIL;
    }

    // Count the number of roots in the root list to iterate through them
    int numRoots = 0;
    NodePtr z = min;
    do
    {
        z = z->right;
        numRoots++;
    } while (z != min);

    // Iterate through the root list
    NodePtr w = min;
    for (i = 1; i <= numRoots; i++)
    {
        NodePtr x = w;
        w = w->right;
        int d = x->degree;

        while (A[d] != NIL) {
            NodePtr y = A[d];   // another node with the same degree as x
            if (x->key > y->key)
                swap(x, y);
            FHlink(y, x);
            A[d] = NIL;
            d++;
        }

        A[d] = x;

    } // End of outer for-loop

    min = NIL;

    for (i = 0; i <= MAX_DEG; i++)
    {
        if (A[i] != NIL)
        {
            if (min == NIL)
            {
                // create a root list for H containg just A[i]
                A[i]->left = A[i]->right = A[i];
                min = A[i];
            }
            else
            {
                // insert A[i] into H's root list
                A[i]->left = min->left;
                A[i]->right = min;
                min->left->right = A[i];
                min->left = A[i];
                if (A[i]->key < min->key)
                {
                    min = A[i];
                }
            }
        }
    }
}

NodePtr FibHeap ::FHextractMin(void)
{
    NodePtr z = min;

    if (z == NIL)
        return NIL; // empty Fibonacci heap
    else
    {
        // Add each child of z to the root list.  We can just
        // splice in z's children, but first we have to set their
        // parent pointers to NIL .
        if (z->child != NIL)
        {
            z->child->p = NIL;

            for (NodePtr x = z->child->right; x != z->child; x = x->right)
                x->p = NIL;

            min = spliceIn(min, z->child);
        }

        // Remove z from the root list.
        z->left->right = z->right;
        z->right->left = z->left;

        // Update min appropriately.
        if (z == z->right)
            min = NIL;
        else
        {
            min = z->right;
            consolidate(min);
        }

        n--;

        return z;
    }
}

void cut(NodePtr x, NodePtr y, NodePtr min)
{
    // Remove x from y's child list, derementing y's degree
    NodePtr xRight = x->right; // Save a child pointer if x is y's child
    x->left->right = x->right;
    x->right->left = x->left;
    y->degree = y->degree - 1;
    if (y->degree == 0)
    { // Update y's child if needed
        y->child = NIL;
    }
    else if (y->child == x)
    {
        y->child = xRight;
    }

    // Add x to the root list
    x->right = x;
    x->left = x;
    min = spliceIn(min, x);
    x->p = NIL;

    x->mark = false;
}

void cascadingCut(NodePtr y, NodePtr min)
{
    NodePtr z = y->p;
    if (z != NIL)
    {
        if (y->mark == false)
            y->mark = true;
        else
            cut(y, z, min);
            cascadingCut(z, min);
    }
}

void FibHeap ::FHdecreaseKey(NodePtr x, KeyType k)
{
    if (k > x->key)
    {
        cout << "New key, " << k << " is > current key" << x->key << endl;
        return;
    }
    x->key = k;
    NodePtr y = x->p;
    if ((y != NIL) && (x->key < y->key))
    {
        cut(x, y, min);
        cascadingCut(y, min);
    }
    if (x->key < min->key)
        min = x;
}

void FibHeap ::FHdelete(NodePtr x)
{
    FHdecreaseKey(x, -1);
    FHextractMin();
}

// non-class-member function
FibHeap FHunion(FibHeap &H1, FibHeap &H2)
// Pass by reference in order to clear H1 and H2 at end
{
    FibHeap H, Htemp;
    NodePtr temp;

    H.min = H1.min;
    // Splice the root lists of H1 and H2 together
    temp = spliceIn(H1.min, H2.min);
    if ((H1.min == NIL) || ((H2.min != NIL) &&
                            (H2.min->key < H1.min->key)))
    {
        H.min = H2.min;
    }
    H.n = H1.n + H2.n;

    // Clear H1 and H2
    H1.min = NIL;
    H1.n = 0;
    H2.min = NIL;
    H2.n = 0;

    return H;
}
