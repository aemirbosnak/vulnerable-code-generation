//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock Holmes' Case Solver

// Function to analyze the evidence
char *analyzeEvidence(char *evidence) {

    // Preprocessing
    char *cleanEvidence = malloc(strlen(evidence) + 1);
    strcpy(cleanEvidence, evidence);
    for (int i = 0; cleanEvidence[i]; i++) {
        cleanEvidence[i] = tolower(cleanEvidence[i]);
    }

    // Analyze suspects
    char *suspects[] = {"Watson", "Lestrade", "Moriarty"};

    // Check for keywords associated with each suspect
    char *keywordsWatson[] = {"loyal", "faithful", "assistant"};
    char *keywordsLestrade[] = {"incompetent", "bumbling", "inspector"};
    char *keywordsMoriarty[] = {"cunning", "arch nemesis", "criminal mastermind"};

    // Initialize suspect scores
    int scores[3] = {0};

    // Count keyword occurrences for each suspect
    for (int i = 0; i < 3; i++) {
        for (int j = 0; keywordsWatson[j]; j++) {
            scores[i] += strstr(cleanEvidence, keywordsWatson[j]) != NULL;
        }
        for (int j = 0; keywordsLestrade[j]; j++) {
            scores[i] += strstr(cleanEvidence, keywordsLestrade[j]) != NULL;
        }
        for (int j = 0; keywordsMoriarty[j]; j++) {
            scores[i] += strstr(cleanEvidence, keywordsMoriarty[j]) != NULL;
        }
    }

    // Identify the suspect with the highest score
    int maxScore = 0;
    int maxIndex = -1;
    for (int i = 0; i < 3; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            maxIndex = i;
        }
    }

    // Return the conclusion
    char *conclusion = malloc(100);
    sprintf(conclusion, "The most likely suspect is: %s", suspects[maxIndex]);
    free(cleanEvidence);
    return conclusion;
}

// Function to handle user input
int main() {

    // Introduction
    printf("Sherlock Holmes' Case Solver\n");
    printf("---------------------------\n");

    // Get the evidence from the user
    printf("Enter the evidence gathered from the crime scene:\n");
    char *evidence = malloc(1000);
    fgets(evidence, 1000, stdin);

    // Analyze the evidence
    char *conclusion = analyzeEvidence(evidence);

    // Present the conclusion
    printf("\nConclusion:\n");
    printf("%s\n", conclusion);

    // Free allocated memory
    free(evidence);
    free(conclusion);

    return 0;
}