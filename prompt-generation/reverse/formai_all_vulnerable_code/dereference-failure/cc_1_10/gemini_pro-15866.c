//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Let's define some macros to make our lives easier.
#define MAX_STRING_LENGTH 1024  // Just a random number, you can change it.
#define MAX_NUMBER_OF_STRINGS 100  // Again, a random number.

// And now, let's create a struct to store our strings.
typedef struct {
    char *string;  // The actual string.
    int length;  // The length of the string.
} String;

// And a function to create a new string.
String *create_string(char *string) {
    // Allocate memory for the new string.
    String *new_string = malloc(sizeof(String));

    // Copy the string into the new string.
    new_string->string = malloc(strlen(string) + 1);
    strcpy(new_string->string, string);

    // Set the length of the new string.
    new_string->length = strlen(string);

    // Return the new string.
    return new_string;
}

// And a function to free (destroy) a string.
void free_string(String *string) {
    // Free the memory allocated for the string.
    free(string->string);

    // Free the memory allocated for the string struct.
    free(string);
}

// And now, let's create an array of strings.
String *strings[MAX_NUMBER_OF_STRINGS];

// And a function to add a string to the array.
int add_string(String *string) {
    // Find the first empty slot in the array.
    int i;
    for (i = 0; i < MAX_NUMBER_OF_STRINGS; i++) {
        if (strings[i] == NULL) {
            break;
        }
    }

    // If we found an empty slot, add the string to it.
    if (i < MAX_NUMBER_OF_STRINGS) {
        strings[i] = string;
        return 0;
    }

    // Otherwise, return an error.
    else {
        return -1;
    }
}

// And a function to remove a string from the array.
int remove_string(String *string) {
    // Find the string in the array.
    int i;
    for (i = 0; i < MAX_NUMBER_OF_STRINGS; i++) {
        if (strings[i] == string) {
            break;
        }
    }

    // If we found the string, remove it from the array.
    if (i < MAX_NUMBER_OF_STRINGS) {
        strings[i] = NULL;
        return 0;
    }

    // Otherwise, return an error.
    else {
        return -1;
    }
}

// And now, let's write a main function to test our code.
int main(int argc, char *argv[]) {
    // Let's create a few strings.
    String *string1 = create_string("Hello, world!");
    String *string2 = create_string("This is a test.");
    String *string3 = create_string("I hope this works!");

    // Let's add the strings to the array.
    add_string(string1);
    add_string(string2);
    add_string(string3);

    // Let's print the strings.
    for (int i = 0; i < MAX_NUMBER_OF_STRINGS; i++) {
        if (strings[i] != NULL) {
            printf("%s\n", strings[i]->string);
        }
    }

    // Let's remove a string from the array.
    remove_string(string2);

    // Let's print the strings again.
    for (int i = 0; i < MAX_NUMBER_OF_STRINGS; i++) {
        if (strings[i] != NULL) {
            printf("%s\n", strings[i]->string);
        }
    }

    // Let's free the strings.
    free_string(string1);
    free_string(string2);
    free_string(string3);

    return 0;
}