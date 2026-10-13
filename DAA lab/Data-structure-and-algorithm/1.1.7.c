#include <stdio.h>
#include <limits.h>
//25070521051
//Hrishikesh dapurkar
#define INF LLONG_MAX

typedef long long ll;

typedef struct {
    int u, v;
    ll w;
} Edge;

int main(void) {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    Edge edges[E];
    for (int i = 0; i < E; i++) {
        printf("Enter edge %d (u v w): ", i + 1);
        scanf("%d %d %I64d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    ll dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int updated = 0;
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            ll w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = 1;
            }
        }

        if (!updated)
            break;
    }

    printf("Vertex\tDistance\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%I64d\n", i, dist[i]);

    return 0;
}
