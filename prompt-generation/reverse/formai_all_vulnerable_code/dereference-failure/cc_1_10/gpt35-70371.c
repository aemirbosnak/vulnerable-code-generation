//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: csvreader [filename]\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];
    char *token;
    int row_count = 0;
    int field_count = 0;

    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        row_count++;

        if (row_count == 1) {
            // First row contains headers
            // Print the headers
            token = strtok(buffer, ",");
            while (token != NULL) {
                printf("%s\t", token);
                field_count++;
                token = strtok(NULL, ",");
            }
            printf("\n");
        } else {
            // Remaining rows contain data
            char **fields = (char**)malloc(sizeof(char*) * field_count);
            token = strtok(buffer, ",");
            int i = 0;
            while (token != NULL) {
                fields[i] = (char*)malloc(sizeof(char) * (strlen(token) + 1));
                strcpy(fields[i], token);
                i++;
                token = strtok(NULL, ",");
            }
            if (i != field_count) {
                printf("Error at row %d: found %d fields, expected %d.\n", row_count, i, field_count);
                return 1;
            }

            // Print the data
            for (int j = 0; j < field_count; j++) {
                printf("%s\t", fields[j]);
                free(fields[j]);
            }
            printf("\n");
            free(fields);
        }
    }

    fclose(file);

    return 0;
}