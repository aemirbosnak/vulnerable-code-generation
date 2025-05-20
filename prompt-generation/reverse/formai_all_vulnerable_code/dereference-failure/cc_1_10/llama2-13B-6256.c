//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAGIC_WORD "MAGICAL_WORD"

int main() {
    char line[MAX_LINE_LENGTH];
    char magic_word[strlen(MAGIC_WORD)];
    int count = 0;

    // Read input from the user
    printf("Enter a line of text: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Check if the user entered the magic word
    strcpy(magic_word, line);
    if (strcmp(magic_word, MAGIC_WORD) == 0) {
        count++;
        printf("You entered the magic word %s! You have %d points.\n", MAGIC_WORD, count);
    }

    // Add some magic to the line
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == 'a') {
            line[i] = 'A';
        } else if (line[i] == 'e') {
            line[i] = 'E';
        } else if (line[i] == 'o') {
            line[i] = 'O';
        }
    }

    // Print the modified line
    printf("Your line of text is now: %s\n", line);

    // Get the user to enter another line
    printf("Enter another line of text: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Repeat the process until the user quits
    while (1) {
        count++;
        printf("You have %d points.\n", count);
    }

    return 0;
}