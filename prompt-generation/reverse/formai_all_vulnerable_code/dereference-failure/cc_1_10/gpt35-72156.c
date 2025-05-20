//FormAI DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ON 1
#define OFF 0

typedef struct {
    int brightness;
    int color;
    int power;
} Light;

void turnOn(Light *light) {
    light->power = ON;
    printf("Light is turn on\n");
}

void turnOff(Light *light) {
    light->power = OFF;
    printf("Light is turn off\n");
}

void setBrightness(Light *light, int brightness) {
    light->brightness = brightness;
    printf("Brightness set to %d\n", brightness);
}

void setColor(Light *light, int color) {
    light->color = color;
    printf("Color set to %d\n", color);
}

int main() {
    Light *myLight = (Light*) malloc(sizeof(Light));
    myLight->brightness = 50;
    myLight->color = 1;
    myLight->power = OFF;
    
    printf("Welcome to Smart Home Light Control\n");
    
    char input[50];
    while (1) {
        printf("Enter command: ");
        fgets(input, 50, stdin);
        strtok(input, "\n");
        if (strcmp(input, "on") == 0) {
            turnOn(myLight);
        } else if (strcmp(input, "off") == 0) {
            turnOff(myLight);
        } else if (strncmp(input, "brightness", 10) == 0) {
            int brightness = atoi(input + 11);
            setBrightness(myLight, brightness);
        } else if (strncmp(input, "color", 5) == 0) {
            int color = atoi(input + 6);
            setColor(myLight, color);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    free(myLight);
    return 0;
}