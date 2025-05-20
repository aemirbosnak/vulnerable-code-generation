//FormAI DATASET v1.0 Category: Smart home light control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    OFF,
    ON
} light_state;

typedef struct {
    int brightness;
    light_state state;
} light;

typedef struct {
    bool connected;
    char *name;
    light *lights;
} bridge;

void initialize_bridge(bridge *b, int num_lights) {
    b->connected = true;
    b->name = "Bridge A";
    b->lights = malloc(num_lights * sizeof(light));
    
    for (int i = 0; i < num_lights; i++) {
        b->lights[i].brightness = 50;
        b->lights[i].state = OFF;
    }
}

void set_light_brightness(light *l, int brightness) {
    if (brightness >= 0 && brightness <= 100) {
        l->brightness = brightness;
    }
}

void turn_on_light(light *l) {
    l->state = ON;
}

void turn_off_light(light *l) {
    l->state = OFF;
}

int main() {
    bridge b;
    initialize_bridge(&b, 3);
    
    printf("Welcome to %s\n", b.name);
    
    while (b.connected) {
        char input[32];
        printf("Enter command: ");
        fgets(input, 32, stdin);
        
        if (strcmp(input, "exit\n") == 0) {
            b.connected = false;
            printf("Goodbye!\n");
        }
        else if (strcmp(input, "list\n") == 0) {
            printf("Lights:\n");
            for (int i = 0; i < 3; i++) {
                printf("Light %d - %s, brightness: %d\n", i+1, b.lights[i].state == OFF ? "OFF" : "ON", b.lights[i].brightness);
            }
        }
        else if (strncmp(input, "brightness", 10) == 0) {
            int light_num, brightness;
            sscanf(input, "brightness %d %d", &light_num, &brightness);
            
            if (light_num < 1 || light_num > 3) {
                printf("Invalid light number\n");
            }
            else {
                set_light_brightness(&b.lights[light_num-1], brightness);
                printf("Set brightness of light %d to %d\n", light_num, brightness);
            }
        }
        else if (strncmp(input, "on", 2) == 0) {
            int light_num;
            sscanf(input, "on %d", &light_num);
            
            if (light_num < 1 || light_num > 3) {
                printf("Invalid light number\n");
            }
            else {
                turn_on_light(&b.lights[light_num-1]);
                printf("Turned on light %d\n", light_num);
            }
        }
        else if (strncmp(input, "off", 3) == 0) {
            int light_num;
            sscanf(input, "off %d", &light_num);
            
            if (light_num < 1 || light_num > 3) {
                printf("Invalid light number\n");
            }
            else {
                turn_off_light(&b.lights[light_num-1]);
                printf("Turned off light %d\n", light_num);
            }
        }
        else {
            printf("Invalid command\n");
        }
    }
    
    free(b.lights);
    
    return 0;
}