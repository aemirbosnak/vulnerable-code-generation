//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
// Dr. Watson's Spell Checker, at your service!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Sherlock's word list, the bastion of correct spelling
const char* dictionary[] = {
    "aberration", "abrogate", "accede", "acclaim", "accolade",
    "accretion", "acquiesce", "acquit", "acrimony", "adamant",
    // ... and so on, Watson. The list is vast indeed!
};

// The corpus of text to be inspected for spelling errors
char* corpus = "The dog barked at the mailman, its bark as loud as a thunderclap.";

// Watson's keen eye for discrepancies
bool is_misspelled(const char* word) {
    // Go through the dictionary, my dear Watson
    for (int i = 0; i < sizeof(dictionary) / sizeof(const char*); i++) {
        // A match! The word is correctly spelled
        if (strcmp(word, dictionary[i]) == 0) {
            return false;
        }
    }
    // Alas, the word is not in the dictionary
    return true;
}

// The main event, where Sherlock's deductions come to light
int main() {
    // Read Sherlock's corpus
    printf("Enter the corpus to be examined, my dear Watson: ");
    fgets(corpus, sizeof(corpus), stdin);

    // Extract each word from the corpus
    char* word = strtok(corpus, " ,.-!?");
    while (word != NULL) {
        // Is it a mystery, Watson?
        if (is_misspelled(word)) {
            printf("Elementary, my dear Watson! The word '%s' is misspelled.\n", word);
        }
        // On to the next word
        word = strtok(NULL, " ,.-!?");
    }

    // The case is closed, Watson
    printf("Your corpus has been thoroughly inspected. The truth has emerged.\n");
    return 0;
}