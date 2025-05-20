//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1GB

typedef struct {
    char *filename;
    int size;
    char *data;
} File;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <device>\n", argv[0]);
        exit(1);
    }

    int dev = open(argv[1], O_RDONLY);
    if (dev < 0) {
        printf("Error opening device\n");
        exit(1);
    }

    printf("Scanning device...\n");
    int num_files = 0;
    File *files = NULL;

    while (num_files < 1000) {
        struct stat sb;
        if (fstat(dev, &sb) < 0) {
            printf("Error statting device\n");
            exit(1);
        }

        if (sb.st_size == 0)
            break;

        if (sb.st_size > MAX_FILE_SIZE) {
            printf("File too large: %s\n", argv[1]);
            exit(1);
        }

        char filename[256];
        snprintf(filename, sizeof(filename), "file_%d", num_files);
        File *file = malloc(sizeof(File));
        file->filename = strdup(filename);
        file->size = sb.st_size;
        file->data = malloc(file->size);

        if (pread(dev, file->data, file->size, sb.st_ino * sb.st_size)!= file->size) {
            printf("Error reading file\n");
            exit(1);
        }

        num_files++;
        files = realloc(files, sizeof(File) * num_files);
        files[num_files - 1] = *file;
        free(file);
    }

    printf("Found %d files:\n", num_files);
    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].filename, files[i].size);
    }

    close(dev);
    return 0;
}