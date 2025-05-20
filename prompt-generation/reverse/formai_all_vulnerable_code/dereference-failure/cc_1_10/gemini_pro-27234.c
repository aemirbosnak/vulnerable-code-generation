//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
/*
 * Smart Home Light Control for the Discerning Connoisseur
 *
 * A testament to the wisdom of Master Knuth, this program orchestrates
 * the illumination of your humble abode with unparalleled elegance and
 * precision.

 * Behold, the symphony of lights at your fingertips!
 *
 * "If you want your program to be fast, do not use a loop!
 *  But if you need it to be slow, then, by all means, loop away!"
 *
 * - Master Knuth, The Art of Computer Programming, Volume 1
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * A graceful structure to encapsulate the ethereal luminescence of a smart bulb.
 * Yes, humble apprentice, you may think of it as a virtual knob.
 */
typedef struct {
    bool is_on;
    unsigned int brightness;
} Bulb;

/*
 * A majestic array to hold the celestial bodies that adorn your home.
 * Each bulb is a universe unto itself, waiting for your command.
 */
Bulb bulbs[10];

/*
 * Behold, the wise master of the lights!
 * He weaves his spells with precision and grace, casting light upon your command.
 */
void LightMaster(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Oh, pitiful apprentice! Thy invocation is incomplete.\n");
        fprintf(stderr, "Syntax: %s bulb_index command [brightness]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Parse bulb index and command */
    int bulb_index = atoi(argv[1]) - 1;
    char* command = argv[2];

    /* Check that bulb index is within bounds */
    if (bulb_index < 0 || bulb_index >= 10) {
        fprintf(stderr, "Oh, foolish apprentice! Thy bulb index is out of bounds.\n");
        exit(EXIT_FAILURE);
    }

    /* Now, let us weave our incantations upon the light! */
    if (!strcmp(command, "on")) {
        bulbs[bulb_index].is_on = true;
        printf("Light unleashed upon bulb %d!\n", bulb_index + 1);
    } else if (!strcmp(command, "off")) {
        bulbs[bulb_index].is_on = false;
        printf("Darkness descends upon bulb %d.\n", bulb_index + 1);
    } else if (!strcmp(command, "bright")) {
        /* Increment brightness only if bulb is on */
        if (bulbs[bulb_index].is_on) {
            bulbs[bulb_index].brightness++;
            printf("Bulb %d glows brighter!\n", bulb_index + 1);
        } else {
            printf("Oh, hapless apprentice! Thy bulb must first be turned on.\n");
        }
    } else if (!strcmp(command, "dim")) {
        /* Decrement brightness only if bulb is on and not already at minimum */
        if (bulbs[bulb_index].is_on && bulbs[bulb_index].brightness > 0) {
            bulbs[bulb_index].brightness--;
            printf("Bulb %d dims slightly.\n", bulb_index + 1);
        } else {
            printf("Oh, misguided apprentice! Thy bulb cannot be dimmed further.\n");
        }
    } else {
        fprintf(stderr, "Oh, uncultured swine! Thy command is unknown to me.\n");
        exit(EXIT_FAILURE);
    }
}

/*
 * The main tapestry upon which our ethereal dance unfolds.
 */
int main(int argc, char* argv[]) {
    LightMaster(argc, argv);

    return EXIT_SUCCESS;
}