//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define MAX_METADATA_LENGTH 1024

int is_regular_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int extract_metadata(const char *filename, char *metadata) {
    if (!is_regular_file(filename)) {
        return -1;
    }

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    char *line = NULL;
    size_t line_size = 0;

    while (getline(&line, &line_size, fd) != -1) {
        if (strstr(line, "metadata:") != NULL) {
            line += strlen("metadata:");
            strcpy(metadata, line);
            strtok(metadata, "\n");
            if (metadata[0] != '\0') {
                free(line);
                close(fd);
                return 0;
            } else {
                free(line);
                close(fd);
                return -1;
            }
        }
    }

    free(line);
    close(fd);
    return -1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    char metadata[MAX_METADATA_LENGTH] = { 0 };
    int rc = extract_metadata(argv[1], metadata);
    if (rc == -1) {
        printf("No metadata found for file '%s'\n", argv[1]);
        return 0;
    }

    printf("Metadata for file '%s':\n", argv[1]);
    printf("%s\n", metadata);

    return 0;
}