//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1024
#define ARRAY_SIZE 10000

void reverseString(char *str, int length) {
    int i = 0, j = length - 1;
    char temp;

    while (i < length / 2) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main(void) {
    char randomString[MAX_STRING_LENGTH];
    char *magicString = (char *) calloc(ARRAY_SIZE, sizeof(char));

    if (!magicString) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    srand(time(NULL));

    printf("Enter a random string (up to %d characters): ", MAX_STRING_LENGTH);
    fgets(randomString, MAX_STRING_LENGTH, stdin);
    reverseString(randomString, strlen(randomString));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        magicString[i] = rand() % 256;
        if (i % 10 == 0)
            magicString[i] = randomString[i % strlen(randomString)];
    }

    printf("\nRandom String: %s", randomString);
    printf("\nMagic String: ");

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%c", magicString[i]);
    }

    printf("\n");

    free(magicString);

    return 0;
}