#include <bits/stdc++.h>
using namespace std;

struct TListItem
{
    string data;
    TListItem *next;
};

struct TListIterator
{
    TListItem *start;
    TListItem *pointer;
};

TListIterator initTListIterator()
{
    TListIterator tmp;
    tmp.pointer = NULL;
    tmp.start = NULL;
    return tmp;
}

bool isValid(TListIterator it)
{
    return it.pointer != NULL && it.pointer->next != it.start;
}

void moveNext(TListIterator &it)
{
    if (isValid(it))
    {
        it.pointer = it.pointer->next;
    }
    return;
}

string getValue(const TListIterator &it)
{
    if (isValid(it))
    {
        return it.pointer->data;
    }
    return 0;
}

void setValue(const TListIterator &it, int value)
{
    if (isValid(it))
    {
        it.pointer->data = value;
    }
    return;
}

TListIterator getBegin(TListItem *l)
{
    TListIterator tmp;
    tmp.pointer = l;
    tmp.start = l;
    return tmp;
}

void push(TListItem *&head_ref, string data)
{
    TListItem *ptr1 = new TListItem();
    ptr1->data = data;
    ptr1->next = head_ref;

    if (head_ref != NULL)
    {
        TListItem *temp = head_ref;
        while (temp->next != head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;

    head_ref = ptr1;
}

void printList(TListItem *head)
{
    TListItem *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    cout << endl;
}

int countOccurences(TListItem *node, string str)
{
    int count = 0;
    TListItem *tmp = node;

    TListIterator it = getBegin(node);

    while (isValid(it))
    {
        if(it.pointer->data == str)
            count++;
        moveNext(it);
    }

    if (it.pointer->data == str)
        count++;

    return count;
}

void input(TListItem *&node)
{
	int count;
	string word;
	cout << "Enter number of words in text: ";
	cin >> count;

	for (int i = 0; i < count; i++)
    {
        cin >> word;
        push(node, word);
    }
}

int main()
{
    TListItem *head = NULL;

    // input(head);
    push(head, "the");
    push(head, "first");
    push(head, "word");
    push(head, "in");
    push(head, "the");
    push(head, "world");
    push(head, "is");
    push(head, "the");

    cout << "Count of occurences: " << countOccurences(head, "the");

    // printList(head);

    return 0;
}