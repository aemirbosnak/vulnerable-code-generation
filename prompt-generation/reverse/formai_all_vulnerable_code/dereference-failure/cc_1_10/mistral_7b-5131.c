//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_INPUT 256
#define TMP_FILE "/tmp/sanitized_input.txt"

void sanitize_input(char *input) {
    int i, len;
    char *filtered_input;

    len = strlen(input);

    filtered_input = malloc(len + 1);
    strncpy(filtered_input, input, len + 1);

    for (i = 0; i < len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            filtered_input[i] = input[i];
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            filtered_input[i] = input[i];
        } else if (input[i] == ' ' || input[i] == '\t') {
            filtered_input[i] = input[i];
        } else {
            filtered_input[i] = '\0';
            break;
        }
    }

    filtered_input[i] = '\0';

    write(STDOUT_FILENO, filtered_input, strlen(filtered_input));

    unlink(TMP_FILE);

    free(filtered_input);
}

int main() {
    char input[MAX_INPUT];
    int fd;

    printf("Enter input: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0';

    sanitize_input(input);

    fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, input, strlen(input));
    close(fd);

    system("cat /tmp/sanitized_input.txt");

    return 0;
}