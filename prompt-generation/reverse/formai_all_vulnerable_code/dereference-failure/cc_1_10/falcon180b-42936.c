//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum number of elements in the array
#define MAX_STRING_SIZE 100 // Maximum length of a string element

typedef struct {
    char *data; // Pointer to the string data
    int length; // Length of the string
} String;

int compareStrings(const void *a, const void *b) {
    String stringA = *(String*)a;
    String stringB = *(String*)b;
    return strcmp(stringA.data, stringB.data);
}

void printStrings(String *strings, int numStrings) {
    for (int i = 0; i < numStrings; i++) {
        printf("%s\n", strings[i].data);
    }
}

int main() {
    int numStrings;
    String *strings;
    char input[MAX_STRING_SIZE];

    // Get the number of strings from the user
    printf("Enter the number of strings: ");
    scanf("%d", &numStrings);

    // Allocate memory for the strings
    strings = (String*)malloc(numStrings * sizeof(String));

    // Get the strings from the user
    for (int i = 0; i < numStrings; i++) {
        printf("Enter string %d: ", i+1);
        scanf("%s", input);
        strings[i].data = strdup(input);
        strings[i].length = strlen(strings[i].data);
    }

    // Sort the strings
    qsort(strings, numStrings, sizeof(String), compareStrings);

    // Print the sorted strings
    printf("Sorted strings:\n");
    printStrings(strings, numStrings);

    // Free the memory allocated for the strings
    for (int i = 0; i < numStrings; i++) {
        free(strings[i].data);
    }
    free(strings);

    return 0;
}