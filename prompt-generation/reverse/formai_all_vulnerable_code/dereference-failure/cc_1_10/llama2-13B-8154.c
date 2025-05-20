//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PATH 512
#define MAX_FILES 1024

void clean_temp_files(void);
void clean_unused_libraries(void);

int main(void)
{
    clean_temp_files();
    clean_unused_libraries();
    return 0;
}

void clean_temp_files(void)
{
    DIR *dirp;
    struct dirent *entry;
    char temp_path[MAX_PATH];
    char filename[MAX_PATH];

    // Get the current working directory
    getcwd(temp_path, MAX_PATH);

    // Open the current working directory as a directory stream
    dirp = opendir(temp_path);

    // Loop through all files in the current working directory
    while ((entry = readdir(dirp)) != NULL) {
        // Check if the file is a temporary file
        if (strstr(entry->d_name, ".tmp") != NULL) {
            // Remove the temporary file
            sprintf(filename, "%s/%s", temp_path, entry->d_name);
            unlink(filename);
        }
    }

    // Close the directory stream
    closedir(dirp);
}

void clean_unused_libraries(void)
{
    char library_path[MAX_PATH];
    char filename[MAX_PATH];
    DIR *dirp;
    struct dirent *entry;

    // Get the current working directory
    getcwd(library_path, MAX_PATH);

    // Open the current working directory as a directory stream
    dirp = opendir(library_path);

    // Loop through all files in the current working directory
    while ((entry = readdir(dirp)) != NULL) {
        // Check if the file is a library
        if (strstr(entry->d_name, ".so") != NULL) {
            // Get the library name
            sprintf(filename, "%s/%s", library_path, entry->d_name);

            // Check if the library is in use
            int fd = open(filename, O_RDONLY);
            if (fd == -1) {
                // The library is not in use, remove it
                unlink(filename);
            } else {
                // The library is in use, do nothing
                close(fd);
            }
        }
    }

    // Close the directory stream
    closedir(dirp);
}