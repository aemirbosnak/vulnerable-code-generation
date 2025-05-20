//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function to backup a file
void backup_file(char *source_file, char *destination_file) {
    FILE *source, *destination;
    char ch;

    // Open source and destination files
    source = fopen(source_file, "r");
    if (source == NULL) {
        printf("Error: Unable to open source file %s\n", source_file);
        exit(1);
    }

    destination = fopen(destination_file, "w");
    if (destination == NULL) {
        printf("Error: Unable to open destination file %s\n", destination_file);
        fclose(source);
        exit(2);
    }

    // Copy contents of source file to destination file
    while ((ch = fgetc(source))!= EOF) {
        fputc(ch, destination);
    }

    // Close source and destination files
    fclose(source);
    fclose(destination);
}

// Function to find all files in a directory and backup them
void backup_directory(char *dir_name, char *backup_dir) {
    DIR *dir;
    struct dirent *ent;
    char file_name[256];

    dir = opendir(dir_name);
    if (dir == NULL) {
        printf("Error: Unable to open directory %s\n", dir_name);
        exit(3);
    }

    // Loop through all files in the directory
    while ((ent = readdir(dir))!= NULL) {
        // Construct the full path of the file
        strcpy(file_name, dir_name);
        strcat(file_name, "/");
        strcat(file_name, ent->d_name);

        // Backup the file
        backup_file(file_name, (char *)malloc(strlen(backup_dir) + strlen(ent->d_name) + 2));
    }

    // Close the directory
    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s source_directory backup_directory\n", argv[0]);
        exit(4);
    }

    // Backup all files in the source directory to the backup directory
    backup_directory(argv[1], argv[2]);

    return 0;
}