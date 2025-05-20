//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char *string;
    int length;
} String;

void initialize_string(String *string) {
    string->string = NULL;
    string->length = 0;
}

void set_string(String *string, char *value) {
    if (string->string!= NULL) {
        free(string->string);
    }

    string->string = strdup(value);
    string->length = strlen(string->string);
}

void print_string(String *string) {
    printf("String: %s\n", string->string);
    printf("Length: %d\n", string->length);
}

void reverse_string(String *string) {
    char *reversed = malloc(string->length + 1);

    int i = 0;
    int j = string->length - 1;

    while (i < j) {
        char temp = string->string[i];
        string->string[i] = string->string[j];
        string->string[j] = temp;

        i++;
        j--;
    }

    string->string = reversed;
}

void concatenate_strings(String *string1, String *string2) {
    char *concatenated = malloc(string1->length + string2->length + 1);

    strcpy(concatenated, string1->string);
    strcat(concatenated, string2->string);

    string1->string = concatenated;
    string1->length = strlen(string1->string);
}

void compare_strings(String *string1, String *string2) {
    if (strcmp(string1->string, string2->string) == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }
}

int main() {
    String string1, string2;

    initialize_string(&string1);
    initialize_string(&string2);

    set_string(&string1, "Hello");
    set_string(&string2, "World");

    print_string(&string1);
    print_string(&string2);

    concatenate_strings(&string1, &string2);

    print_string(&string1);

    reverse_string(&string1);

    print_string(&string1);

    compare_strings(&string1, &string2);

    return 0;
}