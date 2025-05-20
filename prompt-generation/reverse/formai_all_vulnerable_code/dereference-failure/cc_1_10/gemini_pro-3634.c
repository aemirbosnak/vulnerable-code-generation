//GEMINI-pro DATASET v1.0 Category: Educational ; Style: immersive
// Embark on an interactive journey through the enchanted world of code!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our hero: a brave warrior named Arthur
typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Warrior;

// Create a new warrior with the given attributes
Warrior* createWarrior(char* name, int health, int attack, int defense) {
    Warrior* warrior = malloc(sizeof(Warrior));
    strcpy(warrior->name, name);
    warrior->health = health;
    warrior->attack = attack;
    warrior->defense = defense;
    return warrior;
}

// Engage in an epic battle between two warriors
void battle(Warrior* warrior1, Warrior* warrior2) {
    // Roll the dice to determine the order of attacks
    int turn = rand() % 2;
    
    // Prepare for battle
    printf("The battle between %s and %s has begun!\n", warrior1->name, warrior2->name);
    
    // Fight until one warrior falls
    while (warrior1->health > 0 && warrior2->health > 0) {
        // Determine the attacker and defender
        Warrior* attacker = turn ? warrior1 : warrior2;
        Warrior* defender = turn ? warrior2 : warrior1;
        
        // Attack!
        int damage = attacker->attack - defender->defense;
        if (damage < 0) damage = 0;
        defender->health -= damage;
        
        // Display the battle status
        printf("%s attacks %s for %d damage!\n", attacker->name, defender->name, damage);
        printf("%s's health: %d\n", defender->name, defender->health);
        
        // Switch turns
        turn = !turn;
    }
    
    // Declare the victor
    Warrior* victor = warrior1->health > 0 ? warrior1 : warrior2;
    printf("The victor is %s!\n", victor->name);
}

int main() {
    // Create our valiant warriors
    Warrior* arthur = createWarrior("Arthur", 100, 15, 10);
    Warrior* dragon = createWarrior("Dragon", 150, 20, 15);
    
    // Engage in battle
    battle(arthur, dragon);
    
    // Celebrate the victory or mourn the fallen
    if (arthur->health > 0) printf("Arthur has slain the dragon and saved the kingdom!\n");
    else printf("Alas, Arthur has fallen in battle against the mighty dragon.\n");
    
    // Free our brave warriors
    free(arthur);
    free(dragon);
    
    return 0;
}