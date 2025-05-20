//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct unit {
    char *name;
    double factor;
};

struct node {
    int sock;
    struct unit unit;
    struct node *next;
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    struct node *head = NULL, *current = NULL;

    // Add units to the list
    struct unit unit1 = {"m", 1.0};
    struct unit unit2 = {"cm", 0.01};
    struct unit unit3 = {"mm", 0.001};
    struct unit unit4 = {"km", 1000.0};

    head = current = (struct node *)malloc(sizeof(struct node));
    current->sock = sock;
    current->unit = unit1;
    current->next = NULL;

    // Create a list of nodes
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->sock = sock;
    node2->unit = unit2;
    node2->next = current;
    current = node2;

    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->sock = sock;
    node3->unit = unit3;
    node3->next = current;
    current = node3;

    struct node *node4 = (struct node *)malloc(sizeof(struct node));
    node4->sock = sock;
    node4->unit = unit4;
    node4->next = current;
    current = node4;

    // Start the server
    listen(sock, 5);

    while (1) {
        // Wait for a client connection
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        // Read the client request
        char buff[1024];
        recv(client_sock, buff, 1024, 0);
        printf("Client request: %s\n", buff);

        // Convert the unit
        double value = atof(buff);
        struct unit *unit = NULL;
        for (struct node *node = head; node != NULL; node = node->next) {
            if (strcmp(node->unit.name, buff) == 0) {
                unit = &node->unit;
                break;
            }
        }

        // Send the converted value back to the client
        char *converted = NULL;
        if (unit != NULL) {
            converted = malloc(sizeof(char) * (strlen(buff) + 1));
            sprintf(converted, "%.2f %s", value * unit->factor, unit->name);
        }
        send(client_sock, converted, strlen(converted), 0);

        free(converted);
    }

    return 0;
}