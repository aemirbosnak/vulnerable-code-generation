//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 1024

int main() {
    // Get the current time.
    time_t now = time(NULL);

    // Format the current time as a string.
    char time_str[26];
    strftime(time_str, 26, "%Y_%m_%d_%H_%M_%S", localtime(&now));

    // Get the name of the file to be backed up.
    char *file_name = "matrix_data.txt";

    // Open the file to be backed up.
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Create the backup file name.
    char backup_file_name[256];
    snprintf(backup_file_name, 256, "matrix_backup_%s.txt", time_str);

    // Open the backup file.
    FILE *backup_file = fopen(backup_file_name, "w");
    if (backup_file == NULL) {
        perror("Error opening backup file");
        return EXIT_FAILURE;
    }

    // Copy the contents of the file to be backed up to the backup file.
    char buf[BUFSIZE];
    while (fgets(buf, BUFSIZE, file) != NULL) {
        fputs(buf, backup_file);
    }

    // Close the files.
    fclose(file);
    fclose(backup_file);

    // Success!
    printf("File '%s' backed up to '%s'.\n", file_name, backup_file_name);
    return EXIT_SUCCESS;
}