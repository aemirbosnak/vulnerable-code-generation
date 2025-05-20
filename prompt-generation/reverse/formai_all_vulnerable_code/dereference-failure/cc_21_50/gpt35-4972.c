//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));  // Seed the random number generator

    // Define the map size and player starting position
    int mapSize = 10;
    int playerX = mapSize/2;
    int playerY = mapSize/2;
    
    // Define variable for Romeo's HP
    int romeoHP = 100;

    // Define the tiles
    char playerTile = '@';
    char emptyTile = '.';
    char romeoTile = 'R';
    char julietTile = 'J';
    
    // Define the map allocation
    char** map = (char**) malloc(mapSize * sizeof(char*));
    for (int i = 0; i < mapSize; i++) {
        map[i] = (char*) malloc(mapSize * sizeof(char));
    }

    // Populate the map with empty tiles
    for (int y = 0; y < mapSize; y++) {
        for (int x = 0; x < mapSize; x++) {
            map[y][x] = emptyTile;
        }
    }

    // Place the player's starting position
    map[playerY][playerX] = playerTile;

    // Place Romeo and Juliet randomly on the map
    int romeoX = rand() % mapSize;
    int romeoY = rand() % mapSize;
    int julietX = rand() % mapSize;
    int julietY = rand() % mapSize;
    
    // Ensure Romeo and Juliet are not on the same tile
    while (romeoX == julietX && romeoY == julietY) {
        julietX = rand() % mapSize;
        julietY = rand() % mapSize;
    }
    
    map[romeoY][romeoX] = romeoTile;
    map[julietY][julietX] = julietTile;

    // Begin game loop
    while (1) {
        // Print the map
        printf("\n");
        for (int y = 0; y < mapSize; y++) {
            for (int x = 0; x < mapSize; x++) {
                printf("%c ", map[y][x]);
            }
            printf("\n");
        }
        
        // Print Romeo's HP
        printf("\nRomeo's HP: %d\n", romeoHP);

        // Get player input
        char input;
        printf("Move (WASD): ");
        scanf(" %c", &input);

        // Move the player
        switch(input) {
            case 'w': 
                if (playerY > 0) {
                    map[playerY][playerX] = emptyTile;
                    playerY--;
                    map[playerY][playerX] = playerTile;
                }
                break;
            case 'a': 
                if (playerX > 0) {
                    map[playerY][playerX] = emptyTile;
                    playerX--;
                    map[playerY][playerX] = playerTile;
                }
                break;
            case 's': 
                if (playerY < mapSize-1) {
                    map[playerY][playerX] = emptyTile;
                    playerY++;
                    map[playerY][playerX] = playerTile;
                }
                break;
            case 'd': 
                if (playerX < mapSize-1) {
                    map[playerY][playerX] = emptyTile;
                    playerX++;
                    map[playerY][playerX] = playerTile;
                }
                break;
            default:
                printf("Invalid input\n");
                break;
        }

        // Check for collision with Romeo or Juliet
        if (playerY == romeoY && playerX == romeoX) {
            printf("Romeo catches you!\n");
            romeoHP -= 10;
            if (romeoHP <= 0) {
                printf("Romeo is dead! Juliet is yours!\n");
                break;
            }
        }

        if (playerY == julietY && playerX == julietX) {
            printf("Juliet catches you!\n");
            printf("You both die together, but your love remains immortal!\n");
            break;
        }
    }
    
    // Free the map allocation
    for (int i = 0; i < mapSize; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}