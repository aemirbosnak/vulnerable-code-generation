//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 15
#define MIN_LINE_LENGTH 10
#define MAX_LINE_LENGTH 50
#define MIN_PAGE_LENGTH 500
#define MAX_PAGE_LENGTH 1000

// Structure to store a word and its frequency
typedef struct word_frequency {
    char *word;
    int frequency;
} word_frequency;

// Function to calculate the frequency of a word
void calculate_word_frequency(char *text, word_frequency *frequencies) {
    int i, j;
    for (i = 0; text[i] != '\0'; i++) {
        // Check if the current character is a word boundary
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            // If it is, increment the frequency of the previous word
            if (frequencies[i - 1].word != NULL) {
                frequencies[i - 1].frequency++;
            }
            // Reset the previous word frequency
            frequencies[i - 1].word = NULL;
        }
        // If the current character is not a word boundary, check if it is a new word
        else if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            // If it is a new word, initialize the frequency to 1
            frequencies[i].word = text + i;
            frequencies[i].frequency = 1;
        }
    }
}

// Function to print the most frequent words in a page
void print_most_frequent_words(word_frequency *frequencies, int page_length) {
    int i, j;
    for (i = 0; i < page_length; i++) {
        // Find the most frequent word in the current page
        word_frequency *most_frequent = NULL;
        int most_frequent_frequency = 0;
        for (j = 0; j < page_length; j++) {
            if (frequencies[j].frequency > most_frequent_frequency) {
                most_frequent = &frequencies[j];
                most_frequent_frequency = frequencies[j].frequency;
            }
        }
        // Print the most frequent word and its frequency
        printf("%s (%d)\n", most_frequent->word, most_frequent_frequency);
    }
}

// Function to print the average word length and standard deviation
void print_stats(word_frequency *frequencies, int page_length) {
    int i, j;
    double average = 0;
    double standard_deviation = 0;
    for (i = 0; i < page_length; i++) {
        for (j = 0; j < page_length; j++) {
            average += frequencies[i].frequency * (j - i);
            standard_deviation += (frequencies[i].frequency - average * (j - i)) * (frequencies[i].frequency - average * (j - i));
        }
    }
    average /= page_length;
    standard_deviation /= page_length;
    printf("Average word length: %f\n", average);
    printf("Standard deviation: %f\n", standard_deviation);
}

int main() {
    // Load the text from a file
    FILE *file = fopen("example.txt", "r");
    char *text = malloc(1000);
    fread(text, 1, 1000, file);
    fclose(file);

    // Split the text into pages
    int page_length = 500;
    char **pages = malloc(page_length * sizeof(char *));
    int page_count = ceil(strlen(text) / page_length) + 1;
    for (int i = 0; i < page_count; i++) {
        pages[i] = malloc(page_length * sizeof(char));
        memset(pages[i], 0, page_length);
        strncpy(pages[i], text + (i * page_length), page_length);
    }

    // Calculate the frequency of each word in each page
    word_frequency *frequencies = malloc(page_length * sizeof(word_frequency));
    for (int i = 0; i < page_count; i++) {
        calculate_word_frequency(pages[i], frequencies + i * page_length);
    }

    // Print the most frequent words in each page
    for (int i = 0; i < page_count; i++) {
        print_most_frequent_words(frequencies + i * page_length, page_length);
    }

    // Print the average word length and standard deviation
    print_stats(frequencies, page_length);

    return 0;
}