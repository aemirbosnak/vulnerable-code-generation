//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024
#define BUFFER_SIZE 4096

void backup_file(const char *src_file, const char *dst_file);
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    if (strlen(argv[2]) + strlen(argv[1]) + 5 > MAX_FILE_SIZE) {
        printf("Error: The combined length of the source and destination file names exceeds the maximum file size.\n");
        return 1;
    }

    backup_file(argv[1], argv[2]);

    return 0;
}

void backup_file(const char *src_file, const char *dst_file) {
    FILE *src, *dst;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    src = fopen(src_file, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return;
    }

    dst = fopen(dst_file, "wb");
    if (dst == NULL) {
        fclose(src);
        perror("Error opening destination file");
        return;
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        if (fwrite(buffer, 1, bytes_read, dst) != bytes_read) {
            perror("Error writing to destination file");
            fclose(src);
            fclose(dst);
            return;
        }
    }

    if (ferror(src) != 0 || ferror(dst) != 0) {
        perror("Error reading from or writing to files");
        fclose(src);
        fclose(dst);
        return;
    }

    fclose(src);
    fclose(dst);

    printf("File backup completed: %s -> %s\n", src_file, dst_file);
}