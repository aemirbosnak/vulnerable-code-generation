//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char *string;
    int length;
} String;

String *create_string(char *value) {
    String *new_string = malloc(sizeof(String));
    new_string->string = strdup(value);
    new_string->length = strlen(value);
    return new_string;
}

void print_string(String *string) {
    printf("%s\n", string->string);
}

String *concat_strings(String *str1, String *str2) {
    char *new_string = malloc((strlen(str1->string) + strlen(str2->string)) * sizeof(char));
    strcat(new_string, str1->string);
    strcat(new_string, str2->string);
    String *new_str = malloc(sizeof(String));
    new_str->string = new_string;
    new_str->length = strlen(new_string);
    return new_str;
}

String *reverse_string(String *string) {
    char *new_string = malloc(string->length * sizeof(char));
    for (int i = string->length - 1; i >= 0; i--) {
        new_string[i] = string->string[i];
    }
    String *new_str = malloc(sizeof(String));
    new_str->string = new_string;
    new_str->length = strlen(new_string);
    return new_str;
}

int main() {
    String *string1 = create_string("Hello, World!");
    String *string2 = create_string("Alan Turing");
    String *new_string = concat_strings(string1, string2);
    print_string(new_string);
    String *reversed_string = reverse_string(new_string);
    print_string(reversed_string);
    free(string1->string);
    free(string1);
    free(string2->string);
    free(string2);
    free(new_string->string);
    free(new_string);
    free(reversed_string->string);
    free(reversed_string);
    return 0;
}