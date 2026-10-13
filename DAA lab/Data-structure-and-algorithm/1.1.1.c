#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//25070521051
//Hrishikesh dapurkar
static int findParent(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = findParent(parent, parent[x]);
    return parent[x];
}

static void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rootX == rootY)
        return;

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void kruskalMST(int **cost, int V) {
    int parent[V];
    int rank[V];
    int edgeCount = 0;
    int minCost = 0;

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    while (edgeCount < V - 1) {
        int min = INT_MAX;
        int u = -1;
        int v = -1;

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (cost[i][j] != 0 && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u == -1 || v == -1)
            break;

        if (findParent(parent, u) != findParent(parent, v)) {
            unionSets(parent, rank, u, v);
            printf("Edge %d: (%d, %d) cost: %d\n", edgeCount, u, v, min);
            minCost += min;
            edgeCount++;
        }

        cost[u][v] = cost[v][u] = 0;
    }

    printf("Minimum cost = %d\n", minCost);
}

int main(void) {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    if (V <= 0) {
        printf("Invalid graph size.\n");
        return 1;
    }

    int **cost = (int **)malloc((size_t)V * sizeof(int *));
    if (cost == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < V; i++) {
        cost[i] = (int *)malloc((size_t)V * sizeof(int));
        if (cost[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            for (int j = 0; j < i; j++)
                free(cost[j]);
            free(cost);
            return 1;
        }
    }

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
