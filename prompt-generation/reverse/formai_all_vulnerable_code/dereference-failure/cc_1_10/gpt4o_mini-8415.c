//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <ctype.h>
#include <errno.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILES 100
#define MAX_THREADS 4

typedef struct {
    char *directory;
    int thread_id;
    int files_per_thread;
    int total_files;
    int *word_count;
    char **word_list;
} ThreadData;

void *count_words(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    DIR *dir;
    struct dirent *entry;
    char file_path[256];
    char word[MAX_WORD_LENGTH];
    FILE *file;

    int start_index = data->thread_id * data->files_per_thread;
    int end_index = start_index + data->files_per_thread;
    int file_index = 0;

    // Open directory
    if ((dir = opendir(data->directory)) == NULL) {
        perror("opendir");
        return NULL;
    }

    // Loop through the directory entries
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only process regular files
            if (file_index >= start_index && file_index < end_index) {
                snprintf(file_path, sizeof(file_path), "%s/%s", data->directory, entry->d_name);
                file = fopen(file_path, "r");
                if (file == NULL) {
                    perror("fopen");
                    continue;
                }

                // Count words in the file
                while (fscanf(file, "%s", word) == 1) {
                    // Convert word to lowercase and remove punctuation
                    for (char *p = word; *p; p++) *p = tolower(*p); 
                    word[strcspn(word, ",.?!;:")] = 0; 

                    // Increment word frequency
                    for (int i = 0; i < MAX_FILES; i++) {
                        if (strcmp(data->word_list[i], word) == 0) {
                            data->word_count[i]++;
                            break;
                        }
                    }
                }
                fclose(file);
            }
            file_index++;
        }
        if (file_index >= data->total_files) break; // Stop if we've processed all files
    }

    closedir(dir);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *directory = argv[1];
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    int word_count[MAX_FILES] = {0};
    char *word_list[MAX_FILES] = {"the", "and", "is", "in", "to", "a", "of", "it", "that", "was"};
    int total_files = 0;

    // Count total files
    DIR *dir = opendir(directory);
    if (!dir) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while (readdir(dir) != NULL) total_files++;
    closedir(dir);

    // Split files based on threads
    int files_per_thread = total_files / MAX_THREADS;

    // Initialize thread data
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].directory = directory;
        thread_data[i].thread_id = i;
        thread_data[i].files_per_thread = files_per_thread;
        thread_data[i].total_files = total_files;
        thread_data[i].word_count = word_count;
        thread_data[i].word_list = word_list;
        pthread_create(&threads[i], NULL, count_words, (void *)&thread_data[i]);
    }

    // Join threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    printf("Word frequencies:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        printf("%s: %d\n", word_list[i], word_count[i]);
    }

    return EXIT_SUCCESS;
}