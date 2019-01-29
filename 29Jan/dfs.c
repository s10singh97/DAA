// DFS using tree

#include<stdio.h>
#include<stdlib.h>

struct DFS
{
    char data;
    struct DFS *next, *prev;
};

struct DFS * create(char val)
{
    struct DFS *temp = (struct DFS*)malloc(sizeof(struct DFS));
    temp -> data = val;
    temp -> next = NULL;
    temp -> prev = NULL;
}

// void insert(struct DFS *root, struct DFS *temp)
// {
//     // if((root -> data > temp -> data))
//     // {
//     //     if(root -> next == NULL)
//     //         root -> next = temp;
//     //     else
//     //         insert(root -> next, temp);
//     // }
//     // else
//     // {
//     //     if(root -> prev == NULL)
//     //         root -> prev = temp;
//     //     else
//     //         insert(root -> prev, temp);
//     // }    
// }

void display(struct DFS * root)
{
    printf("%c ", root -> data);
    if(root -> prev != NULL)
        display(root -> prev);
    if(root -> next != NULL)
        display(root -> next);
}

int main(int argc, char const *argv[])
{
    struct DFS * root = NULL, *child_l, *child_r;
    root = create('A');
    child_l = create('B');
    child_r = create('C');
    root -> prev = child_l;
    root -> next = child_r;
    child_l = create('D');
    child_r = create('E');
    root -> prev -> prev = child_l;
    root -> prev -> next = child_r;
    child_l = create('F');
    child_r = create('G');
    root -> next -> prev = child_l;
    root -> next -> next = child_r;
    
    int choice;
    char a;
    while(1)
    {
        printf("Choose:\n1. Display DFS\n2. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: display(root);
                    printf("\n");
                    break;
            
            case 2: exit(0);

            default:printf("Please enter a correct choice\n");
        }
    }
    return 0;
}
