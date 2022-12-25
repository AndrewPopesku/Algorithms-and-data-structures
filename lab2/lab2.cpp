using namespace std;
#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node<T> *next;
};

template <typename T>
void init(Node<T> *&stack)
{
    stack = NULL;
}

template <typename T>
int isEmpty(Node<T> *stack)
{
    return stack == NULL;
}

template <typename T>
void push(Node<T> *&stack, T value)
{
    if (isEmpty(stack))
    {
        stack = new Node<T>;
        stack->value = value;
        stack->next = NULL;
    }
    else
    {
        Node<T> *tmp = stack;
        stack = new Node<T>;
        stack->value = value;
        stack->next = tmp;
    }
}

template <typename T>
T pop(Node<T> *&stack)
{
    if (!isEmpty(stack))
    {
        T tmp = stack->value;
        Node<T> *item = stack->next;
        delete stack;
        stack = item;
        return tmp;
    }
    T temp;
    return temp;
}

template <typename T>
T peek(Node<T> *&stack)
{
    if (!isEmpty(stack))
        return stack->value;

    T temp;
    return temp;
}

template <typename T>
void fillStack(Node<T> *&stack, int quantity)
{
    init(stack);
    T number;
    cout << "\nEnter " << quantity << " numbers in stack: \n";
    while(quantity)
    {
        cin >> number;
        push(stack, number);
        quantity--;
    }
}

template <typename T>
void mergeWithEvenNumbers(Node<T> *fromStack, Node<T> *&toStack)
{
    while(!isEmpty(fromStack))
    {
        if(peek(fromStack) % 2 == 0)
            push(toStack, pop(fromStack));
        else
            pop(fromStack);
    }
}

int main()
{
    Node<int> *first_stack, *second_stack, *result;
    fillStack(first_stack, 10);
    fillStack(second_stack, 10);
    init(result);

    mergeWithEvenNumbers(first_stack, result);
    mergeWithEvenNumbers(second_stack, result);

    cout << "\nResult:\n";
    while(!isEmpty(result))
        cout << pop(result) << '\n';

    return 0;
}