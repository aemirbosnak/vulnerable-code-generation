//FormAI DATASET v1.0 Category: Log analysis ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

// define the struct for log entity
typedef struct log_entry {
    char *timestamp;
    char *log_level;
    char *message;
} log_entry_t;

// declare the global queue for storing log entries
log_entry_t **log_queue;
int queue_insert_position = 0;
int queue_read_position = 0;
int max_queue_size = 100;

// define the function for parsing a single log entry
void parse_log_entry(char *log_entry_string) {
    char *timestamp = strtok(log_entry_string, ",");
    char *log_level = strtok(NULL, ",");
    char *message = strtok(NULL, "\n");
    log_entry_t *log_entry = (log_entry_t *) malloc(sizeof(log_entry_t));
    log_entry->timestamp = timestamp;
    log_entry->log_level = log_level;
    log_entry->message = message;

    // insert the log entry into the queue
    log_queue[queue_insert_position] = log_entry;
    queue_insert_position = (queue_insert_position + 1) % max_queue_size;
}

// define the function for reading log entries from a file
void read_log_file(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening log file: %s\n", filename);
        return;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        parse_log_entry(line);
    }

    fclose(fp);
    if (line != NULL) {
        free(line);
    }
}

// define the function for printing log entries to stdout
void print_log_entry(log_entry_t *log_entry) {
    printf("%s %s: %s\n", log_entry->timestamp, log_entry->log_level, log_entry->message);
}

// define the function for reading log entries from the queue and printing them to stdout
void *print_logs(void *arg) {
    while (true) {
        log_entry_t *log_entry = log_queue[queue_read_position];
        if (log_entry != NULL) {
            print_log_entry(log_entry);
            log_queue[queue_read_position] = NULL;
            queue_read_position = (queue_read_position + 1) % max_queue_size;
        }
    }
}

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    log_queue = (log_entry_t **) malloc(sizeof(log_entry_t *) * max_queue_size);

    // create a thread for printing log entries
    pthread_t print_logs_thread;
    pthread_create(&print_logs_thread, NULL, print_logs, NULL);

    // read log entries from the log file and insert them into the queue
    read_log_file(filename);
    printf("Finished reading log file\n");

    // join the thread for printing log entries
    pthread_join(print_logs_thread, NULL);

    // free memory allocated for log queue
    free(log_queue);

    return 0;
}