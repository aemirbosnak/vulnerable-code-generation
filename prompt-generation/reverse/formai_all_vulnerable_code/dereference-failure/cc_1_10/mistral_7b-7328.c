//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void reverse_string(char *str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void print_shady_characters(char *str) {
    int i;

    printf("The string contains the following shady characters:\n");
    for (i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) continue;
        switch (str[i]) {
            case '!': printf("A bang!\n"); break;
            case '?': printf("A query!\n"); break;
            case '.': printf("A period of suspicion.\n"); break;
            case ',': printf("A comma of concealment.\n"); break;
            case ';': printf("A semicolon of secrecy.\n"); break;
            case '-': printf("A hyphen of hidden truth.\n"); break;
            case '_': printf("An underscore of unknown motives.\n"); break;
            case '&': printf("An ampersand of alliance.\n"); break;
            case '|': printf("A vertical bar of vehemence.\n"); break;
            case '/': printf("A slash of subterfuge.\n"); break;
            case '\\': printf("A backslash of betrayal.\n"); break;
            case '(': printf("A left parenthesis of lurking danger.\n"); break;
            case ')': printf("A right parenthesis of hidden intentions.\n"); break;
            case '{': printf("A left brace of enigmatic complexities.\n"); break;
            case '}': printf("A right brace of concealed information.\n"); break;
            case '[': printf("A left bracket of covert plans.\n"); break;
            case ']': printf("A right bracket of disguised schemes.\n"); break;
            case '<': printf("A less-than sign of deception.\n"); break;
            case '>': printf("A greater-than sign of duplicity.\n"); break;
            case ' ': printf("A space of mystery.\n"); break;
            default: printf("An unknown character of intrigue.\n");
        }
    }
}

int main(int argc, char *argv[]) {
    char input_str[MAX_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    strcpy(input_str, argv[1]);

    printf("Sherlock Holmes here. You've given me a string:\n\"%s\"\n", input_str);

    printf("Let me examine it closely.\n");

    // Reverse the string for a hidden message
    reverse_string(input_str);

    printf("After reversing the string, I see:\n\"%s\"\n", input_str);

    // Print out any shady characters in the string
    print_shady_characters(input_str);

    printf("I see no obvious clues in this string, but I'll keep it on file for further investigation.\n");

    return 0;
}