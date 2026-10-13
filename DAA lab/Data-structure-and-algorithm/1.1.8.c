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
int queue[MAX];
int front = -1, rear = -1;

static void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow.\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

static int dequeue(void) {
    if (front == -1 || front > rear) {
        printf("Queue underflow.\n");
        exit(1);
    }
    return queue[front++];
}

static void addEdge(int u, int v) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void BFS(int start) {
    enqueue(start);
    visited[start] = 1;

    while (front != -1 && front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        Node *temp = graph[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }
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

    printf("BFS traversal: ");
    BFS(start);
    printf("\n");

    return 0;
}
