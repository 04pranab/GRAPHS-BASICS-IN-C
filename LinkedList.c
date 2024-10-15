#include <stdio.h>
#include <stdlib.h>


typedef struct GraphNode {
    int vertex;               
    struct GraphNode* next;   
} node;


node* getnode(int v) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(node** list, int a, int b) {

    node* newNode = getnode(b);
    newNode->next = list[a];
    list[a] = newNode;

    
}


void printGraph(node** list, int vertices) {
    for (int v = 0; v < vertices; v++) {
        node* temp = list[v];
        printf("\nVertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;


    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);


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

    printGraph(list, vertices);


    return 0;
}
