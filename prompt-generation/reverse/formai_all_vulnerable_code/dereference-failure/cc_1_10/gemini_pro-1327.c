//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

// macros for gratitude
#define THANK_YOU printf("Thank you! ")
#define APPRECIATE printf("I appreciate your patience and gratitude. ")

// function to check if a file exists
int file_exists(const char *filename) {
    struct stat buf;
    return (stat(filename, &buf) == 0);
}

// function to copy a file
void copy_file(const char *source, const char *destination) {
    // open the source file
    FILE *source_file = fopen(source, "r");
    if (source_file == NULL) {
        perror("Error opening source file");
        exit(1);
    }

    // open the destination file
    FILE *destination_file = fopen(destination, "w");
    if (destination_file == NULL) {
        perror("Error opening destination file");
        fclose(source_file);
        exit(1);
    }

    // copy the contents of the source file to the destination file
    char buffer[1024];
    while (fread(buffer, 1, sizeof(buffer), source_file) != 0) {
        fwrite(buffer, 1, sizeof(buffer), destination_file);
    }

    // close the source and destination files
    fclose(source_file);
    fclose(destination_file);
}

// main function
int main() {
    // get the current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date_time[100];
    strftime(date_time, sizeof(date_time), "%Y-%m-%d_%H-%M-%S", tm);

    // get the home directory
    char *home_directory = getenv("HOME");
    if (home_directory == NULL) {
        perror("Error getting home directory");
        exit(1);
    }

    // create the backup directory
    char backup_directory[100];
    sprintf(backup_directory, "%s/.my_backups/%s", home_directory, date_time);
    if (mkdir(backup_directory, 0755) == -1) {
        perror("Error creating backup directory");
        exit(1);
    }

    THANK_YOU;
    APPRECIATE;

    // get the list of files in the home directory
    DIR *dir = opendir(home_directory);
    if (dir == NULL) {
        perror("Error opening home directory");
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // skip directories
        if (entry->d_type == DT_DIR) {
            continue;
        }

        // copy the file to the backup directory
        char source[100];
        sprintf(source, "%s/%s", home_directory, entry->d_name);
        char destination[100];
        sprintf(destination, "%s/%s", backup_directory, entry->d_name);
        copy_file(source, destination);

        THANK_YOU;
    }

    // close the directory
    closedir(dir);

    // show gratitude
    APPRECIATE;
    printf("Backup completed successfully! :)\n");

    return 0;
}