//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: optimized
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIGHTS 4
#define MAX_NAME_LEN 64

typedef struct {
    char name[MAX_NAME_LEN];
    bool state;
} light_t;

static light_t lights[LIGHTS] = {
    {"Kitchen", false},
    {"Living room", false},
    {"Bedroom", false},
    {"Bathroom", false},
};

static void print_usage(const char *argv[]) {
    printf("Usage: %s <command> <arguments>\n", argv[0]);
    printf("Commands:\n");
    printf("  list: List all lights and their states\n");
    printf("  on <light name>: Turn on the specified light\n");
    printf("  off <light name>: Turn off the specified light\n");
    printf("  toggle <light name>: Toggle the state of the specified light\n");
}

static int find_light_index(const char *name) {
    for (int i = 0; i < LIGHTS; i++) {
        if (strcmp(name, lights[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

static void list_lights(void) {
    printf("Lights:\n");
    for (int i = 0; i < LIGHTS; i++) {
        printf("  %s: %s\n", lights[i].name, lights[i].state ? "on" : "off");
    }
}

static void turn_on(const char *name) {
    int index = find_light_index(name);
    if (index == -1) {
        printf("Error: Unknown light '%s'\n", name);
    } else {
        lights[index].state = true;
        printf("Light '%s' turned on\n", name);
    }
}

static void turn_off(const char *name) {
    int index = find_light_index(name);
    if (index == -1) {
        printf("Error: Unknown light '%s'\n", name);
    } else {
        lights[index].state = false;
        printf("Light '%s' turned off\n", name);
    }
}

static void toggle(const char *name) {
    int index = find_light_index(name);
    if (index == -1) {
        printf("Error: Unknown light '%s'\n", name);
    } else {
        lights[index].state = !lights[index].state;
        printf("Light '%s' toggled\n", name);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv);
        return 1;
    }

    const char *command = argv[1];

    if (strcmp(command, "list") == 0) {
        list_lights();
    } else if (strcmp(command, "on") == 0) {
        if (argc < 3) {
            printf("Error: Missing light name\n");
            return 1;
        }
        turn_on(argv[2]);
    } else if (strcmp(command, "off") == 0) {
        if (argc < 3) {
            printf("Error: Missing light name\n");
            return 1;
        }
        turn_off(argv[2]);
    } else if (strcmp(command, "toggle") == 0) {
        if (argc < 3) {
            printf("Error: Missing light name\n");
            return 1;
        }
        toggle(argv[2]);
    } else {
        printf("Error: Unknown command '%s'\n", command);
        return 1;
    }

    return 0;
}