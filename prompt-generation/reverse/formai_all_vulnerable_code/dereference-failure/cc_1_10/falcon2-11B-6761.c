//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int action;
int state;

char lines[MAX_LINE_LENGTH][MAX_LINE_LENGTH];

void readLine(int index) {
    fgets(lines[index], MAX_LINE_LENGTH, stdin);
}

void checkLine(int index) {
    char *p = strtok(lines[index], " \t");
    if (p) {
        if (strcmp(p, "on") == 0) {
            action |= 1;
        } else if (strcmp(p, "off") == 0) {
            action &= ~1;
        }
    }
}

void setAction() {
    action = (action & ~(1 << 1)) | (state & (1 << 1));
}

int getAction() {
    return action;
}

int getState() {
    return state;
}

void toggleAction() {
    state ^= 1;
    setAction();
}

void toggleState() {
    state ^= 1;
    setAction();
}

void printState() {
    printf("State: %d\nAction: %d\n", getState(), getAction());
}

void getCommand() {
    printf("Enter command (on/off): ");
    fflush(stdout);
    readLine(0);
    checkLine(0);
    setAction();
}

void run() {
    printf("Welcome to the Smart Home Automation Program!\n");
    printState();
    while (getAction()!= 0) {
        getCommand();
    }
}

void cleanUp() {
    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main() {
    printf("Initializing environment...\n");
    printf("Setting up environment...\n");
    readLine(0);
    checkLine(0);
    setAction();
    printf("Environment setup complete.\n");
    printf("Starting program...\n");
    run();
    printf("Program complete.\n");
    printf("Cleaning up environment...\n");
    cleanUp();
    printf("Environment clean up complete.\n");
    return 0;
}