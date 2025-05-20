//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define MAX_PATH_SIZE (1024)

typedef struct {
    char *filename;
    int size;
    char *data;
} file_t;

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file!= NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}

int backup_file(const char *filename) {
    char backup_filename[MAX_PATH_SIZE];
    sprintf(backup_filename, "%s.bak", filename);
    FILE *input_file = fopen(filename, "r");
    FILE *output_file = fopen(backup_filename, "w");
    if (input_file == NULL || output_file == NULL) {
        return 0;
    }
    char buffer[MAX_FILE_SIZE];
    int bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }
    fclose(input_file);
    fclose(output_file);
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    if (!file_exists(filename)) {
        printf("File not found.\n");
        return 1;
    }
    backup_file(filename);
    printf("Backup completed.\n");
    return 0;
}