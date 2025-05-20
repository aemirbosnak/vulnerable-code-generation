//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_LINES 100
#define LINE_SIZE 256
#define TIME_SHIFT 1000

typedef struct {
    int line_num;
    char line[LINE_SIZE];
} line_t;

line_t *lines;
int lines_count = 0;
int current_time = 0;
int current_line = 0;

void setup() {
    int fd;
    char *filename = "input.txt";
    size_t size;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    size = lseek(fd, 0, SEEK_END);
    lines = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    lines_count = size / (sizeof(line_t));
}

void print_line() {
    printf("%d: %s\n", lines[current_line].line_num, lines[current_line].line);
}

void move_time(int offset) {
    int new_line = current_line;

    if ((current_time + offset) < 0) {
        printf("Time travel: Cannot go before the beginning\n");
        return;
    }

    if ((current_time + offset) >= lines_count * TIME_SHIFT) {
        printf("Time travel: Cannot go beyond the end\n");
        return;
    }

    current_time += offset;

    while (new_line < current_line) {
        if (current_time >= (new_line + 1) * TIME_SHIFT) {
            current_line = new_line + 1;
            break;
        }
        new_line++;
    }

    print_line();
}

int main() {
    setup();

    while (1) {
        print_line();
        move_time(1);
        usleep(100000); // Sleep for 100ms before the next iteration
    }

    munmap(lines, lines_count * sizeof(line_t));
    return 0;
}