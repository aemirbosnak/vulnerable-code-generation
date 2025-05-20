//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the light states
enum light_state {
    OFF,
    ON,
    DIMMED
};

// Define the room types
enum room_type {
    BEDROOM,
    LIVING_ROOM,
    KITCHEN,
    BATHROOM
};

// Define the light control structure
struct light_control {
    enum light_state state;
    enum room_type room;
    int brightness;
};

// Define the smart home structure
struct smart_home {
    struct light_control lights[4];
};

// Create a new smart home
struct smart_home *create_smart_home() {
    struct smart_home *home = malloc(sizeof(struct smart_home));
    if (home == NULL) {
        return NULL;
    }

    // Initialize the lights
    for (int i = 0; i < 4; i++) {
        home->lights[i].state = OFF;
        home->lights[i].room = BEDROOM + i;
        home->lights[i].brightness = 0;
    }

    return home;
}

// Destroy a smart home
void destroy_smart_home(struct smart_home *home) {
    free(home);
}

// Turn a light on
void turn_light_on(struct smart_home *home, enum room_type room) {
    home->lights[room].state = ON;
}

// Turn a light off
void turn_light_off(struct smart_home *home, enum room_type room) {
    home->lights[room].state = OFF;
}

// Dim a light
void dim_light(struct smart_home *home, enum room_type room, int brightness) {
    home->lights[room].state = DIMMED;
    home->lights[room].brightness = brightness;
}

// Get the state of a light
enum light_state get_light_state(struct smart_home *home, enum room_type room) {
    return home->lights[room].state;
}

// Get the brightness of a light
int get_light_brightness(struct smart_home *home, enum room_type room) {
    return home->lights[room].brightness;
}

// Print the state of all the lights
void print_light_states(struct smart_home *home) {
    for (int i = 0; i < 4; i++) {
        printf("Light in room %d is ", home->lights[i].room);
        switch (home->lights[i].state) {
            case OFF:
                printf("off\n");
                break;
            case ON:
                printf("on\n");
                break;
            case DIMMED:
                printf("dimmed to %d%%\n", home->lights[i].brightness);
                break;
        }
    }
}

// Main function
int main() {
    // Create a new smart home
    struct smart_home *home = create_smart_home();

    // Turn on the lights in the living room and kitchen
    turn_light_on(home, LIVING_ROOM);
    turn_light_on(home, KITCHEN);

    // Dim the light in the bedroom
    dim_light(home, BEDROOM, 50);

    // Print the state of all the lights
    print_light_states(home);

    // Destroy the smart home
    destroy_smart_home(home);

    return 0;
}