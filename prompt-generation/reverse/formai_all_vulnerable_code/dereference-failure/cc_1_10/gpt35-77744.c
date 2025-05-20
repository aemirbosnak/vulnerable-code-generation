//FormAI DATASET v1.0 Category: Smart home light control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LIGHTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int state;
} Light;

void toggle_light(Light *light) {
    if (light->state == 0) {
        light->state = 1;
        printf("Turning on %s\n", light->name);
    } else {
        light->state = 0;
        printf("Turning off %s\n", light->name);
    }
}

int main() {
    Light lights[MAX_LIGHTS];
    int num_lights = 0;
    char input[100];

    // Instructions for user
    printf("Welcome to the Smart Home Light Control System!\n");
    printf("To add a new light, type \"add light_name\"\n");
    printf("To toggle a light, type \"toggle light_name\"\n");
    printf("To exit the program, type \"exit\"\n");

    while (1) {
        printf("Enter command: ");
        fgets(input, 100, stdin);

        char *token = strtok(input, " ");

        if (strcmp(token, "exit\n") == 0) {
            printf("Exiting Smart Home Light Control System\n");
            break;
        }

        if (strcmp(token, "add") == 0) {
            token = strtok(NULL, " ");

            if (num_lights == MAX_LIGHTS) {
                printf("Max number of lights reached\n");
                continue;
            }

            Light new_light;
            strcpy(new_light.name, token);
            new_light.state = 0;

            lights[num_lights++] = new_light;
            printf("Light added: %s\n", new_light.name);
        } else if (strcmp(token, "toggle") == 0) {
            token = strtok(NULL, " ");
            int found_light = 0;

            for (int i = 0; i < num_lights; i++) {
                if (strcmp(lights[i].name, token) == 0) {
                    toggle_light(&lights[i]);
                    found_light = 1;
                    break;
                }
            }

            if (!found_light) {
                printf("Light not found\n");
            }
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}