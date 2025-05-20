//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LENGTH 50
#define MAX_FIELDS 10
#define BUFFER_SIZE (MAX_FIELDS * MAX_FIELD_LENGTH + MAX_FIELDS)

int main(int argc, char *argv[]) {
    char file_name[MAX_FIELD_LENGTH];
    printf("Enter the CSV file name: ");
    scanf("%s", file_name);
    FILE *file = fopen(file_name, "r");
    char buffer[BUFFER_SIZE];
    int row_count = 0;
    int field_count = 0;
    char *fields[MAX_FIELDS];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char *field;
        field = strtok(buffer, ",");
        while (field != NULL && field_count < MAX_FIELDS) {
            fields[field_count++] = field;
            field = strtok(NULL, ",");
        }
        if (field_count == MAX_FIELDS && strchr(buffer, ',') != NULL) {
            printf("ERROR: Too many fields.\n");
            return EXIT_FAILURE;
        }
        if (field_count == 0) {
            printf("ERROR: Empty line.\n");
            return EXIT_FAILURE;
        }
        for (int i = 0; i < field_count; i++) {
            printf("%s", fields[i]);
            if (i < field_count - 1) {
                printf(",");
            } else {
                printf("\n");
            }
        }
        row_count++;
        field_count = 0;
        if (row_count == 10) {
            printf("NOTE: Only showing first 10 lines.\n");
            break;
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
}