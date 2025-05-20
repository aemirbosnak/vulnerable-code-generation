//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global variables
char *access_log = "access.log"; // Path to log file
int threshold = 10; // Number of requests before triggering alert

int main(void) {
    // Open log file
    FILE *log_file = fopen(access_log, "r");
    if (!log_file) {
        printf("ERROR: Could not open log file.\n");
        return 1;
    }

    // Define data structures
    struct IP {
        char *address;
        int count;
        struct IP *next;
    };
    struct IP *head = NULL;

    char line[256];
    while (fgets(line, sizeof(line), log_file)) {
        char *ip = strtok(line, " ");
        char *status = strtok(NULL, " ");
        if (strcmp(status, "200") == 0) {
            // Find IP in linked list or create new node for IP
            if (head == NULL) {
                head = malloc(sizeof(struct IP));
                head->address = ip;
                head->count = 1;
                head->next = NULL;
            } else {
                struct IP *curr = head;
                while (curr != NULL) {
                    if (strcmp(curr->address, ip) == 0) {
                        curr->count++;
                        break;
                    } else if (curr->next == NULL) {
                        struct IP *new_node = malloc(sizeof(struct IP));
                        new_node->address = ip;
                        new_node->count = 1;
                        new_node->next = NULL;
                        curr->next = new_node;
                        break;
                    }
                    curr = curr->next;
                }
            }
        }

        // Check for threshold breaches
        struct IP *curr = head;
        while (curr != NULL) {
            if (curr->count >= threshold) {
                printf("ALERT: %s has made %d requests.\n", curr->address, curr->count);
                curr->count = 0; // Reset count for next interval
            }
            curr = curr->next;
        }
    }

    // Close log file
    fclose(log_file);

    return 0;
}