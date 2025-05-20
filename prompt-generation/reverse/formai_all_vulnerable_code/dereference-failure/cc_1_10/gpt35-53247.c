//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 20
#define MAX_DRONE_COUNT 5
#define MAX_DRONE_STRING_LENGTH 50

typedef struct {
    int droneId;
    float x,y,z;
    bool isActive;
} Drone;

Drone* drones[MAX_DRONE_COUNT];
int droneCount = 0;

void addDrone(float x, float y, float z) {
    if (droneCount >= MAX_DRONE_COUNT) {
        printf("MAX DRONE COUNT REACHED!\n");
        return;
    }
    
    Drone* drone = (Drone*) malloc(sizeof(Drone));
    
    drone->droneId = droneCount + 1;
    drone->x = x;
    drone->y = y;
    drone->z = z;
    drone->isActive = true;
    
    drones[droneCount] = drone;
    droneCount++;
    
    printf("DRONE ID %d ADDED!\n", drone->droneId);
}

void removeDrone(int droneId) {
    bool found = false;
    for (int i = 0; i < droneCount; i++) {
        if (drones[i]->droneId == droneId) {
            free(drones[i]);
            drones[i] = NULL;
            found = true;
        } else if (found) {
            drones[i-1] = drones[i];
            drones[i] = NULL;
        }
    }
    
    if (found) {
        droneCount--;
        printf("DRONE ID %d REMOVED!\n", droneId);
    } else {
        printf("DRONE ID NOT FOUND!\n");
    }
}

void activateDrone(int droneId) {
    for (int i = 0; i < droneCount; i++) {
        if (drones[i]->droneId == droneId) {
            drones[i]->isActive = true;
            printf("DRONE ID %d ACTIVATED!\n", droneId);
            return;
        }
    }
    printf("DRONE ID NOT FOUND!\n");
}

void deactivateDrone(int droneId) {
    for (int i = 0; i < droneCount; i++) {
        if (drones[i]->droneId == droneId) {
            drones[i]->isActive = false;
            printf("DRONE ID %d DEACTIVATED!\n", droneId);
            return;
        }
    }
    printf("DRONE ID NOT FOUND!\n");
}

void printDroneStatus() {
    for (int i = 0; i < droneCount; i++) {
        printf("DRONE ID %d: (%.2f,%.2f,%.2f)", drones[i]->droneId, drones[i]->x, drones[i]->y, drones[i]->z);
        if (drones[i]->isActive) {
            printf(" STATUS: ACTIVE\n");
        } else {
            printf(" STATUS: INACTIVE\n");
        }
    }
}

void runCommand(char* command) {
    char validCommands[5][MAX_COMMAND_LENGTH] = {"add", "remove", "activate", "deactivate", "status"};
    
    char* token = strtok(command, " ");
    char* args[3];
    int argsCount = 0;
    
    while (token != NULL) {
        if (argsCount == 3) {
            printf("INVALID COMMAND! TOO MANY ARGUMENTS\n");
            return;
        }
        args[argsCount++] = token;
        token = strtok(NULL, " ");
    }
    
    bool isValidCommand = false;
    for (int i = 0; i < 5; i++) {
        if (strcmp(validCommands[i], args[0]) == 0) {
            isValidCommand = true;
            break;
        }
    }
    
    if (!isValidCommand) {
        printf("INVALID COMMAND! PLEASE ENTER A VALID COMMAND.\n");
        return;
    }
    
    if (strcmp(args[0], "add") == 0) {
        if (argsCount != 3) {
            printf("INVALID COMMAND! MISSING ARGUMENTS\n");
            return;
        }
        
        float x = atof(args[1]);
        float y = atof(args[2]);
        float z = 0.0f;
        
        addDrone(x,y,z);
    } else if (strcmp(args[0], "remove") == 0) {
        if (argsCount != 2) {
            printf("INVALID COMMAND! MISSING ARGUMENTS\n");
            return;
        }
        
        int droneId = atoi(args[1]);
        removeDrone(droneId);
    } else if (strcmp(args[0], "activate") == 0) {
        if (argsCount != 2) {
            printf("INVALID COMMAND! MISSING ARGUMENTS\n");
            return;
        }
        
        int droneId = atoi(args[1]);
        activateDrone(droneId);
    } else if (strcmp(args[0], "deactivate") == 0) {
        if (argsCount != 2) {
            printf("INVALID COMMAND! MISSING ARGUMENTS\n");
            return;
        }
        
        int droneId = atoi(args[1]);
        deactivateDrone(droneId);
    } else if (strcmp(args[0], "status") == 0) {
        if (argsCount != 1) {
            printf("INVALID COMMAND! TOO MANY ARGUMENTS\n");
            return;
        }
        
        printDroneStatus();
    }
}

void printIntroMessage() {
    printf("WELCOME TO THE C DRONE REMOTE CONTROL PANEL!\n");
    printf("ENTER YOUR COMMANDS BELOW:\n");
}

void printInstructions() {
    printf("COMMANDS:\n");
    printf("\tadd x y z - ADD NEW DRONE AT POSITION X,Y,Z\n");
    printf("\tremove id - REMOVE DRONE WITH ID\n");
    printf("\tactivate id - ACTIVATE DRONE WITH ID\n");
    printf("\tdeactivate id - DEACTIVATE DRONE WITH ID\n");
    printf("\tstatus - PRINT DRONE STATUS\n");
    printf("\texit - EXIT THE PROGRAM\n");
}

char* readCommand() {
    char* buffer = (char*) malloc(sizeof(char) * MAX_COMMAND_LENGTH);
    fgets(buffer, MAX_COMMAND_LENGTH, stdin);
    return buffer;
}

int main() {
    addDrone(0.0f,0.0f,0.0f);
    printIntroMessage();
    printInstructions();
    
    while (true) {
        printf("\nCOMMAND: ");
        char* input = readCommand();
        
        if (strcmp(input, "exit\n") == 0) {
            printf("\nGOODBYE!\n");
            break;
        }
        
        runCommand(input);
        
        free(input);
    }
    
    return 0;
}