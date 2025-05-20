//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 100

typedef struct {
    char *word;
    int frequency;
} Word;

typedef struct {
    char *sentence;
    int length;
    float score;
} Sentence;

Word *words;
int num_words;

Sentence *sentences;
int num_sentences;

int compare_sentences(const void *a, const void *b) {
    const Sentence *sa = (const Sentence *)a;
    const Sentence *sb = (const Sentence *)b;

    return sb->score - sa->score;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *text = NULL;
    size_t len = 0;
    ssize_t read = getline(&text, &len, fp);
    if (read < 0) {
        perror("getline");
        return EXIT_FAILURE;
    }

    fclose(fp);

    // Tokenize the text into words
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Remove punctuation from the word
        char *p = token;
        while (*p != '\0') {
            if (ispunct(*p)) {
                *p = '\0';
                break;
            }
            p++;
        }

        // Add the word to the list of words
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == num_words) {
            words = realloc(words, (num_words + 1) * sizeof(Word));
            words[num_words].word = strdup(token);
            words[num_words].frequency = 1;
            num_words++;
        }

        token = strtok(NULL, " ");
    }

    // Tokenize the text into sentences
    token = strtok(text, ".");
    while (token != NULL) {
        // Remove whitespace from the sentence
        char *p = token;
        while (*p != '\0') {
            if (isspace(*p)) {
                *p = '\0';
                break;
            }
            p++;
        }

        // Add the sentence to the list of sentences
        sentences = realloc(sentences, (num_sentences + 1) * sizeof(Sentence));
        sentences[num_sentences].sentence = strdup(token);
        sentences[num_sentences].length = strlen(token);
        sentences[num_sentences].score = 0.0;
        num_sentences++;

        token = strtok(NULL, ".");
    }

    // Calculate the score for each sentence
    for (int i = 0; i < num_sentences; i++) {
        Sentence *sentence = &sentences[i];

        // Tokenize the sentence into words
        char *token = strtok(sentence->sentence, " ");
        while (token != NULL) {
            // Find the word in the list of words
            int j;
            for (j = 0; j < num_words; j++) {
                if (strcmp(words[j].word, token) == 0) {
                    // Calculate the score for the word
                    float score = (float)words[j].frequency / (float)sentence->length;

                    // Add the score to the score for the sentence
                    sentence->score += score;

                    break;
                }
            }

            token = strtok(NULL, " ");
        }
    }

    // Sort the sentences by score
    qsort(sentences, num_sentences, sizeof(Sentence), compare_sentences);

    // Print the top 10 sentences
    for (int i = 0; i < 10; i++) {
        Sentence *sentence = &sentences[i];

        printf("%s\n", sentence->sentence);
    }

    return EXIT_SUCCESS;
}