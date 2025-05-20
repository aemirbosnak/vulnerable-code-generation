//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
    char name[100];
    struct mailing_list *next;
};

struct mailing_list *head = NULL;

void add_member(char *name) {
    struct mailing_list *new_member = (struct mailing_list *)malloc(sizeof(struct mailing_list));
    strcpy(new_member->name, name);
    new_member->next = head;
    head = new_member;
}

void remove_member(char *name) {
    struct mailing_list *current = head;
    struct mailing_list *prev = NULL;

    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
                free(current);
            } else {
                prev->next = current->next;
                free(current);
            }
            return;
        }
        prev = current;
        current = current->next;
    }
}

void list_members() {
    struct mailing_list *current = head;

    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    add_member("Alice");
    add_member("Bob");
    add_member("Charlie");

    printf("Members:\n");
    list_members();

    remove_member("Bob");

    printf("\nMembers after removing Bob:\n");
    list_members();

    return 0;
}