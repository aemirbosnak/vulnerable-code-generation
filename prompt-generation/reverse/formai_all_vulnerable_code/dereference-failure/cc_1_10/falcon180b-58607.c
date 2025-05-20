//Falcon-180B DATASET v1.0 Category: Data mining ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100
#define NUM_FEATURES 20

struct feature {
    char *name;
    int count;
};

struct document {
    char *text;
    struct feature *features;
};

struct document *documents;
int num_documents;
int num_features;

void tokenize(char *text) {
    char *token = strtok(text, " \t\n\r\f\v");
    while (token!= NULL) {
        int len = strlen(token);
        if (len > MAX_WORD_LENGTH) {
            len = MAX_WORD_LENGTH;
        }
        strncpy(documents[num_documents].features[num_features].name, token, len);
        documents[num_documents].features[num_features].count = 1;
        num_features++;
        token = strtok(NULL, " \t\n\r\f\v");
    }
}

void load_documents() {
    FILE *fp = fopen("documents.txt", "r");
    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        documents[num_documents].text = strdup(line);
        tokenize(documents[num_documents].text);
        num_documents++;
    }
    fclose(fp);
}

int compare_features(const void *a, const void *b) {
    struct feature *fa = (struct feature *)a;
    struct feature *fb = (struct feature *)b;
    return strcmp(fa->name, fb->name);
}

void print_features() {
    qsort(documents[0].features, num_features, sizeof(struct feature), compare_features);
    for (int i = 0; i < num_features; i++) {
        printf("%s: %d\n", documents[0].features[i].name, documents[0].features[i].count);
    }
}

int main() {
    documents = malloc(MAX_WORDS * sizeof(struct document));
    num_documents = 0;
    num_features = 0;
    load_documents();
    print_features();
    return 0;
}