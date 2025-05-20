//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: medieval
// In the name of the wise and noble King Artur,
// may this code bring glory and honor to thee.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// Function to print a knight's name
void print_knight_name(char name[50]) {
    printf("Sir %s, valiant knight of Camelot,\n", name);
}

int main() {
    // Declaring a knight's name
    char knight_name[50];

    // Initializing the knight's name
    strcpy(knight_name, "Lancelot");

    int i; // Integer counter
    bool is_knight = true; // Boolean flag
    char title[10] = "Sir"; // Character array for the title

    // Looping 10 times to print the knight's name
    for (i = 0; i < 10; i++) {
        if (is_knight) {
            print_knight_name(knight_name);
            printf("%s, thou art brave and true,\n", knight_name);
        } else {
            switch(i % 3) {
                case 0:
                    strcpy(title, "Lady");
                    break;
                case 1:
                    strcpy(title, "Squire");
                    break;
                case 2:
                    strcpy(title, "Dame");
                    break;
                default:
                    break;
            }
            printf("%s%s, noble and virtuous,\n", title, knight_name);
        }
        is_knight = !is_knight;
    }

    // Freeing memory allocated by strcpy
    free(knight_name);

    return 0;
}