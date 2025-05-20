//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// A noble structure for a translation of words and phrases
typedef struct {
    char english[50];
    char catLanguage[50];
} Translation;

// Look ye upon the translations of words, behold!
Translation dictionary[] = {
    {"hello", "meow"},
    {"love", "purr"},
    {"friend", "whiskers"},
    {"night", "hiss"},
    {"light", "tail"},
    {"moon", "feline"},
    {"stars", "pawprints"},
    {"Juliet", "purr-iet"},
    {"Romeo", "meow-eo"},
    {"kiss", "nuzzle"},
    {"sorrow", "whine"},
    {"fight", "claw"},
    {"destiny", "paws"},
    {"heart", "furry soul"},
    {"tear", "meow-ble"},
    {"wound", "scratch"},
    {"forever", "nine lives"},
    {"fate", "claw-tastrophe"},
    {"nightingale", "night-paw"},
    {"dream", "catnap"},
    {"hope", "hiss-pectation"},
};

#define DICTIONARY_SIZE (sizeof(dictionary) / sizeof(dictionary[0]))

// A function to translate from English to Cat Language
void translateToCatLanguage(const char* input) {
    char *token = strtok(input, " ");
    printf("In the language of cats, thou dost say:\n");

    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < DICTIONARY_SIZE; i++) {
            if (strcasecmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].catLanguage);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%s ", token); // If no translation is found, say it as is.
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

// A noble act to capture the speech of our dear Romeo
void speakAsRomeo() {
    printf("Romeo: But, soft! What light through yonder window breaks?\n");
    printf("Alas, I proclaim my love for sweet Juliet in Cat Language:\n");
    translateToCatLanguage("I love you, my dear Juliet");
}

// A noble act to capture the speech of our dear Juliet
void speakAsJuliet() {
    printf("Juliet: O Romeo, Romeo! Wherefore art thou Romeo?\n");
    printf("My heart dost leap in delight for thee, fair Romeo:\n");
    translateToCatLanguage("My heart aches for you, my love");
}

// The main event of the grand play, let it commence!
int main() {
    printf("~~ A Cat's Tale of Romeo and Juliet ~~\n\n");
    speakAsRomeo();
    printf("\n");
    speakAsJuliet();
    
    printf("\nLet us gather thy words, fair audience:\n");
    char userInput[256];
    printf("Translate thy phrase to Cat Language: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0; // Remove newline character
    translateToCatLanguage(userInput);
    
    return 0;
}