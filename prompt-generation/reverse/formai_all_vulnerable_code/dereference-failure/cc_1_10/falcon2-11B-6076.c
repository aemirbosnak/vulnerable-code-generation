//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 10
#define MAX_ENTRIES 100

struct phone_book {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    struct phone_book* next;
};

struct phone_book* head = NULL;

void insert(char* name, char* number) {
    struct phone_book* new_entry = (struct phone_book*)malloc(sizeof(struct phone_book));
    if (new_entry == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(new_entry->name, name);
    strcpy(new_entry->number, number);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        struct phone_book* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

void search(char* name) {
    struct phone_book* current = head;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }
    printf("Name not found.\n");
}

void delete_entry(char* name) {
    struct phone_book* current = head;
    struct phone_book* previous = NULL;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Name not found.\n");
}

int main() {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];

    printf("Enter name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    if (strlen(name) > MAX_NAME_LEN) {
        printf("Name too long.\n");
        return 1;
    }
    printf("Enter number: ");
    fgets(number, MAX_NUM_LEN, stdin);
    if (strlen(number) > MAX_NUM_LEN) {
        printf("Number too long.\n");
        return 1;
    }

    insert(name, number);

    printf("Enter name to search: ");
    fgets(name, MAX_NAME_LEN, stdin);
    if (strlen(name) > MAX_NAME_LEN) {
        printf("Name too long.\n");
        return 1;
    }

    search(name);

    printf("Enter name to delete: ");
    fgets(name, MAX_NAME_LEN, stdin);
    if (strlen(name) > MAX_NAME_LEN) {
        printf("Name too long.\n");
        return 1;
    }

    delete_entry(name);

    return 0;
}