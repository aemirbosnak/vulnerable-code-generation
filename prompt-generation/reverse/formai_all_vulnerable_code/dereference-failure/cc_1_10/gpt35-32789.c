//FormAI DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_SUMMARY 1000

char *read_file(const char *filename);
int count_sentences(const char *text);
int is_vowel(char c);
int count_vowels(const char *sentence);
int compare_sentences(const void *a, const void *b);
void generate_summary(const char *text, char *summary, const int summary_len);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Read input file into memory
    char *text = read_file(argv[1]);

    // Generate summary
    char summary[MAX_SUMMARY];
    generate_summary(text, summary, MAX_SUMMARY);

    // Write summary to output file
    FILE *out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        printf("Error: failed to open output file %s\n", argv[2]);
        exit(1);
    }
    fprintf(out_file, "%s", summary);
    fclose(out_file);

    // Clean up
    free(text);
    return 0;
}

// Reads the contents of a file into a null-terminated string
char *read_file(const char *filename) {
    FILE *in_file = fopen(filename, "r");
    if (in_file == NULL) {
        printf("Error: failed to open input file %s\n", filename);
        exit(1);
    }

    // Get file size
    fseek(in_file, 0, SEEK_END);
    size_t file_size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);

    // Allocate buffer for file contents
    char *buffer = (char *) malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error: failed to allocate memory\n");
        exit(1);
    }

    // Read file contents into buffer
    fread(buffer, file_size, 1, in_file);
    fclose(in_file);

    // Null-terminate buffer
    buffer[file_size] = '\0';

    return buffer;
}

// Counts the number of sentences in a string
int count_sentences(const char *text) {
    int count = 0;
    for (const char *p = text; *p != '\0'; p++) {
        if (*p == '.' || *p == '?' || *p == '!') {
            count++;
        }
    }
    return count;
}

// Returns true if c is a vowel
int is_vowel(char c) {
    return strchr("aeiouAEIOU", c) != NULL;
}

// Counts the number of vowels in a string
int count_vowels(const char *sentence) {
    int count = 0;
    for (const char *p = sentence; *p != '\0'; p++) {
        if (is_vowel(*p)) {
            count++;
        }
    }
    return count;
}

// Comparator function for sorting sentences by number of vowels
int compare_sentences(const void *a, const void *b) {
    const char **sa = (const char **) a;
    const char **sb = (const char **) b;
    return count_vowels(*sa) - count_vowels(*sb);
}

// Generates a summary of a text by selecting the sentences with the most vowels
// and concatenating them together
void generate_summary(const char *text, char *summary, const int summary_len) {
    int num_sentences = count_sentences(text);
    if (num_sentences == 0) {
        return;
    }

    // Allocate array to hold sentences
    const char **sentences = (const char **) malloc(num_sentences * sizeof(char *));
    if (sentences == NULL) {
        printf("Error: failed to allocate memory\n");
        exit(1);
    }

    // Populate array with pointers to sentences
    int i = 0;
    for (const char *p = text; *p != '\0'; p++) {
        if (*p == '.' || *p == '?' || *p == '!') {
            if (i < num_sentences) {
                sentences[i++] = p + 1; // skip the period or other punctuation
            } else {
                break;
            }
        }
    }

    // Sort sentences by number of vowels
    qsort(sentences, num_sentences, sizeof(char *), compare_sentences);

    // Concatenate sentences with most vowels until summary length is reached
    int summary_pos = 0;
    for (int i = num_sentences - 1; i >= 0; i--) {
        int sentence_len = strlen(sentences[i]);
        if (summary_pos + sentence_len <= summary_len) {
            strcpy(summary + summary_pos, sentences[i]);
            summary_pos += sentence_len;
        } else {
            break;
        }
    }

    // Free memory
    free(sentences);
}