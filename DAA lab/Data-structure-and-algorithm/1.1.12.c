#include <stdio.h>
#include <stdbool.h>
//25070521051
//Hrishikesh dapurkar
#define MAX 100

static int minKey(int key[], bool mstSet[], int vertices) {
    int min = 2147483647;
    int minIndex = -1;

    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

static void printMST(int parent[], int graph[MAX][MAX], int vertices) {
    printf("Edge\tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[MAX][MAX], int vertices) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < vertices; i++) {
        key[i] = 2147483647;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        if (u == -1)
            break;

        mstSet[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, vertices);
}

int main(void) {
    int vertices;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix (%d x %d):\n", vertices, vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, vertices);
    return 0;
}
