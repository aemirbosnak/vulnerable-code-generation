//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a custom data structure to represent a silly character
typedef struct {
    char *name;             // The character's name
    int age;                // The character's age
    char *catchphrase;      // The character's catchphrase
    int num_jokes;          // The number of jokes the character knows
    char **jokes;           // An array of the character's jokes
} SillyCharacter;

// Create a function to generate a random silly character
SillyCharacter *generate_silly_character() {
    // Allocate memory for the character
    SillyCharacter *character = malloc(sizeof(SillyCharacter));

    // Generate a random name for the character
    char *names[] = {"Wacky Wally", "Giggles McGee", "Prankster Pete", "Silly Sally", "Goofy George"};
    int name_index = rand() % 5;
    character->name = names[name_index];

    // Generate a random age for the character
    character->age = rand() % 100 + 1;

    // Generate a random catchphrase for the character
    char *catchphrases[] = {"Hold on to your hats!", "Get ready to laugh!", "Prepare yourself for silliness!", "Brace yourself for laughter!", "Buckle up for a wild ride!"};
    int catchphrase_index = rand() % 5;
    character->catchphrase = catchphrases[catchphrase_index];

    // Generate a random number of jokes for the character
    character->num_jokes = rand() % 10 + 1;

    // Allocate memory for the character's jokes
    character->jokes = malloc(sizeof(char *) * character->num_jokes);

    // Generate a random joke for each of the character's jokes
    for (int i = 0; i < character->num_jokes; i++) {
        char *jokes[] = {"Why did the chicken cross the playground? To get to the other slide!", "What do you call a fish with no eyes? Fsh!", "Why did the scarecrow win an award? Because he was outstanding in his field!", "What do you call a deer with no eyes? No idea!"};
        int joke_index = rand() % 4;
        character->jokes[i] = jokes[joke_index];
    }

    // Return the character
    return character;
}

// Create a function to print a silly character
void print_silly_character(SillyCharacter *character) {
    // Print the character's name, age, and catchphrase
    printf("Name: %s\n", character->name);
    printf("Age: %d\n", character->age);
    printf("Catchphrase: %s\n", character->catchphrase);

    // Print the character's jokes
    printf("Jokes:\n");
    for (int i = 0; i < character->num_jokes; i++) {
        printf("\t%s\n", character->jokes[i]);
    }

    // Free the memory allocated for the character's jokes
    free(character->jokes);

    // Free the memory allocated for the character
    free(character);
}

// Create a main function to test the program
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random silly character
    SillyCharacter *character = generate_silly_character();

    // Print the silly character
    print_silly_character(character);

    return 0;
}