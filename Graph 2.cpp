#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int num_vertices;
    Node* adj_list[MAX];
} GraphList;

Node* create_node(int vertex) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

void init_graph(GraphList *graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }
}

void add_edge(GraphList *graph, int u, int v) {
    Node* new_node = create_node(v);
    new_node->next = graph->adj_list[u];
    graph->adj_list[u] = new_node;

    new_node = create_node(u);
    new_node->next = graph->adj_list[v];
    graph->adj_list[v] = new_node;
}

void bfs(GraphList *graph, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        Node* temp = graph->adj_list[vertex];
        while (temp) {
            int adj_vertex = temp->vertex;
            if (!visited[adj_vertex]) {
                queue[rear++] = adj_vertex;
                visited[adj_vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

void dfs_util(GraphList *graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adj_list[vertex];
    while (temp) {
        int adj_vertex = temp->vertex;
        if (!visited[adj_vertex]) {
            dfs_util(graph, adj_vertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(GraphList *graph, int start) {
    int visited[MAX] = {0};
    dfs_util(graph, start, visited);
}

int main() {
    GraphList graph;
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
