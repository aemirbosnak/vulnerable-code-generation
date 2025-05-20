//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_FEATURES 100
#define MAX_DOCS 1000

typedef struct {
    int id;
    char *text;
    int is_spam;
} doc_t;

typedef struct {
    int id;
    char *word;
    int count;
} feature_t;

typedef struct {
    int id;
    int doc_id;
    int feature_id;
    int value;
} feature_value_t;

int compare_docs(const void *a, const void *b) {
    doc_t *doc1 = (doc_t *)a;
    doc_t *doc2 = (doc_t *)b;
    return doc1->id - doc2->id;
}

int compare_features(const void *a, const void *b) {
    feature_t *feature1 = (feature_t *)a;
    feature_t *feature2 = (feature_t *)b;
    return strcmp(feature1->word, feature2->word);
}

int compare_feature_values(const void *a, const void *b) {
    feature_value_t *fv1 = (feature_value_t *)a;
    feature_value_t *fv2 = (feature_value_t *)b;
    return (fv1->doc_id - fv2->doc_id) * MAX_FEATURES + (fv1->feature_id - fv2->feature_id);
}

int main() {
    // Load the data set
    FILE *fp = fopen("spam.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    doc_t docs[MAX_DOCS];
    int num_docs = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *id_str = strtok(line, ",");
        int id = atoi(id_str);

        char *text = strtok(NULL, ",");
        size_t text_len = strlen(text);
        char *text_copy = malloc(text_len + 1);
        strcpy(text_copy, text);

        int is_spam = atoi(strtok(NULL, "\n"));

        docs[num_docs].id = id;
        docs[num_docs].text = text_copy;
        docs[num_docs].is_spam = is_spam;

        num_docs++;
    }

    fclose(fp);

    // Tokenize the documents and count the occurrences of each word
    feature_t features[MAX_FEATURES];
    int num_features = 0;

    for (int i = 0; i < num_docs; i++) {
        char *token = strtok(docs[i].text, " ");
        while (token != NULL) {
            int feature_id = -1;
            for (int j = 0; j < num_features; j++) {
                if (strcmp(token, features[j].word) == 0) {
                    feature_id = j;
                    break;
                }
            }

            if (feature_id == -1) {
                features[num_features].id = num_features;
                features[num_features].word = malloc(strlen(token) + 1);
                strcpy(features[num_features].word, token);
                features[num_features].count = 0;

                num_features++;

                feature_id = num_features - 1;
            }

            features[feature_id].count++;

            token = strtok(NULL, " ");
        }
    }

    // Sort the features by frequency
    qsort(features, num_features, sizeof(feature_t), compare_features);

    // Create the feature matrix
    feature_value_t feature_values[MAX_DOCS * MAX_FEATURES];
    int num_feature_values = 0;

    for (int i = 0; i < num_docs; i++) {
        char *token = strtok(docs[i].text, " ");
        while (token != NULL) {
            int feature_id = -1;
            for (int j = 0; j < num_features; j++) {
                if (strcmp(token, features[j].word) == 0) {
                    feature_id = j;
                    break;
                }
            }

            if (feature_id != -1) {
                feature_values[num_feature_values].id = num_feature_values;
                feature_values[num_feature_values].doc_id = docs[i].id;
                feature_values[num_feature_values].feature_id = feature_id;
                feature_values[num_feature_values].value = 1;

                num_feature_values++;
            }

            token = strtok(NULL, " ");
        }
    }

    // Sort the feature values by document and feature
    qsort(feature_values, num_feature_values, sizeof(feature_value_t), compare_feature_values);

    // Train the spam classifier
    int weights[MAX_FEATURES];
    for (int i = 0; i < num_features; i++) {
        weights[i] = 0;
    }

    int bias = 0;

    for (int i = 0; i < num_docs; i++) {
        int score = bias;
        for (int j = 0; j < num_features; j++) {
            score += weights[j] * feature_values[i * num_features + j].value;
        }

        if ((score > 0 && docs[i].is_spam == 0) || (score <= 0 && docs[i].is_spam == 1)) {
            for (int j = 0; j < num_features; j++) {
                weights[j] += feature_values[i * num_features + j].value * docs[i].is_spam;
            }

            bias += docs[i].is_spam;
        }
    }

    // Evaluate the spam classifier
    int true_positives = 0;
    int true_negatives = 0;
    int false_positives = 0;
    int false_negatives = 0;

    for (int i = 0; i < num_docs; i++) {
        int score = bias;
        for (int j = 0; j < num_features; j++) {
            score += weights[j] * feature_values[i * num_features + j].value;
        }

        if (score > 0) {
            if (docs[i].is_spam == 1) {
                true_positives++;
            } else {
                false_positives++;
            }
        } else {
            if (docs[i].is_spam == 0) {
                true_negatives++;
            } else {
                false_negatives++;
            }
        }
    }

    printf("True positives: %d\n", true_positives);
    printf("True negatives: %d\n", true_negatives);
    printf("False positives: %d\n", false_positives);
    printf("False negatives: %d\n", false_negatives);

    printf("Accuracy: %f\n", (float)(true_positives + true_negatives) / num_docs);
    printf("Precision: %f\n", (float)true_positives / (true_positives + false_positives));
    printf("Recall: %f\n", (float)true_positives / (true_positives + false_negatives));

    // Free the allocated memory
    for (int i = 0; i < num_docs; i++) {
        free(docs[i].text);
    }

    for (int i = 0; i < num_features; i++) {
        free(features[i].word);
    }

    return EXIT_SUCCESS;
}