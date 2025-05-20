//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute checksum based on ASCII values
unsigned long compute_checksum(const char *data) {
    unsigned long checksum = 0;
    while (*data) {
        checksum += (unsigned long)(*data);
        data++;
    }
    return checksum;
}

// Function to calculate average word length and total words
void calculate_statistics(const char *data, double *average_length, int *total_words) {
    char *token;
    int word_count = 0;
    int total_length = 0;

    // Tokenize the input data based on spaces
    char *data_copy = strdup(data);  // Make a copy of data to tokenize
    token = strtok(data_copy, " \n");
    
    while (token) {
        total_length += strlen(token);
        word_count++;
        token = strtok(NULL, " \n");
    }
    
    free(data_copy);

    *total_words = word_count;
    *average_length = word_count ? (double)total_length / word_count : 0.0;
}

// Function to read file contents
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening the file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = malloc(filesize + 1);
    if (!data) {
        fclose(file);
        perror("Error allocating memory");
        return NULL;
    }

    fread(data, 1, filesize, file);
    data[filesize] = '\0'; // Null-terminate the string

    fclose(file);
    return data;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    char *file_content = read_file(filename);
    
    if (!file_content) {
        return EXIT_FAILURE;
    }

    unsigned long checksum = compute_checksum(file_content);
    int total_words = 0;
    double average_word_length = 0.0;

    calculate_statistics(file_content, &average_word_length, &total_words);

    printf("File: %s\n", filename);
    printf("Checksum (ASCII sum): %lu\n", checksum);
    printf("Total words: %d\n", total_words);
    printf("Average word length: %.2f\n", average_word_length);

    free(file_content);
    return EXIT_SUCCESS;
}