//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BUF_SIZE 256
#define MAX_INPUT_SIZE 1024

typedef struct {
    char data[MAX_INPUT_SIZE];
    size_t len;
} input_t;

input_t input;

void sanitize_input(input_t *input) {
    size_t i, j;
    if (input->len > MAX_INPUT_SIZE) {
        fprintf(stderr, "Input size is too large\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < input->len; i++) {
        if ((input->data[i] >= 'A' && input->data[i] <= 'Z') ||
            (input->data[i] >= 'a' && input->data[i] <= 'z') ||
            (input->data[i] >= '0' && input->data[i] <= '9') ||
            input->data[i] == ' ' || input->data[i] == '\t') {
            continue;
        }
        for (j = i + 1; j <= input->len; j++) {
            if (input->data[i] == input->data[j]) {
                fprintf(stderr, "Input contains duplicate characters\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    input->data[input->len] = '\0';
}

void read_input(input_t *input) {
    char *buf;
    size_t len;

    buf = mmap(NULL, BUF_SIZE, PROT_READ, MAP_PRIVATE, 0, 0);
    if (buf == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter input: ");
    fgets(buf, BUF_SIZE, stdin);
    len = strlen(buf);
    buf[len - 1] = '\0';

    if (len > MAX_INPUT_SIZE - 1) {
        fprintf(stderr, "Input size is too large\n");
        munmap(buf, BUF_SIZE);
        exit(EXIT_FAILURE);
    }

    input->len = len;
    strncpy(input->data, buf, len + 1);

    munmap(buf, BUF_SIZE);

    sanitize_input(input);
}

int main() {
    int fd;
    input_t input;

    read_input(&input);

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    write(fd, input.data, input.len);
    close(fd);

    printf("Input sanitized and written to output.txt\n");

    return EXIT_SUCCESS;
}