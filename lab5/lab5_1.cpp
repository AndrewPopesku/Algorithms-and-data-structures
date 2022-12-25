#include <bits/stdc++.h>
using namespace std;

struct TListItem
{
	int value;
	TListItem *next, *prev;
};

struct TList
{
	TListItem *first, *last;
};

struct TListIterator
{
	TListItem *pointer;
};

TListIterator initTListIterator()
{
	TListIterator tmp;
	tmp.pointer = NULL;
	return tmp;
}

TList initList()
{
	TList l;
	l.first = NULL;
	l.last = NULL;

	return l;
}

bool isEmpty(TList &list)
{
	return list.first == NULL;
}

void push(TList &list, int value)
{
	TListItem *newItem = new TListItem;
	newItem->value = value;
	newItem->next = NULL;

	if (list.first == NULL)
	{
		newItem->prev = NULL;
		list.first = newItem;
		list.last = list.first;

		return;
	}

	newItem->prev = list.last;
	list.last->next = newItem;
	list.last = list.last->next;
	return;
}

bool isValid(TListIterator it) { return it.pointer != NULL; }

void moveNext(TListIterator &it)
{
	if (isValid(it))
	{
		it.pointer = it.pointer->next;
	}
	return;
}

void movePrev(TListIterator &it)
{
	if (isValid(it))
	{
		it.pointer = it.pointer->prev;
	}
	return;
}

int getValue(const TListIterator &it)
{
	if (isValid(it))
	{
		return it.pointer->value;
	}
	return 0;
}

void setValue(const TListIterator &it, int value)
{
	if (isValid(it))
	{
		it.pointer->value = value;
	}
	return;
}

TListIterator getBegin(TList l)
{
	TListIterator tmp;
	tmp.pointer = l.first;
	return tmp;
}

TListIterator getEnd(TList l)
{
	TListIterator tmp;
	tmp.pointer = l.last;
	return tmp;
}

void deleteListItem(TList &l, TListIterator &it)
{
	if (!isValid(it))
		return;

	if (it.pointer == l.first)
	{
		l.first = it.pointer->next;
	}
	if (it.pointer == l.last)
	{
		l.last = it.pointer->prev;
	}

	TListItem *next = it.pointer->next;
	TListItem *prev = it.pointer->prev;

	delete it.pointer;
	it.pointer = next;

	if (prev != NULL)
	{
		prev->next = next;
	}
	if (next != NULL)
	{
		next->prev = prev;
	}

	if (l.first == NULL)
	{
		l.last = NULL;
	}
	if (l.last == NULL)
	{
		l.first = NULL;
	}

	return;
}

void printList(TList list)
{
	TListIterator it = getBegin(list);
	while (isValid(it))
	{
		cout << it.pointer->value << " ";
		moveNext(it);
   }
   cout << "\n";
}

int size(TList node)
{
	int count = 0;
	TListIterator it = getBegin(node);

	while(isValid(it))
	{
		count++;
		moveNext(it);
	}

	return count;
}

TList addPolynoms(TList first_poly, TList second_poly)
{
    TList result = initList();
	TListItem *f_poly_head = first_poly.first;
	TListItem *s_poly_head = second_poly.first;
	int f_count = size(first_poly) - 1;
    int s_count = size(second_poly) - 1;

	while(f_count != s_count)
    {
        if(f_count > s_count)
        {
            push(result, f_poly_head->value);
            f_poly_head = f_poly_head->next;
            f_count--;
        }
        else
        {
            push(result, s_poly_head->value);
            s_poly_head = s_poly_head->next;
            s_count--;
        }
    }

    while(f_poly_head != NULL)
    {
        push(result, f_poly_head->value + s_poly_head->value);
        f_poly_head = f_poly_head->next;
        s_poly_head = s_poly_head->next;
    }

    return result;
}

void input(TList &list)
{
    int count, num;
    cout << "\nEnter number of elements in polynom: ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> num;
        push(list, num);
    }
}

void output(TList &list)
{
    cout << "Polynom output: \n";

	TListIterator it = getBegin(list);
	int count = size(list) - 1;

	while(isValid(it))
	{
		if(it.pointer != list.last)
		{
			cout << showpos << getValue(it) << noshowpos << "x^" << count-- << " ";
		}
		else
		{
			cout << showpos << getValue(it);
		}

		moveNext(it);
	}
}

int main()
{
	TList l1 = initList();
	TList l2 = initList();

	input(l1);
	input(l2);

	TList result = addPolynoms(l1, l2);

	output(result);

	return 0;
}