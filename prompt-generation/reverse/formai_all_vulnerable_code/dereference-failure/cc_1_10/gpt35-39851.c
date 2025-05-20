//FormAI DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

// function to check if a string is numeric
int is_numeric(char *str) {
    for(int i = 0; i < strlen(str); ++i) {
        if(!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *ent;
    char path[1024], temp[1024], buf[1024];

    if(argc > 1 && strcmp(argv[1], "-h") == 0) {
        printf("Usage: %s [-h]\n", argv[0]);
        printf("  -h : display this help message\n");
        return 0;
    }

    // open the directory /proc
    if((dir = opendir("/proc")) != NULL) {
        printf("%-10s %-20s %-10s\n", "PID", "CMD", "STATUS");
        // loop through all the entries
        while((ent = readdir(dir)) != NULL) {
            // check if the entry is a directory and not "." or ".."
            if(ent->d_type == DT_DIR && is_numeric(ent->d_name) && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                // create the path to the /proc/PID/status file
                strcpy(path, "/proc/");
                strcat(path, ent->d_name);
                strcat(path, "/status");

                // open the /proc/PID/status file
                FILE *fp = fopen(path, "r");
                if(fp != NULL) {
                    // read the contents of the file line by line
                    while(fgets(buf, 1024, fp) != NULL) {
                        // look for the "Name:" line
                        if(strncmp(buf, "Name:", 5) == 0) {
                            // extract the command name
                            sscanf(buf, "%s %s", temp, temp);
                            printf("%-10s %-20s ", ent->d_name, temp);
                        }
                        // look for the "State:" line
                        else if(strncmp(buf, "State:", 6) == 0) {
                            // extract the process status
                            sscanf(buf, "%s %s", temp, temp);
                            printf("%-10s\n", temp);
                            break;
                        }
                    }
                    fclose(fp);
                }
            }
        }
        closedir(dir);
    } else {
        // failed to open directory
        perror("");
        return EXIT_FAILURE;
    }

    return 0;
}