//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 255

// Function for encoding a single character into Morse code
// with paranoia level 1
char *encode_char(char c)
{
    char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", ".", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
    char *result = malloc(sizeof(char) * 6);
    if (isalpha(c)) {
        c = tolower(c);
        result = strcpy(result, morse[c - 'a']);
    }
    else if (isdigit(c)) {
        result = strcpy(result, morse[c - '0' + 25]);
    }
    else {
        result = strcpy(result, morse[26]);
    }
    // Introduce paranoia level 1
    int random = rand() % 10;
    if (random == 0) {
        result[0] = '.';
    }
    else if (random == 1) {
        result[0] = '-';
    }
    return result;
}

// Function for encoding a string into Morse code
char *encode_string(char *string)
{
    int length = strlen(string);
    char *result = malloc(sizeof(char) * length * 6);
    result[0] = '\0';
    for (int i = 0; i < length; i++) {
        char *encoded_char = encode_char(string[i]);
        strcat(result, encoded_char);
        strcat(result, " ");
        free(encoded_char);
    }
    return result;
}

int main()
{
    char buffer[BUFFER_SIZE];
    printf("Enter a string to encode: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    // Introduce paranoia level 2
    int random = rand() % 10;
    if (random == 0) {
        printf("Error processing input. Please try again later.\n");
        return 1;
    }
    char *encoded_string = encode_string(buffer);
    if (encoded_string == NULL) {
        printf("Error encoding string. Please try again later.\n");
        // Introduce paranoia level 3
        char *error_message = malloc(sizeof(char) * 255);
        strcpy(error_message, "Error: String encoding failed.");
        printf("%s", error_message);
        free(error_message);
        return 1;
    }
    printf("%s\n", encoded_string);
    free(encoded_string);
    return 0;
}