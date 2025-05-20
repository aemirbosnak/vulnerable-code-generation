//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 50
#define MAX_ROWS 6

void printChar(char c, FILE *fout);
void printText(char **text, int num_rows, int num_chars_per_row, FILE *fout);

int main(int argc, char *argv[]) {

    char input_str[MAX_CHARS];
    char **output_str = (char **) malloc(MAX_ROWS * sizeof(char *));
    int str_len, row_len[MAX_ROWS] = {0}, max_len = 0;

    printf("Enter your text (up to 50 characters):\n");
    fgets(input_str, MAX_CHARS, stdin);
    str_len = strlen(input_str);

    srand(time(NULL)); // seed for random number generator

    // generate ASCII art, randomly splitting the characters between rows
    for (int i = 0; i < str_len; i++) {
        int row = rand() % MAX_ROWS;
        if (row_len[row] < (MAX_CHARS / MAX_ROWS)) {
            if (!(output_str[row])) {
                output_str[row] = (char *) malloc((MAX_CHARS / MAX_ROWS) * sizeof(char));
            }
            output_str[row][row_len[row]] = input_str[i];
            row_len[row]++;
            if (row_len[row] > max_len) { max_len = row_len[row]; }
        }
    }

    // add spacing to ensure all rows are same length
    for (int i = 0; i < MAX_ROWS; i++) {
        if (output_str[i]) {
            int spaces_to_add = max_len - row_len[i];
            for (int j = 0; j < spaces_to_add; j++) {
                output_str[i][row_len[i] + j] = ' ';
            }
            row_len[i] += spaces_to_add;
        }
    }

    // print out ASCII art
    FILE *fout = fopen("ascii_art.txt", "w");
    printText(output_str, MAX_ROWS, max_len, fout);
    fclose(fout);

    // free memory
    for (int i = 0; i < MAX_ROWS; i++) {
        if (output_str[i]) { free(output_str[i]); }
    }
    free(output_str);

    return 0;
}

// print a single character to file
void printChar(char c, FILE *fout) {
    for (int i = 0; i < 8; i++) {
        if ((c >> (7 - i)) & 1) {
            fprintf(fout, "#");
        } else {
            fprintf(fout, " ");
        }
    }
    fprintf(fout, "\n");
}

// print a block of text to file (each character is converted to ASCII art)
void printText(char **text, int num_rows, int num_chars_per_row, FILE *fout) {
    for (int i = 0; i < num_rows; i++) {
        if (text[i]) { // row exists
            for (int j = 0; j < num_chars_per_row; j++) {
                if (j < strlen(text[i])) {
                    printChar(text[i][j], fout);
                } else {
                    printChar(' ', fout);
                }
            }
        } else { // row does not exist
            for (int j = 0; j < num_chars_per_row; j++) {
                printChar(' ', fout);
            }
        }
    }
}