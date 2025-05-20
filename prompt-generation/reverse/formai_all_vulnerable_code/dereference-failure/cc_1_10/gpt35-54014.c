//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DRONE_COUNT 10

typedef struct {
    int droneId;
    bool isArmed;
    float altitude;
    float pitch;
    float roll;
    float yaw;
} Drone;

Drone drones[MAX_DRONE_COUNT];
int numDrones = 0;

void arm(int droneId) {
    if (drones[droneId].isArmed) {
        printf("Drone %d is already armed\n", droneId);
    } else {
        drones[droneId].isArmed = true;
        printf("Armed drone %d\n", droneId);
    }
}

void disarm(int droneId) {
    if (!drones[droneId].isArmed) {
        printf("Drone %d is already disarmed\n", droneId);
    } else {
        drones[droneId].isArmed = false;
        printf("Disarmed drone %d\n", droneId);
    }
}

void setAltitude(int droneId, float altitude) {
    if (!drones[droneId].isArmed) {
        printf("Cannot set altitude for disarmed drone %d\n", droneId);
    } else {
        drones[droneId].altitude = altitude;
        printf("Set altitude of drone %d to %f\n", droneId, altitude);
    }
}

void setPitch(int droneId, float pitch) {
    if (!drones[droneId].isArmed) {
        printf("Cannot set pitch for disarmed drone %d\n", droneId);
    } else {
        drones[droneId].pitch = pitch;
        printf("Set pitch of drone %d to %f\n", droneId, pitch);
    }
}

void setRoll(int droneId, float roll) {
    if (!drones[droneId].isArmed) {
        printf("Cannot set roll for disarmed drone %d\n", droneId);
    } else {
        drones[droneId].roll = roll;
        printf("Set roll of drone %d to %f\n", droneId, roll);
    }
}

void setYaw(int droneId, float yaw) {
    if (!drones[droneId].isArmed) {
        printf("Cannot set yaw for disarmed drone %d\n", droneId);
    } else {
        drones[droneId].yaw = yaw;
        printf("Set yaw of drone %d to %f\n", droneId, yaw);
    }
}

int main(int argc, char* argv[]) {
    char input[128];

    while (true) {
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);
        strtok(input, "\n");

        // Parse command and parameters
        char* command = strtok(input, " ");
        char* param1 = strtok(NULL, " ");
        char* param2 = strtok(NULL, " ");

        if (strcmp(command, "add_drone") == 0) {
            if (numDrones == MAX_DRONE_COUNT) {
                printf("Cannot add more drones, maximum supported is %d\n", MAX_DRONE_COUNT);
            } else {
                drones[numDrones].droneId = numDrones;
                drones[numDrones].isArmed = false;
                drones[numDrones].altitude = 0.0f;
                drones[numDrones].pitch = 0.0f;
                drones[numDrones].roll = 0.0f;
                drones[numDrones].yaw = 0.0f;

                printf("Added drone with ID %d\n", numDrones);

                numDrones++;
            }
        } else if (strcmp(command, "arm") == 0) {
            int droneId = atoi(param1);

            arm(droneId);
        } else if (strcmp(command, "disarm") == 0) {
            int droneId = atoi(param1);

            disarm(droneId);
        } else if (strcmp(command, "set_altitude") == 0) {
            int droneId = atoi(param1);
            float altitude = atof(param2);

            setAltitude(droneId, altitude);
        } else if (strcmp(command, "set_pitch") == 0) {
            int droneId = atoi(param1);
            float pitch = atof(param2);

            setPitch(droneId, pitch);
        } else if (strcmp(command, "set_roll") == 0) {
            int droneId = atoi(param1);
            float roll = atof(param2);

            setRoll(droneId, roll);
        } else if (strcmp(command, "set_yaw") == 0) {
            int droneId = atoi(param1);
            float yaw = atof(param2);

            setYaw(droneId, yaw);
        } else if (strcmp(command, "list_drones") == 0) {
            printf("--- Drone List ---\n");

            for (int i = 0; i < numDrones; i++) {
                printf("ID: %d Arming Status: %s Altitude: %f Pitch: %f Roll: %f Yaw: %f\n", drones[i].droneId, drones[i].isArmed ? "armed" : "disarmed", drones[i].altitude, drones[i].pitch, drones[i].roll, drones[i].yaw);
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program\n");
            break;
        } else {
            printf("Invalid command: %s\n", command);
        }
    }

    return 0;
}