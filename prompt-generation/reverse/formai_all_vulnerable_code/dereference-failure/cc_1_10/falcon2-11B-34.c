//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>

int main() {
    char fileName[] = "test.txt";
    char destinationDirectory[] = "backup/";
    char backupFileName[] = "backup.txt";

    struct stat fileStat;
    struct stat backupStat;

    int fileDescriptor = open(fileName, O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    if (fstat(fileDescriptor, &fileStat) == -1) {
        perror("Error getting file stats");
        return 1;
    }

    char* backupPath = malloc(strlen(destinationDirectory) + strlen(backupFileName) + 2);
    strcpy(backupPath, destinationDirectory);
    strcat(backupPath, backupFileName);

    if (stat(backupPath, &backupStat) == -1) {
        mkdir(destinationDirectory, 0700);
        if (chdir(destinationDirectory) == -1) {
            perror("Error changing directory");
            return 1;
        }

        if (chmod(destinationDirectory, 0700) == -1) {
            perror("Error changing directory permissions");
            return 1;
        }

        if (chdir("..") == -1) {
            perror("Error changing directory back");
            return 1;
        }
    }

    int backupFileDescriptor = open(backupPath, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (backupFileDescriptor == -1) {
        perror("Error opening backup file");
        return 1;
    }

    char buffer[1024];
    while (read(fileDescriptor, buffer, sizeof(buffer)) > 0) {
        write(backupFileDescriptor, buffer, sizeof(buffer));
    }

    close(fileDescriptor);
    close(backupFileDescriptor);

    free(backupPath);

    return 0;
}