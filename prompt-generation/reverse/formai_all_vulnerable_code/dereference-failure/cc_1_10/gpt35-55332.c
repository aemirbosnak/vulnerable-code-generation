//FormAI DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to turn on lights
void turnOn(int num, int *arr) {
    int i;
    for (i = 0; i < num; i++) {
        *(arr+i) = 1;
    }
    printf("Lights turned ON.\n");
}

//function to turn off lights
void turnOff(int num, int *arr) {
    int i;
    for (i = 0; i < num; i++) {
        *(arr+i) = 0;
    }
    printf("Lights turned OFF.\n");
}

int main() {
    int numOfLights = 5;
    int *lightArr = (int*) malloc(numOfLights*sizeof(int));
    memset(lightArr, 0, numOfLights*sizeof(int));
    int input;

    //welcome message
    printf("Welcome to Smart Home Light Control!\n");

    //loop until user exits
    while (1) {
        printf("\nEnter 1 to turn ON the lights.\nEnter 2 to turn OFF the lights.\nEnter 3 to exit.\n");
        scanf("%d", &input);
        switch(input) {
            case 1:
                turnOn(numOfLights, lightArr);
                break;
            case 2:
                turnOff(numOfLights, lightArr);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid input. Please enter a number between 1 and 3.\n");
                break;
        }
    }
    free(lightArr);
    return 0;
}