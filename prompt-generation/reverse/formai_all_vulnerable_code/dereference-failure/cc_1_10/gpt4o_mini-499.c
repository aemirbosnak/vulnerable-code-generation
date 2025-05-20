//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char family[50];
} Character;

typedef struct {
    Character *characters;
    int count;
} Play;

void createCharacter(Play *play, const char *name, int age, const char *family) {
    play->characters = realloc(play->characters, sizeof(Character) * (play->count + 1));
    strcpy(play->characters[play->count].name, name);
    play->characters[play->count].age = age;
    strcpy(play->characters[play->count].family, family);
    play->count++;
}

void displayCharacters(Play *play) {
    for (int i = 0; i < play->count; i++) {
        printf("Character: %s, Age: %d, Family: %s\n", 
                play->characters[i].name, 
                play->characters[i].age, 
                play->characters[i].family);
    }
}

void sortCharactersByAge(Play *play) {
    for (int i = 0; i < play->count - 1; i++) {
        for (int j = i + 1; j < play->count; j++) {
            if (play->characters[i].age > play->characters[j].age) {
                Character temp = play->characters[i];
                play->characters[i] = play->characters[j];
                play->characters[j] = temp;
            }
        }
    }
}

void freePlay(Play *play) {
    free(play->characters);
    play->count = 0;
}

int main() {
    Play play = {NULL, 0};

    // Creating Characters in the style of Romeo and Juliet
    createCharacter(&play, "Romeo Montague", 20, "Montague");
    createCharacter(&play, "Juliet Capulet", 18, "Capulet");
    createCharacter(&play, "Mercutio", 21, "None");
    createCharacter(&play, "Tybalt Capulet", 19, "Capulet");
    createCharacter(&play, "Benvolio", 21, "Montague");
    createCharacter(&play, "Nurse", 50, "None");

    printf("Characters in the play:\n");
    displayCharacters(&play);

    printf("\nCharacters sorted by age:\n");
    sortCharactersByAge(&play);
    displayCharacters(&play);

    // Free allocated memory
    freePlay(&play);
    
    return 0;
}