//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
    char name[100];
    int size;
    struct mailing_list* next;
};

struct mailing_list* create_list(const char* name, int size) {
    struct mailing_list* new_list = (struct mailing_list*)malloc(sizeof(struct mailing_list));
    if (new_list == NULL) {
        fprintf(stderr, "Failed to allocate memory for mailing list.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_list->name, name);
    new_list->size = size;
    new_list->next = NULL;
    return new_list;
}

void print_list(struct mailing_list* list) {
    if (list == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Name: %s\n", list->name);
    printf("Size: %d\n", list->size);
    struct mailing_list* current = list->next;
    while (current!= NULL) {
        printf("Address: %s\n", current->name);
        current = current->next;
    }
}

int main() {
    struct mailing_list* list = create_list("Friends", 5);
    if (list == NULL) {
        fprintf(stderr, "Failed to create mailing list.\n");
        exit(EXIT_FAILURE);
    }
    struct mailing_list* person1 = create_list("John Doe", 1);
    if (person1 == NULL) {
        fprintf(stderr, "Failed to create person1.\n");
        exit(EXIT_FAILURE);
    }
    struct mailing_list* person2 = create_list("Jane Smith", 1);
    if (person2 == NULL) {
        fprintf(stderr, "Failed to create person2.\n");
        exit(EXIT_FAILURE);
    }
    person1->next = person2;
    printf("Created mailing list: %s\n", list->name);
    printf("Printing mailing list:\n");
    print_list(list);
    printf("\n");
    printf("Adding person1 to mailing list:\n");
    list->next = person1;
    printf("Printing mailing list after adding person1:\n");
    print_list(list);
    printf("\n");
    printf("Adding person2 to mailing list:\n");
    list->next = person2;
    printf("Printing mailing list after adding person2:\n");
    print_list(list);
    printf("\n");
    printf("Deleting person1 from mailing list:\n");
    struct mailing_list* temp = list->next;
    while (temp->next!= person1) {
        temp = temp->next;
    }
    temp->next = person1->next;
    free(person1);
    printf("Printing mailing list after deleting person1:\n");
    print_list(list);
    printf("\n");
    printf("Deleting person2 from mailing list:\n");
    temp = list->next;
    while (temp->next!= person2) {
        temp = temp->next;
    }
    temp->next = person2->next;
    free(person2);
    printf("Printing mailing list after deleting person2:\n");
    print_list(list);
    printf("\n");
    printf("Deleting mailing list:\n");
    free(list);
    return 0;
}