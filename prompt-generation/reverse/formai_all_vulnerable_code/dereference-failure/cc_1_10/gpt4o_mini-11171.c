//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILES 100
#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    int *word_count;
    pthread_mutex_t *mutex;
} ThreadData;

void *count_words(void *data) {
    ThreadData *thread_data = (ThreadData *)data;
    FILE *file = fopen(thread_data->filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char *word = strtok(buffer, " \n");
        while (word != NULL) {
            pthread_mutex_lock(thread_data->mutex);
            thread_data->word_count[(int)(word[0] % 256)]++;
            pthread_mutex_unlock(thread_data->mutex);
            word = strtok(NULL, " \n");
        }
    }
    fclose(file);
    return NULL;
}

void merge_results(int *final_counts, int *local_counts) {
    for (int i = 0; i < 256; ++i) {
        final_counts[i] += local_counts[i];
    }
}

void print_results(int *word_count) {
    for (int i = 0; i < 256; ++i) {
        if (word_count[i] > 0) {
            printf("Word starting with '%c': %d\n", i, word_count[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int final_word_count[256] = {0};
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_t threads[MAX_FILES];
    ThreadData thread_data[MAX_FILES];
    int file_count = 0;

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Unable to open directory");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL && file_count < MAX_FILES) {
        if (entry->d_type == DT_REG) { // Only process regular files
            char filepath[BUFFER_SIZE];
            snprintf(filepath, sizeof(filepath), "%s/%s", argv[1], entry->d_name);
            thread_data[file_count].filename = strdup(filepath);
            thread_data[file_count].word_count = calloc(256, sizeof(int));
            thread_data[file_count].mutex = &mutex;

            pthread_create(&threads[file_count], NULL, count_words, &thread_data[file_count]);
            file_count++;
        }
    }
    closedir(dir);

    for (int i = 0; i < file_count; ++i) {
        pthread_join(threads[i], NULL);
        merge_results(final_word_count, thread_data[i].word_count);
        free(thread_data[i].filename);
        free(thread_data[i].word_count);
    }

    print_results(final_word_count);
    
    return EXIT_SUCCESS;
}