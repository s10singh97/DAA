// Rabin Karp and Brute Force
#include<stdio.h>

void bruteforce(int t[10], int p[3])
{
    int i, j;
    for(i = 0; i < 10; i++)
    {
        int flag[3] = {0, 0, 0};
        for(j = 0; j < 3; j++)
        {
            if(t[i+j] != p[j])
            {
                flag[j] = 0;
                break;
            }
            else
            {
                flag[j] = 1;
            }
            if(j == 2)
            {
                int sum = 0;
                for(j = 0; j < 3; j++)
                {
                    sum += flag[j];
                }
                if(sum == 3)
                    printf("Pattern found at %d position\n", i+1);
            }
        }
    }
}

int dec(int p[3])
{
    int num = 0, m = 3, i = 0;
    while(m)
    {
        num = num*10 + p[i];
        i++;
        m--;
    }
    return num;
}

void rabinkarp(int t[10], int p[3])
{
    int dec_p = dec(p);
    // printf("%d\n", dec_p);
    int i, j, window[3];
    for(i = 0; i < 10-3+1; i++)
    {
        for(j = 0; j < 3; j++)
        {
            window[j] = t[i+j];
        }
        int dec_win = dec(window);
        if(dec_p == dec_win)
        {
            printf("Pattern found at %d\n", i+1);
        }
    }
}

int main()
{
    int t[10], p[3], i;
    printf("Enter Text: ");
    for(i = 0; i < 10; i++)
        scanf("%d", &t[i]);
    printf("Enter Pattern: ");
    for(i = 0; i < 3; i++)
        scanf("%d", &p[i]);
    char ch;
    do{
        int choice;
        printf("1. Brute Force\n2. Rabin Karp\nEnter Algo to select: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: bruteforce(t, p);
                    break;

            case 2: rabinkarp(t, p);
                    break;
        
            default:printf("Please enter a correct choice");
                    break;
        }/* condition */
        printf("Do you want to enter more: ");
        scanf(" %c", &ch);
    }while(ch == 'y' || ch == 'Y');
    return 0;
}