//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int cars = 0;
    int lanes = 4;
    int roadLength = 500;
    int roadWidth = 10;
    int avgSpeed = 50;
    int avgCarLength = 10;
    int avgCarWidth = 5;
    int minSpeed = 0;
    int maxSpeed = 100;
    int minCarLength = 5;
    int maxCarLength = 20;
    int minCarWidth = 3;
    int maxCarWidth = 15;
    
    // Generate random car parameters
    srand(time(NULL));
    int carLength = rand() % (maxCarLength - minCarLength) + minCarLength;
    int carWidth = rand() % (maxCarWidth - minCarWidth) + minCarWidth;
    
    // Generate random car movement
    while (cars < 1000) {
        // Generate random starting position
        int carPosX = rand() % roadLength;
        int carPosY = rand() % roadWidth;
        
        // Generate random starting direction
        int direction = rand() % 2;
        
        // Generate random movement speed
        int speed = rand() % (maxSpeed - minSpeed) + minSpeed;
        
        // Generate random movement distance
        int distance = rand() % (roadLength - carPosX);
        
        // Generate random movement time
        int time = rand() % (roadLength / speed);
        
        // Update car position
        carPosX += distance;
        
        // Check if car has hit another car or lane boundary
        if (carPosX < 0 || carPosX >= roadLength ||
            carPosY < 0 || carPosY >= roadWidth ||
            (cars > 1 && (carPosX - (carLength / 2) >= (cars - 1) * (carWidth / 2) + 1 || carPosX - (carLength / 2) <= (cars - 1) * (carWidth / 2) - 1))) {
            printf("Car %d has crashed!\n", cars);
            break;
        }
        
        // Update car position
        cars++;
    }
    
    printf("Simulation complete.\n");
    return 0;
}