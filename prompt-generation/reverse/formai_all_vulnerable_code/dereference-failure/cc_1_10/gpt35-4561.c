//FormAI DATASET v1.0 Category: Word Count Tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char* file_name;
    char* word;
    int count = 0;
    int total_count = 0;
    FILE* input_file;

    // Check if user provided both file name and word to search
    if (argc != 3) {
        printf("Usage: ./word_count <file_name> <word>\n");
        return 1;
    } else {
        file_name = argv[1];
        word = argv[2];
    }

    // Open input file
    input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error: failed to open input file %s\n", file_name);
        return 1;
    }

    // Read input file line by line
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, input_file)) != -1) {
        // Count occurrences of word in current line
        char* ptr = line;
        while ((ptr = strstr(ptr, word)) != NULL) {
            count++;
            ptr++;
        }

        // Print current line with word count
        printf("%s (word count: %d)\n", line, count);
        total_count += count;
        count = 0;
    }

    // Print total count of word occurrences in input file
    printf("Total count of \"%s\" in \"%s\": %d\n", word, file_name, total_count);

    // Clean up resources
    fclose(input_file);
    if (line) {
        free(line);
    }

    return 0;
}