//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define FONT_HEIGHT 8
#define FONT_WIDTH 5
#define MAX_LINE_LENGTH 100
#define MAX_TEXT_LENGTH 500

/* Function declarations */
void print_ascii_art(char* text);
char* get_font_path();
char** read_font(char* font_path);
int char_to_ascii_index(char c);
void print_line(char** font, char* line);

/* Program entry point */
int main() {
    char text[MAX_TEXT_LENGTH];
    printf("Enter text (max length %d):\n", MAX_TEXT_LENGTH);
    fgets(text, MAX_TEXT_LENGTH, stdin);
    print_ascii_art(text);
    return 0;
}

/* Prints the ASCII art for the given text */
void print_ascii_art(char* text) {
    // Get the font and calculate the number of lines
    char* font_path = get_font_path();
    char** font = read_font(font_path);
    int num_lines = strlen(text) * FONT_WIDTH;
    char* lines[num_lines];
    
    // Generate each line by iterating over each character of the text
    int line_index = 0;
    for(int i = 0; i < strlen(text) - 1; i++) {
        int ascii_index = char_to_ascii_index(text[i]);
        for(int j = 0; j < FONT_HEIGHT; j++) {
            char* line = malloc(FONT_WIDTH + 1);
            line[5] = '\0'; // Null-terminate the string
            for(int k = 0; k < FONT_WIDTH; k++) {
                line[k] = font[ascii_index][j*FONT_WIDTH + k];
            }
            lines[line_index++] = line;
        }
    }
    
    // Print each line and free memory
    for(int i = 0; i < num_lines; i++) {
        print_line(font, lines[i]);
        free(lines[i]);
    }
}

/* Returns the path to the font file */
char* get_font_path() {
    char* font_path = malloc(strlen("font.txt") + 1);
    strcpy(font_path, "font.txt");
    return font_path;
}

/* Reads the font file into a 2D array */
char** read_font(char* font_path) {
    FILE* font_file = fopen(font_path, "r");
    char** font = malloc(128 * sizeof(char*));
    
    // Read each line of the font file into the font array
    char line[MAX_LINE_LENGTH];
    for(int i = 0; i < 128; i++) {
        fgets(line, MAX_LINE_LENGTH, font_file);
        int line_length = strlen(line) - 1;
        font[i] = malloc(line_length + 1);
        strcpy(font[i], line);
    }
    
    fclose(font_file);
    return font;
}

/* Returns the ASCII index of the given character */
int char_to_ascii_index(char c) {
    if(c >= 'A' && c <= 'Z') {
        return c - 'A' + 65; // Capital letters start at ASCII 65
    } else if(c >= 'a' && c <= 'z') {
        return c - 'a' + 97; // Lowercase letters start at ASCII 97
    } else if(c >= '0' && c <= '9') {
        return c - '0' + 48; // Digits start at ASCII 48
    } else {
        return 32; // Return space for unrecognized characters
    }
}

/* Prints a single line of ASCII art */
void print_line(char** font, char* line) {
    for(int i = 0; i < strlen(line); i++) {
        int ascii_index = char_to_ascii_index(line[i]);
        printf("%s", font[ascii_index]);
    }
    printf("\n");
}