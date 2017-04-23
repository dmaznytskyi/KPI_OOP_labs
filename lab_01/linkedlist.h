#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
#include "dynamicstorage.h"

struct linkedlist
{
    int         num;
    linkedlist  *next;
} ;
typedef unsigned int ui;
class LinkedList : DynamicStorage
{
    public:
        LinkedList();
        ~LinkedList();

        //TODO make this methods great again
        void        pushBack(int element);
        void        insert(int pos, int element);
        void        pushFront(int element);
        void        deleteAt(int pos);
        int         elementAt(int pos);
        void        reverce();
        void        display();
        void        bSort();
        void        qSort();
        void        mSort();
        ui          getSize();
        ui          getCapacity();
        std::string toString();
        //helpers
        linkedlist  *getTail(linkedlist *cur);
        linkedlist  *quickSortRecur(linkedlist *head, linkedlist *end);
        linkedlist  *partition(linkedlist *head, linkedlist *end,
                               linkedlist **newHead, linkedlist **newEnd);
        void        FrontBackSplit(linkedlist *source, linkedlist **frontRef,
                            linkedlist **backRef);
        void        MergeSort(linkedlist **headRef);
        linkedlist  *SortedMerge(linkedlist *a, linkedlist *b);

    private:
        linkedlist  *head;
};

#endif // LINKEDLIST_H
