//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void file_surprise(char *filename) {
    int fd, len;
    char *buffer, temp;
    struct stat file_stat;
    int random_number;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    fstat(fd, &file_stat);
    buffer = (char *)malloc(file_stat.st_size + 1);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        close(fd);
        return;
    }

    len = read(fd, buffer, file_stat.st_size);
    if (len < 0) {
        perror("Error reading file");
        free(buffer);
        close(fd);
        return;
    }

    buffer[len] = '\0';

    random_number = rand() % len;
    for (int i = 0; i < random_number; i++) {
        temp = buffer[i];
        buffer[i] = buffer[i + random_number];
        buffer[i + random_number] = temp;
    }

    close(fd);

    fd = open(filename, O_WRONLY);
    if (fd < 0) {
        perror("Error opening file for writing");
        free(buffer);
        return;
    }

    write(fd, buffer, file_stat.st_size);
    close(fd);

    printf("Surprise! The contents of the file '%s' have been shuffled.\n", filename);

    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file_surprise(argv[1]);

    return 0;
}