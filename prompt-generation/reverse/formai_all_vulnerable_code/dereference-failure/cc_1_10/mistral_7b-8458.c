//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_SIZE 256
#define FILE_NAME "ruins.txt"

char stack[MAX_SIZE];
int top = -1;

void die(char *msg) {
    printf("%s: %s\n", msg, FILE_NAME);
    exit(1);
}

int is_alphanumeric(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

void push(char c) {
    if (top >= MAX_SIZE - 1) die("Stack Overflow!");
    top++;
    stack[top] = c;
}

char pop() {
    if (top < 0) die("Stack Underflow!");
    top--;
    return stack[top + 1];
}

void read_file() {
    int fd = open(FILE_NAME, O_RDONLY);
    if (fd < 0) die("Could not open file!");

    char c;
    while ((c = read(fd, sizeof(char), 1)) > 0) {
        if (!is_alphanumeric(c)) continue;
        push(c);
    }

    close(fd);
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

void print_string(char *str) {
    printf("%s", str);
}

void process_line() {
    char line[MAX_SIZE];
    read(0, line, MAX_SIZE);

    reverse_string(line);
    print_string(line);
    printf(": ");

    read_file();

    char rev_line[MAX_SIZE];
    int i = 0;
    while (top >= 0) {
        rev_line[i++] = pop();
    }
    rev_line[i] = '\0';

    reverse_string(rev_line);
    print_string(rev_line);
    printf("\n");
}

int main() {
    read_file();
    process_line();

    return 0;
}

// In a post-apocalyptic world, the ancient ruins held the last remnants of human knowledge.
// In the heart of these ruins, there was a mysterious artifact, a text file named "ruins.txt"
// The artifact held the power to reverse the order of any text given to it, but only if the text
// was entered in the correct format. The format was a single line followed by the reversed version
// of the line, each line separated by a colon.

// This program, written in the ancient C language, was the key to unlocking the secrets of the artifact.
// It would read the input line by line, reverse the order of the characters in the line, and then compare it
// to the reversed version of the line stored in the artifact. If the two matched, the line was considered valid
// and would be printed out, along with its reversed version, for all to see.