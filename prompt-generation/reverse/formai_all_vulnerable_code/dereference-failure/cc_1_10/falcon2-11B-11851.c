//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

struct diary_entry {
    int id;
    char username[30];
    char content[256];
    struct diary_entry *next;
};

struct diary_entry *head = NULL;
struct diary_entry *tail = NULL;
pthread_mutex_t lock;

void add_entry(char *username, char *content) {
    struct diary_entry *entry = (struct diary_entry*)malloc(sizeof(struct diary_entry));
    strcpy(entry->username, username);
    strcpy(entry->content, content);
    entry->id = rand();
    entry->next = NULL;

    if (head == NULL) {
        head = entry;
        tail = entry;
    } else {
        tail->next = entry;
        tail = entry;
    }

    pthread_mutex_lock(&lock);
    printf("Entry added by %s: %s\n", username, content);
    fflush(stdout);
    pthread_mutex_unlock(&lock);
}

void list_entries() {
    struct diary_entry *current = head;
    while (current!= NULL) {
        printf("Entry by %s: %s\n", current->username, current->content);
        current = current->next;
    }
}

void delete_entry(int id) {
    struct diary_entry *current = head;
    struct diary_entry *prev = NULL;

    while (current!= NULL && current->id!= id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Entry with id %d not found\n", id);
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    if (current == tail) {
        tail = prev;
    }

    free(current);
}

int main() {
    pthread_mutex_init(&lock, NULL);

    while (1) {
        char username[30];
        char content[256];

        printf("Enter your username: ");
        scanf("%s", username);
        fflush(stdin);

        printf("Enter your diary entry: ");
        scanf("%s", content);
        fflush(stdin);

        add_entry(username, content);

        printf("Entries:\n");
        list_entries();

        printf("Enter the id of the entry you want to delete (or any other number to quit): ");
        int id;
        scanf("%d", &id);
        fflush(stdin);

        delete_entry(id);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}