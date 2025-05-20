//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINELEN 80
#define NUM_LINES 10

char *lines[NUM_LINES];

void setup() {
    int i;
    for (i = 0; i < NUM_LINES; i++) {
        lines[i] = malloc(LINELEN * sizeof(char));
        int j;
        for (j = 0; j < LINELEN; j++) {
            lines[i][j] = 'x' + rand() % 26;
        }
    }
}

void print_line(int line_num) {
    printf("\033[%d;1H", line_num + 1);
    printf("%s\n", lines[line_num]);
}

void test(int lines_to_type) {
    int i;
    clock_t start = clock();

    for (i = 0; i < lines_to_type; i++) {
        int line_num = rand() % NUM_LINES;
        print_line(line_num);
        fflush(stdout);
        usleep(500000); // Wait for half a second to see the line before typing the next one
    }

    clock_t end = clock();
    double elapsed_secs = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nYou typed %d lines in %.2fs.\n", lines_to_type, elapsed_secs);
}

int main() {
    srand(time(NULL));
    setup();

    int lines_to_type;
    printf("How many lines would you like to type? ");
    scanf("%d", &lines_to_type);

    test(lines_to_type);

    int i;
    for (i = 0; i < NUM_LINES; i++) {
        free(lines[i]);
    }

    return 0;
}