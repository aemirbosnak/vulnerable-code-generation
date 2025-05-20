//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 255

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int word_count;
} FileData;

void *count_words(void *arg) {
    FileData *data = (FileData *)arg;
    FILE *file = fopen(data->filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        data->word_count = -1; // Indicate an error
        return NULL;
    }

    char buffer[1024];
    int count = 0;
    while (fscanf(file, "%1023s", buffer) != EOF) {
        count++;
    }
    
    fclose(file);
    data->word_count = count;
    printf("File: %s, Word Count: %d\n", data->filename, data->word_count);
    return NULL;
}

void list_files_and_count_words(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    pthread_t threads[MAX_FILES];
    FileData file_data[MAX_FILES];
    int file_count = 0;

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            snprintf(file_data[file_count].filename, MAX_FILENAME_LENGTH, "%s/%s", directory, entry->d_name);
            pthread_create(&threads[file_count], NULL, count_words, (void *)&file_data[file_count]);
            file_count++;

            if (file_count >= MAX_FILES) {
                break; // Reached maximum number of files to process
            }
        }
    }
    
    closedir(dp);

    // Wait for all threads to finish
    for (int i = 0; i < file_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nSummary of Word Counts:\n");
    for (int i = 0; i < file_count; i++) {
        if (file_data[i].word_count != -1) {
            printf("File: %s, Word Count: %d\n", file_data[i].filename, file_data[i].word_count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    list_files_and_count_words(argv[1]);
    return EXIT_SUCCESS;
}