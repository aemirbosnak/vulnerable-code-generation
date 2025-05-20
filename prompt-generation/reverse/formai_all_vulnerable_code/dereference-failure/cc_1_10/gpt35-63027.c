//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for storing statistical information about translated words
typedef struct {
    char original[50];
    char translated[50];
    int count;
} Translation;

int main() {
    int numTranslations;
    printf("Enter number of translations: ");
    scanf("%d", &numTranslations);

    // Allocate memory for translation statistics
    Translation* translations = (Translation*) malloc(numTranslations * sizeof(Translation));

    // Prompt user to enter translations and update statistics
    for (int i = 0; i < numTranslations; i++) {
        printf("Enter original word: ");
        scanf("%s", translations[i].original);
        printf("Enter translation in C Cat Language: ");
        scanf("%s", translations[i].translated);

        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(translations[i].translated, translations[j].translated) == 0) {
                translations[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(translations[i].translated, translations[i].translated);
            translations[i].count = 1;
        }
    }

    // Print translation statistics
    printf("\nTranslation Statistics:\n");
    printf("%-20s %-20s %s\n", "Original Word", "Translation", "Count");
    for (int i = 0; i < numTranslations; i++) {
        printf("%-20s %-20s %d\n", translations[i].original, translations[i].translated, translations[i].count);
    }

    // Clean up memory
    free(translations);

    return 0;
}