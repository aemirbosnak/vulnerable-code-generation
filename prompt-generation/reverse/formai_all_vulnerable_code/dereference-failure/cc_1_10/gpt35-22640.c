//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

// Define macros for metadata types
#define TYPE_STRING 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_DATE 3

// Define a struct for metadata
typedef struct {
    char key[50];
    int type;
    void *value;
} Metadata;

// Define a function to extract metadata from a file
void extract_metadata(char *filename, Metadata *metadata) {
    // Open the file in read mode
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // Get the file size
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    // Read the last 100 bytes of the file
    char buffer[101];
    fseek(fp, -100, SEEK_END);
    fread(&buffer, 1, 100, fp);
    buffer[100] = '\0';

    // Split the buffer into lines
    char *line = strtok(buffer, "\n");

    // Loop through the lines and extract metadata
    while (line != NULL) {
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "\n");

        // Determine the type of metadata
        int type;
        if (strstr(value, "-")) {
            type = TYPE_DATE;
        } else if (strstr(value, ".")) {
            type = TYPE_FLOAT;
        } else if (atoi(value) != 0) {
            type = TYPE_INT;
        } else {
            type = TYPE_STRING;
        }

        // Allocate memory for the metadata value
        void *data;
        if (type == TYPE_STRING) {
            data = malloc(strlen(value) + 1);
            strcpy(data, value);
        } else if (type == TYPE_INT) {
            data = malloc(sizeof(int));
            sscanf(value, "%d", (int*) data);
        } else if (type == TYPE_FLOAT) {
            data = malloc(sizeof(float));
            sscanf(value, "%f", (float*) data);
        } else if (type == TYPE_DATE) {
            struct tm tm = {0};
            strptime(value, "%Y-%m-%d", &tm);
            time_t t = mktime(&tm);
            data = malloc(sizeof(time_t));
            *(time_t*) data = t;
        }

        // Store the metadata in the struct
        metadata->type = type;
        strcpy(metadata->key, key);
        metadata->value = data;

        // Move to the next line
        line = strtok(NULL, "\n");
        metadata++;
    }

    // Close the file
    fclose(fp);
}

// Define a main function for testing purposes
int main() {
    Metadata metadata[10];
    extract_metadata("example.txt", metadata);

    // Print the extracted metadata
    for (int i = 0; i < 10; i++) {
        if (metadata[i].type == TYPE_STRING) {
            printf("%s = %s\n", metadata[i].key, (char*) metadata[i].value);
        } else if (metadata[i].type == TYPE_INT) {
            printf("%s = %d\n", metadata[i].key, *(int*) metadata[i].value);
        } else if (metadata[i].type == TYPE_FLOAT) {
            printf("%s = %f\n", metadata[i].key, *(float*) metadata[i].value);
        } else if (metadata[i].type == TYPE_DATE) {
            struct tm *tm = localtime((time_t*) metadata[i].value);
            char date[20];
            strftime(date, sizeof(date), "%Y-%m-%d", tm);
            printf("%s = %s\n", metadata[i].key, date);
        }
    }

    return 0;
}