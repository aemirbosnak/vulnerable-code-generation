//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

#define MAX_FILENAME 256
#define BACKUP_DIR "backup/"

void create_backup_dir() {
    // Create backup directory if it does not exist
    if (mkdir(BACKUP_DIR, 0777) == -1 && errno != EEXIST) {
        perror("Unable to create backup directory");
        exit(1);
    }
}

void backup_file(const char *filename) {
    FILE *src_file, *dest_file;
    char dest_filename[MAX_FILENAME];

    // Open source file
    src_file = fopen(filename, "rb");
    if (src_file == NULL) {
        perror("Error opening source file");
        return;
    }

    // Create destination filename
    snprintf(dest_filename, sizeof(dest_filename), "%s%s.bak", BACKUP_DIR, filename);

    // Open destination file
    dest_file = fopen(dest_filename, "wb");
    if (dest_file == NULL) {
        perror("Error opening destination file");
        fclose(src_file);
        return;
    }

    // Copy contents from source to destination
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) != 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    // Close files
    fclose(src_file);
    fclose(dest_file);

    printf("Backup of '%s' created at '%s'\n", filename, dest_filename);
}

void list_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    printf("Files in the current directory:\n");

    while ((entry = readdir(dp)) != NULL) {
        // Ignore current and parent directory entries
        if (entry->d_name[0] != '.') {
            printf(" - %s\n", entry->d_name);
            backup_file(entry->d_name);
        }
    }

    closedir(dp);
}

void display_welcome_message() {
    printf("******************************************\n");
    printf("* Welcome to the Happy C File Backup System! *\n");
    printf("******************************************\n");
}

int main(int argc, char *argv[]) {
    // Welcome message
    display_welcome_message();

    // Create backup directory
    create_backup_dir();

    // List files and back them up
    if (argc > 1) {
        // If files are provided in the command line, backup those
        for (int i = 1; i < argc; i++) {
            backup_file(argv[i]);
        }
    } else {
        // Otherwise, backup all files in the current directory
        list_files(".");
    }

    printf("\nBackup process completed with joy! 🎉\n");
    return 0;
}