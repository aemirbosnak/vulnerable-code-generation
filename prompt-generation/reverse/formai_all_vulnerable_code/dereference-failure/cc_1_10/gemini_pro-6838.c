//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

struct phone_book {
    char *name;
    char *number;
};

struct phone_book *pb;
int pb_size;

pthread_mutex_t pb_lock;

void add_entry(char *name, char *number) {
    pthread_mutex_lock(&pb_lock);

    pb = realloc(pb, (pb_size + 1) * sizeof(struct phone_book));
    pb[pb_size].name = name;
    pb[pb_size].number = number;

    pb_size++;

    pthread_mutex_unlock(&pb_lock);
}

void *lookup_entry_async(void *arg) {
    char *name = (char *)arg;

    pthread_mutex_lock(&pb_lock);

    for (int i = 0; i < pb_size; i++) {
        if (strcmp(pb[i].name, name) == 0) {
            char *result = malloc(strlen(pb[i].number) + 1);
            strcpy(result, pb[i].number);

            pthread_mutex_unlock(&pb_lock);

            return result;
        }
    }

    pthread_mutex_unlock(&pb_lock);

    return NULL;
}

void lookup_entry(char *name) {
    pthread_t thread;
    char *result;

    pthread_create(&thread, NULL, lookup_entry_async, name);

    pthread_join(thread, (void **)&result);

    if (result != NULL) {
        printf("%s: %s\n", name, result);
        free(result);
    } else {
        printf("%s: not found\n", name);
    }
}

int main() {
    pb = NULL;
    pb_size = 0;

    pthread_mutex_init(&pb_lock, NULL);

    add_entry("John Doe", "555-1212");
    add_entry("Jane Doe", "555-1213");
    add_entry("Jack Doe", "555-1214");

    lookup_entry("John Doe");
    lookup_entry("Jane Doe");
    lookup_entry("Jack Doe");
    lookup_entry("Bob Smith");

    pthread_mutex_destroy(&pb_lock);

    for (int i = 0; i < pb_size; i++) {
        free(pb[i].name);
        free(pb[i].number);
    }

    free(pb);

    return 0;
}