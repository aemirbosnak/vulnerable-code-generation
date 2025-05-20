//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 100

typedef struct {
    char *email;
    char *name;
    bool subscribed;
} mailing_list_entry;

typedef struct {
    mailing_list_entry *entries;
    int num_entries;
} mailing_list;

mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    if (list == NULL) {
        return NULL;
    }
    list->entries = malloc(sizeof(mailing_list_entry) * MAX_LIST_SIZE);
    if (list->entries == NULL) {
        free(list);
        return NULL;
    }
    list->num_entries = 0;
    return list;
}

void destroy_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_entries; i++) {
        free(list->entries[i].email);
        free(list->entries[i].name);
    }
    free(list->entries);
    free(list);
}

bool add_to_mailing_list(mailing_list *list, char *email, char *name) {
    if (list->num_entries == MAX_LIST_SIZE) {
        return false;
    }
    list->entries[list->num_entries].email = malloc(strlen(email) + 1);
    if (list->entries[list->num_entries].email == NULL) {
        return false;
    }
    strcpy(list->entries[list->num_entries].email, email);
    list->entries[list->num_entries].name = malloc(strlen(name) + 1);
    if (list->entries[list->num_entries].name == NULL) {
        free(list->entries[list->num_entries].email);
        return false;
    }
    strcpy(list->entries[list->num_entries].name, name);
    list->entries[list->num_entries].subscribed = true;
    list->num_entries++;
    return true;
}

bool remove_from_mailing_list(mailing_list *list, char *email) {
    for (int i = 0; i < list->num_entries; i++) {
        if (strcmp(list->entries[i].email, email) == 0) {
            free(list->entries[i].email);
            free(list->entries[i].name);
            for (int j = i + 1; j < list->num_entries; j++) {
                list->entries[j - 1] = list->entries[j];
            }
            list->num_entries--;
            return true;
        }
    }
    return false;
}

bool is_subscribed(mailing_list *list, char *email) {
    for (int i = 0; i < list->num_entries; i++) {
        if (strcmp(list->entries[i].email, email) == 0) {
            return list->entries[i].subscribed;
        }
    }
    return false;
}

void print_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_entries; i++) {
        printf("%s (%s) - %s\n", list->entries[i].email, list->entries[i].name, list->entries[i].subscribed ? "Subscribed" : "Unsubscribed");
    }
}

int main() {
    mailing_list *list = create_mailing_list();
    add_to_mailing_list(list, "alice@example.com", "Alice");
    add_to_mailing_list(list, "bob@example.com", "Bob");
    add_to_mailing_list(list, "charlie@example.com", "Charlie");
    remove_from_mailing_list(list, "bob@example.com");
    print_mailing_list(list);
    destroy_mailing_list(list);
    return 0;
}