//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_SUPPORT 0.1

// Structure to represent a document
typedef struct {
    char *title;
    char *author;
    char *content[5];
} doc;

// Function to tokenize a document
void tokenize(doc *doc) {
    char *token = strtok(doc->content[0], " ");
    int i = 0;
    while (token != NULL && i < 5) {
        doc->content[i++] = token;
        token = strtok(NULL, " ");
    }
}

// Function to calculate the TF-IDF weight for a document
double calculate_tf_idf(doc *doc) {
    int i = 0;
    double sum = 0;
    for (i = 0; i < 5; i++) {
        sum += (doc->content[i][0] == ' ' ? 1 : 0) * (doc->content[i][1] == ' ' ? 1 : 0);
    }
    return sum / (i * (i + 1)) * log(doc->content[0][0] == ' ' ? 1 : 0);
}

// Function to mine frequent phrases
void mine_phrases(doc *docs, int num_docs) {
    int i, j, k;
    char *phrase;
    double tf_idf[5];

    // Initialize the frequency and TF-IDF arrays
    for (i = 0; i < 5; i++) {
        for (j = 0; j < num_docs; j++) {
            tf_idf[i] = 0;
        }
    }

    // Loop through each document and calculate the TF-IDF weight for each phrase
    for (i = 0; i < num_docs; i++) {
        for (j = 0; j < 5; j++) {
            phrase = docs[i].content[j];
            for (k = 0; k < i; k++) {
                if (strcmp(docs[k].content[j], phrase) == 0) {
                    tf_idf[j]++;
                    break;
                }
            }
        }
    }

    // Print the top N frequent phrases
    for (i = 0; i < 5; i++) {
        if (tf_idf[i] > MIN_SUPPORT) {
            printf("%s (%.2f%%)\n", docs[0].content[i], (tf_idf[i] * 100) / num_docs);
        }
    }
}

int main() {
    // Load the documents from a file
    char *file = "documents.txt";
    FILE *fp = fopen(file, "r");
    char line[100];
    int num_docs = 0;

    // Tokenize and calculate the TF-IDF weight for each document
    doc *docs = calloc(1, sizeof(doc));
    while (fgets(line, 100, fp)) {
        num_docs++;
        docs[num_docs - 1].title = strtok(line, " ");
        docs[num_docs - 1].author = strtok(NULL, " ");
        for (int i = 0; i < 5; i++) {
            docs[num_docs - 1].content[i] = strtok(NULL, " ");
        }
        tokenize(docs + num_docs - 1);
        calculate_tf_idf(docs + num_docs - 1);
    }

    // Mine the frequent phrases
    mine_phrases(docs, num_docs);

    return 0;
}