//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Juliet {
    char *name;
    char *fate;
} Juliet;

typedef struct Romeo {
    char *name;
    char *fate;
    Juliet *lovedJuliet;
} Romeo;

void declareLove(Romeo *romeo, Juliet *juliet) {
    printf("%s declares to %s: \"Oh, how my heart beats for thee!\"\n", romeo->name, juliet->name);
    romeo->lovedJuliet = juliet;
}

void tragicEnd(Romeo *romeo) {
    printf("%s meets a tragic fate, believing his love has departed.\n", romeo->name);
}

void yesToLove(Romeo *romeo, Juliet *juliet) {
    printf("%s and %s, their hearts entwined in a dance of love.\n", romeo->name, juliet->name);
    printf("Together they whisper promises into the night.\n");
}

void createRomeo(Romeo **r) {
    *r = (Romeo *)malloc(sizeof(Romeo));
    if (*r == NULL) {
        fprintf(stderr, "Memory allocation failed for Romeo.\n");
        exit(EXIT_FAILURE);
    }
    (*r)->name = strdup("Romeo");
    (*r)->fate = strdup("Destined for sorrow");
    (*r)->lovedJuliet = NULL;
    declareLove(*r, NULL);
}

void createJuliet(Juliet **j) {
    *j = (Juliet *)malloc(sizeof(Juliet));
    if (*j == NULL) {
        fprintf(stderr, "Memory allocation failed for Juliet.\n");
        exit(EXIT_FAILURE);
    }
    (*j)->name = strdup("Juliet");
    (*j)->fate = strdup("A love that knows no bounds");
}

void freeRomeo(Romeo *r) {
    if (r) {
        if (r->name) free(r->name);
        if (r->fate) free(r->fate);
        free(r);
    }
}

void freeJuliet(Juliet *j) {
    if (j) {
        if (j->name) free(j->name);
        if (j->fate) free(j->fate);
        free(j);
    }
}

int main() {
    Romeo *romeo;
    Juliet *juliet;

    createRomeo(&romeo);
    createJuliet(&juliet);

    printf("\nIn fair Verona, where we lay our scene...\n");
    printf("The sun sets, casting a glow upon %s and %s.\n", romeo->name, juliet->name);

    declareLove(romeo, juliet);
    yesToLove(romeo, juliet);
    
    printf("%s and %s enter a world filled with passion and peril.\n", romeo->name, juliet->name);
    
    romeo->lovedJuliet = juliet;
    
    printf("But fate is cruel in its jest...\n");
    
    tragicEnd(romeo);

    freeRomeo(romeo);
    freeJuliet(juliet);

    printf("\nThus ends the tale of love, loss, and betrayal...\n");
    
    return 0;
}