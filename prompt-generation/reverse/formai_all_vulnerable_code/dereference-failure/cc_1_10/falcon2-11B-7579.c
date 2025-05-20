//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random planet name
char* generatePlanetName() {
    char* planetName = (char*)malloc(10 * sizeof(char));
    for (int i = 0; i < 10; i++) {
        planetName[i] = 'a' + rand() % 26;
    }
    return planetName;
}

// Function to print planet information
void printPlanetInfo(char* planetName, int radius, int mass) {
    printf("Planet Name: %s\n", planetName);
    printf("Radius: %d km\n", radius);
    printf("Mass: %d kg\n", mass);
}

// Function to calculate distance between two planets
int calculateDistance(int planet1Radius, int planet2Radius, int planet1Mass, int planet2Mass) {
    int distance = (planet1Radius + planet2Radius) / 2;
    distance += (planet1Mass + planet2Mass) / 2;
    return distance;
}

// Main function
int main() {
    // Generate random planet names
    char* planet1Name = generatePlanetName();
    char* planet2Name = generatePlanetName();
    
    // Generate random planet information
    int planet1Radius = rand() % 1000 + 100;
    int planet1Mass = rand() % 1000 + 1000;
    int planet2Radius = rand() % 1000 + 100;
    int planet2Mass = rand() % 1000 + 1000;
    
    // Calculate distance between planets
    int distance = calculateDistance(planet1Radius, planet2Radius, planet1Mass, planet2Mass);
    
    // Print planet information
    printPlanetInfo(planet1Name, planet1Radius, planet1Mass);
    printPlanetInfo(planet2Name, planet2Radius, planet2Mass);
    
    // Print distance between planets
    printf("Distance between planets: %d km\n", distance);
    
    // Free memory
    free(planet1Name);
    free(planet2Name);
    
    return 0;
}