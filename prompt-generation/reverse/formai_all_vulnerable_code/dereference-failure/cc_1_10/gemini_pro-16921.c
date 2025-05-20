//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sherlock Holmes' Percolation Simulator

// The Baker Street Irregulars
typedef struct {
    int x;
    int y;
} Irregular;

// 221B Baker Street
typedef struct {
    int width;
    int height;
    char **map;
} BakerStreet;

// Initialize 221B Baker Street
BakerStreet *initBakerStreet(int width, int height) {
    BakerStreet *bakerStreet = malloc(sizeof(BakerStreet));
    bakerStreet->width = width;
    bakerStreet->height = height;
    bakerStreet->map = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        bakerStreet->map[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            bakerStreet->map[i][j] = '.';
        }
    }
    return bakerStreet;
}

// Free 221B Baker Street
void freeBakerStreet(BakerStreet *bakerStreet) {
    for (int i = 0; i < bakerStreet->height; i++) {
        free(bakerStreet->map[i]);
    }
    free(bakerStreet->map);
    free(bakerStreet);
}

// Print 221B Baker Street
void printBakerStreet(BakerStreet *bakerStreet) {
    for (int i = 0; i < bakerStreet->height; i++) {
        for (int j = 0; j < bakerStreet->width; j++) {
            printf("%c", bakerStreet->map[i][j]);
        }
        printf("\n");
    }
}

// Add an Irregular to 221B Baker Street
void addIrregular(BakerStreet *bakerStreet, Irregular irregular) {
    bakerStreet->map[irregular.y][irregular.x] = 'I';
}

// Does an Irregular exist at a given location?
int hasIrregular(BakerStreet *bakerStreet, Irregular irregular) {
    return bakerStreet->map[irregular.y][irregular.x] == 'I';
}

// Is a given location open?
int isOpen(BakerStreet *bakerStreet, Irregular irregular) {
    return bakerStreet->map[irregular.y][irregular.x] == '.';
}

// Is a given location blocked?
int isBlocked(BakerStreet *bakerStreet, Irregular irregular) {
    return bakerStreet->map[irregular.y][irregular.x] == '#';
}

// Can an Irregular move from one location to another?
int canMove(BakerStreet *bakerStreet, Irregular from, Irregular to) {
    return isOpen(bakerStreet, to) && !hasIrregular(bakerStreet, to);
}

// Move an Irregular from one location to another
void move(BakerStreet *bakerStreet, Irregular from, Irregular to) {
    bakerStreet->map[from.y][from.x] = '.';
    bakerStreet->map[to.y][to.x] = 'I';
}

// Find a random open location
Irregular findRandomOpenLocation(BakerStreet *bakerStreet) {
    Irregular irregular;
    do {
        irregular.x = rand() % bakerStreet->width;
        irregular.y = rand() % bakerStreet->height;
    } while (!isOpen(bakerStreet, irregular));
    return irregular;
}

// Simulate the Baker Street Irregulars
void simulate(BakerStreet *bakerStreet, int numIrregulars, int numSteps) {
    Irregular irregulars[numIrregulars];
    for (int i = 0; i < numIrregulars; i++) {
        irregulars[i] = findRandomOpenLocation(bakerStreet);
        addIrregular(bakerStreet, irregulars[i]);
    }
    for (int i = 0; i < numSteps; i++) {
        for (int j = 0; j < numIrregulars; j++) {
            Irregular from = irregulars[j];
            Irregular to;
            do {
                to = findRandomOpenLocation(bakerStreet);
            } while (!canMove(bakerStreet, from, to));
            move(bakerStreet, from, to);
            irregulars[j] = to;
        }
    }
}

// Analyze the simulation results
void analyze(BakerStreet *bakerStreet, int numIrregulars) {
    int numOpen = 0;
    int numBlocked = 0;
    int numIrregularsPerOpen = 0;
    for (int i = 0; i < bakerStreet->height; i++) {
        for (int j = 0; j < bakerStreet->width; j++) {
            if (isOpen(bakerStreet, (Irregular){j, i})) {
                numOpen++;
            } else if (isBlocked(bakerStreet, (Irregular){j, i})) {
                numBlocked++;
            }
        }
    }
    numIrregularsPerOpen = numIrregulars / numOpen;
    printf("The simulation results are as follows:\n");
    printf("Number of open locations: %d\n", numOpen);
    printf("Number of blocked locations: %d\n", numBlocked);
    printf("Number of Irregulars per open location: %d\n", numIrregularsPerOpen);
}

// Main function
int main() {
    srand(time(NULL));
    BakerStreet *bakerStreet = initBakerStreet(10, 10);
    simulate(bakerStreet, 10, 100);
    analyze(bakerStreet, 10);
    freeBakerStreet(bakerStreet);
    return 0;
}