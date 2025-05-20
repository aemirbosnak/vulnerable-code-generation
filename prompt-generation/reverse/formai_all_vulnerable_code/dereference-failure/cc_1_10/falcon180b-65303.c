//Falcon-180B DATASET v1.0 Category: Error handling ; Style: realistic
/* C Error Handling Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/* Function to read a line from stdin */
char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t bytes_read;

    line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for line.\n");
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = getline(&line, &len, stdin))!= -1) {
        if (bytes_read >= len) {
            fprintf(stderr, "Error: Line is too long.\n");
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error: Failed to read line from stdin.\n");
        exit(EXIT_FAILURE);
    }

    return line;
}

/* Function to count the number of words in a line */
int count_words(char *line)
{
    int count = 0;
    char *word;

    word = strtok(line, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

/* Main function */
int main(void)
{
    char *line;
    int word_count;

    while (1) {
        printf("Enter a line: ");
        line = read_line();

        word_count = count_words(line);
        printf("The line contains %d words.\n", word_count);

        free(line);
    }

    return 0;
}

/* End of C Error Handling Example Program */