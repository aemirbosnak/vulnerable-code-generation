//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *name;
    int size;
    struct node *next;
} node_t;

typedef struct virus {
    char *name;
    int size;
    char *signature;
} virus_t;

node_t *head = NULL;

void add_node(char *name, int size) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->name = name;
    new_node->size = size;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void print_list() {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%s %d\n", current_node->name, current_node->size);
        current_node = current_node->next;
    }
}

int main() {
    // Initialize the list of viruses
    virus_t viruses[] = {
        {"Virus A", 100, "0x12345678"},
        {"Virus B", 200, "0x98765432"}
    };

    // Add the viruses to the list of files to scan
    for (int i = 0; i < sizeof(viruses) / sizeof(virus_t); i++) {
        add_node(viruses[i].name, viruses[i].size);
    }

    // Scan the list of files for viruses
    node_t *current_node = head;
    while (current_node != NULL) {
        for (int i = 0; i < sizeof(viruses) / sizeof(virus_t); i++) {
            if (strcmp(current_node->name, viruses[i].name) == 0) {
                printf("File %s is infected with virus %s\n", current_node->name, viruses[i].name);
            }
        }
        current_node = current_node->next;
    }

    return 0;
}