//MISTRAL-7B DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char fileName[MAX_FILE_NAME_LENGTH];
    strcpy(fileName, argv[1]);

    int fd = open(fileName, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    int lines = 0;

    while (read(fd, buffer, MAX_LINE_LENGTH) > 0) {
        printf("%s", buffer);
        if (strchr(buffer, '\n') != NULL) {
            lines++;
        }
    }

    close(fd);

    printf("\nNumber of lines in file: %d\n", lines);

    char tempFileName[MAX_FILE_NAME_LENGTH];
    sprintf(tempFileName, "%s.temp", fileName);

    fd = open(tempFileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    char *token;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fd = dup2(0, STDIN_FILENO);

    while ((read = getline(&line, &len, stdin)) > 0) {
        token = strtok(line, "\n");
        if (token != NULL) {
            write(fd, token, strlen(token) + 1);
        }
    }

    free(line);

    close(fd);

    rename(tempFileName, fileName);

    unlink(tempFileName);

    return 0;
}