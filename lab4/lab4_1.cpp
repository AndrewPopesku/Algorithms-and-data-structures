#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

int size(Node *node)
{
    int count = 0;
    while (node != NULL)
    {
        node = node->next;
        count++;
    }

    return count;
}

void push(Node *&head_ref, int new_data)
{
    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = head_ref;
    new_node->prev = NULL;

    if (head_ref != NULL)
        head_ref->prev = new_node;

    head_ref = new_node;
}

void append(Node *&head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *last = head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (head_ref == NULL)
    {
        new_node->prev = NULL;
        head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;

    return;
}

Node* addPolynoms(Node *first_poly, Node *second_poly)
{
    Node *result = NULL;
    int f_count = size(first_poly) - 1;
    int s_count = size(second_poly) - 1;

    while(f_count != s_count)
    {
        if(f_count > s_count)
        {
            append(result, first_poly->data);
            first_poly = first_poly->next;
            f_count--;
        }
        else
        {
            append(result, second_poly->data);
            second_poly = second_poly->next;
            s_count--;
        }
    }

    while(first_poly != NULL)
    {
        append(result, first_poly->data + second_poly->data);
        first_poly = first_poly->next;
        second_poly = second_poly->next;
    }

    return result;
}

void output(Node *node)
{
    Node *last;
    cout << "Polynom output: \n";
    int count = size(node) - 1;

    while (node != NULL)
    {
        if (count != 0)
            cout << showpos << node->data << noshowpos << "x^" << count-- << ' ';
        else
            cout << showpos << node->data;

        node = node->next;
    }
}

void destroyList(Node *&node)
{
    if (node != nullptr)
    {
        destroyList(node);
        delete node;
        node = nullptr;
    }
}

void input(Node *&node)
{
    int count, num;
    cout << "\nEnter number of elements in polynom: ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> num;
        append(node, num);
    }
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    input(poly1);
    output(poly1);

    input(poly2);
    output(poly2);

    Node *result = addPolynoms(poly1, poly2);

    cout << "\n\nResult: " << endl;
    output(result);

    destroyList(result);
    return 0;
}