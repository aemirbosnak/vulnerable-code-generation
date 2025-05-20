//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: complex
// A plethora of cosmic catalysts have converged in this ethereal domain, bestowing upon us the celestial enigma known as the Alien Language Translator.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A celestial lexicon that unravels the secrets of extraterrestrial conversations.
typedef struct AlienDictionary {
    char **glossary;
    int size;
} AlienDictionary;

// A celestial entity that facilitates communication between the Earthly realm and the cosmos.
typedef struct AlienTranslator {
    AlienDictionary *dictionary;
} AlienTranslator;

// A cosmic entity that wields the power to transmute extraterrestrial utterances into Earthly vernacular.
AlienTranslator *createAlienTranslator(char **glossary, int size) {
    AlienTranslator *translator = malloc(sizeof(AlienTranslator));
    translator->dictionary = malloc(sizeof(AlienDictionary));
    translator->dictionary->glossary = glossary;
    translator->dictionary->size = size;
    return translator;
}

// A cosmic entity that possesses the power to unravel the mysteries of extraterrestrial dialects.
char *translateAlienMessage(AlienTranslator *translator, char *message) {
    char *translatedMessage = malloc(strlen(message) + 1);
    int i, j;
    for (i = 0; message[i]; i++) {
        for (j = 0; j < translator->dictionary->size; j++) {
            if (translator->dictionary->glossary[j][0] == message[i]) {
                translatedMessage[i] = translator->dictionary->glossary[j][1];
                break;
            }
        }
    }
    translatedMessage[i] = '\0';
    return translatedMessage;
}

// A celestial entity that orchestrates the translation of extraterrestrial messages.
int main() {
    // A cosmic lexicon that encompasses the wisdom of the ancients.
    char **glossary = malloc(4 * sizeof(char *));
    glossary[0] = malloc(3 * sizeof(char));
    strcpy(glossary[0], "Q");
    glossary[1] = malloc(3 * sizeof(char));
    strcpy(glossary[1], "A");
    glossary[2] = malloc(3 * sizeof(char));
    strcpy(glossary[2], "W");
    glossary[3] = malloc(3 * sizeof(char));
    strcpy(glossary[3], "E");

    // An extraterrestrial emissary that carries the weight of universal communication.
    AlienTranslator *translator = createAlienTranslator(glossary, 4);

    // An intercepted extraterrestrial message that holds the secrets of the cosmos.
    char *message = "QWE";

    // A terrestrial interpretation of the extraterrestrial message, a beacon of wisdom from the depths of space.
    char *translatedMessage = translateAlienMessage(translator, message);

    // Unveiling the cosmic message, illuminating the darkness with its celestial wisdom.
    printf("Translated Message: %s\n", translatedMessage);

    return 0;
}