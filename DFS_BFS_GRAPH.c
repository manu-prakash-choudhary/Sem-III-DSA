#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices

// Graph Structure
struct Graph
{
    int numVertices;
    int adjList[6][6];
    int visited[6];
};

// Queue Structure for BFS
struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

// Queue Operations
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX - 1)
        printf("\nQueue is full!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("\nQueue is empty!");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// BFS algorithm
void bfs(struct Graph *graph, int startVertex)
{
    struct Queue *q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS Traversal: ");

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->adjList[currentVertex][i] == 1 && !graph->visited[i])
            {
                graph->visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

// Create and initialize a graph
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->adjList[i][j] = 0;
        }
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge
void addEdge(struct Graph *graph, int src, int dest)
{
    graph->adjList[src][dest] = 1;
    graph->adjList[dest][src] = 1; // For undirected graph
}

// DFS algorithm
void dfs(struct Graph *graph, int vertex)
{
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->adjList[vertex][i] == 1 && !graph->visited[i])
        {
            dfs(graph, i);
        }
    }
}

int main()
{
    struct Graph *graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    printf("DFS Traversal: ");
    dfs(graph, 0); 
    printf("\n");

    
    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->visited[i] = 0;
    }

    bfs(graph, 0); 

    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->visited[i] = 0;
    }
    return 0;
}
