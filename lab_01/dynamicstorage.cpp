#include "dynamicstorage.h"

DynamicStorage::DynamicStorage()
{
}

void display(int *arr);

std::string toString(int *arr)
{
    std::string s;
    for (int i = 0; i < size; i++)
        s += ' ' + std::to_string(arr[i]);
    return s;
}

//ll methods
void        display(LinkedList *ob);

std::string toString()
{
    linkedlist *tmp = new linkedlist;
    std::string s;
    tmp = head;
    while (tmp != 0)
    {
        s += std::to_string(tmp->num) + " ";
        tmp = tmp->next;
    }
    return s;
}
