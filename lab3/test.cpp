using namespace std;
#include <iostream>
#include <stdlib.h>

struct TQueueItem
{
    char value;
    TQueueItem *next;
};

struct TQueue
{
    TQueueItem *head;
    TQueueItem *tail;

    TQueue()
    {
        head = nullptr;
        tail = nullptr;
    }
};

int isEmpty(TQueue q)
{
    return q.head == nullptr;
}

void enQueue(TQueue &q, char value)
{
    if(isEmpty(q))
    {
        q.head = new TQueueItem();
        q.head->value = value;
        q.head->next = NULL;
        q.tail = q.head;
    }
    else
    {
        q.tail->next = new TQueueItem();
        q.tail->next->value = value;
        q.tail->next->next = NULL;
        q.tail = q.tail->next;
    }
}

char deQueue(TQueue &q)
{
    if(!isEmpty(q))
    {
        char result = q.head->value;
        TQueueItem *item = q.head;
        q.head = q.head->next;
        delete item;
        if(q.head == NULL)
            q.tail = q.head;

        return result;
    }

    return '\0';
}

void destroyQueue(TQueueItem *&item)
{
    if(item != NULL)
    {
        destroyQueue(item->next);
        delete item;
        item = NULL;
    }
}

TQueue copy(const TQueue &q)
{
    TQueue result = TQueue();
    if (isEmpty(q))
        result.head = result.tail = nullptr;

    // result.head = new TQueueItem;
    // result.head->value = q.head->value;
    // result.tail = result.head;

    TQueueItem *curr_q = q.head->next;
    TQueueItem *curr = result.head;

    while (curr_q != nullptr)
    {
        // result.head->next = new TQueueItem;
        // result.head->value = curr_q->value;

        curr_q = curr_q->next;
        // result.tail = result.head;
        // result.head = result.head->next;
    }

    return result;
}

int main()
{
    TQueue q = TQueue();

    enQueue(q, 'a');
    enQueue(q, 'b');
    enQueue(q, 'c');
    enQueue(q, 'd');
    enQueue(q, 'e');

    TQueue q2 = copy(q);

    while(!isEmpty(q2))
        cout << deQueue(q2) << '\0';

    return 0;
}