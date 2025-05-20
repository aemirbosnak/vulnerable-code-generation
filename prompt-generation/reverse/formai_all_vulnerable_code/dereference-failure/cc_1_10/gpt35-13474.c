//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 256

void backupFile(char* fileName) {
    char backupName[BUF_SIZE];
    strcpy(backupName, fileName);
    strcat(backupName, ".bak");

    printf("Creating backup file %s...\n", backupName);

    int src = open(fileName, O_RDONLY);
    if (src == -1) {
        perror("Error opening file");
        exit(1);
    }

    int dest = open(backupName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (dest == -1) {
        perror("Error creating backup file");
        exit(1);
    }

    char buf[BUF_SIZE];
    int bytesRead;

    while ((bytesRead = read(src, buf, BUF_SIZE)) > 0) {
        if (write(dest, buf, bytesRead) == -1) {
            perror("Error writing to backup file");
            exit(1);
        }
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        exit(1);
    }

    if (close(src) == -1) {
        perror("Error closing source file");
        exit(1);
    }

    if (close(dest) == -1) {
        perror("Error closing destination file");
        exit(1);
    }

    printf("Backup file %s successfully created!\n", backupName);
}

void editFile(char* fileName, int lineNum, char* newText) {
    printf("Opening file %s...\n", fileName);

    int fd = open(fileName, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    printf("Editing line %d of file %s...\n", lineNum, fileName);

    char buf[BUF_SIZE];
    int bytesRead;
    int lineCount = 0;

    while ((bytesRead = read(fd, buf, BUF_SIZE)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            if (buf[i] == '\n') {
                lineCount++;
            }

            if (lineCount == lineNum) {
                lseek(fd, i - bytesRead + 1, SEEK_CUR);
                write(fd, newText, strlen(newText));
                close(fd);
                printf("Successfully edited line %d of file %s!\n", lineNum, fileName);
                return;
            }
        }
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        exit(1);
    }

    close(fd);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s [-b] <file> [lineNum] [newText]\n", argv[0]);
        printf("Options:\n");
        printf("  -b: Backup the file before editing\n");
        exit(1);
    }

    int backup = 0;
    char* fileName;

    if (strcmp(argv[1], "-b") == 0) {
        backup = 1;
        fileName = argv[2];
    } else {
        fileName = argv[1];
    }

    if (backup) {
        backupFile(fileName);
    }

    if (argc == 4) {
        int lineNum = atoi(argv[2]);
        char* newText = argv[3];

        editFile(fileName, lineNum, newText);
    }

    return 0;
}