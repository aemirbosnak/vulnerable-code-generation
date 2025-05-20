//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRINGS 10
#define MAX_LENGTH 100

void surreal_caterpillar(char *input, char *output) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            output[i] = input[len - 1 - i]; // Reverse every second character
        } else {
            output[i] = input[i]; // Keep original character
        }
    }
    output[len] = '\0';
}

char* whimsical_cloud(int count) {
    char *cloud = (char *)malloc(count * sizeof(char));
    for (int i = 0; i < count; i++) {
        cloud[i] = (char)(rand() % 26 + 97); // Random lower-case letters
    }
    cloud[count] = '\0';
    return cloud;
}

void echoing_river(char *input, char *echo) {
    sprintf(echo, "%s %s %s", input, input, input); // Triple the string
}

int main() {
    srand(time(0));
    
    char strings[MAX_STRINGS][MAX_LENGTH];
    char transformed[MAX_LENGTH];
    char echoed[MAX_LENGTH];
    
    // Let's populate the strings with surreal dreams
    for (int i = 0; i < MAX_STRINGS; i++) {
        int length = rand() % (MAX_LENGTH - 1) + 1; // random length between 1 and MAX_LENGTH
        char *dream = whimsical_cloud(length);
        strcpy(strings[i], dream);
        free(dream);
    }

    printf("Welcome to the Surreal String Manipulator!\n");
    printf("Here are your dream strings:\n");
    
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("Dream %d: %s\n", i + 1, strings[i]);
    }

    // Transforming the strings
    printf("\nTransforming the strings into caterpillar motifs...\n");
    for (int i = 0; i < MAX_STRINGS; i++) {
        surreal_caterpillar(strings[i], transformed);
        printf("Caterpillar Dream %d: %s\n", i + 1, transformed);
    }
    
    // Echos through the echoing river
    printf("\nSending the dreams down the echoing river...\n");
    for (int i = 0; i < MAX_STRINGS; i++) {
        echoing_river(strings[i], echoed);
        printf("Echoing Dream %d: %s\n", i + 1, echoed);
    }

    // The kaleidoscope of the surreal experience
    printf("\nThe kaleidoscope spins...\n");
    for (int i = 0; i < MAX_STRINGS; i++) {
        char kaleidoscope[MAX_LENGTH];
        snprintf(kaleidoscope, sizeof(kaleidoscope), "Dream: '%s' becomes '%s'", strings[i], transformed);
        printf("%s\n", kaleidoscope);
    }

    // The clouds of abstraction linger
    printf("\nThe ethereal clouds drift away, leaving trails behind...\n");
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("Dream %d in abstraction: ", i + 1);
        for (int j = 0; j < strlen(strings[i]); j++) {
            printf("%c ", strings[i][j]);
        }
        printf("\n");
    }

    // A finale of stars
    printf("\nAnd now, let us gaze upon the stars...\n");
    for (int i = 0; i < MAX_STRINGS; i++) {
        for (int j = 0; j < MAX_LENGTH - 1; j++) {
            if (j % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("  Dream %d\n", i + 1);
    }

    // Clean exit into the void
    printf("\nAs the program fades into oblivion, all strings are returned to the cosmic ether.\n");
    return 0;
}