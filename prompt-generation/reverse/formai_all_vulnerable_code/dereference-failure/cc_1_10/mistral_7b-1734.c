//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Head {
    char name[50];
    int age;
    struct Dream *dreams;
    struct Head *next;
} Head;

typedef struct Dream {
    char name[50];
    struct Head *head;
    struct Dream *next;
} Dream;

void create_head(Head **head_list, char *name, int age) {
    Head *new_head = (Head *)malloc(sizeof(Head));
    strcpy(new_head->name, name);
    new_head->age = age;
    new_head->next = *head_list;
    new_head->dreams = NULL;
    *head_list = new_head;
}

void create_dream(Dream **dream_list, char *name, Head *head) {
    Dream *new_dream = (Dream *)malloc(sizeof(Dream));
    strcpy(new_dream->name, name);
    new_dream->head = head;
    new_dream->next = *dream_list;
    *dream_list = new_dream;
}

void print_head(Head *head) {
    printf("Name: %s, Age: %d\n", head->name, head->age);
    printf("Dreams:\n");
    Dream *dream = head->dreams;
    while (dream != NULL) {
        printf("- %s\n", dream->name);
        dream = dream->next;
    }
}

Head *head_list = NULL;
Dream *dream_list = NULL;

int main() {
    create_head(&head_list, "Alice", 27);
    create_head(&head_list, "Bob", 33);
    create_head(&head_list, "Charlie", 19);

    create_dream(&dream_list, "Flying with eagles", head_list);
    create_dream(&dream_list, "Eating a giant marshmallow", head_list);
    create_dream(&dream_list, "Becoming a pirate captain", head_list);
    create_dream(&dream_list, "Dancing with the stars", head_list);

    Head *current_head = head_list;
    while (current_head != NULL) {
        print_head(current_head);
        current_head = current_head->next;
    }

    return 0;
}