//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct {
    char *alienWord;
    char *englishWord;
} WordPair;

// Create a new word pair.
WordPair *createWordPair(char *alienWord, char *englishWord) {
    WordPair *newWordPair = malloc(sizeof(WordPair));
    newWordPair->alienWord = strdup(alienWord);
    newWordPair->englishWord = strdup(englishWord);
    return newWordPair;
}

// Free the memory allocated for a word pair.
void freeWordPair(WordPair *wordPair) {
    free(wordPair->alienWord);
    free(wordPair->englishWord);
    free(wordPair);
}

// Load the dictionary of alien words and their English translations from a file.
WordPair **loadDictionary(char *filename, int *numWords) {
    // Open the file.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the number of words in the dictionary.
    fscanf(file, "%d", numWords);

    // Allocate memory for the dictionary.
    WordPair **dictionary = malloc(sizeof(WordPair *) * (*numWords));

    // Read the words from the file and add them to the dictionary.
    for (int i = 0; i < *numWords; i++) {
        char alienWord[MAX_WORD_LENGTH];
        char englishWord[MAX_WORD_LENGTH];
        fscanf(file, "%s %s", alienWord, englishWord);
        dictionary[i] = createWordPair(alienWord, englishWord);
    }

    // Close the file.
    fclose(file);

    return dictionary;
}

// Free the memory allocated for the dictionary.
void freeDictionary(WordPair **dictionary, int numWords) {
    for (int i = 0; i < numWords; i++) {
        freeWordPair(dictionary[i]);
    }
    free(dictionary);
}

// Translate an alien word to English.
char *translateWord(WordPair **dictionary, int numWords, char *alienWord) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(dictionary[i]->alienWord, alienWord) == 0) {
            return dictionary[i]->englishWord;
        }
    }

    return NULL;
}

// Translate an English sentence to Alien.
char *translateSentence(WordPair **dictionary, int numWords, char *englishSentence) {
    // Allocate memory for the translated sentence.
    char *translatedSentence = malloc(strlen(englishSentence) + 1);

    // Tokenize the English sentence.
    char *token = strtok(englishSentence, " ");

    // Translate each token.
    while (token != NULL) {
        char *alienWord = translateWord(dictionary, numWords, token);
        if (alienWord != NULL) {
            strcat(translatedSentence, alienWord);
        } else {
            strcat(translatedSentence, token);
        }
        strcat(translatedSentence, " ");
        token = strtok(NULL, " ");
    }

    // Remove the trailing space.
    translatedSentence[strlen(translatedSentence) - 1] = '\0';

    return translatedSentence;
}

// Print the usage message.
void printUsage() {
    printf("Usage: ./alien_translator [dictionary_file] [input_file] [output_file]\n");
}

// Main function.
int main(int argc, char **argv) {
    // Check if the correct number of arguments are provided.
    if (argc != 4) {
        printUsage();
        return 1;
    }

    // Load the dictionary.
    int numWords;
    WordPair **dictionary = loadDictionary(argv[1], &numWords);
    if (dictionary == NULL) {
        return 1;
    }

    // Open the input file.
    FILE *inputFile = fopen(argv[2], "r");
    if (inputFile == NULL) {
        printf("Error opening file %s\n", argv[2]);
        freeDictionary(dictionary, numWords);
        return 1;
    }

    // Open the output file.
    FILE *outputFile = fopen(argv[3], "w");
    if (outputFile == NULL) {
        printf("Error opening file %s\n", argv[3]);
        fclose(inputFile);
        freeDictionary(dictionary, numWords);
        return 1;
    }

    // Translate the input file.
    char line[1024];
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Translate the line.
        char *translatedLine = translateSentence(dictionary, numWords, line);

        // Write the translated line to the output file.
        fprintf(outputFile, "%s", translatedLine);
        free(translatedLine);
    }

    // Close the input and output files.
    fclose(inputFile);
    fclose(outputFile);

    // Free the memory allocated for the dictionary.
    freeDictionary(dictionary, numWords);

    return 0;
}