//FormAI DATASET v1.0 Category: Smart home light control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int brightness;
    int temperature;
    int color;
    int on;
} Light;

void turnOn(Light* light) {
    light->on = 1;
}

void turnOff(Light* light) {
    light->on = 0;
}

void setBrightness(Light* light, int brightness) {
    light->brightness = brightness;
}

void setTemperature(Light* light, int temperature) {
    light->temperature = temperature;
}

void setColor(Light* light, int color) {
    light->color = color;
}

int main() {
    Light* bedroomLight = (Light *)malloc(sizeof(Light));
    bedroomLight->name = "Bedroom Light";
    bedroomLight->brightness = 50;
    bedroomLight->temperature = 3000;
    bedroomLight->color = 0xffffff;
    bedroomLight->on = 0;

    printf("%s is turned %s.\n", bedroomLight->name, bedroomLight->on ? "on" : "off");

    turnOn(bedroomLight);
    printf("Turning %s on...\n", bedroomLight->name);
    printf("%s is turned %s.\n", bedroomLight->name, bedroomLight->on ? "on" : "off");

    setBrightness(bedroomLight, 100);
    printf("Setting %s brightness to %d%%...\n", bedroomLight->name, bedroomLight->brightness);
    printf("%s brightness is %d%%.\n", bedroomLight->name, bedroomLight->brightness);

    setTemperature(bedroomLight, 4500);
    printf("Setting %s temperature to %d K...\n", bedroomLight->name, bedroomLight->temperature);
    printf("%s temperature is %d K.\n", bedroomLight->name, bedroomLight->temperature);

    setColor(bedroomLight, 0x00ff00);
    printf("Setting %s color to green...\n", bedroomLight->name);
    printf("%s color is 0x%x.\n", bedroomLight->name, bedroomLight->color);

    turnOff(bedroomLight);
    printf("Turning %s off...\n", bedroomLight->name);
    printf("%s is turned %s.\n", bedroomLight->name, bedroomLight->on ? "on" : "off");

    free(bedroomLight);

    return 0;
}