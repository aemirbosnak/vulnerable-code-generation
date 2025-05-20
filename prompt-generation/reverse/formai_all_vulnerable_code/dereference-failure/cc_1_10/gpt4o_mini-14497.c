//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 100
#define BACKUP_SUFFIX "_backup"

// Function Prototypes
void create_backup(const char *filename);
void rename_file(const char *original, const char *backup);
void print_funny_message();

// The main function: the circus starts here!
int main() {
    char filename[MAX_FILENAME_LENGTH];

    // Welcome to the wacky world of file backups!
    print_funny_message();

    printf("Enter the file name you want to backup (no pressure): ");
    scanf("%s", filename);

    // Check if the file exists
    if (access(filename, F_OK) != 0) {
        printf("Oops! The file '%s' does not exist! Maybe it's on vacation?\n", filename);
        return 1;
    }

    create_backup(filename);
    printf("Backup complete! Your '%s' file has been saved as '%s'.\n", filename, 
           strcat(strdup(filename), BACKUP_SUFFIX));
    
    return 0;
}

// The Great Backup Creator
void create_backup(const char *filename) {
    // Generate new backup filename
    char backup_filename[MAX_FILENAME_LENGTH];
    snprintf(backup_filename, sizeof(backup_filename), "%s%s", filename, BACKUP_SUFFIX);

    // Simulate a wacky delay as if the computer is juggling (not really)
    printf("Creating backup... Please hold tight! (This won't take long, I promise)\n");
    sleep(2);

    // Copy the original file to the backup
    FILE *original_file = fopen(filename, "rb");
    FILE *backup_file = fopen(backup_filename, "wb");

    // Check if files opened successfully
    if (!original_file || !backup_file) {
        printf("Seems like the backup machine is out of order!\n");
        exit(1);
    }

    // Performing the infamous file copy (with a twist of drama)
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, 1, bytes, backup_file);
    }

    // Close the files as if they are tired from the work
    fclose(original_file);
    fclose(backup_file);

    printf("Backup successfully created! Your files are safe with me, promise!\n");
}

// Rename old files, it's like changing outfits
void rename_file(const char *original, const char *backup) {
    if (rename(original, backup) == 0) {
        printf("File renamed from '%s' to '%s'. It's now sporting a new look!\n", original, backup);
    } else {
        perror("Failed to rename the file. Perhaps it needs a motivational speech?");
    }
}

// Print a funny welcome message to kick off the adventure
void print_funny_message() {
    printf("Welcome to the 'Funky File Backup System'!\n");
    printf("Where every file gets a chance to wear a backup outfit!\n");
    printf("Get ready for some wild file antics!\n");
    printf("Don't blame the backups if they start dancing!\n\n");
    
    printf("We'll be creating backups faster than a squirrel on espresso!\n");
    printf("Hang tight, and let's roll!\n\n");
}