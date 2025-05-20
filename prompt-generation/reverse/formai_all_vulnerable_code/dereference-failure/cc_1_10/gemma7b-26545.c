//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char buffer[MAX_BUFFER_SIZE] = "";
    char *meta_data = NULL;
    int i = 0;
    FILE *fp = NULL;

    fp = fopen("metadata.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file contents into the buffer
    fread(buffer, MAX_BUFFER_SIZE, 1, fp);

    // Allocate memory for the metadata
    meta_data = malloc(strlen(buffer) + 1);
    if (meta_data == NULL) {
        perror("Error allocating memory");
        return EXIT_FAILURE;
    }

    // Extract the metadata from the buffer
    for (i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == '{' && buffer[i + 1] == ':') {
            int start = i + 2;
            int end = buffer[i - 1] == '}' ? i - 1 : strlen(buffer);
            char meta_data_key[MAX_BUFFER_SIZE] = "";
            char meta_data_value[MAX_BUFFER_SIZE] = "";

            // Extract the key and value from the metadata
            memcpy(meta_data_key, buffer + start, end - start);
            meta_data_key[end - start] = '\0';

            memcpy(meta_data_value, buffer + end + 1, strlen(buffer) - end - 1);
            meta_data_value[strlen(buffer) - end - 1] = '\0';

            // Print the key-value pair
            printf("%s: %s\n", meta_data_key, meta_data_value);
        }
    }

    fclose(fp);
    free(meta_data);

    return EXIT_SUCCESS;
}