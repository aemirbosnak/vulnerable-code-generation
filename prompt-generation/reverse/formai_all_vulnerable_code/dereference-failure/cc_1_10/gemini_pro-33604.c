//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_SPAM_FEATURES 100
#define MAX_HAM_FEATURES 100
#define MAX_FEATURES (MAX_SPAM_FEATURES + MAX_HAM_FEATURES)

typedef struct {
    char *word;
    int count;
} word_t;

typedef struct {
    word_t *words;
    int num_words;
} vocabulary_t;

typedef struct {
    int *features;
    int num_features;
} feature_vector_t;

vocabulary_t *load_vocabulary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening vocabulary file");
        exit(1);
    }

    vocabulary_t *vocabulary = malloc(sizeof(vocabulary_t));
    if (vocabulary == NULL) {
        perror("Error allocating memory for vocabulary");
        exit(1);
    }

    vocabulary->num_words = 0;
    vocabulary->words = malloc(sizeof(word_t) * MAX_WORDS);
    if (vocabulary->words == NULL) {
        perror("Error allocating memory for vocabulary words");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *word = strtok(line, " ");
        int count = atoi(strtok(NULL, " "));

        if (vocabulary->num_words >= MAX_WORDS) {
            fprintf(stderr, "Error: Vocabulary size exceeded\n");
            exit(1);
        }

        vocabulary->words[vocabulary->num_words].word = strdup(word);
        vocabulary->words[vocabulary->num_words].count = count;
        vocabulary->num_words++;
    }

    fclose(file);

    return vocabulary;
}

feature_vector_t *load_feature_vector(const char *filename, const vocabulary_t *vocabulary) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening feature vector file");
        exit(1);
    }

    feature_vector_t *feature_vector = malloc(sizeof(feature_vector_t));
    if (feature_vector == NULL) {
        perror("Error allocating memory for feature vector");
        exit(1);
    }

    feature_vector->num_features = 0;
    feature_vector->features = malloc(sizeof(int) * MAX_FEATURES);
    if (feature_vector->features == NULL) {
        perror("Error allocating memory for feature vector features");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *word = strtok(line, " ");
        int count = atoi(strtok(NULL, " "));

        int feature_index = -1;
        for (int i = 0; i < vocabulary->num_words; i++) {
            if (strcmp(vocabulary->words[i].word, word) == 0) {
                feature_index = i;
                break;
            }
        }

        if (feature_index == -1) {
            fprintf(stderr, "Error: Word not found in vocabulary\n");
            exit(1);
        }

        if (feature_vector->num_features >= MAX_FEATURES) {
            fprintf(stderr, "Error: Feature vector size exceeded\n");
            exit(1);
        }

        feature_vector->features[feature_vector->num_features] = count;
        feature_vector->num_features++;
    }

    fclose(file);

    return feature_vector;
}

double cosine_similarity(const feature_vector_t *fv1, const feature_vector_t *fv2) {
    if (fv1->num_features != fv2->num_features) {
        fprintf(stderr, "Error: Feature vectors must have the same number of features\n");
        exit(1);
    }

    double dot_product = 0.0;
    for (int i = 0; i < fv1->num_features; i++) {
        dot_product += fv1->features[i] * fv2->features[i];
    }

    double magnitude1 = 0.0;
    for (int i = 0; i < fv1->num_features; i++) {
        magnitude1 += fv1->features[i] * fv1->features[i];
    }
    magnitude1 = sqrt(magnitude1);

    double magnitude2 = 0.0;
    for (int i = 0; i < fv2->num_features; i++) {
        magnitude2 += fv2->features[i] * fv2->features[i];
    }
    magnitude2 = sqrt(magnitude2);

    return dot_product / (magnitude1 * magnitude2);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s vocabulary spam_features ham_features\n", argv[0]);
        exit(1);
    }

    vocabulary_t *vocabulary = load_vocabulary(argv[1]);
    feature_vector_t *spam_features = load_feature_vector(argv[2], vocabulary);
    feature_vector_t *ham_features = load_feature_vector(argv[3], vocabulary);

    double similarity = cosine_similarity(spam_features, ham_features);
    printf("Similarity: %.4f\n", similarity);

    if (similarity > 0.5) {
        printf("Message is spam\n");
    } else {
        printf("Message is ham\n");
    }

    return 0;
}