//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

struct line {
    char *text;
    int length;
};

struct line lines[MAX_NUM_LINES];
int num_lines = 0;

void add_line(char *line_text) {
    if (num_lines >= MAX_NUM_LINES) {
        printf("Error: Too many lines\n");
        exit(1);
    }
    lines[num_lines].text = malloc(strlen(line_text) + 1);
    strcpy(lines[num_lines].text, line_text);
    lines[num_lines].length = strlen(line_text);
    num_lines++;
}

int get_checksum(char *line_text) {
    int sum = 0;
    for (int i = 0; i < strlen(line_text); i++) {
        if (isdigit(line_text[i])) {
            sum += line_text[i] - '0';
        }
    }
    return sum;
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char *line_text;

    printf("Enter lines of text (type 'done' when finished):\n");

    while (fgets(input_buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (strcmp(input_buffer, "done") == 0) {
            break;
        }
        line_text = strtok(input_buffer, "\n");
        add_line(line_text);
    }

    printf("Enter a number to calculate the checksum for:\n");
    scanf("%d", &num_lines);

    for (int i = 0; i < num_lines; i++) {
        line_text = lines[i].text;
        int checksum = get_checksum(line_text);
        printf("Checksum for line %d: %d\n", i + 1, checksum);
    }

    return 0;
}