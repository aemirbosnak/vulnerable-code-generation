//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        close(input_fd);
        return 1;
    }

    char input_buffer[MAX_LINE];
    char *output_buffer = malloc(MAX_LINE * sizeof(char));

    while ((read(input_fd, input_buffer, MAX_LINE))!= 0) {
        int input_length = strlen(input_buffer);
        int output_length = 0;

        for (int i = 0; i < input_length; i++) {
            if (input_buffer[i]!= '\n') {
                output_buffer[output_length++] = input_buffer[i];
            }
        }

        output_buffer[output_length] = '\0';
        write(output_fd, output_buffer, output_length);
    }

    close(input_fd);
    close(output_fd);
    free(output_buffer);

    return 0;
}