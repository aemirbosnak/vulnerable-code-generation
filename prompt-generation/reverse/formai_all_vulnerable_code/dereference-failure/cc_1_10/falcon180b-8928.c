//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME 100
#define MAX_BACKUP_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME];
    time_t file_time;
} FileInfo;

void backup_file(char* source_file, char* dest_file) {
    FILE* source = fopen(source_file, "rb");
    FILE* dest = fopen(dest_file, "wb");

    if (source == NULL || dest == NULL) {
        printf("Error opening file(s)\n");
        exit(1);
    }

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), source)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, dest);
    }

    fclose(source);
    fclose(dest);
}

int main() {
    char source_file[MAX_FILE_NAME];
    char dest_file[MAX_FILE_NAME];
    char backup_dir[MAX_FILE_NAME];
    time_t current_time;

    printf("Enter the source file path: ");
    scanf("%s", source_file);

    printf("Enter the destination file path: ");
    scanf("%s", dest_file);

    printf("Enter the backup directory path: ");
    scanf("%s", backup_dir);

    time(&current_time);

    char backup_file_name[MAX_FILE_NAME];
    sprintf(backup_file_name, "%s/%ld-%s.bak", backup_dir, current_time, source_file);

    backup_file(source_file, backup_file_name);
    backup_file(dest_file, backup_file_name);

    printf("Backup complete!\n");

    return 0;
}