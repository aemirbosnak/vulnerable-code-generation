//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define NUM_FEATURES 10000
#define MIN_DOCUMENT_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFeature;

typedef struct {
    WordFeature *features;
    int numFeatures;
    int docLength;
} Document;

void tokenize(char *text, int docLength, WordFeature *features) {
    char *token = strtok(text, ",.?!;:");
    while (token!= NULL && features < NUM_FEATURES) {
        int len = strlen(token);
        if (len > 0 && len <= MAX_WORD_LENGTH) {
            strcpy(features->word, token);
            features->count = 1;
            features++;
        }
        token = strtok(NULL, ",.?!;:");
    }
}

int compare(const void *a, const void *b) {
    WordFeature *w1 = (WordFeature *)a;
    WordFeature *w2 = (WordFeature *)b;
    return strcmp(w1->word, w2->word);
}

void sort(WordFeature *features, int numFeatures) {
    qsort(features, numFeatures, sizeof(WordFeature), compare);
}

int main() {
    FILE *fp;
    char line[1024];
    char *text = NULL;
    int docLength = 0;
    WordFeature *features = NULL;
    int numFeatures = 0;
    int i;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: unable to open input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        docLength += strlen(line);
        if (docLength > MIN_DOCUMENT_LENGTH) {
            break;
        }
        text = realloc(text, docLength + 1);
        strcat(text, line);
    }

    features = malloc(NUM_FEATURES * sizeof(WordFeature));
    numFeatures = 0;
    tokenize(text, docLength, features);
    sort(features, numFeatures);

    printf("Document length: %d\n", docLength);
    printf("Number of features: %d\n", numFeatures);
    for (i = 0; i < numFeatures; i++) {
        printf("%s: %d\n", features[i].word, features[i].count);
    }

    free(text);
    free(features);
    fclose(fp);

    return 0;
}