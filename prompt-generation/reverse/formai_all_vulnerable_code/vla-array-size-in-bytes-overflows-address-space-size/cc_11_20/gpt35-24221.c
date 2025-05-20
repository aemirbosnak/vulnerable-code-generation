//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to our Graph Coloring Problem program!\n");
    printf("We're here to color graphs, and we're all out of crayons.\n");
    printf("Please enter the number of nodes you would like to color: ");

    int num_nodes;
    scanf("%d", &num_nodes);

    int nodes[num_nodes];

    printf("\nHow many colors would you like to use? ");
    int num_colors;
    scanf("%d", &num_colors);

    for (int i = 0; i < num_nodes; i++) {
        printf("Please enter the number of connections for node %d: ", i + 1);
        int num_connections;
        scanf("%d", &num_connections);
        int connections[num_connections];
        printf("Please enter the connections for node %d (separated by spaces): ", i + 1);
        for (int j = 0; j < num_connections; j++) {
            scanf("%d", &connections[j]);
        }
        int unique_colors = 0;
        for (int k = 1; k <= num_colors; k++) {
            int is_unique = 1;
            for (int l = 0; l < num_connections; l++) {
                if (nodes[connections[l] - 1] == k) {
                    is_unique = 0;
                    break;
                }
            }
            if (is_unique) {
                unique_colors++;
            }
        }
        printf("Node %d can be colored with %d unique colors\n", i + 1, unique_colors);
        for (int m = 1; m <= num_colors; m++) {
            int is_unique = 1;
            for (int n = 0; n < i; n++) {
                if (nodes[n] == m) {
                    is_unique = 0;
                    break;
                }
            }
            if (is_unique) {
                nodes[i] = m;
                break;
            }
        }
    }

    printf("\nThe final color assignment is:\n");
    for (int o = 0; o < num_nodes; o++) {
        printf("Node %d: Color %d\n", o + 1, nodes[o]);
    }

    printf("\nThank you for using our Graph Coloring Problem program! Unfortunately, your graphs are still uncolored, as we are a computer program and do not have crayons. Please come again soon!\n");

    return 0;
}