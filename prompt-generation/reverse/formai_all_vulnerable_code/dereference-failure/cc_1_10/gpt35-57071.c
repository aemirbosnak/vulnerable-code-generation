//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get castle names
char* getCastleName(int castleNum) {
    char* castleName = malloc(50);
    if (castleNum == 1) {
        strcpy(castleName, "Castle Camelot");
    } else if (castleNum == 2) {
        strcpy(castleName, "Castle Aragon");
    } else if (castleNum == 3) {
        strcpy(castleName, "Castle Dunholm");
    } else if (castleNum == 4) {
        strcpy(castleName, "Castle Ravenhold");
    } else if (castleNum == 5) {
        strcpy(castleName, "Castle Blackthorn");
    } else {
        strcpy(castleName, "Unknown Castle");
    }
    return castleName;
}

int main() {
    int numCastles = 5;
    int adjMatrix[numCastles][numCastles];
    int i, j;
    char* castle1;
    char* castle2;
    
    // Set adjacency matrix values manually
    adjMatrix[0][1] = adjMatrix[1][0] = 1;
    adjMatrix[1][2] = adjMatrix[2][1] = 1;
    adjMatrix[2][3] = adjMatrix[3][2] = 1;
    adjMatrix[3][4] = adjMatrix[4][3] = 1;
    
    // Print out the network topology in a medieval style
    printf("----------------- Network Topology -----------------\n\n");
    
    for (i = 0; i < numCastles; i++) {
        castle1 = getCastleName(i+1);
        
        printf("   %s is connected to: ", castle1);
        
        for (j = 0; j < numCastles; j++) {
            if (adjMatrix[i][j] == 1) {
                castle2 = getCastleName(j+1);
                printf("%s, ", castle2);
                free(castle2);
            }
        }
        
        printf("\n");
        free(castle1);
    }
    
    printf("\n----------------------------------------------------\n");
    
    return 0;
}