#include "linkedlist.h"
#include <time.h>

LinkedList::LinkedList()
{
    head = 0;
}

LinkedList::~LinkedList()
{
    linkedlist *tmp = new linkedlist;
    while (head)
    {
        tmp = head->next;
        delete head;
        head = tmp;
    }
    delete tmp;
    delete head;
}

void LinkedList::pushBack(int element)
{
    linkedlist *tmp = new linkedlist;
    tmp = head;
    while (tmp->next != 0)
        tmp = tmp->next;
    linkedlist *n = new linkedlist;
    n->num = element;
    n->next = 0;
    tmp->next = n;
}

void LinkedList::insert(int pos, int element)
{
    if (pos == 0)
    {
        linkedlist *ne = new linkedlist;
        ne->next = head;
        ne->num = element;
        head = ne;
    }
    else
    {
        linkedlist *tmp = new linkedlist;
        tmp = head;
        for (int i = 0; i < pos - 1; i++)
            tmp = tmp->next;
        linkedlist *new_entry = new linkedlist;
        new_entry->next = tmp->next;
        tmp->next = new_entry;
        new_entry->num = element;
    }
}

void LinkedList::pushFront(int element)
{
    linkedlist *tmp = new linkedlist;
    tmp->num = element;
    tmp->next = head;
    head = tmp;
    size++;
}

void LinkedList::deleteAt(int pos)
{
    if (pos == 0)
        head = head->next;
    else
    {
        linkedlist *tmp = new linkedlist;
        tmp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
    }
}

int LinkedList::elementAt(int pos)
{
    if (pos == 0)
        return head->num;
    else
    {
        linkedlist *tmp = new linkedlist;
        tmp = head;
        for (int i = 0; i < pos; i++)
        {
            tmp = tmp->next;
        }
        return (tmp->num);
    }
}

void LinkedList::reverce()
{
    linkedlist *nl = new linkedlist;
    nl = 0;
    while (head != 0)
    {
        linkedlist *ne = new linkedlist;
        ne->next = nl;
        ne->num = head->num;
        nl = ne;
        head = head->next;
    }
    head = nl;
}

void LinkedList::display()
{
    linkedlist *tmp = new linkedlist;
    tmp = head;
    while (tmp != 0)
    {
        std::cout << tmp->num << " ";
        tmp = tmp->next;
    }
    std::cout << "\n";
}

void LinkedList::bSort()
{
    linkedlist *curr = new linkedlist;
    linkedlist *trail = new linkedlist;
    linkedlist *temp = new linkedlist;
    for (int i = 0; i < size + 1; i++)
    {
        curr = trail = head;
        while (curr->next)
        {
            if (curr->num > curr->next->num)
            {
                temp = curr->next;
                curr->next = curr->next->next;
                temp->next = curr;
                if(curr == head)
                    head = trail = temp;
                else
                    trail->next = temp;
                curr = temp;
            }
            trail = curr;
            curr = curr->next;
        }
    }
}
//qsort functions start
void LinkedList::qSort()
{
    double t = clock();
    head = quickSortRecur(head, getTail(head));
    std::cout << (clock() - t) / CLK_TCK << " секунди\n";
}

// Returns the last node of the list
linkedlist *LinkedList::getTail(linkedlist *cur)
{
    while (cur != 0 && cur->next != 0)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the last element as the pivot
linkedlist *LinkedList::partition(linkedlist *lhead, linkedlist *end,
                       linkedlist **newHead, linkedlist **newEnd)
{
    linkedlist *pivot = end;
    linkedlist *prev = 0, *cur = lhead, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->num < pivot->num)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == 0)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            linkedlist *tmp = cur->next;
            cur->next = 0;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update newEnd to the current last node
    (*newEnd) = tail;

    // Return the pivot node
    return pivot;
}

//here the sorting happens exclusive of the end node
linkedlist *LinkedList::quickSortRecur(linkedlist *lhead, linkedlist *end)
{
    // base condition
    if (!lhead || lhead == end)
        return lhead;

    linkedlist *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    linkedlist *pivot = partition(lhead, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        linkedlist *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);

        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}
//qsort functions end

//msort functions start
void LinkedList::mSort()
{
    double t = clock();
    MergeSort(&head);
    std::cout << (clock() - t) / CLK_TCK << " секунди\n";
}

void LinkedList::MergeSort(linkedlist **headRef)
{
    linkedlist *lhead = *headRef;
    linkedlist *a;
    linkedlist *b;

    /* Base case -- length 0 or 1 */
    if ((lhead == 0) || (lhead->next == 0))
    {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(lhead, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

linkedlist *LinkedList::SortedMerge(linkedlist *a, linkedlist *b)
{
    linkedlist *result = 0;

    /* Base cases */
    if (a == 0)
        return(b);
    else if (b == 0)
        return(a);

    /* Pick either a or b, and recur */
    if (a->num <= b->num)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

/* Split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.
     If the length is odd, the extra node should go in the front list.
     Uses the fast/slow pointer strategy.  */
void LinkedList::FrontBackSplit(linkedlist *source, linkedlist **frontRef,
                    linkedlist **backRef)
{
    linkedlist *fast;
    linkedlist *slow;
    if (source == 0 || source->next == 0)
    {
        /* length < 2 cases */
        *frontRef = source;
        *backRef = 0;
    }
    else
    {
        slow = source;
        fast = source->next;

        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != 0)
        {
            fast = fast->next;
            if (fast != 0)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

    /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
        *frontRef = source;
        *backRef = slow->next;
        slow->next = 0;
    }
}
//msort functions end

//выводят одинаковое значение
/*
ui LinkedList::getSize()
{
    return getCapacity();
}

ui LinkedList::getCapacity()
{
    return size;
}

std::string LinkedList::toString()
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
*/
