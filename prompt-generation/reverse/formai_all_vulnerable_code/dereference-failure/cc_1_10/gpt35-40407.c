//FormAI DATASET v1.0 Category: Text Summarizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

// Function to get the text input from user
void get_text_input(char *text_input) {
    printf("Enter the text to summarize:\n");
    fgets(text_input, MAX_STRING_LENGTH, stdin);
}

// Function to remove unwanted characters from the text and convert it to lowercase
void clean_text(char *text_input) {
    int i, j, len;
    len = strlen(text_input);

    // Convert uppercase to lowercase
    for (i=0; i<len; i++) {
        if (text_input[i] >= 'A' && text_input[i] <= 'Z') {
            text_input[i] = text_input[i] + 32;
        }
    }

    // Remove unwanted characters
    for (i=0; text_input[i]; i++) {
        while (!(text_input[i] >= 'a' && text_input[i] <= 'z') && !(text_input[i] >= 'A' && text_input[i] <= 'Z') && !(text_input[i] == '\0')) {
            for (j=i; text_input[j]!='\0'; j++) {
                text_input[j] = text_input[j+1];
            }
            text_input[j] = '\0';
        }
    }
}

// Function to split the text into sentences
void split_into_sentences(char **sentences, int *num_sentences, char *text_input) {
    int i, j, k, len;
    len = strlen(text_input);
    i = 0;
    j = 0;
    k = 0;
    while (i < len && k < MAX_SUMMARY_LENGTH) {
        while (text_input[i] != '.' && text_input[i] != '!' && text_input[i] != '?' && i < len) {
            sentences[k][j++] = text_input[i++];
        }
        sentences[k][j++] = text_input[i++];
        sentences[k++][j] = '\0';
        j = 0;
    }
    *num_sentences = k;
}

// Function to calculate the frequency of each word in the text
void calculate_word_frequency(char **sentences, int num_sentences, char **words, int *freq) {
    int i, j, k, len;
    k = 0;
    for (i=0; i<num_sentences; i++) {
        len = strlen(sentences[i]);
        j = 0;
        while (j < len) {
            while (!(sentences[i][j] >= 'a' && sentences[i][j] <= 'z') && !(sentences[i][j] >= 'A' && sentences[i][j] <= 'Z') && !(sentences[i][j] == '\0')) {
                j++;
            }
            if (!(sentences[i][j] == '\0')) {
                words[k][0] = sentences[i][j];
                len = strlen(sentences[i]) - j;
                for (len=1; (sentences[i][j+len] >= 'a' && sentences[i][j+len] <= 'z') || (sentences[i][j+len] >= 'A' && sentences[i][j+len] <= 'Z'); len++) {
                    words[k][len] = sentences[i][j+len];
                }
                words[k][len] = '\0';
                clean_text(words[k]);
                freq[k] = 1;
                k++;
            }
            j += len;
        }
    }
}

// Function to sort the words in descending order of frequency
void sort_words_by_frequency(char **words, int *freq, int num_words) {
    int i, j, max_freq, temp_freq;
    char temp_word[MAX_STRING_LENGTH];
    for (i=0; i<num_words-1; i++) {
        max_freq = i;
        for (j=i+1; j<num_words; j++) {
            if (freq[j] > freq[max_freq]) {
                max_freq = j;
            }
        }
        strcpy(temp_word, words[i]);
        strcpy(words[i], words[max_freq]);
        strcpy(words[max_freq], temp_word);
        temp_freq = freq[i];
        freq[i] = freq[max_freq];
        freq[max_freq] = temp_freq;
    }
}

// Function to generate the summary from the most frequent words
void generate_summary(char **sentences, int num_sentences, char **words, int *freq, int num_words) {
    int i, j, k, len, index;
    printf("Summary:\n");
    for (i=0; i<num_words && i<MAX_SUMMARY_LENGTH; i++) {
        index = -1;
        for (j=0; j<num_sentences; j++) {
            len = strlen(sentences[j]);
            k = 0;
            while (k < len) {
                if (strstr(&sentences[j][k], words[i]) == &sentences[j][k]) {
                    index = j;
                    break;
                }
                k++;
            }
            if (index != -1) {
                break;
            }
        }
        if (index != -1) {
            printf("%s", sentences[index]);
        }
    }
}

int main() {
    char *text_input = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
    char **sentences = (char **) malloc(MAX_SUMMARY_LENGTH * sizeof(char *));
    char **words = (char **) malloc(MAX_SUMMARY_LENGTH * sizeof(char *));
    int *freq = (int *) calloc(MAX_SUMMARY_LENGTH, sizeof(int));
    int num_sentences, num_words;

    int i;
    for (i=0; i<MAX_SUMMARY_LENGTH; i++) {
        sentences[i] = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
        words[i] = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
    }

    // Get the text input from user
    get_text_input(text_input);

    // Remove unwanted characters from the text and convert to lowercase
    clean_text(text_input);

    // Split the text into sentences
    split_into_sentences(sentences, &num_sentences, text_input);

    // Calculate the frequency of each word in the text
    calculate_word_frequency(sentences, num_sentences, words, freq);

    // Sort the words in descending order of frequency
    num_words = sizeof(freq) / sizeof(freq[0]);
    sort_words_by_frequency(words, freq, num_words);

    // Generate the summary from the most frequent words
    generate_summary(sentences, num_sentences, words, freq, num_words);

    // Free the memory allocated for the arrays
    free(text_input);
    free(sentences);
    free(words);
    free(freq);

    return 0;
}