//FormAI DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LOG_LINES 50000
#define MAX_LINE_LENGTH 1024

typedef struct log_line {
    char *line_string;
} log_line;

typedef struct thread_args {
    log_line *lines;
    int start_index;
    int end_index;
} thread_args;

void *analyze_logs(void *args) {
    thread_args *t_args = (thread_args *) args;
    log_line *lines = t_args->lines;
    int start_index = t_args->start_index;
    int end_index = t_args->end_index;
    int i, count = 0;

    for (i = start_index; i < end_index; i++) {
        char *line = lines[i].line_string;
        if (strstr(line, "ERROR") != NULL) {
            count++;
        }
    }
    int *result = (int *) malloc(sizeof(int));
    *result = count;
    return (void *) result;
}

int main() {
    FILE *fp;
    char *line;
    log_line logs[MAX_LOG_LINES];
    int log_count = 0;
    pthread_t thread1, thread2;
    int thread1_count, thread2_count;

    fp = fopen("sample_logs.txt", "r");
    if (fp == NULL) {
        printf("Error opening log file\n");
        return 1;
    }

    while ((line = malloc(MAX_LINE_LENGTH)) && fgets(line, MAX_LINE_LENGTH, fp)) {
        logs[log_count++].line_string = strdup(line);
    }

    fclose(fp);

    thread_args t_arg1 = {logs, 0, log_count / 2};
    thread_args t_arg2 = {logs, log_count / 2, log_count};
    pthread_create(&thread1, NULL, analyze_logs, (void *) &t_arg1);
    pthread_create(&thread2, NULL, analyze_logs, (void *) &t_arg2);
    pthread_join(thread1, (void **) &thread1_count);
    pthread_join(thread2, (void **) &thread2_count);
    int total_count = thread1_count + thread2_count;
    printf("Total number of error logs: %d\n", total_count);
    return 0;

}