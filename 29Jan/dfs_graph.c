// DFS using graph

#include<stdio.h>
#include<stdlib.h>

struct DFS
{
    char data;
    int color;
    struct DFS *c1, *c2;
};

struct DFS * create(char val)
{
    struct DFS *temp = (struct DFS*)malloc(sizeof(struct DFS));
    temp -> data = val;
    temp -> c1 = NULL;
    temp -> c2 = NULL;
    temp -> color = 0;
    // temp -> c3 = NULL;
    // temp -> c4 = NULL;
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
    if(root -> color == 0)
    {
        printf("%c ", root -> data);
        root -> color = 1;
        if(root -> c1 != NULL)
            display(root -> c1);
        if(root -> c2 != NULL)
            display(root -> c2);
    }
}

int main(int argc, char const *argv[])
{
    struct DFS * root = NULL, *child1, *child2, *child3, *child4;
    root = create('A');
    child1 = create('B');
    child2 = create('C');
    child3 = create('D');
    child4 = create('E');
    root -> c1 = child1;
    root -> c2 = child2;
    child1 -> c1 = child3;
    child1 -> c2 = child4;
    child2 -> c1 = child3;
    child2 -> c2 = child4;
    child1 = create('F');
    child3 -> c1 = child1;
    child4 -> c1 = child1;


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
