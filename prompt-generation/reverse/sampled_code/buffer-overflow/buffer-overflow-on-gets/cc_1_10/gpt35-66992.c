//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random number between given range
int randomRange(int lower, int upper){
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    // Welcome message
    printf("\nWelcome to the Alien Invasion Probability Calculator\n\n");

    // Initializing variables
    int day, month, year, invasionChance, topSecret;
    char name[20];
    int alienType, alienStrength;
    float alienProbability;
    invasionChance = 0;

    // Taking user inputs
    printf("Enter your name: ");
    gets(name);

    printf("\nEnter today's date(dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("\nI hope you are not an Alien trying to infiltrate our system.\nPlease enter the top secret code:");
    scanf("%d", &topSecret);

    if (topSecret != 314159) {
        printf("\nSorry, you are not authorized to use this program. Goodbye!\n\n");
        return 0;
    }

    // Alien type and strength selection by user
    printf("\nSelect alien type:\n1. Green\n2. Grey\n3. Red\n");
    scanf("%d", &alienType);

    printf("\nSelect alien strength:\n1. Weak\n2. Medium\n3. Strong\n");
    scanf("%d", &alienStrength);

    // Using random number to generate probability
    alienProbability = randomRange(1, 100) / 100.0;

    // Calculating invasion chances
    if (alienType == 2 && alienStrength == 3) {
        invasionChance += 20;
    }
    if (alienProbability > 0.5) {
        invasionChance += 30;
    }
    if (month >= 1 && month <= 3) {
        invasionChance += 15;
    }
    if (year >= 2020 && year <= 2025) {
        invasionChance += 10;
    }
    if (alienType == 1 && alienStrength == 2) {
        invasionChance += 25;
    }
    if (day >= 15 && day <= 31) {
        invasionChance += 10;
    }

    // Displaying final results
    printf("\nHello, %s!\n\n", name);
    printf("The invasion probability by %s alien of %s strength on %d/%d/%d is %.2f%%\n", 
        alienType == 1 ? "Green" : alienType == 2 ? "Grey" : "Red", 
        alienStrength == 1 ? "Weak" : alienStrength == 2 ? "Medium" : "Strong", 
        day, month, year, alienProbability * 100);
    printf("The final invasion probability is: %d%%\n\n", invasionChance);

    return 0;
}