#include <stdio.h>
#define MAX 20
#define INF 99999
//25070521051
//Hrishikesh dapurkar
static void printPath(int parent[], int node) {
    if (parent[node] == -1) {
        printf("%d", node);
        return;
    }
    printPath(parent, parent[node]);
    printf(" -> %d", node);
}

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int distance[MAX];
    int visited[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[startnode] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDistance = INF;
        int nextNode = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        if (nextNode == -1)
            break;

        visited[nextNode] = 1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && G[nextNode][i] != 0 && distance[nextNode] + G[nextNode][i] < distance[i]) {
                distance[i] = distance[nextNode] + G[nextNode][i];
                parent[i] = nextNode;
            }
        }
    }

    printf("Node\tDistance\tPath\n");
    for (int i = 0; i < n; i++) {
        if (i == startnode)
            continue;

        printf("%d\t%d\t", i, distance[i]);
        if (distance[i] == INF)
            printf("NO PATH\n");
        else
            printPath(parent, i), printf("\n");
    }
}

int main(void) {
    int n, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter start node (0-based index): ");
    scanf("%d", &start);

    dijkstra(graph, n, start);
    return 0;
}
