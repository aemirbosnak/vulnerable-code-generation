//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *email;
    char *name;
} subscriber;

typedef struct {
    subscriber *subscribers;
    int count;
    int capacity;
} mailing_list;

void mailing_list_init(mailing_list *list) {
    list->subscribers = malloc(sizeof(subscriber) * 10);
    list->count = 0;
    list->capacity = 10;
}

void mailing_list_destroy(mailing_list *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->subscribers[i].email);
        free(list->subscribers[i].name);
    }
    free(list->subscribers);
}

void mailing_list_add(mailing_list *list, const char *email, const char *name) {
    if (list->count == list->capacity) {
        list->subscribers = realloc(list->subscribers, sizeof(subscriber) * list->capacity * 2);
        list->capacity *= 2;
    }
    list->subscribers[list->count].email = strdup(email);
    list->subscribers[list->count].name = strdup(name);
    list->count++;
}

void mailing_list_remove(mailing_list *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            free(list->subscribers[i].email);
            free(list->subscribers[i].name);
            list->count--;
            for (int j = i; j < list->count; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            break;
        }
    }
}

void mailing_list_print(mailing_list *list) {
    for (int i = 0; i < list->count; i++) {
        printf("%s: %s\n", list->subscribers[i].email, list->subscribers[i].name);
    }
}

int main() {
    mailing_list list;
    mailing_list_init(&list);

    mailing_list_add(&list, "john@example.com", "John Doe");
    mailing_list_add(&list, "jane@example.com", "Jane Doe");
    mailing_list_add(&list, "bob@example.com", "Bob Smith");

    mailing_list_print(&list);

    mailing_list_remove(&list, "jane@example.com");

    mailing_list_print(&list);

    mailing_list_destroy(&list);

    return 0;
}