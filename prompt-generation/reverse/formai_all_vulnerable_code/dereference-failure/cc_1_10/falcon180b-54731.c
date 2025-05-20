//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct conspiracy_theory {
    char *name;
    char *description;
};

struct conspiracy_theory generate_theory(void) {
    struct conspiracy_theory theory;
    theory.name = (char*)malloc(50 * sizeof(char));
    theory.description = (char*)malloc(200 * sizeof(char));

    srand(time(NULL));
    int random_index = rand() % 5;

    switch(random_index) {
        case 0:
            strcpy(theory.name, "The Moon Landing Hoax");
            strcpy(theory.description, "The Apollo moon landings were faked by NASA and the U.S. government.");
            break;
        case 1:
            strcpy(theory.name, "The Illuminati");
            strcpy(theory.description, "A secret society that controls world events and governments.");
            break;
        case 2:
            strcpy(theory.name, "Flat Earth Theory");
            strcpy(theory.description, "The belief that the Earth is flat and not a sphere.");
            break;
        case 3:
            strcpy(theory.name, "9/11 Conspiracy");
            strcpy(theory.description, "The belief that the U.S. government orchestrated the 9/11 attacks.");
            break;
        case 4:
            strcpy(theory.name, "Area 51");
            strcpy(theory.description, "A top-secret U.S. Air Force facility believed to house extraterrestrial life and UFOs.");
            break;
    }

    return theory;
}

void print_theory(struct conspiracy_theory theory) {
    printf("Name: %s\n", theory.name);
    printf("Description: %s\n", theory.description);
}

int main(void) {
    struct conspiracy_theory theory = generate_theory();
    print_theory(theory);

    free(theory.name);
    free(theory.description);

    return 0;
}