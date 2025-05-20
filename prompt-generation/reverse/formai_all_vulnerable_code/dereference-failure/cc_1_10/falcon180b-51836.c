//Falcon-180B DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print error message and exit program
void handle_error(const char* error_message) {
    fprintf(stderr, "ERROR: %s\n", error_message);
    exit(EXIT_FAILURE);
}

// Function to read a file into a buffer
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        handle_error("Unable to open file");
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        handle_error("Unable to allocate memory");
    }

    if (fread(buffer, 1, file_size, file)!= file_size) {
        handle_error("Unable to read file");
    }

    fclose(file);
    buffer[file_size] = '\0';
    return buffer;
}

// Function to count the number of words in a string
int count_words(const char* string) {
    int count = 0;
    char* token = strtok(string, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        handle_error("Invalid number of arguments");
    }

    char* file_contents = read_file(argv[1]);
    int word_count = count_words(file_contents);

    printf("The file '%s' contains %d words.\n", argv[1], word_count);

    free(file_contents);
    return 0;
}