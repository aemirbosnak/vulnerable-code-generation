//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS_PER_SENTENCE 100
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 20
#define MIN_SUMMARY_LENGTH 50
#define MAX_SUMMARY_LENGTH 200

typedef struct {
    char* words[MAX_WORDS_PER_SENTENCE];
    int num_words;
} sentence;

typedef struct {
    sentence sentences[MAX_SENTENCES];
    int num_sentences;
} text;

void print_text(text* t) {
    for (int i = 0; i < t->num_sentences; i++) {
        for (int j = 0; j < t->sentences[i].num_words; j++) {
            printf("%s ", t->sentences[i].words[j]);
        }
        printf("\n");
    }
}

void free_text(text* t) {
    for (int i = 0; i < t->num_sentences; i++) {
        for (int j = 0; j < t->sentences[i].num_words; j++) {
            free(t->sentences[i].words[j]);
        }
    }
    free(t);
}

text* read_text(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    text* t = malloc(sizeof(text));
    t->num_sentences = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        sentence* s = &t->sentences[t->num_sentences++];
        s->num_words = 0;

        char* word = strtok(line, " ");
        while (word != NULL) {
            if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
                s->words[s->num_words++] = strdup(word);
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    return t;
}

void summarize_text(text* t, char* summary_filename) {
    FILE* fp = fopen(summary_filename, "w");
    if (fp == NULL) {
        return;
    }

    int num_sentences_in_summary = t->num_sentences * 0.25;
    if (num_sentences_in_summary < MIN_SUMMARY_LENGTH) {
        num_sentences_in_summary = MIN_SUMMARY_LENGTH;
    } else if (num_sentences_in_summary > MAX_SUMMARY_LENGTH) {
        num_sentences_in_summary = MAX_SUMMARY_LENGTH;
    }

    int sentences_in_summary[num_sentences_in_summary];
    for (int i = 0; i < num_sentences_in_summary; i++) {
        sentences_in_summary[i] = -1;
    }

    for (int i = 0; i < num_sentences_in_summary; i++) {
        int best_sentence = -1;
        int best_score = -1;
        for (int j = 0; j < t->num_sentences; j++) {
            int score = 0;
            for (int k = 0; k < t->sentences[j].num_words; k++) {
                for (int l = 0; l < num_sentences_in_summary; l++) {
                    if (sentences_in_summary[l] == j) {
                        score -= 10;
                    } else {
                        for (int m = 0; m < t->sentences[sentences_in_summary[l]].num_words; m++) {
                            if (strcmp(t->sentences[j].words[k], t->sentences[sentences_in_summary[l]].words[m]) == 0) {
                                score += 1;
                            }
                        }
                    }
                }
            }
            if (score > best_score) {
                best_score = score;
                best_sentence = j;
            }
        }
        sentences_in_summary[i] = best_sentence;
    }

    for (int i = 0; i < num_sentences_in_summary; i++) {
        for (int j = 0; j < t->sentences[sentences_in_summary[i]].num_words; j++) {
            fprintf(fp, "%s ", t->sentences[sentences_in_summary[i]].words[j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_filename> <summary_filename>\n", argv[0]);
        return 1;
    }

    text* t = read_text(argv[1]);
    if (t == NULL) {
        printf("Error reading input file.\n");
        return 1;
    }

    summarize_text(t, argv[2]);

    free_text(t);

    return 0;
}