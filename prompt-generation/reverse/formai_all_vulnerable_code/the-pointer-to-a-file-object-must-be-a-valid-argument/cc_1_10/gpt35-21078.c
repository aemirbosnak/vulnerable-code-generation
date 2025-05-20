//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void printAscii(int, int);
void travel(int*);
void encounter(int*);
void shop(int*);

// Main function
int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Declare and initialize variables
    int fuel = 100;
    int credits = 500;
    int choice;

    // Display intro message and current status
    printf("Welcome to the Cyberpunk Space Adventure game!\n\n");
    printf("Current fuel: %d\n", fuel);
    printf("Current credits: %d\n\n", credits);

    // Loop until the player runs out of fuel or decides to quit
    while (fuel > 0)
    {
        // Print ASCII art for the current location
        printAscii(fuel, credits);

        // Prompt the player for their next action
        printf("What would you like to do?\n");
        printf("1. Travel to a new location\n");
        printf("2. Encounter an alien ship\n");
        printf("3. Visit a space station shop\n");
        printf("4. Quit game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement to determine which function to call based on user choice
        switch (choice)
        {
        case 1:
            travel(&fuel);
            break;
        case 2:
            encounter(&credits);
            break;
        case 3:
            shop(&credits);
            break;
        case 4:
            printf("Thanks for playing Cyberpunk Space Adventure!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    // If the player runs out of fuel, game over
    printf("You're out of fuel and stranded in space. Game over.\n");
    return 0;
}

// Function to print ASCII art based on fuel and credits
void printAscii(int fuel, int credits)
{
    // Variables to track current location and ASCII art file name
    int location = rand() % 3;
    char* asciiFile;

    // Determine the location and set the correct file name
    switch (location)
    {
    case 0:
        asciiFile = "planet.ascii";
        break;
    case 1:
        asciiFile = "asteroids.ascii";
        break;
    case 2:
        asciiFile = "spacestation.ascii";
        break;
    }

    // Open the ASCII art file and print it to the console
    FILE* file = fopen(asciiFile, "r");
    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    // Close the file and print fuel and credits
    fclose(file);
    printf("Current fuel: %d\n", fuel);
    printf("Credits: %d\n", credits);
}

// Function to travel to a new location
void travel(int* fuel)
{
    // Deduct random fuel amount (between 10 and 30)
    int cost = rand() % 21 + 10;
    *fuel -= cost;

    // Show travel message and new fuel level
    printf("Traveling to a new location...\n");
    printf("Fuel lost: %d\n", cost);
    printf("New fuel level: %d\n\n", *fuel);
}

// Function to encounter an alien ship
void encounter(int* credits)
{
    // Generate random bounty (between 100 and 500)
    int bounty = rand() % 401 + 100;
    *credits += bounty;

    // Show encounter message and bounty earned
    printf("Encountered an alien ship!\n");
    printf("Bounty earned: %d credits\n\n", bounty);
}

// Function to visit a space station shop
void shop(int* credits)
{
    // Display shop message and available items
    printf("Welcome to the space station shop!\n");
    printf("Here are the items for sale:\n");
    printf("1. Fuel (50 credits)\n");
    printf("2. Shield upgrade (+20 shield for your ship, 100 credits)\n");
    printf("3. Power up (+10 attack power, 200 credits)\n");
    printf("4. Leave shop\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    // Switch statement to determine which item to purchase based on user choice
    switch (choice)
    {
    case 1:
        if (*credits >= 50)
        {
            // Deduct credits and add fuel
            *credits -= 50;
            printf("Purchased fuel. Current fuel: %d\n\n", 150);
        }
        else
        {
            printf("Not enough credits to purchase fuel.\n\n");
        }
        break;
    case 2:
        if (*credits >= 100)
        {
            // Deduct credits and upgrade shield
            *credits -= 100;
            printf("Upgraded shield. Current shield: %d\n\n", 20);
        }
        else
        {
            printf("Not enough credits to upgrade shield.\n\n");
        }
        break;
    case 3:
        if (*credits >= 200)
        {
            // Deduct credits and add power
            *credits -= 200;
            printf("Purchased power up. Current power: %d\n\n", 10);
        }
        else
        {
            printf("Not enough credits to purchase power up.\n\n");
        }
        break;
    case 4:
        printf("Leaving shop.\n\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n\n");
    }
}