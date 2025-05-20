//FormAI DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define FILENAME_MAX_LEN 256

void backup(char *filename) {
    char time_str[20];
    time_t now = time(NULL);
    strftime(time_str, 20, "%Y-%m-%d_%H-%M-%S", localtime(&now));

    size_t filename_len = strlen(filename);
    char *backup_filename = malloc(FILENAME_MAX_LEN);
    snprintf(backup_filename, FILENAME_MAX_LEN, "%s_%s", filename, time_str);
    FILE *file = fopen(filename, "r");
    FILE *backup_file = fopen(backup_filename, "w");

    if (file == NULL || backup_file == NULL) {
        printf("Error accessing files.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    size_t n;
    while ((n = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        if (fwrite(buffer, 1, n, backup_file) != n) {
            printf("Error writing to backup file.\n");
            exit(1);
        }
    }

    printf("Backup created: %s\n", backup_filename);
    fclose(file);
    fclose(backup_file);
    free(backup_filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    backup(filename);

    return 0;
}