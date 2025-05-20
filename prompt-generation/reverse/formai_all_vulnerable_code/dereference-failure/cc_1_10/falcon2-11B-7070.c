//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_EMAIL_SIZE 50

typedef struct {
    char email[MAX_EMAIL_SIZE];
    char name[MAX_EMAIL_SIZE];
} list_t;

typedef struct {
    list_t* list;
    int size;
} mailing_list;

mailing_list* create_mailing_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    list->size = 0;
    list->list = malloc(MAX_LIST_SIZE * sizeof(list_t));
    return list;
}

void add_to_mailing_list(mailing_list* list, const char* email, const char* name) {
    if (list->size == MAX_LIST_SIZE) {
        fprintf(stderr, "Mailing list is full\n");
        return;
    }
    list_t new_entry;
    strcpy(new_entry.email, email);
    strcpy(new_entry.name, name);
    list->list[list->size] = new_entry;
    list->size++;
}

void display_mailing_list(const mailing_list* list) {
    for (int i = 0; i < list->size; i++) {
        printf("Email: %s, Name: %s\n", list->list[i].email, list->list[i].name);
    }
}

void free_mailing_list(mailing_list* list) {
    free(list->list);
    free(list);
}

int main() {
    mailing_list* list = create_mailing_list();
    add_to_mailing_list(list, "ada.lovelace@example.com", "Ada Lovelace");
    add_to_mailing_list(list, "charles.babbage@example.com", "Charles Babbage");
    add_to_mailing_list(list, "mary.shelley@example.com", "Mary Shelley");
    display_mailing_list(list);
    free_mailing_list(list);
    return 0;
}