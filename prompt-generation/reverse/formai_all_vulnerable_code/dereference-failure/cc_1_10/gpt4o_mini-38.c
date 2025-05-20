//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_STRING_LENGTH 256

typedef struct {
    char *data;
    size_t length;
} String;

String* createString(const char *input) {
    String *newString = malloc(sizeof(String));
    if (newString == NULL) {
        fprintf(stderr, "Error allocating memory for String structure: %s\n", strerror(errno));
        return NULL;
    }
    
    newString->length = strlen(input);
    newString->data = malloc(newString->length + 1); // +1 for the null-terminator
    if (newString->data == NULL) {
        fprintf(stderr, "Error allocating memory for string data: %s\n", strerror(errno));
        free(newString);
        return NULL;
    }
    
    strcpy(newString->data, input);
    return newString;
}

void releaseString(String *str) {
    if (str != NULL) {
        free(str->data);
        free(str);
    }
}

void copyString(String *dest, const String *src) {
    if (dest == NULL || src == NULL) {
        fprintf(stderr, "NULL parameter passed to copyString.\n");
        return;
    }
    
    dest->length = src->length;
    dest->data = realloc(dest->data, dest->length + 1);
    if (dest->data == NULL) {
        fprintf(stderr, "Error reallocating memory for string data: %s\n", strerror(errno));
        return;
    }
    
    strcpy(dest->data, src->data);
}

void printString(const String *str) {
    if (str == NULL || str->data == NULL) {
        fprintf(stderr, "String is NULL or empty.\n");
        return;
    }
    
    printf("String contents: %s\n", str->data);
}

int main() {
    const char *inputText = "Hello, World!";
    String *myString = createString(inputText);
    if (myString == NULL) {
        return EXIT_FAILURE;
    }
    
    printString(myString);
    
    // Let's try copying the string to another String instance
    String *anotherString = malloc(sizeof(String));
    if (anotherString == NULL) {
        fprintf(stderr, "Error allocating memory for another String structure: %s\n", strerror(errno));
        releaseString(myString);
        return EXIT_FAILURE;
    }
    
    anotherString->data = NULL; // Initializes to NULL; realloc will handle it
    copyString(anotherString, myString);
    printString(anotherString);
    
    // Let's modify the original string and see how it impacts the copied string
    strcpy(myString->data, "Goodbye, World!");
    printString(myString);
    printString(anotherString);  // Should remain unchanged

    // Clean up all allocated strings
    releaseString(myString);
    releaseString(anotherString);
    
    printf("Memory successfully released.\n");
    
    return EXIT_SUCCESS;
}