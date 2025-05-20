//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_LINE_LEN 1024
#define MAX_BUF_SIZE (1024 * 1024)

int main() {
    char *line = NULL;
    size_t line_len = 0;
    size_t buf_len = 0;
    int fd = 0;
    int ret = 0;

    // Open the file in read-only mode
    fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening input file");
        return 1;
    }

    // Set up the buffer to store the line
    char *buf = (char *)mmap(NULL, MAX_BUF_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        perror("Error mapping input file");
        close(fd);
        return 1;
    }

    // Read lines from the file into the buffer
    while ((ret = read(fd, buf + buf_len, MAX_LINE_LEN)) > 0) {
        buf_len += ret;
        line_len = strcspn(buf, "\n");
        if (line_len > 0) {
            // Found a line, so allocate a new line buffer
            char *new_line = malloc(line_len + 1);
            if (new_line == NULL) {
                perror("Error allocating memory for line");
                munmap(buf, MAX_BUF_SIZE);
                close(fd);
                return 1;
            }

            // Copy the line into the new buffer
            strncpy(new_line, buf, line_len);
            new_line[line_len] = '\0';

            // Print the line
            printf("%s\n", new_line);

            // Advance the buffer pointer to the next line
            buf_len = line_len + 1;
            buf += line_len + 1;
        }
    }

    // Check for EOF
    if (ret == 0) {
        printf("End of file reached\n");
    }

    // Unmap the buffer
    munmap(buf, MAX_BUF_SIZE);

    // Close the file
    close(fd);

    return 0;
}