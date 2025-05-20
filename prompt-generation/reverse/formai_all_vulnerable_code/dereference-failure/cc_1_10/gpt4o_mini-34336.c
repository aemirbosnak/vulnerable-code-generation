//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PATH 260
#define BUFFER_SIZE 1024

void backup_the_file(const char *src, const char *dest) {
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    source = fopen(src, "rb");
    if (!source) {
        printf("Could not open source file: %s\n", strerror(errno));
        return;
    }

    destination = fopen(dest, "wb");
    if (!destination) {
        printf("Could not open destination file: %s\n", strerror(errno));
        fclose(source);
        return;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    printf("Backup completed from '%s' to '%s'\n", src, dest);

    fclose(source);
    fclose(destination);
}

void create_backup_directory(const char *backupDir) {
    char command[MAX_PATH];
    snprintf(command, sizeof(command), "mkdir -p %s", backupDir);
    system(command);
}

void get_backup_path(const char *fileName, const char *backupDir, char *backupPath) {
    snprintf(backupPath, MAX_PATH, "%s/%s.bak", backupDir, fileName);
}

int main() {
    const char *original_file = "example.txt"; // Change this to your source file
    const char *backup_directory = "./backup";  // Desired backup directory
    char backup_path[MAX_PATH];

    create_backup_directory(backup_directory);

    get_backup_path(original_file, backup_directory, backup_path);

    backup_the_file(original_file, backup_path);

    printf("Backup path: %s\n", backup_path);
    return 0;
}