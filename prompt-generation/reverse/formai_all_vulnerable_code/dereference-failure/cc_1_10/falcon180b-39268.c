//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_PATH 1024
#define MAX_COMMAND_LENGTH 1024
#define BACKUP_DIR "backup"
#define BACKUP_FILE_EXTENSION ".bak"

typedef struct {
    char *path;
    time_t mtime;
} FileInfo;

void backup_file(const char *file_path) {
    char backup_path[MAX_PATH];
    snprintf(backup_path, MAX_PATH, "%s/%s", BACKUP_DIR, file_path);
    mkdir(BACKUP_DIR, 0755);
    rename(file_path, backup_path);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    snprintf(command, MAX_COMMAND_LENGTH, "find %s -type f -exec backup_file {} \\;", argv[1]);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    char line[MAX_PATH];
    while (fgets(line, MAX_PATH, fp)!= NULL) {
        printf("%s", line);
    }

    pclose(fp);

    return 0;
}