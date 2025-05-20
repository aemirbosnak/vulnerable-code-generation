//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB
#define VIRUS_SIGNATURE "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"
#define VIRUS_SIGNATURE_LENGTH 68

typedef struct {
    char *file_name;
    FILE *file;
    unsigned char *buffer;
    size_t buffer_size;
    size_t buffer_pos;
} FileScanner;

int is_virus(FileScanner *scanner) {
    if (scanner->buffer_pos >= VIRUS_SIGNATURE_LENGTH) {
        return 0;
    }

    if (memcmp(scanner->buffer, VIRUS_SIGNATURE, VIRUS_SIGNATURE_LENGTH) == 0) {
        return 1;
    }

    return 0;
}

void scan_file(const char *file_path, FileScanner *scanner) {
    scanner->file = fopen(file_path, "rb");
    if (scanner->file == NULL) {
        printf("Error: Failed to open file '%s'\n", file_path);
        exit(1);
    }

    scanner->buffer = malloc(MAX_FILE_SIZE);
    if (scanner->buffer == NULL) {
        printf("Error: Failed to allocate memory for buffer\n");
        exit(1);
    }

    scanner->buffer_size = MAX_FILE_SIZE;
    scanner->buffer_pos = 0;

    while (fread(scanner->buffer + scanner->buffer_pos, 1, scanner->buffer_size - scanner->buffer_pos, scanner->file) > 0) {
        scanner->buffer_pos += fread(scanner->buffer + scanner->buffer_pos, 1, scanner->buffer_size - scanner->buffer_pos, scanner->file);
    }

    fclose(scanner->file);
}

void scan_directory(const char *dir_path, FileScanner *scanner) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Error: Failed to open directory '%s'\n", dir_path);
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_REG) {
            char path[strlen(dir_path) + strlen(entry->d_name) + 2];
            sprintf(path, "%s/%s", dir_path, entry->d_name);

            scan_file(path, scanner);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        exit(1);
    }

    FileScanner scanner;
    scanner.file_name = argv[1];
    scan_directory(scanner.file_name, &scanner);

    return 0;
}