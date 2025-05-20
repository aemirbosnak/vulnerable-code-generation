//FormAI DATASET v1.0 Category: System process viewer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[40], buff[256];
    FILE *fp;

    // Get all the directories in the /proc folder
    dir = opendir("/proc/");
    if (dir == NULL) {
        perror("Couldn't open the directory");
        exit(1);
    }

    // Loop through each directory and only show directories that are numbered and therefore correspond to a process
    while ((ent = readdir(dir)) != NULL) {
        if(isdigit(*ent->d_name)) {
            printf("%s\n", ent->d_name);

            // Construct the path to the cmdline file for the current process
            sprintf(path, "/proc/%s/cmdline", ent->d_name);

            // Open the cmdline file
            fp = fopen(path, "r");
            if (fp == NULL) {
                perror("Couldn't open the file");
                exit(1);
            }

            // Read the contents of the file and convert all null characters to spaces for readability
            fgets(buff, sizeof(buff), fp);
            int length = strlen(buff);
            for (int i = 0; i < length; i++) {
                if (buff[i] == '\0') {
                    buff[i] = ' ';
                }
            }

            printf("%s\n", buff);

            // Close the file
            fclose(fp);
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}