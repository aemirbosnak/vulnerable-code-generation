//GEMINI-pro DATASET v1.0 Category: Educational ; Style: curious
// Behold, the curious tale of a C educational escapade!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// A merry band of curious characters
typedef struct {
    char* name;
    int age;
    float height;
} CuriousCharacter;

// A parchment for their curious musings
typedef struct {
    char* text;
    int length;
} CuriousParchment;

// The grand stage for our curious adventures
typedef struct {
    CuriousCharacter** characters;
    int numCharacters;

    CuriousParchment** parchments;
    int numParchments;
} CuriousRealm;

// Let us conjure a curious realm
CuriousRealm* createCuriousRealm() {
    CuriousRealm* realm = malloc(sizeof(CuriousRealm));

    realm->characters = malloc(sizeof(CuriousCharacter*) * 10);
    realm->numCharacters = 0;

    realm->parchments = malloc(sizeof(CuriousParchment*) * 10);
    realm->numParchments = 0;

    return realm;
}

// Let us add a curious character to our realm
void addToRealm(CuriousRealm* realm, char* name, int age, float height) {
    if (realm->numCharacters >= 10) {
        printf("The realm is too crowded, weary traveler.");
    } else {
        CuriousCharacter* character = malloc(sizeof(CuriousCharacter));
        character->name = strdup(name);
        character->age = age;
        character->height = height;

        realm->characters[realm->numCharacters++] = character;

        printf("Welcome to the realm, curious %s!\n", name);
    }
}

// Let us add a curious parchment to our realm
void addParchment(CuriousRealm* realm, char* text, int length) {
    if (realm->numParchments >= 10) {
        printf("The library is bursting at the seams, scribe.");
    } else {
        CuriousParchment* parchment = malloc(sizeof(CuriousParchment));
        parchment->text = strdup(text);
        parchment->length = length;

        realm->parchments[realm->numParchments++] = parchment;

        printf("Your parchment has found a home, curious scribe.\n");
    }
}

// Let us peruse the curious characters in our realm
void exploreCharacters(CuriousRealm* realm) {
    if (realm->numCharacters == 0) {
        printf("The realm is eerily empty, like a forgotten dream.");
    } else {
        printf("Behold, the curious inhabitants of our realm:\n");

        for (int i = 0; i < realm->numCharacters; i++) {
            printf("%s - Age: %d, Height: %.2f\n",
                realm->characters[i]->name,
                realm->characters[i]->age,
                realm->characters[i]->height);
        }

        printf("May their curious spirits inspire your own.\n");
    }
}

// Let us read the curious parchments in our realm
void readParchments(CuriousRealm* realm) {
    if (realm->numParchments == 0) {
        printf("The library shelves are barren, like a scholar's mind without knowledge.");
    } else {
        printf("Unveil the wisdom contained within our curious parchments:\n");

        for (int i = 0; i < realm->numParchments; i++) {
            printf("Parchment #%d:\n%s\n",
                i + 1,
                realm->parchments[i]->text);
        }

        printf("May the words ignite the flame of curiosity within you.\n");
    }
}

// Let us depart from the curious realm
void farewellRealm(CuriousRealm* realm) {
    for (int i = 0; i < realm->numCharacters; i++) {
        free(realm->characters[i]->name);
        free(realm->characters[i]);
    }

    free(realm->characters);

    for (int i = 0; i < realm->numParchments; i++) {
        free(realm->parchments[i]->text);
        free(realm->parchments[i]);
    }

    free(realm->parchments);

    free(realm);

    printf("Farewell, curious traveler. May your adventures be filled with wonder and discovery.\n");
}

int main() {
    CuriousRealm* realm = createCuriousRealm();

    addToRealm(realm, "Aetheria", 123, 1.65);
    addToRealm(realm, "Zenith", 456, 1.82);
    addToRealm(realm, "Orion", 789, 2.01);

    addParchment(realm, "The wisdom of the ancients lies not in their knowledge, but in their curiosity.", 75);
    addParchment(realm, "The greatest adventures begin with a single step into the unknown.", 63);
    addParchment(realm, "To explore is to learn, and to learn is to grow.", 49);

    exploreCharacters(realm);
    readParchments(realm);
    farewellRealm(realm);

    return 0;
}