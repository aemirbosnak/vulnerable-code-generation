//GEMINI-pro DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters in a word
#define MAX_WORD_LENGTH 20

// Define the maximum number of words in a sentence
#define MAX_SENTENCE_LENGTH 100

// Define the maximum number of sentences in a paragraph
#define MAX_PARAGRAPH_LENGTH 10

// Create a struct to represent a word
typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Create a struct to represent a sentence
typedef struct Sentence {
    char sentence[MAX_SENTENCE_LENGTH];
    int count;
} Sentence;

// Create a struct to represent a paragraph
typedef struct Paragraph {
    char paragraph[MAX_PARAGRAPH_LENGTH];
    int count;
} Paragraph;

// Create an array of words
Word words[MAX_WORD_LENGTH];

// Create an array of sentences
Sentence sentences[MAX_SENTENCE_LENGTH];

// Create an array of paragraphs
Paragraph paragraphs[MAX_PARAGRAPH_LENGTH];

// Function to read a file into a string
char *read_file(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the string
    char *string = malloc(file_size + 1);
    if (string == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read the file into the string
    fread(string, file_size, 1, file);
    fclose(file);

    // Null-terminate the string
    string[file_size] = '\0';

    // Return the string
    return string;
}

// Function to tokenize a string into words
void tokenize_string(char *string, Word *words, int *num_words) {
    // Split the string into words
    char *word = strtok(string, " ");
    while (word != NULL) {
        // Copy the word into the array of words
        strcpy(words[*num_words].word, word);

        // Increment the count of words
        (*num_words)++;

        // Get the next word
        word = strtok(NULL, " ");
    }
}

// Function to count the number of occurrences of each word in a string
void count_words(Word *words, int num_words) {
    // Iterate over the words
    for (int i = 0; i < num_words; i++) {
        // Increment the count of the word
        words[i].count++;
    }
}

// Function to print the words and their counts
void print_words(Word *words, int num_words) {
    // Iterate over the words
    for (int i = 0; i < num_words; i++) {
        // Print the word and its count
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

// Function to tokenize a string into sentences
void tokenize_sentences(char *string, Sentence *sentences, int *num_sentences) {
    // Split the string into sentences
    char *sentence = strtok(string, ".");
    while (sentence != NULL) {
        // Copy the sentence into the array of sentences
        strcpy(sentences[*num_sentences].sentence, sentence);

        // Increment the count of sentences
        (*num_sentences)++;

        // Get the next sentence
        sentence = strtok(NULL, ".");
    }
}

// Function to count the number of occurrences of each sentence in a string
void count_sentences(Sentence *sentences, int num_sentences) {
    // Iterate over the sentences
    for (int i = 0; i < num_sentences; i++) {
        // Increment the count of the sentence
        sentences[i].count++;
    }
}

// Function to print the sentences and their counts
void print_sentences(Sentence *sentences, int num_sentences) {
    // Iterate over the sentences
    for (int i = 0; i < num_sentences; i++) {
        // Print the sentence and its count
        printf("%s: %d\n", sentences[i].sentence, sentences[i].count);
    }
}

// Function to tokenize a string into paragraphs
void tokenize_paragraphs(char *string, Paragraph *paragraphs, int *num_paragraphs) {
    // Split the string into paragraphs
    char *paragraph = strtok(string, "\n");
    while (paragraph != NULL) {
        // Copy the paragraph into the array of paragraphs
        strcpy(paragraphs[*num_paragraphs].paragraph, paragraph);

        // Increment the count of paragraphs
        (*num_paragraphs)++;

        // Get the next paragraph
        paragraph = strtok(NULL, "\n");
    }
}

// Function to count the number of occurrences of each paragraph in a string
void count_paragraphs(Paragraph *paragraphs, int num_paragraphs) {
    // Iterate over the paragraphs
    for (int i = 0; i < num_paragraphs; i++) {
        // Increment the count of the paragraph
        paragraphs[i].count++;
    }
}

// Function to print the paragraphs and their counts
void print_paragraphs(Paragraph *paragraphs, int num_paragraphs) {
    // Iterate over the paragraphs
    for (int i = 0; i < num_paragraphs; i++) {
        // Print the paragraph and its count
        printf("%s: %d\n", paragraphs[i].paragraph, paragraphs[i].count);
    }
}

// Main function
int main() {
    // Read the file into a string
    char *string = read_file("text.txt");

    // Tokenize the string into words
    int num_words = 0;
    tokenize_string(string, words, &num_words);

    // Count the number of occurrences of each word
    count_words(words, num_words);

    // Print the words and their counts
    print_words(words, num_words);

    // Tokenize the string into sentences
    int num_sentences = 0;
    tokenize_sentences(string, sentences, &num_sentences);

    // Count the number of occurrences of each sentence
    count_sentences(sentences, num_sentences);

    // Print the sentences and their counts
    print_sentences(sentences, num_sentences);

    // Tokenize the string into paragraphs
    int num_paragraphs = 0;
    tokenize_paragraphs(string, paragraphs, &num_paragraphs);

    // Count the number of occurrences of each paragraph
    count_paragraphs(paragraphs, num_paragraphs);

    // Print the paragraphs and their counts
    print_paragraphs(paragraphs, num_paragraphs);

    // Free the memory allocated for the string
    free(string);

    return 0;
}