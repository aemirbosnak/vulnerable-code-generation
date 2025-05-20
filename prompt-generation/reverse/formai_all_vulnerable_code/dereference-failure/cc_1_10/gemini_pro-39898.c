//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
// Interstellar Assembly Plant Floor Optimization

#include <stdio.h>
#include <stdlib.h>

// Spaceship parts representation
typedef struct SpaceshipPart {
    char* name;
    int size;
    double value;
} SpaceshipPart;

// Cargo ship representation
typedef struct CargoShip {
    double capacity;
    SpaceshipPart* parts;
    int numParts;
} CargoShip;

// Comparator for sorting parts by value per unit size
int cmpPartsByValuePerUnitSize(const SpaceshipPart* p1, const SpaceshipPart* p2) {
    return (p1->value / p1->size) - (p2->value / p2->size);
}

// Greedy algorithm to load the cargo ship
CargoShip* loadCargoShip(SpaceshipPart* parts, int numParts, double capacity) {
    // Create cargo ship
    CargoShip* ship = malloc(sizeof(CargoShip));
    ship->capacity = capacity;
    ship->numParts = 0;

    // Sort parts by value per unit size in descending order
    qsort(parts, numParts, sizeof(SpaceshipPart), (int (*)(const void*, const void*))cmpPartsByValuePerUnitSize);

    // Iteratively add parts to the ship
    for (int i = 0; i < numParts; i++) {
        if (ship->capacity - parts[i].size >= 0) {
            // Add part to ship
            ship->parts = realloc(ship->parts, (ship->numParts + 1) * sizeof(SpaceshipPart));
            ship->parts[ship->numParts] = parts[i];
            ship->numParts++;

            // Update ship capacity
            ship->capacity -= parts[i].size;
        }
    }

    return ship;
}

// Main function
int main() {
    // Initialize spaceship parts
    SpaceshipPart parts[] = {
        { "Quantum Engine", 100, 100000 },
        { "Fusion Reactor", 50, 50000 },
        { "Ion Thruster", 25, 25000 },
        { "Life Support System", 15, 15000 },
        { "Navigation Computer", 10, 10000 },
    };
    int numParts = sizeof(parts) / sizeof(SpaceshipPart);

    // Initialize cargo ship with a capacity of 100 units
    double capacity = 100;
    CargoShip* ship = loadCargoShip(parts, numParts, capacity);

    // Print loaded parts
    printf("Loaded Parts:\n");
    for (int i = 0; i < ship->numParts; i++) {
        printf("%s (Value: %.2f, Size: %d)\n", ship->parts[i].name, ship->parts[i].value, ship->parts[i].size);
    }

    // Print remaining capacity
    printf("\nRemaining Capacity: %.2f\n", ship->capacity);

    return 0;
}