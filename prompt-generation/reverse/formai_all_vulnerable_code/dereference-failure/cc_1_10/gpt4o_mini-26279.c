//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define MAX_FILENAME_LEN 255
#define BUFFER_SIZE 4096

void greet_user() {
    printf("Greetings, human! I am BackupBuddy, your friendly file backup robot!\n");
    printf("I will help you copy your precious files to a safe location.\n\n");
}

void display_instructions() {
    printf("Here's how you can use my services:\n");
    printf("1. Provide the path of the file you want to back up.\n");
    printf("2. Provide your desired backup destination.\n");
    printf("3. I will take care of the rest!\n");
}

char* get_time_stamp() {
    time_t rawtime;
    struct tm *info;
    static char time_buffer[80];
    
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(time_buffer, sizeof(time_buffer), "%Y%m%d_%H%M%S", info);
    
    return time_buffer;
}

int backup_file(const char* source, const char* destination) {
    FILE *src_file, *dest_file;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    src_file = fopen(source, "rb");
    if (!src_file) {
        fprintf(stderr, "Uh-oh! I couldn't open the source file: %s\n", source);
        return 1; // Error opening source file
    }

    char backup_filename[MAX_FILENAME_LEN];
    snprintf(backup_filename, MAX_FILENAME_LEN, "%s/%s_backup_%s", destination, 
             strrchr(source, '/') + 1, get_time_stamp());

    dest_file = fopen(backup_filename, "wb");
    if (!dest_file) {
        fprintf(stderr, "Yikes! I couldn't create the backup file: %s\n", backup_filename);
        fclose(src_file);
        return 1; // Error creating destination file
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytesRead, dest_file);
    }

    printf("Hooray! I successfully backed up %s to %s\n", source, backup_filename);

    fclose(src_file);
    fclose(dest_file);
    return 0; // Success
}

void list_files_in_directory(const char* path) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "I couldn't open the directory: %s\n", path);
        return;
    }

    printf("Files in the directory '%s':\n", path);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dir);
}

int main() {
    char source[MAX_FILENAME_LEN];
    char destination[MAX_FILENAME_LEN];

    greet_user();
    display_instructions();

    printf("Please enter the source file path: ");
    fgets(source, MAX_FILENAME_LEN, stdin);
    source[strcspn(source, "\n")] = 0; // Remove newline

    printf("Please enter the backup destination path: ");
    fgets(destination, MAX_FILENAME_LEN, stdin);
    destination[strcspn(destination, "\n")] = 0; // Remove newline

    // List files in the destination directory
    list_files_in_directory(destination);

    // Attempting to create a backup
    if (backup_file(source, destination) != 0) {
        fprintf(stderr, "Oops! Backup failed. Please try again!\n");
    }

    printf("Thank you for using BackupBuddy! Have a great day!\n");
    return 0;
}