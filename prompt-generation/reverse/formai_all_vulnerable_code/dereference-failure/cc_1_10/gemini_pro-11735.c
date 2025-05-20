//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: medieval
// A Knightly Error Handling Adventure

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Define the errant squire, who handles all errors
int errant_squire(int errnum) {
    switch (errnum) {
        case EIO:
            printf("Alas, my liege, a dread troll hath invaded the stables and devoured the steeds!\n");
            return -1;
        case EACCES:
            printf("The castle gates stand barred, my lord. We cannot proceed without the key!\n");
            return -1;
        case ENOTCONN:
            printf("The drawbridge hath been lowered, but the moat is dry. We cannot cross!\n");
            return -1;
        default:
            printf("A mysterious evil hath befallen us, my lord. I know not its name.\n");
            return -1;
    }
}

int main(void) {
    // The noble knight sets out on a perilous quest
    int err = 0;

    // He traverses a dense forest
    FILE *forest = fopen("forest.txt", "r");
    if (forest == NULL) {
        err = errno;
        errant_squire(err);
        return -1;
    }

    // He battles a monstrous dragon
    int dragon = rand() % 2;
    if (dragon == 1) {
        err = EIO;
        errant_squire(err);
        return -1;
    }

    // He crosses a raging river
    FILE *river = fopen("river.txt", "r");
    if (river == NULL) {
        err = errno;
        errant_squire(err);
        return -1;
    }

    // He enters a treacherous dungeon
    int dungeon = rand() % 2;
    if (dungeon == 1) {
        err = EACCES;
        errant_squire(err);
        return -1;
    }

    // He slays an evil sorcerer
    int sorcerer = rand() % 2;
    if (sorcerer == 1) {
        err = ENOTCONN;
        errant_squire(err);
        return -1;
    }

    // He returns to his castle triumphant
    printf("By the grace of the gods, we have triumphed over all obstacles and returned victorious!\n");
    return 0;
}