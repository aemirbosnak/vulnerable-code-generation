//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_NUMBER_OF_STRINGS 1000

typedef struct {
    char *string;
    int length;
} String;

int main() {
    int number_of_strings, i, j;
    String *strings;

    printf("Enter the number of strings: ");
    scanf("%d", &number_of_strings);

    strings = (String *) malloc(number_of_strings * sizeof(String));

    for (i = 0; i < number_of_strings; i++) {
        strings[i].string = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
        printf("Enter string %d: ", i+1);
        scanf("%s", strings[i].string);
        strings[i].length = strlen(strings[i].string);
    }

    for (i = 0; i < number_of_strings - 1; i++) {
        for (j = i + 1; j < number_of_strings; j++) {
            if (strings[i].length > strings[j].length) {
                String temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }

    for (i = 0; i < number_of_strings; i++) {
        printf("String %d: %s\n", i+1, strings[i].string);
        printf("Length: %d\n", strings[i].length);
        printf("\n");
    }

    for (i = 0; i < number_of_strings; i++) {
        free(strings[i].string);
    }

    free(strings);

    return 0;
}