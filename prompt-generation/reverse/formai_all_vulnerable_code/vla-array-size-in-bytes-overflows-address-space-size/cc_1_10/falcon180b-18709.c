//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a knight
typedef struct {
    char name[50];
    int age;
    int strength;
    int agility;
    int intelligence;
} Knight;

// Function to generate a random knight
Knight generateKnight() {
    Knight knight;
    knight.name[0] = '\0';
    srand(time(NULL));
    knight.age = rand() % 101;
    knight.strength = rand() % 101;
    knight.agility = rand() % 101;
    knight.intelligence = rand() % 101;
    sprintf(knight.name, "Sir %d", knight.age);
    return knight;
}

// Function to print a knight's information
void printKnight(Knight knight) {
    printf("Name: %s\n", knight.name);
    printf("Age: %d\n", knight.age);
    printf("Strength: %d\n", knight.strength);
    printf("Agility: %d\n", knight.agility);
    printf("Intelligence: %d\n", knight.intelligence);
    printf("\n");
}

// Function to compare two knights based on their strength
int compareStrength(Knight knight1, Knight knight2) {
    if (knight1.strength > knight2.strength) {
        return 1;
    } else if (knight1.strength < knight2.strength) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int numKnights;
    printf("Enter the number of knights: ");
    scanf("%d", &numKnights);

    // Create an array of knights
    Knight knights[numKnights];

    // Generate random knights
    for (int i = 0; i < numKnights; i++) {
        knights[i] = generateKnight();
    }

    // Sort the knights by strength
    for (int i = 0; i < numKnights - 1; i++) {
        for (int j = i + 1; j < numKnights; j++) {
            if (compareStrength(knights[i], knights[j]) > 0) {
                Knight temp = knights[i];
                knights[i] = knights[j];
                knights[j] = temp;
            }
        }
    }

    // Print the strongest knight
    printf("The strongest knight is:\n");
    printKnight(knights[0]);

    return 0;
}