//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* key;
    char* value;
} Metadata;

int main() {
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }

    Metadata metadata = {NULL, NULL};
    char line[MAX_LINE_LENGTH] = {0};
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (metadata.key!= NULL) {
            if (metadata.value == NULL) {
                metadata.value = strdup(line);
            } else {
                char* temp = metadata.value;
                metadata.value = realloc(metadata.value, strlen(metadata.value) + strlen(line) + 2);
                strcat(metadata.value, "\n");
                strcat(metadata.value, line);
                free(temp);
            }
        } else if (strncmp(line, "key:", 4) == 0) {
            metadata.key = strdup(line + 4);
        }
    }

    if (metadata.key == NULL || metadata.value == NULL) {
        fprintf(stderr, "Error: Invalid metadata.\n");
        exit(1);
    }

    printf("Metadata:\n");
    printf("Key: %s\n", metadata.key);
    printf("Value:\n%s\n", metadata.value);

    free(metadata.key);
    free(metadata.value);
    fclose(file);

    return 0;
}