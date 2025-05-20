//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_LOG_SIZE 1024 * 1024 * 10 // 10MB
#define MAX_THREADS 10
#define MAX_KEYWORDS 10

typedef struct {
    char *keyword;
    int count;
} KeywordCount;

typedef struct {
    char *filename;
    FILE *file;
    pthread_mutex_t mutex;
    KeywordCount keywords[MAX_KEYWORDS];
    int num_keywords;
} LogFile;

void *analyze_log_file(void *arg) {
    LogFile *log_file = (LogFile *)arg;
    char line[MAX_LOG_SIZE];
    char *token;
    KeywordCount *keyword_count;

    while (fgets(line, MAX_LOG_SIZE, log_file->file)!= NULL) {
        pthread_mutex_lock(&log_file->mutex);
        keyword_count = log_file->keywords;
        while (keyword_count->keyword!= NULL) {
            token = strtok(line, " ");
            while (token!= NULL) {
                if (strcmp(token, keyword_count->keyword) == 0) {
                    keyword_count->count++;
                    break;
                }
                token = strtok(NULL, " ");
            }
            keyword_count++;
        }
        pthread_mutex_unlock(&log_file->mutex);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int num_threads = 1;
    pthread_t threads[MAX_THREADS];
    LogFile log_files[MAX_THREADS];

    if (argc < 3) {
        printf("Usage: %s <log_file1> [<log_file2>...]\n", argv[0]);
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        LogFile *log_file = &log_files[num_threads - 1];
        log_file->filename = argv[i];
        log_file->file = fopen(log_file->filename, "r");

        if (log_file->file == NULL) {
            printf("Error: could not open log file %s\n", log_file->filename);
            exit(1);
        }

        pthread_create(&threads[num_threads - 1], NULL, analyze_log_file, log_file);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}