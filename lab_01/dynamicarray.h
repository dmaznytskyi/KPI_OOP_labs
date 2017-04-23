#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <string>
#include <iostream>
#include "dynamicstorage.h"

typedef unsigned int ui;
class DynamicArray : public DynamicStorage
{
    public:
        DynamicArray();
        DynamicArray(int initSize);
        ~DynamicArray();

        void        shift(int position);
        void        resize(int newsize);
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
        void        mSort_0(int arr[], int s);
        int         merge(int list1[], int size1, int list2[], int size2, int list3[]);
        void        quickSort(int l, int r);

    private:
        int *array;
};

#endif // DYNAMICARRAY_H
