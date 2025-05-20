//FormAI DATASET v1.0 Category: Smart home light control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A structure to hold the state of each light */
typedef struct {
    char* name;
    int brightness;
    int is_on;
} Light;

/* A structure to hold the state of the entire system */
typedef struct {
    Light* lights;
    int num_lights;
} SmartHome;

/* Function to create and initialize a new light */
Light* create_light(char* name) {
    Light* light = malloc(sizeof(Light));
    light->name = strdup(name);
    light->brightness = 0;
    light->is_on = 0;
    return light;
}

/* Function to add a new light to the system */
void add_light(SmartHome* home, char* name) {
    Light* light = create_light(name);
    home->lights = realloc(home->lights, sizeof(Light) * (home->num_lights + 1));
    home->lights[home->num_lights] = *light;
    home->num_lights++;
}

/* Function to remove a light from the system */
void remove_light(SmartHome* home, int index) {
    int i;
    for (i = index; i < home->num_lights - 1; i++) {
        home->lights[i] = home->lights[i + 1];
    }
    home->num_lights--;
}

/* Function to turn a light on or off */
void set_light_on(SmartHome* home, int index, int on) {
    home->lights[index].is_on = on;
}

/* Function to set the brightness of a light */
void set_light_brightness(SmartHome* home, int index, int brightness) {
    home->lights[index].brightness = brightness;
}

int main() {
    SmartHome home;
    home.lights = malloc(sizeof(Light));
    home.num_lights = 0;

    add_light(&home, "Living Room Lamp");
    add_light(&home, "Kitchen Light");
    add_light(&home, "Bedroom Lamp");

    printf("Welcome to the Smart Home Light Control System\n");
    printf("Number of lights in the system: %d\n", home.num_lights);

    int i, choice;
    for (;;) {
        printf("\nEnter your choice:\n");
        printf("1. Turn a light on\n");
        printf("2. Turn a light off\n");
        printf("3. Set the brightness of a light\n");
        printf("4. Add a new light\n");
        printf("5. Remove a light\n");
        printf("6. Quit\n");

        scanf("%d", &choice);
        if (choice == 6) {
            break;
        }

        if (choice == 1) {
            printf("Which light do you want to turn on? (Enter the index): ");
            scanf("%d", &i);
            set_light_on(&home, i, 1);
        } else if (choice == 2) {
            printf("Which light do you want to turn off? (Enter the index): ");
            scanf("%d", &i);
            set_light_on(&home, i, 0);
        } else if (choice == 3) {
            printf("Which light do you want to set the brightness of? (Enter the index): ");
            scanf("%d", &i);
            printf("Enter the brightness value (0-100): ");
            int brightness;
            scanf("%d", &brightness);
            set_light_brightness(&home, i, brightness);
        } else if (choice == 4) {
            printf("Enter the name of the new light: ");
            char name[100];
            scanf("%s", name);
            add_light(&home, name);
        } else if (choice == 5) {
            printf("Which light do you want to remove? (Enter the index): ");
            scanf("%d", &i);
            remove_light(&home, i);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}