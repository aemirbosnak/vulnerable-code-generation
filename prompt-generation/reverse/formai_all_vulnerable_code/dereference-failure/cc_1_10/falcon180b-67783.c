//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *text;
    int length;
} String;

String *create_string(const char *text) {
    String *string = malloc(sizeof(String));
    string->text = strdup(text);
    string->length = strlen(text);
    return string;
}

void destroy_string(String *string) {
    free(string->text);
    free(string);
}

void reverse_string(String *string) {
    char *start = string->text;
    char *end = string->text + string->length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char input[1000];
    String *original_string;
    String *reversed_string;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    original_string = create_string(input);
    reversed_string = create_string(input);

    reverse_string(reversed_string);

    printf("Original string: %s\n", original_string->text);
    printf("Reversed string: %s\n", reversed_string->text);

    destroy_string(original_string);
    destroy_string(reversed_string);

    return 0;
}