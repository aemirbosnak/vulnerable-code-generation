//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20
#define MAX_FEATURES 100

typedef struct {
    char* word;
    int count;
} Word;

typedef struct {
    Word* words;
    int num_words;
} Feature;

typedef struct {
    Feature* features;
    int num_features;
} Model;

Model* train_model(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[1000];
    int num_lines = 0;
    while (fgets(line, 1000, file) != NULL) {
        num_lines++;
    }
    fclose(file);

    Model* model = malloc(sizeof(Model));
    model->features = malloc(num_lines * sizeof(Feature));
    model->num_features = num_lines;

    file = fopen(filename, "r");
    int feature_index = 0;
    while (fgets(line, 1000, file) != NULL) {
        Feature* feature = &model->features[feature_index];
        feature->words = malloc(MAX_WORDS * sizeof(Word));
        feature->num_words = 0;

        char* word = strtok(line, " ");
        while (word != NULL) {
            int word_index = 0;
            while (word_index < feature->num_words && strcmp(word, feature->words[word_index].word) != 0) {
                word_index++;
            }
            if (word_index == feature->num_words) {
                feature->words[word_index].word = malloc(strlen(word) + 1);
                strcpy(feature->words[word_index].word, word);
                feature->words[word_index].count = 1;
                feature->num_words++;
            } else {
                feature->words[word_index].count++;
            }
            word = strtok(NULL, " ");
        }
        feature_index++;
    }
    fclose(file);

    return model;
}

int classify_email(Model* model, char* email) {
    int feature_scores[model->num_features];
    for (int i = 0; i < model->num_features; i++) {
        feature_scores[i] = 0;
    }

    char* word = strtok(email, " ");
    while (word != NULL) {
        int word_index = 0;
        while (word_index < model->features[0].num_words && strcmp(word, model->features[0].words[word_index].word) != 0) {
            word_index++;
        }
        if (word_index < model->features[0].num_words) {
            for (int i = 0; i < model->num_features; i++) {
                Feature* feature = &model->features[i];
                for (int j = 0; j < feature->num_words; j++) {
                    if (strcmp(word, feature->words[j].word) == 0) {
                        feature_scores[i] += feature->words[j].count;
                    }
                }
            }
        }
        word = strtok(NULL, " ");
    }

    int max_score = 0;
    int max_score_index = -1;
    for (int i = 0; i < model->num_features; i++) {
        if (feature_scores[i] > max_score) {
            max_score = feature_scores[i];
            max_score_index = i;
        }
    }

    return max_score_index;
}

int main() {
    Model* model = train_model("spam.txt");
    int result = classify_email(model, "This is a spam email.");
    if (result == 0) {
        printf("The email is spam.\n");
    } else {
        printf("The email is not spam.\n");
    }

    return 0;
}