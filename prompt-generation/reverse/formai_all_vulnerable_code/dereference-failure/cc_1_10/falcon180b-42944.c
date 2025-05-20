//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    bool is_on;
    int brightness;
} Light;

Light lights[MAX_LIGHTS];

void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].is_on = false;
        lights[i].brightness = 0;
    }
}

void turn_on_light(int index) {
    lights[index].is_on = true;
}

void turn_off_light(int index) {
    lights[index].is_on = false;
}

void set_brightness(int index, int brightness) {
    lights[index].brightness = brightness;
}

void print_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].is_on) {
            printf("%s is on with brightness %d\n", lights[i].name, lights[i].brightness);
        } else {
            printf("%s is off\n", lights[i].name);
        }
    }
}

int main() {
    init_lights();
    turn_on_light(0);
    set_brightness(0, 100);
    turn_on_light(1);
    set_brightness(1, 50);
    print_lights();
    while (true) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        int hour = t->tm_hour;
        if (hour >= 6 && hour <= 18) {
            printf("It's daytime. Lights are on.\n");
        } else {
            printf("It's nighttime. Lights are off.\n");
            for (int i = 0; i < MAX_LIGHTS; i++) {
                turn_off_light(i);
            }
        }
        sleep(3600);
    }
    return 0;
}