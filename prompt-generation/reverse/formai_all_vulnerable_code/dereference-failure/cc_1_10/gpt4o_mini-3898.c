//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATIONS 100

// Struct to hold translation pairs.
typedef struct {
    char english[MAX_WORD_LENGTH];
    char catLanguage[MAX_WORD_LENGTH];
} Translation;

// Function prototypes
void initializeTranslations(Translation *translations);
void translateToCat(const char *input, Translation *translations, int translationCount);
void displayTranslations(Translation *translations, int translationCount);
void addTranslation(Translation *translations, int *translationCount, const char *english, const char *catLanguage);

int main() {
    // Create an array of translations
    Translation translations[MAX_TRANSLATIONS];
    int translationCount = 0;

    // Initialize translations
    initializeTranslations(translations);
    translationCount += 10;  // Arbitrary number of translations pre-loaded

    // Interactive interface
    char input[MAX_WORD_LENGTH];
    printf("Futuristic Cat Language Translator\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("\nEnter an English phrase to translate: ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            break;  // Exit the loop
        }

        // Perform translation
        translateToCat(input, translations, translationCount);
    }

    printf("Thank you for using the Futuristic Cat Language Translator!\n");
    return 0;
}

// Function to initialize predefined translations
void initializeTranslations(Translation *translations) {
    addTranslation(translations, &translations[0].english, "hello", "meow-meow");
    addTranslation(translations, &translations[1].english, "food", "nom-nom");
    addTranslation(translations, &translations[2].english, "play", "pounce");
    addTranslation(translations, &translations[3].english, "friend", "fur mate");
    addTranslation(translations, &translations[4].english, "sleep", "snooze");
    addTranslation(translations, &translations[5].english, "home", "cat castle");
    addTranslation(translations, &translations[6].english, "human", "big paw");
    addTranslation(translations, &translations[7].english, "out", "explore");
    addTranslation(translations, &translations[8].english, "love", "purr");
    addTranslation(translations, &translations[9].english, "water", "splashy");

    printf("Predefined translations loaded!\n");
}

// Function to translate English phrases to Cat Language
void translateToCat(const char *input, Translation *translations, int translationCount) {
    int translated = 0;
    
    for (int i = 0; i < translationCount; i++) {
        if (strcasecmp(input, translations[i].english) == 0) {
            printf("Cat Translation: %s\n", translations[i].catLanguage);
            translated = 1;
            break;  // Break on first match
        }
    }

    if (!translated) {
        printf("Translation not found: %s\n", input);
    }
}

// Function to add a new translation to the array
void addTranslation(Translation *translations, int *translationCount, const char *english, const char *catLanguage) {
    if (*translationCount < MAX_TRANSLATIONS) {
        strcpy(translations[*translationCount].english, english);
        strcpy(translations[*translationCount].catLanguage, catLanguage);
        (*translationCount)++;
    } else {
        printf("Translation table is full!\n");
    }
}