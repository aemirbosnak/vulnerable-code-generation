//FormAI DATASET v1.0 Category: Text Summarizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 1000

/* This program is a simple text summarizer that takes in a file and reduces it to a summary.
   The summary consists of the most important sentences of the text.
   It works by scoring each sentence based on the number of "important" words it contains,
   and then selecting the top n sentences by score.
*/

// This is a list of the most important words in the English language.
const char* IMPORTANT_WORDS[] = {"the", "and", "of", "to", "a", "in", "that", "is", "was", "for", "on", "with", "it", "as", "at", "by", "an", "be", "this", "but", "not", "or", "they", "from", "we", "have", "will", "one", "had", "who", "all", "were", "there", "when", "which", "their", "if", "do", "out", "so", "what", "up", "other", "its", "about", "into", "than", "some", "more", "her", "like", "these", "your", "our", "two", "been", "now"};

// This function checks whether a word is in the list of important words.
int is_important_word(const char* word) {
    int i;
    for (i = 0; i < sizeof(IMPORTANT_WORDS) / sizeof(IMPORTANT_WORDS[0]); i++) {
        if (strcasecmp(word, IMPORTANT_WORDS[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: summarize <input_file> <num_sentences>\n");
        return 1;
    }

    const char* input_file_path = argv[1];
    int num_sentences = atoi(argv[2]);

    // Read in the input file.
    FILE* input_file = fopen(input_file_path, "r");
    if (!input_file) {
        printf("Failed to open input file: %s\n", input_file_path);
        return 1;
    }

    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int sentence_scores[MAX_SENTENCES];
    int num_sentences_found = 0;

    char buffer[MAX_SENTENCE_LENGTH];
    char* word;
    while (fgets(buffer, MAX_SENTENCE_LENGTH, input_file)) {
        int len = strlen(buffer);
        if (len == 0) {
            continue; // skip empty lines
        }

        // Replace newlines with spaces
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = ' ';
        }

        // Split the line into words
        word = strtok(buffer, " ");
        int num_important_words = 0;
        while (word != NULL && strlen(word) > 1) {
            if (is_important_word(word)) {
                num_important_words++;
            }
            word = strtok(NULL, " ");
        }

        // Only add the sentence if it contains at least one important word.
        if (num_important_words > 0) {
            strcpy(sentences[num_sentences_found], buffer);
            sentence_scores[num_sentences_found] = num_important_words;
            num_sentences_found++;
        }

        // Stop searching for sentences if we have found enough.
        if (num_sentences_found >= MAX_SENTENCES) {
            break;
        }
    }

    // Select the sentences with the highest scores.
    int i, j, max_index, tmp_score;
    char tmp_sentence[MAX_SENTENCE_LENGTH];
    for (i = 0; i < num_sentences - 1; i++) {
        max_index = i;
        for (j = i + 1; j < num_sentences_found; j++) {
            if (sentence_scores[j] > sentence_scores[max_index]) {
                max_index = j;
            }
        }
        // Swap sentences and scores
        tmp_score = sentence_scores[i];
        strcpy(tmp_sentence, sentences[i]);
        sentence_scores[i] = sentence_scores[max_index];
        strcpy(sentences[i], sentences[max_index]);
        sentence_scores[max_index] = tmp_score;
        strcpy(sentences[max_index], tmp_sentence);
    }

    // Print out the summary.
    for (i = 0; i < num_sentences && i < num_sentences_found; i++) {
        printf("%s", sentences[i]);
    }

    fclose(input_file);
    return 0;
}