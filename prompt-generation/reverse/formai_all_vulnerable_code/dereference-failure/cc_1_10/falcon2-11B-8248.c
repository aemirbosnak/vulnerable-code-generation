//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_directory target_directory\n", argv[0]);
        return 1;
    }

    // Get the source and target directories from command line arguments
    char *source_directory = argv[1];
    char *target_directory = argv[2];

    // Open the source and target directories
    DIR *source_dir = opendir(source_directory);
    DIR *target_dir = opendir(target_directory);

    // If the directories cannot be opened, exit the program
    if (source_dir == NULL || target_dir == NULL) {
        fprintf(stderr, "Error opening directories: %s %s\n", source_directory, target_directory);
        return 1;
    }

    // Iterate over each file in the source directory
    struct dirent *source_file;
    while ((source_file = readdir(source_dir))!= NULL) {
        // Get the file name
        char source_file_name[256];
        strncpy(source_file_name, source_file->d_name, 255);

        // Open the source file
        FILE *source_file_ptr = fopen(source_file_name, "rb");

        // If the source file cannot be opened, exit the program
        if (source_file_ptr == NULL) {
            fprintf(stderr, "Error opening file: %s\n", source_file_name);
            return 1;
        }

        // Get the file size
        struct stat source_file_stat;
        fstat(fileno(source_file_ptr), &source_file_stat);

        // Open the target file
        char target_file_name[256];
        strncpy(target_file_name, source_file_name, 255);
        FILE *target_file_ptr = fopen(target_file_name, "wb");

        // If the target file cannot be opened, exit the program
        if (target_file_ptr == NULL) {
            fprintf(stderr, "Error opening file: %s\n", target_file_name);
            return 1;
        }

        // Copy the source file to the target file
        fwrite(fread(source_file_ptr, 1, source_file_stat.st_size, source_file_ptr), 1, source_file_stat.st_size, target_file_ptr);

        // Close the source and target files
        fclose(source_file_ptr);
        fclose(target_file_ptr);
    }

    // Close the source and target directories
    closedir(source_dir);
    closedir(target_dir);

    return 0;
}