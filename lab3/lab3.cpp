using namespace std;
#include <stdlib.h>
#include <iostream>

struct TQueueItem
{
    char value;
    TQueueItem *next;
};

struct TQueue
{
    TQueueItem *head;
    TQueueItem *tail;
};

TQueue initQueue()
{
    TQueue q;
    q.head = nullptr;
    q.tail = nullptr;
    return q;
}

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
    if(item != nullptr)
    {
        destroyQueue(item->next);
        delete item;
        item = nullptr;
    }
}

void destroyQueue(TQueue &q)
{
    destroyQueue(q.head);
    q.tail = nullptr;
}

int isContains(TQueue &q, char c)
{
    if (isEmpty(q))
        return 0;

    TQueueItem *curr_q = q.head;

    while(curr_q != nullptr)
    {
        if (curr_q->value == c)
            return 1;

        curr_q = curr_q->next;
    }
}

TQueue differenceBetween(TQueue first_q, TQueue second_q)
{
    TQueue result = initQueue();

    while(!isEmpty(first_q))
    {
        char tmp = deQueue(first_q);

        if (!isContains(second_q, tmp))
            enQueue(result, tmp);
    }

    return result;
}

void inputValues(TQueue &q)
{
    int size;
    cout << "\nEnter size of queue: ";
    cin >> size;
    cout << "Enter char values in queue:\n";
    char c;
    for (int i = 0; i < size; i++)
    {
        cin >> c;
        enQueue(q, c);
    }
}

int main()
{
    TQueue first_queue = initQueue();
    TQueue second_queue = initQueue();

    inputValues(first_queue);
    inputValues(second_queue);

    TQueue result = differenceBetween(first_queue, second_queue);

    cout << "\nResult:\n";
    while(!isEmpty(result))
        cout << deQueue(result) << '\n';

    destroyQueue(first_queue);
    destroyQueue(second_queue);
    destroyQueue(result);
    return 0;
}