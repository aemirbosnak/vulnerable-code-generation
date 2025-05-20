//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILENAME_LENGTH 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char lines[MAX_LINE_LENGTH];
    int checksum;
} file_t;

file_t *new_file(const char *filename) {
    file_t *file = (file_t *)malloc(sizeof(file_t));
    strcpy(file->filename, filename);
    file->checksum = 0;
    return file;
}

void free_file(file_t *file) {
    free(file);
}

int lines_count(file_t *file) {
    int count = 0;
    char *line = strtok(file->lines, "\n");
    while (line!= NULL) {
        count++;
        line = strtok(NULL, "\n");
    }
    return count;
}

int calculate_checksum(file_t *file) {
    int checksum = 0;
    char *line = strtok(file->lines, "\n");
    while (line!= NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (isalpha(line[i])) {
                checksum += tolower(line[i]);
            }
        }
        line = strtok(NULL, "\n");
    }
    return checksum;
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    file_t *file = new_file(filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: cannot open file.\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, f)!= NULL) {
        strcat(file->lines, line);
        strcat(file->lines, "\n");
    }
    fclose(f);
    int checksum = calculate_checksum(file);
    printf("Checksum for %s: %d\n", filename, checksum);
    free_file(file);
    return 0;
}