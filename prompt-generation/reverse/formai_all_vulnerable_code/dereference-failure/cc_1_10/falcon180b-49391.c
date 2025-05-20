//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

/* Function to split a string into tokens */
void split(char* str, char delimiter, char** tokens) {
    char* token = strtok(str, delimiter);
    int count = 0;

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }

    tokens[count] = NULL;
}

/* Function to parse a line of text */
void parse_line(char* line, char* name, char* email, char* phone) {
    char* tokens[3];
    int i = 0;

    /* Split line into tokens */
    split(line, ',', tokens);

    /* Extract name */
    if (tokens[0]!= NULL && tokens[0][0]!= '\0') {
        strcpy(name, tokens[0]);
    }

    /* Extract email */
    if (tokens[1]!= NULL && tokens[1][0]!= '\0') {
        strcpy(email, tokens[1]);
    }

    /* Extract phone number */
    if (tokens[2]!= NULL && tokens[2][0]!= '\0') {
        strcpy(phone, tokens[2]);
    }
}

/* Function to read a file and parse its contents */
void parse_file(FILE* file, void (*parse_line_func)(char*, char*, char*, char*)) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        parse_line_func(line, "", "", "");
    }
}

/* Main function */
int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    parse_file(file, parse_line);

    fclose(file);

    return 0;
}