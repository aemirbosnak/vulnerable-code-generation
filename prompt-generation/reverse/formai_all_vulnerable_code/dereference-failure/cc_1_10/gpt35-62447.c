//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum size of file that can be processed

int main() {
    char filename[100];
    printf("Enter the name of the file to extract metadata from: ");
    scanf("%s", filename);

    FILE *file_ptr;
    file_ptr = fopen(filename, "r");

    if (file_ptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the first 1000000 bytes of the file into memory
    char file_data[MAX_FILE_SIZE];
    size_t bytes_read = fread(file_data, sizeof(char), MAX_FILE_SIZE, file_ptr);

    if (bytes_read == 0) {
        printf("Error reading file!\n");
        return 1;
    }

    // Define metadata keys and extract values
    char *author_key = "author:";
    char *title_key = "title:";
    char *date_key = "date:";
    char *author_value = strstr(file_data, author_key);
    char *title_value = strstr(file_data, title_key);
    char *date_value = strstr(file_data, date_key);

    // Print metadata
    printf("Extracted metadata:\n");
    if (author_value != NULL) {
        printf("Author: %s\n", author_value+strlen(author_key));
    } else {
        printf("Author not found in file.\n");
    }
    if (title_value != NULL) {
        printf("Title: %s\n", title_value+strlen(title_key));
    } else {
        printf("Title not found in file.\n");
    }
    if (date_value != NULL) {
        printf("Date: %s\n", date_value+strlen(date_key));
    } else {
        printf("Date not found in file.\n");
    }

    fclose(file_ptr);
    return 0;
}