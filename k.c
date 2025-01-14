#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX] = {0}, par[MAX] = {0}, i, j, e = 0, cost = 0, min = 999, u, v;

int find(int x) {
    while (x != par[x]) {
        x = par[x];
    }
    return x;
}

void uniona(int x, int y) {
    int u = find(x);
    int v = find(y);
    if (u != v) {
        par[v] = u; // Union the sets
    }
}

int main() {
    int n;

    // Input for the number of nodes
    printf("Enter the number of nodes (n): ");
    scanf("%d", &n);

    // Input for the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize the parent array for union-find
    for (i = 0; i < n; i++) {
        par[i] = i; // Initially each node is its own parent
    }

    // Main loop to process edges and construct MST
    while (e < n - 1) {
        min = 999;

        // Find the minimum weight edge that hasn't been processed
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (adj[i][j] < min && adj[i][j] != 0) {
                    min = adj[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // If the nodes are in different sets, include the edge
        if (find(u) != find(v)) {
            uniona(u, v);  // Union the sets
            e += 1;         // Increase the number of edges in the MST
            cost += min;    // Add the weight of the edge to the total cost

            // Print the selected edge
            printf("Edge {%d, %d} with weight %d\n", u, v, min);
        }

        // Mark the selected edge as processed by setting it to a large value
        adj[u][v] = 999;
        adj[v][u] = 999;
    }

    // Print the total cost of the MST
    printf("Total cost of MST: %d\n", cost);

    return 0;
}
