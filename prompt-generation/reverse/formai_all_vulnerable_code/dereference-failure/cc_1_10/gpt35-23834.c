//FormAI DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[50];
    char email[50];
    struct person *next;
};

struct person *head = NULL;

void add_person(char name[], char email[]) {
    struct person *new_person = malloc(sizeof(struct person));
    strcpy(new_person->name, name);
    strcpy(new_person->email, email);
    new_person->next = NULL;

    if(head == NULL) {
        head = new_person;
        return;
    }

    struct person *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_person;
}

void print_list() {
    struct person *temp = head;

    while(temp != NULL) {
        printf("%s (%s)\n", temp->name, temp->email);
        temp = temp->next;
    }
}

void delete_person(char email[]) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct person *temp = head;
    struct person *prev = NULL;

    while(temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Person not found\n");
        return;
    }

    if(prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

int main() {
    add_person("Alice", "alice@gmail.com");
    add_person("Bob", "bob@yahoo.com");
    add_person("Charlie", "charlie@hotmail.com");
    add_person("Dave", "dave@gmail.com");
    add_person("Eve", "eve@yahoo.com");

    printf("Initial list:\n");
    print_list();

    delete_person("charlie@hotmail.com");
    printf("List after deleting Charlie:\n");
    print_list();

    return 0;
}