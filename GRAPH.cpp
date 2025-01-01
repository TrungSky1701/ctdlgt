#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int num_vertices;
    int adj_matrix[MAX][MAX];
} GraphMatrix;

void init_graph(GraphMatrix *graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(GraphMatrix *graph, int u, int v) {
    graph->adj_matrix[u][v] = 1;
    graph->adj_matrix[v][u] = 1;
}

void bfs(GraphMatrix *graph, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adj_matrix[vertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs_util(GraphMatrix *graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[vertex][i] == 1 && !visited[i]) {
            dfs_util(graph, i, visited);
        }
    }
}

void dfs(GraphMatrix *graph, int start) {
    int visited[MAX] = {0};
    dfs_util(graph, start, visited);
}

int main() {
    GraphMatrix graph;
    init_graph(&graph, 7);

    int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6;

    add_edge(&graph, a, b);
    add_edge(&graph, a, c);
    add_edge(&graph, a, d);
    add_edge(&graph, b, e);
    add_edge(&graph, e, c);
    add_edge(&graph, e, f);
    add_edge(&graph, e, g);
    add_edge(&graph, g, f);
    add_edge(&graph, g, b);
    add_edge(&graph, d, f);
    add_edge(&graph, d, e);

    printf("BFS: ");
    bfs(&graph, a);
    printf("\n");

    printf("DFS: ");
    dfs(&graph, a);
    printf("\n");

    return 0;
}
