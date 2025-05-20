//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FEATURES 1000
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *token;
    int is_spam;
} Feature;

int compare_features(const void *a, const void *b) {
    Feature *feature_a = (Feature *)a;
    Feature *feature_b = (Feature *)b;

    return strcmp(feature_a->token, feature_b->token);
}

int main() {
    // Load the dataset of emails and their classifications (spam or not spam)
    FILE *dataset_file = fopen("dataset.txt", "r");
    if (dataset_file == NULL) {
        printf("Error: could not open dataset file.\n");
        return 1;
    }

    char line[MAX_TOKEN_LENGTH];
    Feature features[NUM_FEATURES];
    int num_spam_emails = 0;
    int num_not_spam_emails = 0;

    while (fgets(line, MAX_TOKEN_LENGTH, dataset_file)!= NULL) {
        char *token = strtok(line, " ");
        int is_spam = atoi(token);

        if (is_spam == 1) {
            num_spam_emails++;
        } else {
            num_not_spam_emails++;
        }

        Feature *feature = &features[num_spam_emails + num_not_spam_emails];
        strcpy(feature->token, token);
        feature->is_spam = is_spam;
    }

    fclose(dataset_file);

    // Sort the features alphabetically
    qsort(features, NUM_FEATURES, sizeof(Feature), compare_features);

    // Print the sorted list of features
    for (int i = 0; i < NUM_FEATURES; i++) {
        Feature *feature = &features[i];
        printf("%s %d\n", feature->token, feature->is_spam);
    }

    return 0;
}