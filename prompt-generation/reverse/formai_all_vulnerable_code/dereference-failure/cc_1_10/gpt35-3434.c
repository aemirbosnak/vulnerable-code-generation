//FormAI DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 1024
#define MAX_FILE_NAME_LEN 256

void backup_file(const char* src_file_path, const char* dest_dir) {
    char dest_file_path[MAX_PATH_LEN];
    char* file_name = strrchr(src_file_path, '/');

    if (file_name == NULL) {
        file_name = strrchr(src_file_path, '\\');
    }

    if (file_name == NULL) {
        file_name = src_file_path;
    } else {
        file_name++; // skip the '/'
    }

    snprintf(dest_file_path, MAX_PATH_LEN, "%s/%s.bak", dest_dir, file_name);

    FILE* src_file = fopen(src_file_path, "rb");
    FILE* dest_file = fopen(dest_file_path, "wb");

    if (src_file == NULL || dest_file == NULL) {
        perror("Failed to open file!");
        if (src_file != NULL) fclose(src_file);
        if (dest_file != NULL) fclose(dest_file);
        return;
    }

    char buffer[1024];
    size_t count = 0;
    while((count = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, count, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    printf("File '%s' backed up to '%s'\n", src_file_path, dest_file_path);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <src_file_path> <dest_dir>\n", argv[0]);
        return EXIT_FAILURE;
    }

    backup_file(argv[1], argv[2]);

    return EXIT_SUCCESS;
}