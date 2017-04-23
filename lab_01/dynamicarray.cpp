#include "dynamicarray.h"

DynamicArray::DynamicArray()
{
    size = 0;
    array = 0;
}

DynamicArray::DynamicArray(int initSize)
{
    size = initSize;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
    array = arr;
}

DynamicArray::~DynamicArray()
{
    delete array;
}

void DynamicArray::pushBack(int element)
{
    shift(size);
    array[size] = element;
}

void DynamicArray::insert(int pos, int element)
{
    if (pos > size)
        resize(pos);
    if (array[pos] != 0)
        array[pos] = element;
}

void DynamicArray::pushFront(int element)
{
    shift(0);
    array[0] = element;
}

void DynamicArray::deleteAt(int pos)
{
    int *arr = new int[size - 1];
    for (int i = 0; i < size; i++)
    {
        if (i >= pos)
        {
            arr[i] = array[i + 1];
        }
        else
        {
            arr[i] = array[i];
        }
    }
    size++;
    delete[] array;
    array = arr;
}

void DynamicArray::reverce()
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = array[size - i];
    delete[] array;
    array = arr;
}

void DynamicArray::display()
{
    for(int i = 0; i < size; i++)
        std::cout << array[i] << std::endl;
}

void DynamicArray::bSort()
{
    int tmp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void DynamicArray::qSort()
{
    quickSort(0, size - 1);
}

void DynamicArray::quickSort(int l, int r)
{
        int x = array[l + (r - l) / 2];
        //запись эквивалентна (l+r)/2,
        //но не вызввает переполнения на больших данных
        int i = l;
        int j = r;
        //код в while обычно выносят в процедуру particle
        while(i <= j)
        {
            while(array[i] < x) i++;
            while(array[j] > x) j--;
            if(i <= j)
            {
                std::swap(array[i], array[j]);
                i++;
                j--;
            }
        }
        if (i<r)
                    quickSort(i, r);

        if (l<j)
            quickSort(l, j);
}

void DynamicArray::mSort()
{
    mSort_0(array, size);
}

void DynamicArray::mSort_0(int arr[], int s)
{
    int temp[s];
    int mid, i;
    if (s < 2)
        return;
    else
    {
        mid = s / 2;
        mSort_0(arr, mid);
        mSort_0(arr + mid, s - mid);
        merge(arr, mid, arr + mid, s - mid, temp);
        for (i = 0; i < s; i++)
            arr[i] = temp[i];
    }
}

int DynamicArray::merge(int list1[], int size1, int list2[], int size2, int list3[])
{
    int i1, i2, i3;
    if (size1+size2 > size)
        return false;
    i1 = 0; i2 = 0; i3 = 0;
    /* while both lists are non-empty */
    while (i1 < size1 && i2 < size2)
    {
        if (list1[i1] < list2[i2])
            list3[i3++] = list1[i1++];
        else
            list3[i3++] = list2[i2++];
    }
    while (i1 < size1)
    {
        /* copy remainder of list1 */
        list3[i3++] = list1[i1++];
    }
    while (i2 < size2)
    {
        /* copy remainder of list2 */
        list3[i3++] = list2[i2++];
    }
    return true;
}

int DynamicArray::elementAt(int pos)
{
    return pos < size ? array[pos] : 0;
}

ui DynamicArray::getCapacity()
{
    return size;
}

ui DynamicArray::getSize()
{
    int i = 0;
    int ret = 0;
    while (i < size)
    {
        if (array[i] != 0)
            ret++;
        i++;
    }
    return ret;
}

std::string DynamicArray::toString()
{
    std::string s;
    for (int i = 0; i < size; i++)
        s += ' ' + std::to_string(array[i]);
    return s;
}

void DynamicArray::shift(int position)
{
    int* arr = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        if (i >= position)
            arr[i + 1] = array[i];
        else
            arr[i] = array[i];
    }
    size++;
    array = arr;
}

void DynamicArray::resize(int newsize)
{
    if (newsize < size)
        std::cout << "\033[1;31mERROR!\033[0m\nYou are trying to eleminate some data!\nAction is not performed!" << std::endl;
    else
    {
        int *arr = new int[newsize];
        for (int i = 0; i < size; ++i)
            arr[i] = array[i];
        for (int i = size; i < newsize; i++)
            arr[i] = 0;
        size = newsize;
        delete[] array;
        array = arr;
    }
}
