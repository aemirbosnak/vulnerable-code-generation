//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Define lengths
#define MAX_FILENAME 256
#define MAX_BACKUP 10

// Function to simulate the ancient art of file backup
void perform_backup(const char* file) {
    char backup_filename[MAX_FILENAME];
    
    // Get current time for the backup filename
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Creating a backup file name
    snprintf(backup_filename, sizeof(backup_filename), "%s_backup_%04d-%02d-%02d_%02d-%02d-%02d.bak",
             file, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
             tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Simulate the backup operation
    printf("Initiating backup for [%s]... \n", file);
    sleep(1); // Pause for dramatic effect

    // Simulating file copy (Identified a simple approach instead of real copy)
    printf("Copying the secrets... Shhhh! 🤫 \n");
    sleep(1);

    // Inform the world about our successful backup
    FILE* fp = fopen(backup_filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Backup failed... The file gods are angry! 😱\n");
        return;
    }
    
    fprintf(fp, "Backup of file: %s at %s\n", file, ctime(&t));
    fclose(fp);

    printf("Backup successful! Your file is now over here: [%s] 🎉\n", backup_filename);
}

// Function to reign in chaos of files
int backup_files(int file_count, char* files[]) {
    if (file_count == 0) {
        printf("No files to back up! 😮 Please find some friends to back up. \n");
        return -1;
    }

    // Backup each file in style
    for (int i = 0; i < file_count && i < MAX_BACKUP; i++) {
        perform_backup(files[i]);
        printf("\n");
    }
    
    printf("All backups are done! Now, let's throw a party! 🎊\n");
    return 0;
}

// Main program starts here
int main(int argc, char* argv[]) {
    printf("Welcome to the Magical Backup Adventure 3000! 🚀\n");

    // Check if files are provided or not
    if (argc < 2) {
        printf("You forgot to add files! 🤦‍♂️\n");
        printf("Usage: %s file1.txt file2.txt ...\n", argv[0]);
        return 1;
    }

    // Get ready for the roller coaster!
    int file_count = argc - 1;  // Subtracting the program name

    // Print what files we're backing up
    printf("Preparing to back up %d files...\n", file_count);
    for (int i = 1; i <= file_count; i++) {
        printf("File %d: %s\n", i, argv[i]);
    }

    // Engage backup process
    backup_files(file_count, &argv[1]);

    // Sign out with style
    printf("Thank you for backing up! Remember: Backup is like a seatbelt, wear it before it's too late! 🚗💨\n");

    return 0;
}