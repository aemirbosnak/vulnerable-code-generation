//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BACKUP_COUNT 5

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    int backup_count;
} BackupFileInfo;

void createBackupFile(const char* filename) {
    int fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Failed to create backup file");
        return;
    }

    close(fd);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    BackupFileInfo* backupInfo = (BackupFileInfo*)malloc(sizeof(BackupFileInfo));
    if (backupInfo == NULL) {
        fprintf(stderr, "Failed to allocate memory for backup file info\n");
        return 1;
    }

    strncpy(backupInfo->filename, filename, MAX_FILE_NAME_LENGTH);
    backupInfo->backup_count = 0;

    while (backupInfo->backup_count < MAX_BACKUP_COUNT) {
        createBackupFile(backupInfo->filename);
        backupInfo->backup_count++;
    }

    free(backupInfo);

    return 0;
}