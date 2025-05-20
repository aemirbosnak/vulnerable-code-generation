//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int source_file, destination_file;
    char line[MAX_LINE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        exit(1);
    }

    source_file = open(argv[1], O_RDONLY);
    if (source_file == -1) {
        perror("Failed to open source file");
        exit(1);
    }

    destination_file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (destination_file == -1) {
        perror("Failed to open or create destination file");
        close(source_file);
        exit(1);
    }

    while (fgets(line, MAX_LINE, source_file) != NULL) {
        if (fprintf(destination_file, "%s", line) < 0) {
            perror("Failed to write to destination file");
            close(source_file);
            close(destination_file);
            exit(1);
        }
    }

    if (fclose(source_file) != 0) {
        perror("Failed to close source file");
        close(destination_file);
        exit(1);
    }

    if (fclose(destination_file) != 0) {
        perror("Failed to close destination file");
        exit(1);
    }

    printf("File copied successfully!\n");
    exit(0);
}