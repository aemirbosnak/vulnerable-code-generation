//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CMD_INVALID -1
#define CMD_FORWARD 0
#define CMD_BACKWARD 1
#define CMD_LEFT 2
#define CMD_RIGHT 3
#define CMD_STOP 4
#define CMD_QUIT 5

struct vehicle {
    int x;
    int y;
    int direction;
};

void print_usage() {
    printf("Usage: remote_control_vehicle [command]\n");
    printf("Available commands:\n");
    printf("    forward: Move the vehicle forward\n");
    printf("    backward: Move the vehicle backward\n");
    printf("    left: Turn the vehicle left\n");
    printf("    right: Turn the vehicle right\n");
    printf("    stop: Stop the vehicle\n");
    printf("    quit: Quit the program\n");
}

int parse_command(char *cmd) {
    if (strcmp(cmd, "forward") == 0) {
        return CMD_FORWARD;
    } else if (strcmp(cmd, "backward") == 0) {
        return CMD_BACKWARD;
    } else if (strcmp(cmd, "left") == 0) {
        return CMD_LEFT;
    } else if (strcmp(cmd, "right") == 0) {
        return CMD_RIGHT;
    } else if (strcmp(cmd, "stop") == 0) {
        return CMD_STOP;
    } else if (strcmp(cmd, "quit") == 0) {
        return CMD_QUIT;
    } else {
        return CMD_INVALID;
    }
}

void move_vehicle(struct vehicle *vehicle, int cmd) {
    switch (cmd) {
    case CMD_FORWARD:
        vehicle->y++;
        break;
    case CMD_BACKWARD:
        vehicle->y--;
        break;
    case CMD_LEFT:
        vehicle->direction = (vehicle->direction + 3) % 4;
        break;
    case CMD_RIGHT:
        vehicle->direction = (vehicle->direction + 1) % 4;
        break;
    case CMD_STOP:
        break;
    default:
        printf("Invalid command\n");
    }
}

void print_vehicle(struct vehicle vehicle) {
    printf("Vehicle position: (%d, %d)\n", vehicle.x, vehicle.y);
    printf("Vehicle direction: ");
    switch (vehicle.direction) {
    case 0:
        printf("North\n");
        break;
    case 1:
        printf("East\n");
        break;
    case 2:
        printf("South\n");
        break;
    case 3:
        printf("West\n");
        break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    struct vehicle vehicle = {
        .x = 0,
        .y = 0,
        .direction = 0,
    };

    int cmd = parse_command(argv[1]);
    if (cmd == CMD_INVALID) {
        printf("Invalid command\n");
        print_usage();
        return 1;
    }

    while (cmd != CMD_QUIT) {
        move_vehicle(&vehicle, cmd);
        print_vehicle(vehicle);

        printf("Enter the next command: ");
        scanf("%s", argv[1]);
        cmd = parse_command(argv[1]);
    }

    return 0;
}