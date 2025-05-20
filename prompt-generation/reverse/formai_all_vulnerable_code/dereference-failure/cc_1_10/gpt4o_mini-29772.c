//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayError(const char *message) {
    fprintf(stderr, "Alas! An error hath occurred: %s\n", message);
}

void die(const char *reason) {
    displayError(reason);
    exit(EXIT_FAILURE);
}

typedef struct Montague {
    char *name;
    int fate; // 0: alive, 1: dead
} Montague;

typedef struct Capulet {
    char *name;
    int fate; // 0: alive, 1: dead
} Capulet;

Montague *createMontague(const char *name) {
    Montague *m = malloc(sizeof(Montague));
    if (!m) die("The spirit of programming doth elude me; memory allocation failed.");
    m->name = malloc(strlen(name) + 1);
    if (!m->name) {
        free(m);
        die("The ghost of memory hath haunted me; name allocation failed.");
    }
    strcpy(m->name, name);
    m->fate = 0; // alive
    return m;
}

Capulet *createCapulet(const char *name) {
    Capulet *c = malloc(sizeof(Capulet));
    if (!c) die("Verily, I cannot create a Capulet; memory allocation hath perished.");
    c->name = malloc(strlen(name) + 1);
    if (!c->name) {
        free(c);
        die("Oh, dread! The name allocation has faltered for a Capulet.");
    }
    strcpy(c->name, name);
    c->fate = 0; // alive
    return c;
}

void freeMontague(Montague *m) {
    if (m) {
        free(m->name);
        free(m);
    }
}

void freeCapulet(Capulet *c) {
    if (c) {
        free(c->name);
        free(c);
    }
}

void piqueFate(Montague *m, Capulet *c) {
    if (m->fate == 0 && c->fate == 0) {
        m->fate = 1; // dead
        c->fate = 1; // dead
        printf("Oh, tragic! %s and %s have met their cruel fate!\n", m->name, c->name);
    } else {
        printf("Nay! One or both are already lost to the realm of the shadows.\n");
    }
}

void displayFate(Montague *m, Capulet *c) {
    printf("%s is %s\n", m->name, m->fate == 0 ? "alive" : "departed"); 
    printf("%s is %s\n", c->name, c->fate == 0 ? "alive" : "departed");
}

int main() {
    Montague *romeo = createMontague("Romeo");
    Capulet *juliet = createCapulet("Juliet");

    printf("In fair Verona, where we lay our scene...\n");
    
    displayFate(romeo, juliet);
    
    printf("When suddenly fate intervenes...\n");
    
    piqueFate(romeo, juliet);
    
    displayFate(romeo, juliet);
    
    freeMontague(romeo);
    freeCapulet(juliet);
    
    return EXIT_SUCCESS;
}