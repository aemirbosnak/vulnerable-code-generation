//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CMD_ON  "on"
#define CMD_OFF "off"
#define CMD_BLINK "blink"
#define CMD_CYCLE "cycle"

typedef struct {
    bool state;
    int rate;  // milliseconds
} light_t;

void light_init(light_t *light) {
    light->state = false;
    light->rate = 1000;  // default blink rate
}

void light_on(light_t *light) {
    light->state = true;
}

void light_off(light_t *light) {
    light->state = false;
}

void light_toggle(light_t *light) {
    light->state = !light->state;
}

void light_blink(light_t *light, int rate) {
    light->state = false;
    light->rate = rate;
}

void light_cycle(light_t *light, int rate) {
    light->state = true;
    light->rate = rate;
}

void light_print(light_t *light) {
    printf("Light is %s\n", light->state ? "on" : "off");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return EXIT_FAILURE;
    }

    light_t light;
    light_init(&light);

    if (!strcmp(argv[1], CMD_ON)) {
        light_on(&light);
    } else if (!strcmp(argv[1], CMD_OFF)) {
        light_off(&light);
    } else if (!strcmp(argv[1], CMD_BLINK)) {
        if (argc < 3) {
            printf("Usage: %s blink <rate>\n", argv[0]);
            return EXIT_FAILURE;
        }
        light_blink(&light, atoi(argv[2]));
    } else if (!strcmp(argv[1], CMD_CYCLE)) {
        if (argc < 3) {
            printf("Usage: %s cycle <rate>\n", argv[0]);
            return EXIT_FAILURE;
        }
        light_cycle(&light, atoi(argv[2]));
    } else {
        printf("Invalid command: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    light_print(&light);
    return EXIT_SUCCESS;
}