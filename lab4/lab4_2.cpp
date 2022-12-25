#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	string data;
	Node *next;
};

void push(Node *&head_ref, string data)
{

	Node *ptr1 = new Node();
	ptr1->data = data;
	ptr1->next = head_ref;

	if (head_ref != NULL)
	{

		Node *temp = head_ref;
		while (temp->next != head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1;

	head_ref = ptr1;
}

void printList(Node *head)
{
	Node *temp = head;
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

int countOccurences(Node *node, string str)
{
	int count = 0;
	Node *tmp = node;
	do
	{
		if (node->data == str)
			count++;
		node = node->next;
	} while (tmp != node);

	return count;
}

// void input(Node *&node)
// {
// 	int count;
// 	string word;
// 	cout << "Enter number of words in text: ";
// 	cin >> count;

// 	for (int i = 0; i < count; i++)
// }

int main()
{
	Node *head = NULL;

	push(head, "the");
	push(head, "first");
	push(head, "word");
	push(head, "in");
	push(head, "the");
	push(head, "world");
	push(head, "is");
	push(head, "the");

	cout << countOccurences(head, "the");

	// printList(head);

	return 0;
}