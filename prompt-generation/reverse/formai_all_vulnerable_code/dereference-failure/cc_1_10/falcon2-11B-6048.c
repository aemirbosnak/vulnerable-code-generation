//Falcon2-11B DATASET v1.0 Category: File handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int count_unique_words(const char* filename, int buffer_size) {
    char buffer[BUFFER_SIZE];
    int num_chunks = 0;
    int num_unique_words = 0;

    struct stat file_stats;
    if (stat(filename, &file_stats) == 0) {
        int file_size = file_stats.st_size;
        int num_chunks = file_size / buffer_size + 1;

        for (int i = 0; i < num_chunks; i++) {
            char* chunk_filename = malloc(BUFFER_SIZE * sizeof(char));
            sprintf(chunk_filename, "%s.%d", filename, i);

            FILE* chunk_file = fopen(chunk_filename, "r");
            if (chunk_file == NULL) {
                fprintf(stderr, "Error opening file: %s\n", chunk_filename);
                exit(1);
            }

            while (fgets(buffer, BUFFER_SIZE, chunk_file)!= NULL) {
                char* word = strtok(buffer, " \n");
                while (word!= NULL) {
                    if (strchr(" ", word[strlen(word) - 1]) == NULL) {
                        if (strstr(word, &buffer[strlen(word) - 1]) == NULL) {
                            num_unique_words++;
                        }
                    }
                    word = strtok(NULL, " \n");
                }
            }

            fclose(chunk_file);
            free(chunk_filename);
        }

        return num_unique_words;
    } else {
        fprintf(stderr, "Error accessing file: %s\n", filename);
        exit(1);
    }
}

int main() {
    const char* filename = "words.txt";
    int buffer_size = BUFFER_SIZE;
    int num_unique_words = count_unique_words(filename, buffer_size);

    printf("Number of unique words in %s: %d\n", filename, num_unique_words);

    return 0;
}