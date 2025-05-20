//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty network guardian, the Intrusion Detection System (IDS)
int main() {
    // Let's create a virtual network with some nodes and connections
    struct node {
        char *name;
        struct node *next;
    };

    struct connection {
        struct node *src;
        struct node *dest;
        char *protocol;
    };

    struct node *nodes[5];
    for (int i = 0; i < 5; i++) {
        nodes[i] = malloc(sizeof(struct node));
        nodes[i]->name = malloc(10);
        sprintf(nodes[i]->name, "Node %d", i);
        nodes[i]->next = NULL;
    }

    struct connection connections[5];
    for (int i = 0; i < 5; i++) {
        connections[i].src = nodes[i];
        connections[i].dest = nodes[(i + 1) % 5];
        connections[i].protocol = malloc(10);
        sprintf(connections[i].protocol, "TCP");
    }

    // Time to monitor the network for suspicious activity
    int alert_count = 0;
    while (1) {
        // Scan the connections for any anomalies
        for (int i = 0; i < 5; i++) {
            if (strcmp(connections[i].protocol, "ICMP") == 0) {
                // ICMP traffic is rare on this network, raise an alert!
                printf("Alert! ICMP traffic detected between %s and %s\n", connections[i].src->name, connections[i].dest->name);
                alert_count++;
            } else if (connections[i].src == connections[i].dest) {
                // Loopback connections are suspicious, investigate!
                printf("Alert! Loopback connection detected on %s\n", connections[i].src->name);
                alert_count++;
            }
        }

        // Check if we've reached a critical number of alerts
        if (alert_count >= 3) {
            printf("Intrusion detected! Shutting down the network.\n");
            break;
        }
    }

    // Clean up the network resources
    for (int i = 0; i < 5; i++) {
        free(nodes[i]->name);
        free(nodes[i]);
    }
    for (int i = 0; i < 5; i++) {
        free(connections[i].protocol);
    }

    return 0;
}