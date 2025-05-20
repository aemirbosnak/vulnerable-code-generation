//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LEN 1024
#define MAX_WORD_LEN 64

struct word {
    char *word;
    int frequency;
    float sentiment;
};

struct sentence {
    char *sentence;
    float sentiment;
};

struct sentiment_analyzer {
    struct word *dictionary;
    int dictionary_size;
    struct sentence *sentences;
    int sentences_size;
};

struct sentiment_analyzer *new_sentiment_analyzer() {
    struct sentiment_analyzer *sa = malloc(sizeof(struct sentiment_analyzer));
    sa->dictionary = NULL;
    sa->dictionary_size = 0;
    sa->sentences = NULL;
    sa->sentences_size = 0;
    return sa;
}

void free_sentiment_analyzer(struct sentiment_analyzer *sa) {
    if (sa->dictionary != NULL) {
        for (int i = 0; i < sa->dictionary_size; i++) {
            free(sa->dictionary[i].word);
        }
        free(sa->dictionary);
    }
    if (sa->sentences != NULL) {
        for (int i = 0; i < sa->sentences_size; i++) {
            free(sa->sentences[i].sentence);
        }
        free(sa->sentences);
    }
    free(sa);
}

static int compare_words(const void *a, const void *b) {
    struct word *wa = (struct word *)a;
    struct word *wb = (struct word *)b;
    return strcmp(wa->word, wb->word);
}

static int compare_sentences(const void *a, const void *b) {
    struct sentence *sa = (struct sentence *)a;
    struct sentence *sb = (struct sentence *)b;
    return strcmp(sa->sentence, sb->sentence);
}

int load_dictionary(struct sentiment_analyzer *sa, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return -1;
    }
    char line[MAX_SENTENCE_LEN];
    while (fgets(line, MAX_SENTENCE_LEN, f) != NULL) {
        char *word = strtok(line, " ");
        char *sentiment = strtok(NULL, " ");
        if (word != NULL && sentiment != NULL) {
            struct word *w = malloc(sizeof(struct word));
            w->word = strdup(word);
            w->frequency = 0;
            w->sentiment = atof(sentiment);
            sa->dictionary = realloc(sa->dictionary, (sa->dictionary_size + 1) * sizeof(struct word));
            sa->dictionary[sa->dictionary_size++] = *w;
        }
    }
    fclose(f);
    qsort(sa->dictionary, sa->dictionary_size, sizeof(struct word), compare_words);
    return 0;
}

int load_sentences(struct sentiment_analyzer *sa, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return -1;
    }
    char line[MAX_SENTENCE_LEN];
    while (fgets(line, MAX_SENTENCE_LEN, f) != NULL) {
        char *sentence = strdup(line);
        struct sentence *s = malloc(sizeof(struct sentence));
        s->sentence = sentence;
        s->sentiment = 0.0;
        sa->sentences = realloc(sa->sentences, (sa->sentences_size + 1) * sizeof(struct sentence));
        sa->sentences[sa->sentences_size++] = *s;
    }
    fclose(f);
    qsort(sa->sentences, sa->sentences_size, sizeof(struct sentence), compare_sentences);
    return 0;
}

float analyze_sentence(struct sentiment_analyzer *sa, const char *sentence) {
    int i, j;
    float sentiment = 0.0;
    char *words = strdup(sentence);
    char *word = strtok(words, " ");
    while (word != NULL) {
        for (i = 0; i < sa->dictionary_size; i++) {
            if (strcmp(sa->dictionary[i].word, word) == 0) {
                sentiment += sa->dictionary[i].sentiment;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    free(words);
    return sentiment;
}

void print_results(struct sentiment_analyzer *sa) {
    for (int i = 0; i < sa->sentences_size; i++) {
        printf("%s: %.2f\n", sa->sentences[i].sentence, sa->sentences[i].sentiment);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <dictionary> <sentences>\n", argv[0]);
        return EXIT_FAILURE;
    }
    struct sentiment_analyzer *sa = new_sentiment_analyzer();
    if (load_dictionary(sa, argv[1]) != 0) {
        fprintf(stderr, "Error loading dictionary: %s\n", argv[1]);
        free_sentiment_analyzer(sa);
        return EXIT_FAILURE;
    }
    if (load_sentences(sa, argv[2]) != 0) {
        fprintf(stderr, "Error loading sentences: %s\n", argv[2]);
        free_sentiment_analyzer(sa);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < sa->sentences_size; i++) {
        sa->sentences[i].sentiment = analyze_sentence(sa, sa->sentences[i].sentence);
    }
    qsort(sa->sentences, sa->sentences_size, sizeof(struct sentence), compare_sentences);
    print_results(sa);
    free_sentiment_analyzer(sa);
    return EXIT_SUCCESS;
}