//FormAI DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

char* get_input_string() {
    char* buffer = malloc(MAX_LINE);
    fgets(buffer, MAX_LINE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    return buffer;
}

char* get_file_extension(char* filename) {
    char* extension = strrchr(filename, '.');
    if (extension == NULL) {
        return "";
    }
    return extension + 1;
}

void backup_file(char* filename) {
    FILE* original_file = fopen(filename, "rb");
    if (original_file == NULL) {
        printf("Sorry, unable to open %s for reading.\n", filename);
        return;
    }

    char* backup_filename = malloc(strlen(filename) + 5); // ".bak\0"
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    FILE* backup_file = fopen(backup_filename, "wb");
    if (backup_file == NULL) {
        printf("Sorry, unable to open %s for writing.\n", backup_filename);
        fclose(original_file);
        free(backup_filename);
        return;
    }

    char buffer[MAX_LINE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), MAX_LINE, original_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
    free(backup_filename);
}

int main() {
    printf("Welcome to C File Backup System! Please enter a file name to backup:\n");
    char* filename = get_input_string();

    char* extension = get_file_extension(filename);
    if (strcmp(extension, "bak") == 0) {
        printf("Sorry, can't backup a backup file.\n");
        free(filename);
        return 0;
    }

    backup_file(filename);

    free(filename);
    return 0;
}