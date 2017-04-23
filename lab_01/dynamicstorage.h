#ifndef DYNAMICSTORAGE_H
#define DYNAMICSTORAGE_H
#include <iostream>

typedef unsigned int ui;
class DynamicStorage
{
public:
    DynamicStorage();

    void        display(int *arr);
    ui          getSize(int *arr);
    ui          getCapacity(int *arr);
    std::string toString(int *arr);

    void        display(struct linkedlist *ob);
    ui          getSize(struct linkedlist *ob);
    ui          getCapacity(struct linkedlist *ob);
    std::string toString(struct linkedlist *ob);
protected:
    int size;
};

#endif // DYNAMICSTORAGE_H
