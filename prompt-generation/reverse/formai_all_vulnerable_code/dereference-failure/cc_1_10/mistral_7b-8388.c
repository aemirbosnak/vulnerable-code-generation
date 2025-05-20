//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 30

void print_line(int line_num) {
    int i;
    char line[WIDTH];

    memset(line, ' ', WIDTH);

    if (line_num == 1) {
        strncpy(line + 8, "YIPPEE!!", 7);
        strncpy(line + 17, "I JUST GOT", 9);
        strncpy(line + 27, "MY FIRST PAYCHECK!!!", 15);
    } else if (line_num > 1 && line_num < HEIGHT + 1) {
        for (i = 0; i < line_num - 1; i++) {
            line[i] = ' ';
            line[i + WIDTH] = ' ';
        }
        line[line_num - 1] = '>';
        line[line_num + WIDTH - 1] = '>';
    }

    write(STDOUT_FILENO, line, WIDTH + 1);
    write(STDOUT_FILENO, "\n", 1);
}

int main() {
    int i;
    time_t t;

    time(&t);
    srand(time(NULL));

    printf("\033[2J"); // Clear the terminal

    for (i = 1; i <= HEIGHT; i++) {
        print_line(i);
        usleep(rand() % 1000001 + 500000); // Random sleep between lines
    }

    sleep(3); // Wait for a while before exiting

    return 0;
}