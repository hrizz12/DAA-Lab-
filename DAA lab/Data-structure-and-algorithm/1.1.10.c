#include <stdio.h>
#include <stdlib.h>
//25070521051
//Hrishikesh dapurkar
#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

Node *adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

static Node *createNode(int vertex) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

static void addEdge(int u, int v) {
    Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

static void DFS(int start) {
    visited[start] = 1;
    printf("%d ", start);

    Node *temp = adjList[start];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex])
            DFS(connectedVertex);
        temp = temp->next;
    }
}

int main(void) {
    int V, E, start;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
