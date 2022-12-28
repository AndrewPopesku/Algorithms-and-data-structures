#include<iostream>

using namespace std;

struct node
{
	string data;
	int count;
	node *left;
	node *right;
};

node* CreateNode(string data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->count = 1;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

node* InsertIntoTree(node* root, string data)
{
	node *temp = CreateNode(data);
	node *t = new node;
	t = root;

	if(root == NULL)
		root = temp;
	else	
	{
		while(t != NULL)
		{
			if(t->data == data)
			{
				t->count++;
				break;
			}
			else if(t->data < data )
			{
				if(t->right == NULL)
				{
					t->right = temp;
					break;
				}
				t = t->right;
			}
			else if(t->data > data)
			{
				if(t->left == NULL)
				{
					t->left = temp;
					break;
				}
				t = t->left;
			}
		}
	}
	return root;
}

void Search(node *root, string data)
{
	node *temp = new node;
	temp = root;
	while(temp != NULL)
	{
		if(temp->data == data)
		{
			cout<<"\nData item '"<<data<<"' is present "<<temp->count<<" number of times.";
			return;
		}
		else if(temp->data > data)
			temp = temp->left;
		else
			temp = temp->right;
	}

	cout<<"\n Data not found";
	return;
}


int main()
{
    string n, a[25] = {
        "parent",
        "child",
        "nice",
        "world",
        "word",
        "parent",
        "child",
        "space",
        "parent", 
        "study",
        "C#"
    };
    node *root = new node;
	root = NULL;

	for(int i = 0; i < 25; i++)
		root = InsertIntoTree(root, a[i]);

	cout<<"\nEnter the Element to be searched: ";
	cin>>n;

	Search(root, n);
	return 0;
}