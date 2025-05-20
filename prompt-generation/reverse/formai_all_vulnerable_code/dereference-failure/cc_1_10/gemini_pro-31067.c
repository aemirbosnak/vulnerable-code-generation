//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buf[BUF_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buf, 1, BUF_SIZE, source)) > 0) {
        fwrite(buf, 1, bytes_read, destination);
    }

    if (ferror(source)) {
        perror("fread");
        return EXIT_FAILURE;
    }

    if (ferror(destination)) {
        perror("fwrite");
        return EXIT_FAILURE;
    }

    fclose(source);
    fclose(destination);

    // Add a timestamp to the destination file name
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d-%H-%M-%S", tm);
    char new_destination[strlen(argv[2]) + strlen(timestamp) + 1];
    sprintf(new_destination, "%s-%s", argv[2], timestamp);
    rename(argv[2], new_destination);

    return EXIT_SUCCESS;
}