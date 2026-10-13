#include <stdio.h>
#include <stdlib.h>
//25070521051
//Hrishikesh dapurkar
#define MAX 100

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

Node *graph[MAX];
int visited[MAX];

static Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = value;
    newNode->next = NULL;
    return newNode;
}

static void addEdge(int u, int v) {
    Node *newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;
}

static void DFS(int start) {
    visited[start] = 1;
    printf("%d ", start);

    Node *temp = graph[start];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFS(temp->vertex);
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
        graph[i] = NULL;
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
