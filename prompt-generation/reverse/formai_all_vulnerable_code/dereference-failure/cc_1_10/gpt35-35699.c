//FormAI DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main() {

    printf("Welcome to my unique C System process viewer!\n\n");

    DIR *dir; // pointer to directory stream
    struct dirent *entry; // struct to hold directory entry
    
    // open directory "/proc" for reading
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dir)) != NULL) { // read directory entries until end
        if (entry->d_name[0] >= '0' && entry->d_name[0] <= '9') { // check if first character of directory entry is a number (process id)
            char filename[512];
            snprintf(filename, sizeof(filename), "/proc/%s/status", entry->d_name); // build path to status file

            FILE *file = fopen(filename, "r"); // open status file for reading
            if (file != NULL) { // check if file opened successfully
                char name[512], status[512], line[512]; // arrays to hold process name and status
                while (fgets(line, sizeof(line), file)) { // read contents of status file line by line
                    if (strstr(line, "Name:") != NULL) { // search for "Name:" in each line
                        sscanf(line, "%*s %s", name); // extract process name from line
                    }
                    else if (strstr(line, "State:") != NULL) { // search for "State:" in each line
                        sscanf(line, "%*s %s", status); // extract process status from line
                    }
                }
                fclose(file); // close file stream

                printf("Process ID: %s\n", entry->d_name);
                printf("Process Name: %s\n", name);
                printf("Process Status: %s\n\n", status);
            }
        }
    }

    closedir(dir); // close directory stream

    printf("Thank you for using my C System process viewer!\n");

    return EXIT_SUCCESS;
}