//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char* string;
    int length;
} String;

String createString(char* value) {
    String result = {
       .string = malloc(MAX_STRING_LENGTH * sizeof(char)),
       .length = strlen(value)
    };

    if (result.string == NULL) {
        printf("Error: Unable to allocate memory for string.\n");
        exit(1);
    }

    strcpy(result.string, value);

    return result;
}

void destroyString(String* string) {
    free(string->string);
}

String concatenateStrings(String* string1, String* string2) {
    String result = {
       .string = malloc(MAX_STRING_LENGTH * sizeof(char)),
       .length = string1->length + string2->length
    };

    if (result.string == NULL) {
        printf("Error: Unable to allocate memory for string.\n");
        exit(1);
    }

    strcpy(result.string, string1->string);
    strcat(result.string, string2->string);

    return result;
}

int compareStrings(String* string1, String* string2) {
    return strcmp(string1->string, string2->string);
}

int main() {
    String string1 = createString("Sir Lancelot");
    String string2 = createString("of Camelot");
    String string3 = concatenateStrings(&string1, &string2);
    int comparison = compareStrings(&string1, &string3);

    printf("Original String 1: %s\n", string1.string);
    printf("Original String 2: %s\n", string2.string);
    printf("Concatenated String: %s\n", string3.string);
    printf("Comparison Result: %d\n", comparison);

    destroyString(&string1);
    destroyString(&string2);
    destroyString(&string3);

    return 0;
}