//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char source_path[MAX_PATH_LENGTH];
    char dest_path[MAX_PATH_LENGTH];

    strcpy(source_path, argv[1]);
    strcpy(dest_path, argv[2]);

    struct stat src_stat, dest_stat;

    if (stat(source_path, &src_stat) < 0 || stat(dest_path, &dest_stat) < 0) {
        perror("Error getting file status.");
        return 1;
    }

    if (S_ISDIR(src_stat.st_mode) || S_ISDIR(dest_stat.st_mode)) {
        printf("Error: Cannot synchronize directories.\n");
        return 1;
    }

    if (src_stat.st_mtime > dest_stat.st_mtime) {
        FILE *src_file = fopen(source_path, "rb");
        FILE *dest_file = fopen(dest_path, "wb");

        if (!src_file || !dest_file) {
            perror("Error opening files.");
            return 1;
        }

        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;

        while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, src_file)) > 0) {
            fwrite(buffer, sizeof(char), bytes_read, dest_file);
        }

        fclose(src_file);
        fclose(dest_file);

        printf("File %s updated.\n", dest_path);
    } else {
        printf("File %s is up-to-date.\n", dest_path);
    }

    return 0;
}