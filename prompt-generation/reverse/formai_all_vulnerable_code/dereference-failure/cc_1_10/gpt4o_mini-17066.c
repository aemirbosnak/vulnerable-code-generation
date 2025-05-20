//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define CHUNK_SIZE 100   // Number of characters to read at a time
#define MAX_BUFFER 1024  // Maximum buffer size for lines

typedef struct {
    char *filename;
    char *word_to_search;
} ReaderArgs;

char text_buffer[CHUNK_SIZE + 1];
int stop_reading = 0;

void *read_file_chunks(void *args) {
    ReaderArgs *reader_args = (ReaderArgs *)args;
    FILE *file = fopen(reader_args->filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    while (!stop_reading && fread(text_buffer, sizeof(char), CHUNK_SIZE, file) > 0) {
        text_buffer[CHUNK_SIZE] = '\0'; // Null-terminate the string
        printf("Reading chunk:\n%s\n", text_buffer);
        sleep(1); // Simulate reading time
    }
    
    fclose(file);
    return NULL;
}

int search_word_in_text(const char *text, const char *word) {
    return strstr(text, word) != NULL;
}

void *search_word(void *args) {
    ReaderArgs *reader_args = (ReaderArgs *)args;
    char line[MAX_BUFFER];
    
    FILE *file = fopen(reader_args->filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    while (!stop_reading && fgets(line, sizeof(line), file)) {
        if (search_word_in_text(line, reader_args->word_to_search)) {
            printf("Found the word '%s' in line: %s", reader_args->word_to_search, line);
        }
    }

    fclose(file);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename> [word_to_search]\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    ReaderArgs reader_args;
    reader_args.filename = argv[1];
    if (argc >= 3) {
        reader_args.word_to_search = argv[2];
    } else {
        reader_args.word_to_search = NULL;
    }

    pthread_t reader_thread, search_thread;

    // Start reading file asynchronously
    pthread_create(&reader_thread, NULL, read_file_chunks, &reader_args);

    // Start searching for the word asynchronously, if provided
    if (reader_args.word_to_search) {
        pthread_create(&search_thread, NULL, search_word, &reader_args);
    }

    // Wait for user input to stop reading
    printf("Press Enter to stop reading...\n");
    getchar(); // Wait for user to press Enter
    stop_reading = 1; // Signal threads to stop
    
    pthread_join(reader_thread, NULL);
    
    if (reader_args.word_to_search) {
        pthread_join(search_thread, NULL);
    }

    printf("Finished reading.\n");
    return EXIT_SUCCESS;
}