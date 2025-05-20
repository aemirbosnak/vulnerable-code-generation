//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_THREADS 10
#define MAX_FILES 100

typedef struct {
    char *filename;
    int word_count;
} FileData;

FileData file_data[MAX_FILES];
int total_word_count = 0;
int file_count = 0;
pthread_mutex_t mutex;

void *count_words(void *arg) {
    FileData *fdata = (FileData *)arg;
    FILE *file = fopen(fdata->filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char word[256];
    int count = 0;
    while (fscanf(file, "%s", word) == 1) {
        // Simple word validation
        int is_word = 1;
        for (int i = 0; word[i] != '\0'; i++) {
            if (!isalnum(word[i])) {
                is_word = 0;
                break;
            }
        }
        if (is_word) count++;
    }

    fclose(file);

    // Update the word count and total count in a thread-safe manner
    pthread_mutex_lock(&mutex);
    fdata->word_count = count;
    total_word_count += count;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void read_file_list(const char *list_filename) {
    FILE *list_file = fopen(list_filename, "r");
    if (list_file == NULL) {
        perror("Error opening file list");
        exit(EXIT_FAILURE);
    }

    while (fgets(file_data[file_count].filename, sizeof(file_data[file_count].filename), list_file)) {
        file_data[file_count].filename[strcspn(file_data[file_count].filename, "\n")] = 0; // Remove newline
        file_count++;
    }

    fclose(list_file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_list.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    pthread_mutex_init(&mutex, NULL);

    read_file_list(argv[1]);

    for (int i = 0; i < file_count; i++) {
        if (i < MAX_THREADS) {
            pthread_create(&threads[i], NULL, count_words, (void *)&file_data[i]);
        } else {
            // Join threads when we reach the maximum limit
            for (int j = 0; j < MAX_THREADS; j++) {
                pthread_join(threads[j], NULL);
            }
            // Reset thread count
            i -= MAX_THREADS;
            memset(threads, 0, sizeof(threads));
            continue;
        }
    }

    // Join remaining threads
    for (int i = 0; i < file_count && i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total Word Count: %d\n", total_word_count);
    for (int i = 0; i < file_count; i++) {
        printf("File: %s - Word Count: %d\n", file_data[i].filename, file_data[i].word_count);
    }

    pthread_mutex_destroy(&mutex);
    return EXIT_SUCCESS;
}