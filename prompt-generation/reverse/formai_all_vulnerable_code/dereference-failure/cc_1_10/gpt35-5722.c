//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define structure for remote control
typedef struct RemoteControl {
    int up;
    int down;
    int left;
    int right;
    int front;
    int back;
} RemoteControl;

// Define function to initialize remote control
RemoteControl* initRemoteControl() {
    RemoteControl* rc = malloc(sizeof(RemoteControl));
    rc->up = 0;
    rc->down = 0;
    rc->left = 0;
    rc->right = 0;
    rc->front = 0;
    rc->back = 0;
    return rc;
}

// Define function to control drone movement
void controlDrone(RemoteControl* rc) {
    char action;
    printf("\nEnter Action (u=up,d=down,l=left,r=right,f=front,b=back,e=exit): ");
    scanf(" %c", &action);
    switch(action) {
        case 'u':
            rc->up = 1;
            rc->down = 0;
            printf("Moving Up\n");
            break;
        case 'd':
            rc->up = 0;
            rc->down = 1;
            printf("Moving Down\n");
            break;
        case 'l':
            rc->left = 1;
            rc->right = 0;
            printf("Moving Left\n");
            break;
        case 'r':
            rc->left = 0;
            rc->right = 1;
            printf("Moving Right\n");
            break;
        case 'f':
            rc->front = 1;
            rc->back = 0;
            printf("Moving Forward\n");
            break;
        case 'b':
            rc->front = 0;
            rc->back = 1;
            printf("Moving Backward\n");
            break;
        case 'e':
            printf("\nExiting Remote Control\n");
            break;
        default:
            printf("\nInvalid Action!\n");
            break;
    }
}

// Define function to print remote control status
void printRemoteControlStatus(RemoteControl* rc) {
    printf("\nCurrent Remote Control Status:\n");
    printf("Up: %d\n", rc->up);
    printf("Down: %d\n", rc->down);
    printf("Left: %d\n", rc->left);
    printf("Right: %d\n", rc->right);
    printf("Front: %d\n", rc->front);
    printf("Back: %d\n", rc->back);
}

int main() {
    // Initialize remote control
    RemoteControl* rc = initRemoteControl();

    // Control drone movement
    char choice = 'y';
    while (choice == 'y') {
        printRemoteControlStatus(rc);
        controlDrone(rc);
        printf("\nDo you want to perform another action? (y=yes, n=no): ");
        scanf(" %c", &choice);
    }

    return 0;
}