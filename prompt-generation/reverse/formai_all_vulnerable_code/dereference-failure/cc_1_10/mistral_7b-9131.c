//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BAGGAGE 100
#define COMMAND_SIZE 20

typedef struct {
    int id;
    char destination[COMMAND_SIZE];
} baggage_t;

typedef struct node {
    baggage_t data;
    struct node *next;
} node_t;

node_t *head = NULL;

void display_queue() {
    node_t *current = head;
    printf("\nCurrent state of the baggage queue:\n");
    printf("ID\tDestination\n");
    while (current != NULL) {
        printf("%d\t%s\n", current->data.id, current->data.destination);
        current = current->next;
    }
}

void add_baggage(int id, char *destination) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    strcpy(new_node->data.destination, destination);
    new_node->data.id = id;
    new_node->next = head;
    head = new_node;
}

void remove_baggage() {
    if (head == NULL) {
        printf("Error: Empty queue\n");
        return;
    }

    node_t *temp = head;
    head = head->next;
    free(temp);
}

int main() {
    char command[COMMAND_SIZE];
    int id;
    char *destination;

    while (1) {
        printf("\nEnter command (add <ID> <destination> | remove | display): ");
        fgets(command, COMMAND_SIZE, stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strncmp(command, "add", 3) == 0) {
            sscanf(command, "add %d %s", &id, destination);
            add_baggage(id, destination);
        } else if (strncmp(command, "remove", 5) == 0) {
            remove_baggage();
        } else if (strncmp(command, "display", 6) == 0) {
            display_queue();
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}