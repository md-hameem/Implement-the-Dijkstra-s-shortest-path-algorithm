#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 5
#define INF INT_MAX

void dijkstra_shortest_path(int graph[MAX_NODES][MAX_NODES], int length[MAX_NODES], int num_nodes, int src_node) {
    // Keep track of visited nodes
    bool visited[MAX_NODES] = { false };

    // Initialize distances of all nodes to infinity
    for (int i = 0; i < num_nodes; i++) {
        length[i] = INF;
    }

    // Distance from source node to itself is 0
    length[src_node] = 0;

    // Find shortest path for all nodes
    for (int count = 0; count < num_nodes - 1; count++) {
        // Find the minimum distance node that hasn't been visited
        int min_dist = INF, min_index = -1;
        for (int i = 0; i < num_nodes; i++) {
            if (!visited[i] && length[i] <= min_dist) {
                min_dist = length[i];
                min_index = i;
            }
        }

        // Mark the selected node as visited
        visited[min_index] = true;

        // Update distance of adjacent nodes to the selected node
        for (int i = 0; i < num_nodes; i++) {
            if (!visited[i] && graph[min_index][i] && length[min_index] != INF
                && length[min_index] + graph[min_index][i] < length[i]) {
                length[i] = length[min_index] + graph[min_index][i];
            }
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        { INF, 10, 5, INF, INF },
        { INF, INF, INF, 1, INF },
        { INF, 3, INF, 9, 2 },
        { INF, INF, INF, INF, 4 },
        { 7, INF, INF, 6, INF }
    };

    int length[MAX_NODES];
    const int num_nodes = MAX_NODES;
    const int src_node = 0;

    // Find shortest path from source node to all other nodes
    dijkstra_shortest_path(graph, length, num_nodes, src_node);

    // Print the shortest paths
    for (int i = 1; i < num_nodes; i++) {
        printf("Shortest path from node %d to node %d: %d\n", src_node, i, length[i]);
    }

    return 0;
}
