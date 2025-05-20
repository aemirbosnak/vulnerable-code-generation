//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom stop words list
char *stop_words[] = {"a", "an", "and", "are", "as", "at", "be", "by", "for",
                       "from", "has", "he", "her", "his", "I", "in", "is",
                       "it", "its", "me", "my", "of", "on", "or", "our", "she",
                       "so", "some", "that", "the", " their", "them", "then",
                       "there", "they", "this", "to", "up", "us", "was", "we",
                       "were", "what", "when", "where", "which", "who", "why", "will",
                       "with", "you", "your"};

// Calculate the frequency of words in a given text
int *count_words(char *text) {
    int *word_counts = (int *)calloc(256, sizeof(int));
    char *word = strtok(text, " ");
    while (word != NULL) {
        word_counts[(int)word[0]]++;
        word = strtok(NULL, " ");
    }
    return word_counts;
}

// Sort the words by their frequency
typedef struct {
    char *word;
    int count;
} WordFrequency;

int compare_word_frequency(const void *a, const void *b) {
    WordFrequency *wa = (WordFrequency *)a;
    WordFrequency *wb = (WordFrequency *)b;
    return wb->count - wa->count;
}

WordFrequency *sort_words(int *word_counts) {
    WordFrequency *sorted_words = (WordFrequency *)malloc(256 * sizeof(WordFrequency));
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (word_counts[i] > 0) {
            sorted_words[index].word = (char *)malloc(100 * sizeof(char));
            sprintf(sorted_words[index].word, "%c", i);
            sorted_words[index].count = word_counts[i];
            index++;
        }
    }
    qsort(sorted_words, index, sizeof(WordFrequency), compare_word_frequency);
    return sorted_words;
}

// Print the top N most frequent words
void print_summary(WordFrequency *sorted_words, int n) {
    printf("\nTop %d Most Frequent Words:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%s (%d)\n", sorted_words[i].word, sorted_words[i].count);
    }
}

// Remove stop words from the text
char *remove_stop_words(char *text) {
    char *cleaned_text = (char *)malloc(strlen(text) * sizeof(char));
    int offset = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        int is_stop_word = 0;
        for (int i = 0; i < sizeof(stop_words) / sizeof(char *); i++) {
            if (strcmp(word, stop_words[i]) == 0) {
                is_stop_word = 1;
                break;
            }
        }
        if (!is_stop_word) {
            strcpy(cleaned_text + offset, word);
            offset += strlen(word);
            cleaned_text[offset++] = ' ';
        }
        word = strtok(NULL, " ");
    }
    cleaned_text[offset - 1] = '\0';
    return cleaned_text;
}

// Summarize the given text
char *summarize_text(char *text, int n) {
    int *word_counts = count_words(text);
    WordFrequency *sorted_words = sort_words(word_counts);
    char *cleaned_text = remove_stop_words(text);
    print_summary(sorted_words, n);
    return cleaned_text;
}

int main() {
    // Input text
    char *text = "The quick brown fox jumped over the lazy dog. The dog was very tired, and the fox was very clever. The fox ate the dog's food, and the dog was very angry. The dog chased the fox, but the fox was too fast. The dog was very exhausted, and the fox was very satisfied.";
    // Number of words to summarize
    int n = 5;
    // Summarize the text
    char *summary = summarize_text(text, n);
    // Print the summary
    printf("\nSummary:\n%s", summary);
    return 0;
}