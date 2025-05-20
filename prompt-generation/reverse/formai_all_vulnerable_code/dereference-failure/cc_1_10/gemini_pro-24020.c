//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct Light {
    bool is_on;
    int brightness;
    char *name;
};

struct Room {
    char *name;
    struct Light *lights;
    int num_lights;
};

struct SmartHome {
    struct Room *rooms;
    int num_rooms;
};

void toggle_light(struct Light *light) {
    light->is_on = !light->is_on;
}

void set_brightness(struct Light *light, int brightness) {
    light->brightness = brightness;
}

void print_light(struct Light *light) {
    printf("%s: %s, %d%%\n", light->name, light->is_on ? "on" : "off", light->brightness);
}

void print_room(struct Room *room) {
    printf("Room: %s\n", room->name);
    for (int i = 0; i < room->num_lights; i++) {
        print_light(&room->lights[i]);
    }
}

void print_smart_home(struct SmartHome *smart_home) {
    for (int i = 0; i < smart_home->num_rooms; i++) {
        print_room(&smart_home->rooms[i]);
    }
}

int main() {
    struct Light kitchen_light = {
        .is_on = false,
        .brightness = 0,
        .name = "Kitchen Light"
    };

    struct Light bedroom_light = {
        .is_on = true,
        .brightness = 50,
        .name = "Bedroom Light"
    };

    struct Room kitchen = {
        .name = "Kitchen",
        .lights = &kitchen_light,
        .num_lights = 1
    };

    struct Room bedroom = {
        .name = "Bedroom",
        .lights = &bedroom_light,
        .num_lights = 1
    };

    struct SmartHome smart_home = {
        .rooms = &kitchen,
        .num_rooms = 2
    };

    print_smart_home(&smart_home);

    toggle_light(&kitchen_light);
    set_brightness(&bedroom_light, 100);

    print_smart_home(&smart_home);

    return 0;
}