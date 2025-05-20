//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char* name;
    struct list* next;
};

struct list* head = NULL;

void add_member(char* name) {
    struct list* new_member = (struct list*) malloc(sizeof(struct list));
    if (new_member == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        return;
    }
    new_member->name = strdup(name);
    new_member->next = NULL;

    if (head == NULL) {
        head = new_member;
    } else {
        struct list* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_member;
    }
}

void remove_member(char* name) {
    struct list* current = head;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            struct list* temp = current;
            current = current->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    fprintf(stderr, "Error: Member not found in the mailing list.\n");
}

int main() {
    char* name1 = "John";
    char* name2 = "Alice";
    char* name3 = "Bob";

    add_member(name1);
    add_member(name2);
    add_member(name3);

    remove_member(name2);

    printf("Mailing list:\n");
    struct list* current = head;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }

    return 0;
}