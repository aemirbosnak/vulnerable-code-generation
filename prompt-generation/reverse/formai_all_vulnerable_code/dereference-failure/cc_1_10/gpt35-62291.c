//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

struct file_metadata {
    char *name;
    char *type;
    int size;
    char *date_created;
    char *date_modified;
};

void extract_file_metadata(const char *filename, struct file_metadata *metadata) {
    int file_descriptor = open(filename, O_RDONLY);

    if (file_descriptor == -1) {
        perror("ERROR: Unable to open file");
        return;
    }

    struct stat file_stats;
    if (fstat(file_descriptor, &file_stats) == -1) {
        perror("ERROR: Unable to retrieve file statistics");
        return;
    }

    metadata->name = strdup(filename);
    metadata->size = (int)file_stats.st_size;

    if (S_ISREG(file_stats.st_mode)) {
        metadata->type = "Regular file";
    } else if (S_ISDIR(file_stats.st_mode)) {
        metadata->type = "Directory";
    } else if (S_ISLNK(file_stats.st_mode)) {
        metadata->type = "Symbolic link";
    } else if (S_ISBLK(file_stats.st_mode)) {
        metadata->type = "Block special file";
    } else if (S_ISCHR(file_stats.st_mode)) {
        metadata->type = "Character special file";
    } else if (S_ISSOCK(file_stats.st_mode)) {
        metadata->type = "Socket";
    } else if (S_ISFIFO(file_stats.st_mode)) {
        metadata->type = "FIFO/pipe";
    } else {
        metadata->type = "Unknown file type";
    }

    metadata->date_created = malloc(BUFFER_SIZE);
    strftime(metadata->date_created, BUFFER_SIZE, "%Y-%m-%d %H:%M:%S", localtime(&file_stats.st_ctime));

    metadata->date_modified = malloc(BUFFER_SIZE);
    strftime(metadata->date_modified, BUFFER_SIZE, "%Y-%m-%d %H:%M:%S", localtime(&file_stats.st_mtime));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: metadata_extractor <filename>\n");
        return 1;
    }

    struct file_metadata metadata;
    extract_file_metadata(argv[1], &metadata);

    printf("File name: %s\n", metadata.name);
    printf("File type: %s\n", metadata.type);
    printf("File size: %d bytes\n", metadata.size);
    printf("Date created: %s\n", metadata.date_created);
    printf("Date modified: %s\n", metadata.date_modified);

    free(metadata.name);
    free(metadata.date_created);
    free(metadata.date_modified);

    return 0;
}