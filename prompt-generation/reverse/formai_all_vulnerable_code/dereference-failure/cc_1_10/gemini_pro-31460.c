//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int random_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to generate a random character
char random_char() {
    return 'a' + (rand() % 26);
}

// Function to generate a random string of length n
char* random_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = random_char();
    }
    str[n] = '\0';
    return str;
}

// Function to recursively generate a list of n random strings
char** random_list(int n) {
    if (n == 0) {
        return NULL;
    } else {
        char** list = malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            list[i] = random_string(random_range(1, 10));
        }
        list[n - 1] = NULL;
        return list;
    }
}

// Function to print a list of strings
void print_list(char** list) {
    if (list == NULL) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; list[i] != NULL; i++) {
            printf("%s, ", list[i]);
        }
        printf("\b\b]\n");
    }
}

// Function to free a list of strings
void free_list(char** list) {
    if (list == NULL) {
        return;
    } else {
        for (int i = 0; list[i] != NULL; i++) {
            free(list[i]);
        }
        free(list);
    }
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random list of 10 strings
    char** list = random_list(10);

    // Print the list
    print_list(list);

    // Free the list
    free_list(list);

    return 0;
}