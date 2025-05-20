//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_FILE "config.txt"

// Structure to store light configuration
typedef struct light_config {
    char name[32];
    int pin;
    int state;
} light_config;

// Array to store light configurations
light_config lights[16];

// Read light configurations from file
int read_config() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        return -1;
    }

    int num_lights = 0;
    while (!feof(file)) {
        char line[128];
        fgets(line, sizeof(line), file);

        char *name = strtok(line, ",");
        char *pin = strtok(NULL, ",");
        char *state = strtok(NULL, ",");

        if (name != NULL && pin != NULL && state != NULL) {
            strcpy(lights[num_lights].name, name);
            lights[num_lights].pin = atoi(pin);
            lights[num_lights].state = atoi(state);
            num_lights++;
        }
    }

    fclose(file);
    return num_lights;
}

// Write light configurations to file
int write_config() {
    FILE *file = fopen(CONFIG_FILE, "w");
    if (file == NULL) {
        return -1;
    }

    for (int i = 0; i < sizeof(lights) / sizeof(light_config); i++) {
        fprintf(file, "%s,%d,%d\n", lights[i].name, lights[i].pin, lights[i].state);
    }

    fclose(file);
    return 0;
}

// Toggle light state
void toggle_light(int light_index) {
    lights[light_index].state = !lights[light_index].state;
    write_config();
}

// Print light status
void print_status() {
    for (int i = 0; i < sizeof(lights) / sizeof(light_config); i++) {
        printf("%s: %s\n", lights[i].name, lights[i].state ? "ON" : "OFF");
    }
}

// Main function
int main() {
    int num_lights = read_config();
    if (num_lights < 0) {
        printf("Error reading config file\n");
        return -1;
    }

    char command[128];
    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        char *verb = strtok(command, " ");
        char *arg1 = strtok(NULL, " ");

        if (strcmp(verb, "help") == 0) {
            printf("Available commands:\n");
            printf("help: Display this help message\n");
            printf("list: List all lights\n");
            printf("toggle <light_name>: Toggle the state of a light\n");
            printf("exit: Exit the program\n");
        } else if (strcmp(verb, "list") == 0) {
            print_status();
        } else if (strcmp(verb, "toggle") == 0) {
            // Find light by name
            int light_index = -1;
            for (int i = 0; i < num_lights; i++) {
                if (strcmp(lights[i].name, arg1) == 0) {
                    light_index = i;
                    break;
                }
            }

            if (light_index == -1) {
                printf("Light not found\n");
            } else {
                toggle_light(light_index);
                printf("%s is now %s\n", lights[light_index].name, lights[light_index].state ? "ON" : "OFF");
            }
        } else if (strcmp(verb, "exit") == 0) {
            break;
        } else {
            printf("Unknown command\n");
        }
    }

    return 0;
}