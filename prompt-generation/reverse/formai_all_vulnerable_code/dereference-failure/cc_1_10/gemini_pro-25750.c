//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_TOKENS 1000
#define MAX_FEATURES 10000

typedef struct {
    int id;
    char *feature;
    double weight;
} Feature;

typedef struct {
    int id;
    char *text;
    int num_tokens;
    double score;
} Document;

Feature *features[MAX_FEATURES];
Document *documents[MAX_TOKENS];
int num_features = 0;
int num_documents = 0;

void init_features() {
    features[0] = malloc(sizeof(Feature));
    features[0]->id = 0;
    features[0]->feature = "positive";
    features[0]->weight = 1.0;

    features[1] = malloc(sizeof(Feature));
    features[1]->id = 1;
    features[1]->feature = "negative";
    features[1]->weight = -1.0;
}

void init_documents() {
    documents[0] = malloc(sizeof(Document));
    documents[0]->id = 0;
    documents[0]->text = "I love this product!";
    documents[0]->num_tokens = 3;
    documents[0]->score = 1.0;

    documents[1] = malloc(sizeof(Document));
    documents[1]->id = 1;
    documents[1]->text = "This product is terrible!";
    documents[1]->num_tokens = 3;
    documents[1]->score = -1.0;
}

double calculate_score(Document *document) {
    double score = 0.0;
    for (int i = 0; i < document->num_tokens; i++) {
        for (int j = 0; j < num_features; j++) {
            if (strcmp(document->text[i], features[j]->feature) == 0) {
                score += features[j]->weight;
            }
        }
    }
    return score;
}

int main() {
    init_features();
    init_documents();

    for (int i = 0; i < num_documents; i++) {
        documents[i]->score = calculate_score(documents[i]);
    }

    for (int i = 0; i < num_documents; i++) {
        printf("%s: %.2f\n", documents[i]->text, documents[i]->score);
    }

    return 0;
}