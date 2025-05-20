//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>

#define LINE_LENGTH 80
#define NUM_LINES 10
#define MAX_CHARS 8192

void print_line(char *line) {
    printf("\033[1;1H"); // move cursor to the home position
    printf("\033[J"); // clear the screen
    printf("%s\n\n", line);
    fflush(stdout);
}

void generate_text(char *text, int length) {
    int i;
    char c;

    for (i = 0; i < length; i++) {
        c = rand() % 26 + 'a';
        text[i] = c;
    }
    text[length] = '\0';
}

void save_text_to_file(char *filename, char *text) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, text, strlen(text));
    close(fd);
}

void read_text_from_file(char *filename, char *text) {
    int fd = open(filename, O_RDONLY);
    ssize_t n;

    while ((n = read(fd, text, MAX_CHARS)) > 0) {
        text += n;
    }

    close(fd);
}

int main() {
    int i, j, k, l, m, n, o;
    clock_t start, end;
    double elapsed_time;
    char lines[NUM_LINES][LINE_LENGTH];
    char *text;
    char filename[50];

    srand(time(NULL));

    for (i = 0; i < NUM_LINES; i++) {
        generate_text(lines[i], LINE_LENGTH);
        save_text_to_file(filename, lines[i]);
    }

    start = clock();

    for (i = 0; i < NUM_LINES; i++) {
        read_text_from_file(filename, lines[i]);
        print_line(lines[i]);

        for (j = 0; j < strlen(lines[i]); j++) {
            usleep(500000 / 20); // wait for 25ms before printing the next character
            printf("%c", lines[i][j]);
            fflush(stdout);

            for (k = 0; isatty(STDIN_FILENO) && k < 5; k++) {
                usleep(500000); // wait for 500ms for user input
                getchar();
            }
        }

        printf("\n");
    }

    end = clock();
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Total elapsed time: %.2f seconds\n", elapsed_time);

    for (i = 0; i < NUM_LINES; i++) {
        unlink(filename);
    }

    return 0;
}