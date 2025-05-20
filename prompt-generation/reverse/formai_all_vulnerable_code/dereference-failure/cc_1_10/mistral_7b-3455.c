//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024
#define BACKUP_DIR "/home/holmes/backups"

struct FileMetadata {
    char fileName[100];
    off_t fileSize;
    char fileContents[MAX_FILE_SIZE];
};

void backupFile(const char *filePath) {
    int fileFD = open(filePath, O_RDONLY);
    if (fileFD < 0) {
        fprintf(stderr, "Could not open file: %s\n", filePath);
        return;
    }

    struct stat fileStat;
    fstat(fileFD, &fileStat);

    if (fileStat.st_size > MAX_FILE_SIZE) {
        fprintf(stderr, "File %s is too large to be backed up\n", filePath);
        close(fileFD);
        return;
    }

    struct FileMetadata fileMeta;
    strcpy(fileMeta.fileName, filePath);
    fileMeta.fileSize = fileStat.st_size;

    ssize_t readBytes = read(fileFD, fileMeta.fileContents, fileStat.st_size);
    if (readBytes != fileStat.st_size) {
        fprintf(stderr, "Error reading file: %s\n", filePath);
        close(fileFD);
        return;
    }

    close(fileFD);

    char backupPath[150];
    snprintf(backupPath, sizeof(backupPath), "%s/%s_%ld_%s.bak", BACKUP_DIR, fileMeta.fileName, (long)time(NULL), "holmes");

    int backupFD = open(backupPath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (backupFD < 0) {
        fprintf(stderr, "Could not create backup file: %s\n", backupPath);
        return;
    }

    write(backupFD, &fileMeta, sizeof(struct FileMetadata));
    write(backupFD, fileMeta.fileContents, fileMeta.fileSize);

    close(backupFD);

    printf("Backed up file: %s to %s\n", filePath, backupPath);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_to_backup>\n", argv[0]);
        return 1;
    }

    char filePath = argv[1];
    backupFile(filePath);

    return 0;
}