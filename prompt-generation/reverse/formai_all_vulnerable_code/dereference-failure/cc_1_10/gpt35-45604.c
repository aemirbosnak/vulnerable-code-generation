//FormAI DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000
#define MAX_SUMMARY_LENGTH 200

// function to read text from file
char *read_text(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // get file size in bytes
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // allocate memory for file content
    char *content = malloc(file_size + 1);
    if (content == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // read text from file into memory
    if (fread(content, 1, file_size, file) != file_size) {
        perror("Error reading file");
        exit(1);
    }
    fclose(file);

    // null-terminate the content string
    content[file_size] = '\0';
    return content;
}

// function to split text into individual words
int split_text(char *text, char words[MAX_NUM_WORDS][MAX_WORD_LENGTH]) {
    int num_words = 0;
    char *word = strtok(text, " ");
    while (word != NULL && num_words < MAX_NUM_WORDS) {
        // remove punctuation from word
        int len = strlen(word);
        if (ispunct(word[len-1])) {
            word[len-1] = '\0';
        }
        strcpy(words[num_words], word);
        num_words++;
        word = strtok(NULL, " ");
    }
    return num_words;
}

// function to calculate the frequency of each word
void calculate_frequencies(char words[MAX_NUM_WORDS][MAX_WORD_LENGTH], int num_words, int freqs[MAX_NUM_WORDS]) {
    for (int i = 0; i < num_words; i++) {
        freqs[i] = 1;
        for (int j = i+1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freqs[i]++;
            }
        }
    }
}

// function to select the most frequent words for the summary
void select_summary_words(char words[MAX_NUM_WORDS][MAX_WORD_LENGTH], int freqs[MAX_NUM_WORDS], int num_words, char summary_words[MAX_NUM_WORDS][MAX_WORD_LENGTH], int *num_summary_words) {
    int max_freq = 1;
    for (int i = 0; i < num_words; i++) {
        if (freqs[i] > max_freq) {
            max_freq = freqs[i];
        }
    }

    *num_summary_words = 0;
    for (int i = 0; i < num_words && *num_summary_words < MAX_NUM_WORDS; i++) {
        if (freqs[i] >= max_freq/2 && strlen(words[i]) >= 4 && strcmp(words[i], "the") != 0 && strcmp(words[i], "and") != 0) {
            strcpy(summary_words[*num_summary_words], words[i]);
            (*num_summary_words)++;
        }
    }
}

// function to capitalize the first letter of each sentence in the summary
void capitalize_sentences(char *summary) {
    int len = strlen(summary);
    for (int i = 0; i < len-1; i++) {
        if (summary[i] == '.' && isspace(summary[i+1])) {
            int j = i+2;
            while (j < len-1 && isspace(summary[j])) {
                j++;
            }
            summary[j] = toupper(summary[j]);
        }
    }
}

// main function
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // read text from file
    char *text = read_text(argv[1]);

    // split text into individual words
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int num_words = split_text(text, words);

    // calculate the frequency of each word
    int freqs[MAX_NUM_WORDS];
    calculate_frequencies(words, num_words, freqs);

    // select the most frequent words for the summary
    char summary_words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int num_summary_words;
    select_summary_words(words, freqs, num_words, summary_words, &num_summary_words);

    // create summary from selected words
    char summary[MAX_SUMMARY_LENGTH] = "";
    for (int i = 0; i < num_summary_words; i++) {
        strcat(summary, summary_words[i]);
        if (i < num_summary_words-1) {
            strcat(summary, " ");
        }
        if (strlen(summary) > MAX_SUMMARY_LENGTH) {
            break;
        }
    }

    // capitalize the first letter of each sentence in the summary
    capitalize_sentences(summary);

    // output the summary
    printf("%s\n", summary);

    // free dynamically allocated memory
    free(text);

    return 0;
}