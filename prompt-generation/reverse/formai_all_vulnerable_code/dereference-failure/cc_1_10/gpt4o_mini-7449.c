//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <time.h>

#define MAX_QUOTES 10
#define QUOTE_LENGTH 256

// Structure to hold the quotes
typedef struct {
    char quotes[MAX_QUOTES][QUOTE_LENGTH];
    int count;
} QuoteLibrary;

// Function to initialize the quote library
QuoteLibrary* create_quote_library() {
    QuoteLibrary* lib = (QuoteLibrary*)malloc(sizeof(QuoteLibrary));
    lib->count = 0;

    // Random quotes
    strcpy(lib->quotes[lib->count++], "To be or not to be, that is the question.");
    strcpy(lib->quotes[lib->count++], "The only thing we have to fear is fear itself.");
    strcpy(lib->quotes[lib->count++], "I think, therefore I am.");
    strcpy(lib->quotes[lib->count++], "In the middle of difficulty lies opportunity.");
    strcpy(lib->quotes[lib->count++], "Life is what happens when you're busy making other plans.");
    strcpy(lib->quotes[lib->count++], "The purpose of our lives is to be happy.");
    strcpy(lib->quotes[lib->count++], "Get busy living or get busy dying.");
    strcpy(lib->quotes[lib->count++], "You have within you right now, everything you need to deal with whatever the world can throw at you.");
    strcpy(lib->quotes[lib->count++], "Believe you can and you're halfway there.");
    strcpy(lib->quotes[lib->count++], "The best way to predict the future is to invent it.");

    return lib;
}

// Function to get a random quote
const char* get_random_quote(QuoteLibrary* lib) {
    if (lib->count == 0) return "No quotes available.";
    int index = rand() % lib->count;
    return lib->quotes[index];
}

// Function to free the quote library
void free_quote_library(QuoteLibrary* lib) {
    free(lib);
}

// Main function simulating a browser plugin
int main() {
    srand(time(0)); // Seed for randomness
    QuoteLibrary* lib = create_quote_library();

    // Simulating multiple calls as the browser would
    for (int i = 0; i < 5; i++) {
        const char* quote = get_random_quote(lib);
        printf("Random Quote: %s\n", quote);
    }

    free_quote_library(lib);
    return 0;
}