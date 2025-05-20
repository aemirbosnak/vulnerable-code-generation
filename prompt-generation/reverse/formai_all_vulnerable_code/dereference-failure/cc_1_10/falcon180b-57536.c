//Falcon-180B DATASET v1.0 Category: Recursive ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char *string;
    int length;
} String;

String *create_string(char *str) {
    String *s = malloc(sizeof(String));
    s->string = strdup(str);
    s->length = strlen(str);
    return s;
}

int is_palindrome(String *s) {
    int i = 0;
    int j = s->length - 1;
    while (i < j) {
        if (tolower(s->string[i])!= tolower(s->string[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

void print_string(String *s) {
    printf("%s\n", s->string);
}

int main() {
    char input[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character
    String *s = create_string(input);
    if (is_palindrome(s)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
    print_string(s);
    free(s->string);
    free(s);
    return 0;
}