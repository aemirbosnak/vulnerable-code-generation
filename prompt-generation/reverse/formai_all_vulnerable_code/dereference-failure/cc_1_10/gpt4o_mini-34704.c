//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_FILES 100
#define BUFFER_SIZE 1024

void create_backup(const char *source, const char *destination) {
    FILE *source_file = fopen(source, "rb");
    if (!source_file) {
        perror("Error opening source file");
        return;
    }

    char backup_file[256];
    snprintf(backup_file, sizeof(backup_file), "%s/%s_%ld.bak", destination, source, time(NULL));
  
    FILE *dest_file = fopen(backup_file, "wb");
    if (!dest_file) {
        perror("Error opening backup file");
        fclose(source_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, source_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dest_file);
    }

    printf("Backup of '%s' created as '%s'\n", source, backup_file);

    fclose(source_file);
    fclose(dest_file);
}

int main() {
    char *files[MAX_FILES];
    char destination[256];
    int num_files = 0;

    printf("Welcome to the Simple File Backup System\n");

    while (num_files < MAX_FILES) {
        char input[256];
        printf("Enter a file to backup (or type 'done' to finish): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove the newline character

        if (strcmp(input, "done") == 0) {
            break;
        }

        files[num_files] = strdup(input);
        num_files++;
    }

    printf("Enter the destination directory for backups: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = 0; // Remove the newline character

    struct stat stat_buf;
    if (stat(destination, &stat_buf) != 0 || !S_ISDIR(stat_buf.st_mode)) {
        fprintf(stderr, "Error: '%s' is not a valid directory.\n", destination);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_files; i++) {
        create_backup(files[i], destination);
        free(files[i]);
    }

    printf("Backup process completed.\n");
    return EXIT_SUCCESS;
}