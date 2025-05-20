//Falcon-180B DATASET v1.0 Category: File handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_SIZE 100
#define MAX_FILE_SIZE 100000

typedef struct {
    char *filename;
    FILE *file;
    int line_count;
} file_t;

void surreal_open(file_t *file) {
    char filename[MAX_LINE_SIZE];
    int i;

    printf("Enter filename: ");
    scanf("%s", filename);

    file->filename = strdup(filename);
    file->file = fopen(filename, "r");

    if (file->file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    file->line_count = 0;
}

void surreal_read(file_t *file) {
    char line[MAX_LINE_SIZE];
    int i;

    printf("Reading file '%s'...\n", file->filename);

    while (fgets(line, MAX_LINE_SIZE, file->file)!= NULL) {
        for (i = 0; line[i]!= '\0'; i++) {
            if (line[i] == '\n') {
                file->line_count++;
            }
        }
        printf("%s", line);
    }

    printf("\nTotal lines: %d\n", file->line_count);
}

void surreal_close(file_t *file) {
    fclose(file->file);
    free(file->filename);
}

int main() {
    file_t file;
    int choice;

    surreal_open(&file);

    do {
        printf("\n");
        printf("1. Read file\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                surreal_read(&file);
                break;
            case 2:
                surreal_close(&file);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}