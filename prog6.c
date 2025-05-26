#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <limits.h>

struct Edges
{
    int src, dest, wt;
};

struct Graph
{
    int Vertex, Edge;
    struct Edges *edge;
};

struct Graph *designGraph(int Vertex, int Edge)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->Vertex = Vertex;
    graph->Edge = Edge;
    graph->edge = (struct Edges *)malloc(graph->Edge * sizeof(struct Edges));
    return graph;
}

void Solution(int dist[], int n)
{
    printf("\nVertex\tDistance from Source Vertex\n");
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void BellmanFordalgorithm(struct Graph *graph, int src)
{
    int Vertex = graph->Vertex;
    int Edge = graph->Edge;
    int Distance[Vertex];
    int i, j;

    for (i = 0; i < Vertex; i++)
        Distance[i] = INT_MAX;
    Distance[src] = 0;

    for (i = 1; i <= Vertex - 1; i++)
    {
        for (j = 0; j < Edge; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int wt = graph->edge[j].wt;
            if (Distance[u] + wt < Distance[v])
                Distance[v] = Distance[u] + wt;
        }
    }

    for (i = 0; i < Edge; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int wt = graph->edge[i].wt;
        if (Distance[u] + wt < Distance[v])
            printf("This graph contains negative edge cycle\n");
    }

    Solution(Distance, Vertex);
    return;
}

int main()
{
    int V, E, S;
    printf("Enter number of vertices\n");
    scanf("%d", &V);
    printf("Enter number of edges\n");
    scanf("%d", &E);
    printf("Enter the source vertex number\n");
    scanf("%d", &S);

    struct Graph *graph = designGraph(V, E);
    int i;
    for (i = 0; i < E; i++)
    {
        printf("\nEnter edge %d properties Source, destination, weight respectively\n", i + 1);
        scanf("%d", &graph->edge[i].src);
        scanf("%d", &graph->edge[i].dest);
        scanf("%d", &graph->edge[i].wt);
    }

    BellmanFordalgorithm(graph, S);

    return 0;
}
