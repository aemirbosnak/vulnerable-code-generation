//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);

    strcpy(reversed, str);
    for (int i = 0; i < length / 2; i++) {
        char temp = reversed[i];
        reversed[i] = reversed[length - i - 1];
        reversed[length - i - 1] = temp;
    }

    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

void replaceSubstring(char* str, char* oldSub, char* newSub) {
    int length = strlen(str);
    char* modified = malloc(length + 1);

    strcpy(modified, str);
    int oldSubLength = strlen(oldSub);
    int newSubLength = strlen(newSub);

    int index = 0;
    while ((index = strstr(modified, oldSub))!= NULL) {
        strncpy(index, newSub, newSubLength);
        index += newSubLength;
        length -= oldSubLength;
        length += newSubLength;
        modified = realloc(modified, length + 1);
    }

    printf("Modified string: %s\n", modified);
    free(modified);
}

int main() {
    char* str = "Hello, world!";
    printf("Original string: %s\n", str);

    reverseString(str);
    str = "Programming is fun!";
    replaceSubstring(str, "fun", "amazing");

    return 0;
}