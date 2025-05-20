//FormAI DATASET v1.0 Category: System process viewer ; Style: enthusiastic
// Hello and welcome to the C System Process Viewer program!

// First, let's import some necessary libraries:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Let's define a function that will return a list of all processes running on the system
void list_processes() {
    // create the dirent structures
    DIR *directory = opendir("/proc");
    struct dirent *entry;

    // loop through all the files in the "/proc" directory
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // if the name of the directory is a number, it is a process
            if (isdigit(*entry->d_name)) {
                // open the "status" file for the process
                char filename[1024];
                snprintf(filename, sizeof(filename), "/proc/%s/status", entry->d_name);
                FILE *file = fopen(filename, "r");

                if (file) {
                    char line[128];
                    // read the first line of the "status" file to get the process name
                    fgets(line, 128, file);
                    // print out the process ID and name
                    printf("PID: %s %s\n", entry->d_name, line + 6);
                    fclose(file);
                }
            }
        }
    }
    // close the directory
    closedir(directory);
}

// Finally, let's define our main function
int main() {
    // print a welcome message
    printf("Welcome to the C System Process Viewer!\n");

    // call the function to list all the running processes on the system
    list_processes();

    // print a goodbye message
    printf("Thank you for using the C System Process Viewer!\n");

    return 0;
}