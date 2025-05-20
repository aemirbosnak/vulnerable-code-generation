//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 1048576

typedef struct line_tag {
    char str[MAX_LINE_LENGTH];
    struct line_tag *next;
} line_t;

bool file_exists(char *filename) {
    struct stat st;
    return stat(filename, &st) == 0;
}

void print_lines_reverse(line_t *head) {
    if (head == NULL) return;

    print_lines_reverse(head->next);
    printf("%s\n", head->str);
}

void read_file_into_lines(char *filename, line_t **head) {
    int fd = open(filename, O_RDONLY);
    char buffer[MAX_LINE_LENGTH];
    line_t *current, *new_line;

    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    current = *head;
    while (fgets(buffer, MAX_LINE_LENGTH, fd) != NULL) {
        new_line = malloc(sizeof(line_t));
        strcpy(new_line->str, buffer);
        new_line->next = current;
        current = new_line;
        if (current == *head) *head = current;
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    line_t *head = NULL;

    if (file_exists(argv[1])) {
        read_file_into_lines(argv[1], &head);
        print_lines_reverse(head);

        line_t *current = head;
        while (current != NULL) {
            line_t *next = current->next;
            free(current);
            current = next;
        }
    } else {
        printf("File does not exist\n");
    }

    return EXIT_SUCCESS;
}