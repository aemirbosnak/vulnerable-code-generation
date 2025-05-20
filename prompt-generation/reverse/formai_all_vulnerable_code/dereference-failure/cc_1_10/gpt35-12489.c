//FormAI DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
// C system process viewer by [Your Name]
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>

// Define constants
#define PROC_DIRECTORY "/proc/"
#define MAX_PID_LENGTH 6
#define MAX_NAME_LENGTH 255
#define MAX_LINE_LENGTH 1024

// Function to check if a string contains only digits
int is_digits(char *str) {
    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

int main() {
    DIR *directory;
    struct dirent *entry;
    char pid[MAX_PID_LENGTH];
    char pname[MAX_NAME_LENGTH];

    printf("PID  PROCESS NAME\n");

    directory = opendir(PROC_DIRECTORY);
    if (directory != NULL) {
        while ((entry = readdir(directory))) {
            if (is_digits(entry->d_name)) {
                // Read process name from cmdline file
                snprintf(pname, sizeof(pname), PROC_DIRECTORY "%s/cmdline", entry->d_name);
                FILE *cname = fopen(pname, "r");

                // Check if process name file exists and read it
                if (cname != NULL) {
                    fgets(pname, sizeof(pname), cname);
                    fclose(cname);

                    // Remove leading path from process name
                    char *name = pname;
                    while (*name != '\0') {
                        if (*name == '/')
                            pname[0] = '\0';
                        name++;
                    }

                    // Print process PID and name
                    printf("%s %s\n", entry->d_name, pname);
                }
            }
        }

        closedir(directory);
    }

    return 0;
}