//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILE_NAME_LENGTH 256

void signal_handler(int signum) {
    printf("Caught signal %d, exiting...\n", signum);
    exit(0);
}

void scan_directory(const char* dir_name, const char* ext) {
    DIR* dir = opendir(dir_name);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (strstr(ent->d_name, ext)!= NULL) {
            printf("Scanning file: %s\n", ent->d_name);
            char filename[MAX_PATH_LENGTH];
            strcpy(filename, dir_name);
            strcat(filename, "/");
            strcat(filename, ent->d_name);

            FILE* fp = fopen(filename, "r");
            if (fp == NULL) {
                perror("fopen");
                continue;
            }

            char buffer[MAX_FILE_NAME_LENGTH];
            while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
                if (strstr(buffer, "virus")!= NULL) {
                    printf("Virus found: %s\n", buffer);
                    fclose(fp);
                    remove(filename);
                }
            }
            fclose(fp);
        }
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    signal(SIGINT, signal_handler);

    char dir_name[MAX_PATH_LENGTH];
    printf("Enter directory name: ");
    scanf("%s", dir_name);

    char ext[MAX_FILE_NAME_LENGTH];
    printf("Enter file extension to scan: ");
    scanf("%s", ext);

    scan_directory(dir_name, ext);

    return 0;
}