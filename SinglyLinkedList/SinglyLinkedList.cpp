#include <iostream>
#include "SList.h"

using namespace std;
template <class T>
void removeDuplicates(SList<T>& lst)
{
    SListIterator<T> outer = lst.getIterator();
    while (outer.isValid())
    {
        SListIterator<T> inner(outer);
        inner++;
        while (inner.isValid())
        {
            if (*inner == *outer)
            {
                SListIterator<T> temp(inner);
                temp++;
                lst.remove(inner);
                inner = temp;
            }

            else
            {
                inner++;
            }
        }
        outer++;
    }
}
template <class T>
void swapPairs(SList<T>& lst)
{
    SListNode<T>* st = lst.head;
    SListNode<T>* prev=nullptr;
    while (st != lst.tail && st != nullptr)
    {
        SListNode<T>* a =prev;
        SListNode<T>* b= st;
        SListNode<T>* c = st->getNext();
        SListNode<T>* d = st->getNext()->getNext();
        if (a != nullptr)
            a->setNext(c);

        b->setNext(d);
        c->setNext(b);
        if (b == lst.head)
            lst.head = c;
        if (c == lst.tail)
            lst.tail = b;

        st = d;
        prev = b;

    }
}
template <class T>
void display(SList<T>& lst)
{
    SListIterator<T> it = lst.getIterator();
    while (it.isValid())
    {
        cout << *it <<" " ;
        it++;
    }
    cout << endl;
}
int main()
{
    SList<int> lst;
    for (int i = 1; i <= 5; i++)
    {
        for (int x = 1; x <= i; x++)
        {
            lst.append(i);
        }
    }
    display(lst);
    removeDuplicates(lst);
    display(lst);
    swapPairs(lst);
    display(lst);
    return 0;
}

