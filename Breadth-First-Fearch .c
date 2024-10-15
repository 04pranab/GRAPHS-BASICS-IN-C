#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode
{
    int vertex;
    struct GraphNode *next;
} node;

typedef struct Queue
{

    int front;
    int rear;
    unsigned capacity;
    int *array;

} qw;

// initialize the a queue

qw *createQW(unsigned capacity)
{
    qw *queue = (qw *)malloc(sizeof(qw));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(qw *queue)
{
    return (queue->front == -1);
}

int isFull(qw *queue)
{
    if (queue->front == queue->rear && queue->front != -1 && queue->rear != -1)
    {
        return 1;
    }

    else if (queue->front == (queue->rear - 1))
    {
        return 1;
    }

    else if (queue->front == 0 && queue->rear == (queue->capacity) - 1)

    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void Enqueue(qw *queue, int x)
{
    if (isFull(queue))
    {
        printf("Queue is full.\n");
    }

    if (isEmpty(queue))
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->array[queue->rear] = x;

    //printf("Enqueued : %d\n", x);
}

int Dequeue(qw *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty.\n");
    }

    int item = queue->array[queue->front];
     
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }

    return item;
}


void displayQueue(qw *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue elements are: \n");
    int i = queue->front;
    while (i != queue->rear)
    {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("%d\n", queue->array[queue->rear]);
}

///////////////////////////////////////////////////////

node *getnode(int v)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(node **list, int a, int b)
{

    node *newNode = getnode(b);
    newNode->next = list[a];
    list[a] = newNode;

    node *newNode2 = getnode(a);
    newNode2->next = list[b];
    list[b] = newNode2;
}

void printGraph(node **list, int vertices)
{
    for (int v = 0; v < vertices; v++)
    {
        node *temp = list[v];
        printf("\nVertex %d: ", v);
        while (temp)
        {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}


void printPath(int arr[], int source,int target, int v)
{
    if (arr[target] != -1)
    {
        printPath(arr, source ,arr[target],v);
    }

    printf("%d -> ", target);
}



int main() {
    int vertices, edges;


    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int flags[vertices];
    int pred[vertices];

    for(int i = 0; i < vertices; i++)
    {
        flags[i] = 0;
        pred[i] = -1;
    }

    node** list = (node**)malloc(vertices * sizeof(node*));


    for (int i = 0; i < vertices; i++) {
        list[i] = NULL;
    }

    printf("Enter the edges (as pairs of vertices):\n");
    for (int i = 0; i < edges; i++) {
        int a, b;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &a, &b);

        addEdge(list, a, b);
    }
    
    printf("The adj List looks like : \n");
    printGraph(list, vertices);

    
    int source, target;

    printf("\n\nEnter the Source node :");
    scanf("%d", &source);

    printf("\nEnter the Target node :");
    scanf("%d", &target);



    qw* Q = createQW(edges);

    flags[source] = 1;

    Enqueue(Q,source);

    while(!(isEmpty(Q)))
    {
        int v = Dequeue(Q);
        node *temp = list[v];

        while (temp != NULL)
        {
            if (!(flags[temp->vertex]))
            {
                flags[temp->vertex] = 1;
                pred[temp->vertex] = v;
                Enqueue(Q, temp->vertex);
            }

            temp = temp->next;
        }

    }
    

    /*for (int j = 0; j <  vertices; j++)
    {
        printf("%d -- %d\n", j, pred[j]);
    }*/

    printf("\n");
    printPath(pred, source, target, vertices);
    printf("\n");

    return 0;
}
