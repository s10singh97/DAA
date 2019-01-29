// Depth First Search(DFS)
#include<iostream>
using namespace std;

class node
{
    public:
    char data;
    node *left, *right;
};

node * create(char ch)
{
    node *temp = new node;
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> data = ch;
    return temp;
}

void insert(node *root, node *temp)
{
    if(root -> left == NULL)
        root -> left = temp;
    else
    {
        insert(root -> left, temp);
    }

    
}