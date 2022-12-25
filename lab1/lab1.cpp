using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node() : data(T()), next(NULL) {}
    Node(T data) : data(data), next(NULL) {}
    Node(T data, Node<T> *next) : data(data), next(next) {}
};

template <typename T>
struct Stack
{
    Node<T> *head;

    Stack() : head(NULL) {}

    int isEmpty() { return head == NULL; }
    void push(T data);
    void pop();
    T top();
};

template <typename T>
void Stack<T>::push(T data)
{
    if (isEmpty())
    {
        head = new Node<T>(data);
        return;
    }

    head = new Node<T>(data, head);
}

template <typename T>
T Stack<T>::top()
{
    if (isEmpty())
    return head->data;
}

template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
        return;

    Node<T> *tmp = head;
    head = head->next;
    delete tmp;
}

int main()
{
    Node<int> *first_stack;
    Node<int> *second_stack;

    // init(first_stack);
    // for (int i = 0; i < 10; i++)
    //     push(first_stack, i * i);

    return 0;
}