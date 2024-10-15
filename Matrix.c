#include <stdio.h>
#include <stdlib.h>

void Initialise(int **Mat, int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            Mat[i][j] = 0; 
        }
    }
}

void printMatrix(int **Mat, int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", Mat[i][j]);
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

    int **Mat = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        Mat[i] = (int *)malloc(vertices * sizeof(int));
    }


    Initialise(Mat, vertices);


    printf("Enter the edges (as pairs of vertices):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        Mat[u-1][v-1] = 1;


        
    }

   
    printMatrix(Mat, vertices);


    return 0;
}
