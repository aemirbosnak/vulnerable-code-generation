//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024
#define MAX_ARRAY_SIZE 100

void printDynamic(const char* message) {
    printf("[%s] ", message);
    if (strlen(message) > 10) {
        printf("(%.2f seconds ago)", (float)difftime(time(NULL), strtok(message, " ")));
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Generate a random string
    char* str = malloc(rand() % MAX_STRING_LENGTH + 1);
    for (int i = 0; i < rand() % MAX_STRING_LENGTH; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[rand() % MAX_STRING_LENGTH] = '\0';

    // Generate an array of integers
    int arr[MAX_ARRAY_SIZE];
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Print the array in a dynamic style
    printf("Array: ");
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n");

    // Print the random string in a dynamic style
    printDynamic(str);

    // Free memory
    free(str);

    return 0;
}