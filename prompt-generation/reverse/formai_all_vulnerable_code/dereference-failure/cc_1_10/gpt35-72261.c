//FormAI DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

// function to check if a string is numeric
int is_numeric(char str[]) {
    int i = 0;
    while(str[i] != '\0') {
        if(!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    char path[1024], pid[10], status[1024], buf[1024];
    FILE *fp;

    // open the directory '/proc'
    dir = opendir("/proc");
    if(dir == NULL) {
        perror("Failed to open directory");
        exit(EXIT_FAILURE);
    }

    // print the header
    printf("%s %6s %10s %20s %10s\n", "STATUS", "PID", "PPID", "CMD", "USER");

    // loop through the entries in the directory
    while((entry = readdir(dir)) != NULL) {
        // check if the entry is a directory and its name is numeric
        if(entry->d_type == DT_DIR && is_numeric(entry->d_name)) {
            strcpy(pid, entry->d_name);
            sprintf(path, "/proc/%s/status", pid);

            // open the /proc/[pid]/status file
            fp = fopen(path, "r");
            if(fp == NULL) {
                perror("Failed to open file");
                exit(EXIT_FAILURE);
            }

            // read the first line of the status file to get the process status
            fgets(status, sizeof(status), fp);
            sscanf(status, "%s %s", buf, buf);

            // check if the process status is running or sleeping
            if(strcmp(buf, "R") == 0 || strcmp(buf, "S") == 0) {
                // read the PPID and CMD of the process from the /proc/[pid]/status file
                while(fgets(status, sizeof(status), fp) != NULL) {
                    if(strncmp(status, "PPid:", 5) == 0) {
                        sscanf(status, "%s %s", buf, buf);
                        break;
                    }
                }
                while(fgets(status, sizeof(status), fp) != NULL) {
                    if(strncmp(status, "Name:", 5) == 0) {
                        sscanf(status, "%s %s", buf, buf);
                        break;
                    }
                }
                fclose(fp);

                // open the /proc/[pid]/loginuid file to get the UID of the user
                sprintf(path, "/proc/%s/loginuid", pid);
                fp = fopen(path, "r");
                if(fp == NULL) {
                    perror("Failed to open file");
                    exit(EXIT_FAILURE);
                }

                // read the UID from the loginuid file
                fgets(buf, sizeof(buf), fp);
                fclose(fp);

                // print the process information
                printf("%6s %10s %20s ", buf, pid, buf);
                printf("%10s %s\n", buf, entry->d_name);
            }
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}