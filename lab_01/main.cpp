#include <iostream>
#include <dynamicarray.h>
#include <linkedlist.h>

using namespace std;

int main(int argc, char *argv[])
{
    //DynamicArray test area
    /*
    DynamicArray *test = new DynamicArray();
    cout << "-Size-------------------------------------" << endl;
    cout << test->getSize() << endl;
    cout << "-Capacity---------------------------------" << endl;
    cout << test->getCapacity() << endl;
    cout << "-Display----------------------------------" << endl;
    test->display();
    cout << "-Sort-------------------------------------" << endl;
    test->bSort();
    cout << "-Display----------------------------------" << endl;
    test->display();
    cout << "-Insert(10) to front----------------------" << endl;
    test->pushFront(10);
    cout << "-Display----------------------------------" << endl;
    test->display();
    cout << "-buble_Sort-------------------------------" << endl;
    test->bSort();
    //cout << "-quick_Sort-------------------------------" << endl;
    //test->qSort();
    //cout << "-merge_Sort-------------------------------" << endl;
    //test->mSort();
    cout << "-Display----------------------------------" << endl;
    test->display();
    cout << "-resize(20)-------------------------------" << endl;
    test->resize(20);
    cout << "-Size-------------------------------------" << endl;
    cout << test->getSize() << endl;
    cout << "-Capacity---------------------------------" << endl;
    cout << test->getCapacity() << endl;
    cout << "-resize(0)--------------------------------" << endl;
    test->resize(0);
    test->display();
    cout << "\033[1;32m>>>>>>>>>> TESTS ARE DONE <<<<<<<<<<\033[0m" << endl;
    delete test;
*/

    //LinkedList test area
    LinkedList *test2 = new LinkedList();

    cout << endl;
    cout << "ll created\n";
    cout << test2->toString() << endl;
    test2->pushFront(1);
    cout << test2->toString() << endl;
    cout << "1 pushed front\n";
    test2->pushBack(4);
    cout << "4 pushed\n";
    test2->pushBack(3);
    cout << "3 pushed\n";
    cout << test2->toString() << endl;
    test2->deleteAt(1);
    cout << test2->toString() << endl;
    test2->insert(1,2);
    cout << test2->toString() << endl;
    test2->reverce();
    cout << test2->toString() << endl;
    test2->bSort();
    test2->display();
    test2->reverce();
    test2->display();
    test2->qSort();
    test2->display();
    test2->reverce();
    test2->pushFront(1);
    test2->pushFront(2);
    test2->pushFront(3);
    test2->pushFront(4);
    test2->pushFront(5);
    test2->pushFront(6);
    test2->pushFront(7);
    test2->pushFront(8);
    test2->display();
    LinkedList *test3 = test2;
    test2->mSort();
    test2->display();
    test3->qSort();
    test3->display();

    return 0;
}
