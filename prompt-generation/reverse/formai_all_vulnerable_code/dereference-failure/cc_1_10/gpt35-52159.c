//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: imaginative
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define GREEN_LIGHT 0
#define YELLOW_LIGHT 1
#define RED_LIGHT 2

typedef struct{ 
    int light_color; 
    int countdown; 
} Traffic_Light; 

void change_light(Traffic_Light *tl) {
    switch(tl->light_color) {
        case GREEN_LIGHT:
            tl->light_color = YELLOW_LIGHT;
            tl->countdown = 3; // yellow light lasts for 3 seconds
            printf("Green light turned yellow. \n");
            break;
        case YELLOW_LIGHT:
            tl->light_color = RED_LIGHT;
            tl->countdown = 5; // red light lasts for 5 seconds
            printf("Yellow light turned red. \n");
            break;
        case RED_LIGHT:
            tl->light_color = GREEN_LIGHT;
            tl->countdown = 7; // green light lasts for 7 seconds
            printf("Red light turned green. \n");
            break;
    }
}

void handle_input(Traffic_Light *tl) {
    printf("Press any key to change the traffic light. \n");
    fflush(stdin); // clear input buffer
    getchar(); // wait for user input
    change_light(tl); // change light
}

void print_traffic_light(Traffic_Light *tl) {
    switch(tl->light_color) {
        case GREEN_LIGHT:
            printf("Green light. \n");
            break;
        case YELLOW_LIGHT:
            printf("Yellow light. \n");
            break;
        case RED_LIGHT:
            printf("Red light. \n");
            break;
    }
}

void countdown(Traffic_Light *tl) {
    tl->countdown--;
    printf("%d seconds left. \n", tl->countdown);
}

int main() {
    srand(time(0)); // initialize random seed

    Traffic_Light *tl = malloc(sizeof(Traffic_Light)); // allocate memory for traffic light
    tl->light_color = GREEN_LIGHT; // set initial light color to green
    tl->countdown = 7; // set initial countdown to 7

    int i;
    for(i = 10; i > 0; i--) { // countdown from 10 seconds
        printf("%d seconds left until simulation starts... \n", i);
        sleep(1);
    }

    printf("Simulation started. \n");

    while(1) { // loop infinitely
        print_traffic_light(tl);
        countdown(tl);

        if(tl->countdown == 0) { // if countdown reaches 0, change light
            change_light(tl);
        }

        if(rand() % 5 == 0) { // 20% chance of user input
            handle_input(tl);
        }

        sleep(1);
    }

    return 0;
}