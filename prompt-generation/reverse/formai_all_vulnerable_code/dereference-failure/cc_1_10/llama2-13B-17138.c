//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_LINE_LEN 1024
#define MAX_BUF_LEN 4096

struct line {
    char *text;
    size_t len;
};

int main() {
    char *buf = malloc(MAX_BUF_LEN);
    size_t buf_len = 0;
    size_t line_len = 0;
    struct line *lines = NULL;

    while (1) {
        // Read a line from the standard input
        printf("> ");
        fgets(buf + buf_len, MAX_LINE_LEN - buf_len, stdin);
        line_len = strlen(buf + buf_len);
        buf_len += line_len;

        // Check if the line is empty or reaches the maximum length
        if (line_len == 0 || buf_len >= MAX_BUF_LEN) {
            break;
        }

        // Split the line into words and store them in the line structure
        char *word = strtok(buf + buf_len, " ");
        while (word != NULL && line_len < MAX_LINE_LEN) {
            lines = realloc(lines, (lines->len + 1) * sizeof(struct line));
            lines[lines->len].text = word;
            lines[lines->len].len = strlen(word);
            word = strtok(NULL, " ");
            line_len += lines[lines->len].len;
            lines->len++;
        }

        // Print the current line and reset the line buffer
        if (line_len > 0) {
            printf("%s\n", lines->text);
            lines->text = NULL;
            line_len = 0;
        }
    }

    // Free the memory allocated for the line buffer and the lines array
    free(buf);
    free(lines);

    return 0;
}