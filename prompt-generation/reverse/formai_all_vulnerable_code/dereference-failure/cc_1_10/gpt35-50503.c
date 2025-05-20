//FormAI DATASET v1.0 Category: Smart home light control ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define LIGHT_BULB_ON 1        // define a constant to represent light bulb state
#define LIGHT_BULB_OFF 0       // define a constant to represent light bulb state

#define MAX_LIGHT_BULBS 10     // define a constant to represent the maximum number of bulbs in the smart home system

// define a LightBulb structure
typedef struct LightBulb {
    int id;                    // the id of the light bulb
    int state;                 // the state of the light bulb (on/off)
} LightBulb;

// define a SmartHome structure
typedef struct SmartHome {
    LightBulb* light_bulbs[MAX_LIGHT_BULBS];  // an array of pointers to light bulbs
    int num_light_bulbs;  // number of light bulbs in the system
} SmartHome;

// declare functions
SmartHome* create_smart_home();
int count_light_bulbs(SmartHome* home);
LightBulb* create_light_bulb(int id);
void add_light_bulb(SmartHome* home, LightBulb* bulb);
void turn_on_off_light(SmartHome* home, int id, int state);
void print_light_bulbs(SmartHome* home);

int main() {
    SmartHome* home = create_smart_home();

    LightBulb* living_room_bulb = create_light_bulb(1);
    LightBulb* kitchen_bulb = create_light_bulb(2);

    add_light_bulb(home, living_room_bulb);
    add_light_bulb(home, kitchen_bulb);

    printf("Number of light bulbs in smart home system: %d\n", count_light_bulbs(home));

    printf("Turning on living room bulb...\n");
    turn_on_off_light(home, 1, LIGHT_BULB_ON);

    printf("Turning off kitchen bulb...\n");
    turn_on_off_light(home, 2, LIGHT_BULB_OFF);

    printf("Smart home system light bulbs:\n");
    print_light_bulbs(home);

    return 0;
}

// create a new SmartHome object
SmartHome* create_smart_home() {
    SmartHome* home = (SmartHome*)malloc(sizeof(SmartHome));
    home->num_light_bulbs = 0;
    return home;
}

// count the number of light bulbs in the SmartHome system
int count_light_bulbs(SmartHome* home) {
    return home->num_light_bulbs;
}

// create a new LightBulb object
LightBulb* create_light_bulb(int id) {
    LightBulb* bulb = (LightBulb*)malloc(sizeof(LightBulb));
    bulb->id = id;
    bulb->state = LIGHT_BULB_OFF;
    return bulb;
}

// add a LightBulb to the SmartHome system
void add_light_bulb(SmartHome* home, LightBulb* bulb) {
    home->light_bulbs[home->num_light_bulbs++] = bulb;
}

// turn a LightBulb on or off
void turn_on_off_light(SmartHome* home, int id, int state) {
    for (int i = 0; i < home->num_light_bulbs; i++) {
        if (home->light_bulbs[i]->id == id) {
            home->light_bulbs[i]->state = state;
            return;
        }
    }
}

// print the current state of all LightBulbs in the SmartHome system
void print_light_bulbs(SmartHome* home) {
    for (int i = 0; i < home->num_light_bulbs; i++) {
        printf("Light bulb %d state: %s\n", home->light_bulbs[i]->id,
            home->light_bulbs[i]->state ? "On" : "Off");
    }
}