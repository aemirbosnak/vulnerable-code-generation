//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

enum light_state {
    OFF,
    ON,
    DIM
};

struct light {
    char *name;
    enum light_state state;
    int brightness;
};

struct smart_home {
    struct light lights[MAX_LIGHTS];
    int num_lights;
};

void init_smart_home(struct smart_home *home) {
    home->num_lights = 0;
}

void add_light(struct smart_home *home, char *name) {
    if (home->num_lights < MAX_LIGHTS) {
        struct light *light = &home->lights[home->num_lights++];
        light->name = strdup(name);
        light->state = OFF;
        light->brightness = 0;
    }
}

void turn_on(struct light *light) {
    light->state = ON;
    light->brightness = 100;
}

void turn_off(struct light *light) {
    light->state = OFF;
    light->brightness = 0;
}

void dim(struct light *light, int brightness) {
    light->state = DIM;
    light->brightness = brightness;
}

void print_light_status(struct light *light) {
    printf("%s: ", light->name);
    switch (light->state) {
        case OFF:
            printf("off\n");
            break;
        case ON:
            printf("on\n");
            break;
        case DIM:
            printf("dimmed to %d%%\n", light->brightness);
            break;
    }
}

int main() {
    struct smart_home home;
    init_smart_home(&home);

    add_light(&home, "Living Room");
    add_light(&home, "Kitchen");
    add_light(&home, "Bedroom");

    turn_on(&home.lights[0]);
    dim(&home.lights[1], 50);
    turn_off(&home.lights[2]);

    for (int i = 0; i < home.num_lights; i++) {
        print_light_status(&home.lights[i]);
    }

    return 0;
}