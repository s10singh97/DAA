// Dijkstra's

#include <stdio.h> 
#include <limits.h> 
#include <stdlib.h>
#include <stdbool.h>
#define V 7

int minc(int parent[], bool vnotinc[])
{
    int min = INT_MAX, min_ind;
    for(int i = 0; i < V; i++)
    {
        if(vnotinc[i] == false && parent[i] <= min)
        {
            min = parent[i];
            min_ind = i;
        }
    }
    return min_ind;
}

void prim(int graph[V][V])
{
    int parent[V];
    bool vnotinc[V];
    for(int i = 0; i < V; i++)
    {
        parent[i] = INT_MAX;
        vnotinc[i] = false;
    }
    parent[0] = 0;
    for(int j = 0; j < V-1; j++)
    {
        int a = minc(parent, vnotinc);
        vnotinc[a] = true;
        for(int j = 0; j < V; j++)
        {
            if(graph[a][j] && vnotinc[j] == false && parent[a] + graph[a][j] < parent[j] && parent[a] != INT_MAX)
            {
                parent[j] = parent[a] + graph[a][j];
            }
        }
    }
    
    printf("Source to Destination\n"); 
    for (int i = 1; i < V; i++) 
        printf("%c\t%d\n", i+65, parent[i]);
    printf("\n");
}

int main()
{
    int graph[V][V] = {
        {0,5,4,0.0,0,0},{5,0,3,4,7,0,0},{4,3,0,2,0,6,0},{0,4,2,0,5,1,0},{0,7,0,5,0,0,6},{0,0,6,1,0,0,7},{0,0,0,0,6,7,0}
    };
    prim(graph);
    return 0;
}
