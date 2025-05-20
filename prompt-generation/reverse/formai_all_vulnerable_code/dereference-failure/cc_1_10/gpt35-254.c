//FormAI DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Firewall {
    char* rule;
    int action;
    char* from;
    char* to;
} Firewall;

int main() {
    Firewall firewall[100];
    int num_rules = 0;

    // Add rules to firewall
    firewall[num_rules].rule = "Block all incoming traffic";
    firewall[num_rules].action = 0;
    firewall[num_rules].from = "Any";
    firewall[num_rules].to = "This Computer";
    num_rules++;

    firewall[num_rules].rule = "Allow HTTP traffic from specific IP address";
    firewall[num_rules].action = 1;
    firewall[num_rules].from = "192.168.0.5";
    firewall[num_rules].to = "This Computer";
    num_rules++;

    firewall[num_rules].rule = "Block all traffic from specific IP address";
    firewall[num_rules].action = 0;
    firewall[num_rules].from = "192.168.0.10";
    firewall[num_rules].to = "Any";
    num_rules++;

    char* input = (char*) malloc(sizeof(char) * 100);

    // Listen for incoming traffic
    while (1) {
        printf("Enter IP address: ");
        scanf("%s", input);

        int allowed = -1;

        // Check all firewall rules for a match
        for (int i = 0; i < num_rules; i++) {
            int from_match = strcmp(firewall[i].from, input) == 0 || strcmp(firewall[i].from, "Any") == 0;
            int to_match = strcmp(firewall[i].to, input) == 0 || strcmp(firewall[i].to, "This Computer") == 0;

            // If both from and to match, apply action
            if (from_match && to_match) {
                allowed = firewall[i].action;
                printf("Traffic %s\n", allowed ? "allowed" : "blocked");
                break;
            }
        }

        // If no match found, block traffic
        if (allowed == -1) {
            printf("Traffic blocked\n");
        }
    }

    free(input);

    return 0;
}