//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_NAME_SIZE 1024
#define MAX_FILE_SIZE (1024 * 1024) // 1 MB
#define VIRUS_SIGNATURE "EICAR"

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    char file_data[MAX_FILE_SIZE];
    size_t file_size;
} FileInfo;

int is_virus(const char* data, size_t size) {
    const char* signature = VIRUS_SIGNATURE;
    size_t signature_size = strlen(signature);

    for (size_t i = 0; i < size - signature_size; i++) {
        if (memcmp(data + i, signature, signature_size) == 0) {
            return 1;
        }
    }

    return 0;
}

void scan_file(const char* file_path) {
    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        printf("Failed to open file: %s\n", file_path);
        return;
    }

    struct stat file_stat;
    fstat(fd, &file_stat);

    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("File is too large: %s\n", file_path);
        close(fd);
        return;
    }

    FileInfo file_info = {0};
    strncpy(file_info.file_name, file_path, MAX_FILE_NAME_SIZE - 1);
    read(fd, file_info.file_data, file_info.file_size = file_stat.st_size);
    close(fd);

    if (is_virus(file_info.file_data, file_info.file_size)) {
        printf("Virus found in file: %s\n", file_info.file_name);
    } else {
        printf("File is clean: %s\n", file_info.file_name);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}