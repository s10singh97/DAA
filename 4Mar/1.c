// Floyd Warshall

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define V 5
#define MAX 1000

void bellman(int graph[V][V])
{
    int dist[V][V];
    int i, j;
    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            dist[i][j] = graph[i][j]; 
    int k;
    for(k = 0; k < V; k++)
    {
        for(i = 0; i < V; i++)
        {
            for(j = 0; j < V; j++)
            {
                if(dist[i][j] > dist[i][k] + graph[k][j])
                {
                    dist[i][j] = dist[i][k] + graph[k][j];
                    // if(dist[i][0] < 0)
                    // {
                    //     printf("Negative Cycle Detected\n");
                    //     exit(0);
                    // }
                }
            }
        }
    }
    for(i = 0; i < V; i++)
    {
        for(j = 0; j < V; j++)
        {
            if(dist[i][j] == MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {
        {0,4,6,MAX,MAX}, {MAX,0,3,4,5}, {MAX,MAX,0,MAX,4},
        {MAX,MAX,MAX,0,MAX}, {MAX,MAX,MAX,5,0}
    };
    bellman(graph);
    return 0;
}