//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024 * 1024 * 10
#define MAX_LOG_FILES 10

struct log_entry {
    time_t timestamp;
    char *message;
    struct log_entry *next;
};

struct log_file {
    char *filename;
    struct log_entry *head;
    struct log_entry *tail;
};

void log_init(struct log_file *log_files, int num_files) {
    int i;
    for (i = 0; i < num_files; i++) {
        log_files[i].filename = malloc(strlen("log.") + strlen(log_files[i].filename) + 1);
        strcpy(log_files[i].filename, "log.");
        strcat(log_files[i].filename, log_files[i].filename);
        log_files[i].head = NULL;
        log_files[i].tail = NULL;
    }
}

void log_add(struct log_file *log_files, char *message) {
    struct log_entry *new_entry = malloc(sizeof(struct log_entry));
    new_entry->timestamp = time(NULL);
    new_entry->message = message;
    new_entry->next = NULL;

    if (log_files->head == NULL) {
        log_files->head = new_entry;
        log_files->tail = new_entry;
    } else {
        log_files->tail->next = new_entry;
        log_files->tail = new_entry;
    }
}

void log_print(struct log_file *log_files) {
    struct log_entry *current = log_files->head;

    while (current != NULL) {
        printf("%s %s\n", current->timestamp, current->message);
        current = current->next;
    }
}

int main() {
    struct log_file log_files[MAX_LOG_FILES];
    char *messages[] = {"Message 1", "Message 2", "Message 3"};
    int i;

    log_init(log_files, MAX_LOG_FILES);

    for (i = 0; i < sizeof(messages) / sizeof(char *); i++) {
        log_add(log_files, messages[i]);
    }

    log_print(log_files);

    return 0;
}