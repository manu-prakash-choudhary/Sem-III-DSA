#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in adjacency list
struct AdjListNode
{
    int value;
    struct AdjListNode *next;
};

// Structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head; // Pointer to head node of the list
};

// Structure to represent a graph
struct Graph
{
    int V;                 // Number of vertices
    struct AdjList *array; // Array of adjacency lists
};

// Function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int value)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    if (graph == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    graph->V = V;

    // Create an array of adjacency lists. Size of array will be V
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
    if (graph->array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
    {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int value)
{
    // Add an edge from src to dest
    struct AdjListNode *newNode = newAdjListNode(value);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[value].head;
    graph->array[value].head = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->V; ++v)
    {
        struct AdjListNode *temp = graph->array[v].head;
        printf("Adjacency list of vertex %d\n head", v);
        while (temp)
        {
            printf(" -> %d", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Structure for stack
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// Function to create a stack of given capacity
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (stack == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    if (stack->array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return stack;
}

// Stack functions
int isStackEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (!isStackEmpty(stack))
    {
        return stack->array[stack->top--];
    }
    return -1; // Stack is empty
}

// Function to perform Depth First Search (DFS) traversal
void DFS(struct Graph *graph, int start)
{
    // Create a stack for DFS
    struct Stack *stack = createStack(graph->V);

    // Array to keep track of visited vertices
    int *visited = (int *)malloc(graph->V * sizeof(int));
    if (visited == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < graph->V; ++i)
    {
        visited[i] = 0;
    }

    // Push the start vertex onto the stack and mark it as visited
    push(stack, start);
    visited[start] = 1;

    // Traverse while stack is not empty
    while (!isStackEmpty(stack))
    {
        // Pop a vertex from stack and print it
        int current = pop(stack);
        printf("%d ", current);

        // Get all adjacent vertices of the popped vertex current
        // If an adjacent has not been visited, then mark it visited
        // and push it to the stack
        struct AdjListNode *temp = graph->array[current].head;
        while (temp)
        {
            if (!visited[temp->value])
            {
                push(stack, temp->value);
                visited[temp->value] = 1;
            }
            temp = temp->next;
        }
    }

    // Free allocated memory
    free(stack->array);
    free(stack);
    free(visited);
}

// Structure for queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// Function to create a queue of given capacity
struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (queue == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // This is important, see the enqueue
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    if (queue->array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return queue;
}

// Queue functions
int isQueueEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

int isQueueFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

void enqueue(struct Queue *queue, int item)
{
    if (isQueueFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue *queue)
{
    if (isQueueEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to perform Breadth First Search (BFS) traversal
void BFS(struct Graph *graph, int start)
{
    // Create a queue for BFS
    struct Queue *queue = createQueue(graph->V);

    // Array to keep track of visited vertices
    int *visited = (int *)malloc(graph->V * sizeof(int));
    if (visited == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < graph->V; ++i)
    {
        visited[i] = 0;
    }

    // Enqueue the start vertex and mark it as visited
    enqueue(queue, start);
    visited[start] = 1;

    // Traverse while queue is not empty
    while (!isQueueEmpty(queue))
    {
        // Dequeue a vertex from queue and print it
        int current = dequeue(queue);
        printf("%d ", current);

        // Get all adjacent vertices of the dequeued vertex current
        // If an adjacent has not been visited, then mark it visited
        // and enqueue it
        struct AdjListNode *temp = graph->array[current].head;
        while (temp)
        {
            if (!visited[temp->value])
            {
                enqueue(queue, temp->value);
                visited[temp->value] = 1;
            }
            temp = temp->next;
        }
    }

    
}

// Driver program to test above functions
int main()
{
    // Create a graph with 5 vertices
    int V = 5;
    struct Graph *graph = createGraph(V);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency list representation of the graph
    printf("Graph represented using adjacency list:\n");
    printGraph(graph);
    printf("\n");

    // Perform BFS traversal starting from vertex 0
    printf("BFS traversal starting from vertex 0:\n");
    BFS(graph, 0);
    printf("\n");
}