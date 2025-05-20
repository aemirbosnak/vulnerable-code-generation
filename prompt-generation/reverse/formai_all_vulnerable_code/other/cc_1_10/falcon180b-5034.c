//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_SIZE 1024
#define VIRUS_SIGNATURE "1234567890"
#define VIRUS_SIGNATURE_SIZE strlen(VIRUS_SIGNATURE)

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    off_t file_size;
} FileInfo;

void scan_directory(const char* directory, void (*callback)(const FileInfo* file_info)) {
    DIR* dir = opendir(directory);

    if (dir == NULL) {
        printf("Error: could not open directory %s\n", directory);
        return;
    }

    struct dirent* dirent = NULL;
    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_REG) {
            FileInfo file_info;
            strcpy(file_info.file_name, dirent->d_name);
            file_info.file_size = dirent->d_reclen;

            callback(&file_info);
        }
    }

    closedir(dir);
}

void scan_file(const char* file_path, void (*callback)(const char* virus_name)) {
    FILE* file = fopen(file_path, "rb");

    if (file == NULL) {
        printf("Error: could not open file %s\n", file_path);
        return;
    }

    char buffer[VIRUS_SIGNATURE_SIZE + 1];
    memset(buffer, 0, VIRUS_SIGNATURE_SIZE + 1);

    while (fread(buffer, 1, VIRUS_SIGNATURE_SIZE, file) == VIRUS_SIGNATURE_SIZE) {
        if (memcmp(buffer, VIRUS_SIGNATURE, VIRUS_SIGNATURE_SIZE) == 0) {
            callback("Virus found!");
            break;
        }

        memmove(buffer, buffer + 1, VIRUS_SIGNATURE_SIZE - 1);
        memset(buffer + VIRUS_SIGNATURE_SIZE - 1, 0, 1);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1], &scan_file);

    return 0;
}