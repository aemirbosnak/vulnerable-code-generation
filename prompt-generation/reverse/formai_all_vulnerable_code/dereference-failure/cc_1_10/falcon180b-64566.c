//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define our medieval kingdom
typedef struct {
    char* name;
    int population;
    int wealth;
} Kingdom;

// Function declarations
void initializeKingdom(Kingdom* kingdom, char* name);
void printKingdomStats(Kingdom kingdom);
void addVillager(Kingdom* kingdom);
void removeVillager(Kingdom* kingdom);
void collectTaxes(Kingdom* kingdom);

int main() {
    // Initialize our kingdom
    Kingdom myKingdom;
    initializeKingdom(&myKingdom, "My Medieval Kingdom");

    // Print initial stats
    printf("Welcome to %s!\n", myKingdom.name);
    printKingdomStats(myKingdom);

    // Add some villagers
    addVillager(&myKingdom);
    addVillager(&myKingdom);

    // Print updated stats
    printf("\nAfter adding 2 villagers:\n");
    printKingdomStats(myKingdom);

    // Remove a villager
    removeVillager(&myKingdom);

    // Print updated stats
    printf("\nAfter removing 1 villager:\n");
    printKingdomStats(myKingdom);

    // Collect taxes
    collectTaxes(&myKingdom);

    // Print final stats
    printf("\nAfter collecting taxes:\n");
    printKingdomStats(myKingdom);

    return 0;
}

// Initialize a kingdom with the given name
void initializeKingdom(Kingdom* kingdom, char* name) {
    strcpy(kingdom->name, name);
    kingdom->population = 0;
    kingdom->wealth = 0;
}

// Print the stats of a kingdom
void printKingdomStats(Kingdom kingdom) {
    printf("Population: %d\n", kingdom.population);
    printf("Wealth: %d gold coins\n", kingdom.wealth);
}

// Add a villager to the kingdom
void addVillager(Kingdom* kingdom) {
    kingdom->population++;
    kingdom->wealth += 10; // Each villager brings 10 gold coins to the kingdom
}

// Remove a villager from the kingdom
void removeVillager(Kingdom* kingdom) {
    kingdom->population--;
    kingdom->wealth -= 10; // Removing a villager takes away 10 gold coins from the kingdom
}

// Collect taxes from the villagers
void collectTaxes(Kingdom* kingdom) {
    int taxPerVillager = 5; // 5 gold coins per villager
    kingdom->wealth += taxPerVillager * kingdom->population;
    printf("Collected %d gold coins in taxes!\n", taxPerVillager * kingdom->population);
}