//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void to_uppercase(char *str);
void to_lowercase(char *str);
void reverse_string(char *str);
void find_and_replace(char *str, const char *old_word, const char *new_word);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return 1;
    }

    char *operation = argv[1];
    char *input_string = argv[2];
    char *extra_param = argv[3];

    printf("Original Input: %s\n", input_string);

    if (strcmp(operation, "uppercase") == 0) {
        to_uppercase(input_string);
        printf("Uppercased: %s\n", input_string);
    } else if (strcmp(operation, "lowercase") == 0) {
        to_lowercase(input_string);
        printf("Lowercased: %s\n", input_string);
    } else if (strcmp(operation, "reverse") == 0) {
        reverse_string(input_string);
        printf("Reversed: %s\n", input_string);
    } else if (strcmp(operation, "replace") == 0) {
        find_and_replace(input_string, argv[2], argv[3]);
        printf("Replaced: %s\n", input_string);
    } else {
        printf("Unknown operation: %s\n", operation);
        print_usage(argv[0]);
        return 1;
    }

    return 0;
}

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void reverse_string(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void find_and_replace(char *str, const char *old_word, const char *new_word) {
    char buffer[1024];
    char *pos;
    int index = 0;
    int old_word_len = strlen(old_word);
    int new_word_len = strlen(new_word);

    while ((pos = strstr(str, old_word)) != NULL) {
        strcpy(buffer + index, str);
        index += pos - str;
        strcpy(buffer + index, new_word);
        index += new_word_len;
        str += pos - str + old_word_len;
    }
    strcpy(buffer + index, str);
    strcpy(str, buffer);
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <operation> <string> <params>\n", prog_name);
    printf("Operations:\n");
    printf("  uppercase         Convert string to uppercase\n");
    printf("  lowercase         Convert string to lowercase\n");
    printf("  reverse           Reverse the string\n");
    printf("  replace <old> <new>  Replace occurrences of old word with new word\n");
}