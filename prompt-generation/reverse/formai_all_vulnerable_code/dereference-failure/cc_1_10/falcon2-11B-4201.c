//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *path;
    char *extension;
} file_info;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    FILE *logfile = fopen(argv[1], "r");
    if (logfile == NULL) {
        fprintf(stderr, "Failed to open '%s'\n", argv[1]);
        return 2;
    }

    file_info *files = (file_info*)malloc(sizeof(file_info) * 100);
    if (files == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 3;
    }

    char line[1024];
    while (fgets(line, sizeof(line), logfile)) {
        size_t pos = strcspn(line, "\n");
        line[pos] = '\0';
        char *filename = strtok(line, " ");
        char *extension = strrchr(filename, '.');
        if (extension == NULL) {
            continue;
        }
        extension++;
        file_info *file = &files[strlen(files) % 100];
        strcpy(file->path, filename);
        strcpy(file->extension, extension);
    }

    fclose(logfile);
    printf("Total number of files: %lu\n", strlen(files));
    for (int i = 0; i < strlen(files); i++) {
        file_info *file = &files[i];
        printf("%s\t%s\n", file->path, file->extension);
    }

    free(files);
    return 0;
}