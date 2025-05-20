//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct suspect_node {
    char *name;
    int age;
    char *occupation;
    char *location;
    struct suspect_node *next;
} suspect_node_t;

typedef struct suspect_list {
    suspect_node_t *head;
    suspect_node_t *tail;
} suspect_list_t;

suspect_node_t *create_suspect_node(char *name, int age, char *occupation, char *location) {
    suspect_node_t *new_node = (suspect_node_t *)malloc(sizeof(suspect_node_t));
    new_node->name = strdup(name);
    new_node->age = age;
    new_node->occupation = strdup(occupation);
    new_node->location = strdup(location);
    new_node->next = NULL;
    return new_node;
}

suspect_list_t *create_suspect_list() {
    suspect_list_t *new_list = (suspect_list_t *)malloc(sizeof(suspect_list_t));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

void add_suspect_to_list(suspect_list_t *list, suspect_node_t *new_node) {
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_suspect_list(suspect_list_t *list) {
    suspect_node_t *current_node = list->head;
    while (current_node != NULL) {
        printf("Name: %s\n", current_node->name);
        printf("Age: %d\n", current_node->age);
        printf("Occupation: %s\n", current_node->occupation);
        printf("Location: %s\n", current_node->location);
        printf("\n");
        current_node = current_node->next;
    }
}

void free_suspect_list(suspect_list_t *list) {
    suspect_node_t *current_node = list->head;
    while (current_node != NULL) {
        suspect_node_t *next_node = current_node->next;
        free(current_node->name);
        free(current_node->occupation);
        free(current_node->location);
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

int main() {
    // Create a list of suspects.
    suspect_list_t *suspect_list = create_suspect_list();

    // Add suspects to the list.
    add_suspect_to_list(suspect_list, create_suspect_node("John Smith", 30, "Doctor", "221B Baker Street"));
    add_suspect_to_list(suspect_list, create_suspect_node("Mary Jones", 25, "Teacher", "10 Downing Street"));
    add_suspect_to_list(suspect_list, create_suspect_node("Bob Brown", 40, "Lawyer", "555 Park Avenue"));

    // Print the list of suspects.
    printf("Suspect List:\n");
    print_suspect_list(suspect_list);

    // Free the list of suspects.
    free_suspect_list(suspect_list);

    return 0;
}