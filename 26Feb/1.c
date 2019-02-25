// Bellman Ford

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<stdlib.h>
#define V 5

void bellman(int graph[V][V])
{
    int dist[5] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    dist[0] = 0;
    int i, j;
    for(i = 0; i < V; i++)
    {
        for(j = 0; j < V; j++)
        {
            if((dist[j] > dist[i] + graph[i][j]) && graph[i][j] != 0)
            {
                dist[j] = dist[i] + graph[i][j];
                if(dist[0] < 0)
                {
                    printf("Negative Cycle Detected\n");
                    exit(0);
                }
            }
        }
    }
    for(i = 0; i < V; i++)
        printf("%c\t%d\n", i+65, dist[i]);
}

int main()
{
    int graph[V][V] = {
        {0,-1,4,0,0}, {0,0,3,2,2}, {0,0,0,0,0}, {0,1,5,0,0}, {0,0,0,-3,0}
    };
    bellman(graph);
    return 0;
}