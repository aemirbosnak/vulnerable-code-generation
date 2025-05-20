//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_STRINGS 5
#define STRING_LENGTH 100

const char *kStrings[] = {
    "apple",
    "banana",
    "cherry",
    "date",
    "elderberry"
};

char **gStrings;
int gSize = 0;

void printStrings(char **strings, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", strings[i]);
    }
}

int findStringIndex(char **strings, int size, const char *stringToFind) {
    for (int i = 0; i < size; i++) {
        if (strcmp(strings[i], stringToFind) == 0) {
            return i;
        }
    }

    return -1;
}

void swapStrings(char **strings1, char **strings2, int size) {
    char *temp = strings1[size];
    strings1[size] = strings2[size];
    strings2[size] = temp;
}

void reverseString(char *string, int length) {
    for (int i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
}

void deleteString(char **strings, int *size, const char *stringToDelete) {
    if (*size < 1) {
        return;
    }

    int index = findStringIndex(strings, *size, stringToDelete);

    if (index == -1) {
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        strings[i] = strings[i + 1];
    }

    free(strings[*size - 1]);
    *size -= 1;
}

int main() {
    gStrings = (char **)malloc(NUM_STRINGS * sizeof(char *));

    for (int i = 0; i < NUM_STRINGS; i++) {
        gStrings[i] = (char *)malloc(STRING_LENGTH * sizeof(char));
        printf("Enter string %d: ", i + 1);
        scanf("%s", gStrings[i]);
        gSize++;
    }

    printf("\nStrings in the array:\n");
    printStrings(gStrings, gSize);

    const char *searchString = "cherry";
    int index = findStringIndex(gStrings, gSize, searchString);

    if (index != -1) {
        printf("\nString '%s' found at index %d.\n", searchString, index);
    } else {
        printf("\nString '%s' not found.\n", searchString);
    }

    const char *strings1 = "hello";
    const char *strings2 = "world";
    printStrings(gStrings, gSize);
    swapStrings(gStrings + index, gStrings + 0, gSize);
    printStrings(gStrings, gSize);

    reverseString(gStrings[2], strlen(gStrings[2]));
    printStrings(gStrings, gSize);

    const char *stringToDelete = "date";
    deleteString(gStrings, &gSize, stringToDelete);
    printStrings(gStrings, gSize);

    for (int i = 0; i < gSize; i++) {
        free(gStrings[i]);
    }
    free(gStrings);

    return 0;
}