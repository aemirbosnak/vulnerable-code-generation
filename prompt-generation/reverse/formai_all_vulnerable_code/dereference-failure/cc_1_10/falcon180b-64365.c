//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000000

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH * sizeof(char));
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF && i < MAX_LINE_LENGTH) {
        if (!isspace(ch)) {
            line[i++] = ch;
        }
    }

    line[i] = '\0';
    return line;
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void write_file(FILE *file, char *str) {
    fprintf(file, "%s\n", str);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    char *line;
    int num_lines = 0;

    while ((line = read_line(input_file))!= NULL) {
        reverse_string(line);
        write_file(output_file, line);
        num_lines++;

        if (num_lines >= MAX_NUM_LINES) {
            printf("Reached maximum number of lines.\n");
            break;
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}