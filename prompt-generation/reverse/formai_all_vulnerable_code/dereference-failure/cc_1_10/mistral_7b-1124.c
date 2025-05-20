//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 50
#define MAX_CHAR 256

typedef struct {
    char name[MAX_CHAR];
    char path[MAX_CHAR];
    time_t timestamp;
} FileInfo;

FileInfo files[MAX_FILES];
int num_files = 0;

void backup_file(char *path) {
    FILE *src, *dst;
    char buffer[MAX_CHAR];
    size_t read;
    strcpy(files[num_files].path, path);
    strcpy(files[num_files].name, strrchr(path, '/') + 1);
    src = fopen(path, "rb");
    if (src == NULL) {
        printf("Error: Unable to open file %s for reading.\n", path);
        return;
    }

    files[num_files].timestamp = time(NULL);
    dst = fopen(strcat(getcwd(NULL, MAX_CHAR), "/TimeCapsule_Backup/"), files[num_files].name);
    if (dst == NULL) {
        printf("Error: Unable to create backup file %s.\n", files[num_files].name);
        fclose(src);
        return;
    }

    while ((read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, read, 1, dst);
    }

    fclose(src);
    fclose(dst);
    num_files++;
    printf("Backup of %s created successfully.\n", files[num_files - 1].name);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path_to_file>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1]);

    printf("\nList of files backed up:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s (%ld bytes, last backed up %s)\n", files[i].name, strlen(files[i].path), ctime(&files[i].timestamp));
    }

    return 0;
}