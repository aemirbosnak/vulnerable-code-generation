//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct survivor {
    char *name;
    char *number;
    struct survivor *next;
};

struct survivor *head = NULL;

void add_survivor(char *name, char *number) {
    struct survivor *new_survivor = malloc(sizeof(struct survivor));
    new_survivor->name = strdup(name);
    new_survivor->number = strdup(number);
    new_survivor->next = head;
    head = new_survivor;
}

void find_survivor(char *name) {
    struct survivor *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found %s: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }
    printf("Survivor not found.\n");
}

void remove_survivor(char *name) {
    struct survivor *current = head;
    struct survivor *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current->number);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Survivor not found.\n");
}

void print_survivors() {
    struct survivor *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

int main() {
    add_survivor("Rick Grimes", "555-1212");
    add_survivor("Daryl Dixon", "555-1213");
    add_survivor("Michonne Hawthorne", "555-1214");
    add_survivor("Carol Peletier", "555-1215");
    add_survivor("Maggie Greene", "555-1216");
    add_survivor("Glenn Rhee", "555-1217");
    add_survivor("Abraham Ford", "555-1218");
    add_survivor("Sasha Williams", "555-1219");
    add_survivor("Eugene Porter", "555-1220");
    add_survivor("Rosita Espinosa", "555-1221");

    find_survivor("Rick Grimes");
    find_survivor("Negan Smith");

    remove_survivor("Glenn Rhee");

    print_survivors();

    return 0;
}