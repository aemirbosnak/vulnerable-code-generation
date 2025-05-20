//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50
#define WORD_FILE "words.txt"

typedef struct {
    char *name;
    int age;
} person_t;

person_t *generate_person(void) {
    person_t *person = malloc(sizeof(person_t));

    person->name = malloc(MAX_WORDS * sizeof(char));
    person->age = rand() % 100;

    FILE *file = fopen(WORD_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open word file.\n");
        exit(1);
    }

    char word[MAX_WORDS];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        strcat(person->name, word);
        strcat(person->name, " ");
        i++;
        if (i >= MAX_WORDS) {
            break;
        }
    }

    fclose(file);
    return person;
}

void free_person(person_t *person) {
    free(person->name);
    free(person);
}

void generate_conspiracy(person_t *person, char *conspiracy) {
    char *verb = "is secretly ";
    char *preposition = " in ";
    char *object = "a conspiracy to ";

    strcat(conspiracy, verb);
    strcat(conspiracy, person->name);
    strcat(conspiracy, preposition);
    strcat(conspiracy, object);

    int length = strlen(conspiracy);
    conspiracy[length] = '\0';
}

int main(void) {
    srand(time(NULL));

    person_t *person = generate_person();
    char conspiracy[MAX_WORDS * 3] = "";

    generate_conspiracy(person, conspiracy);

    printf("The %s %s %s.\n", person->name, conspiracy, person->age < 18? "is too young to be involved in" : "is a key player in");

    free_person(person);
    return 0;
}