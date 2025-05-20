//FormAI DATASET v1.0 Category: Browser Plugin ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Define struct for the plugin */
typedef struct {
    char *name;
    bool enabled;
} Plugin;

/* Define an array of plugins */
Plugin plugins[10];

/* Function to enable a plugin */
void enablePlugin(char* name) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(plugins[i].name, name) == 0) {
            plugins[i].enabled = true;
            printf("%s plugin has been enabled!\n", name);
            return;
        }
    }
    printf("Plugin not found!\n");
}

/* Function to disable a plugin */
void disablePlugin(char* name) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(plugins[i].name, name) == 0) {
            plugins[i].enabled = false;
            printf("%s plugin has been disabled!\n", name);
            return;
        }
    }
    printf("Plugin not found!\n");
}

/* Main function */
int main() {
    /* Initialize plugins */
    plugins[0].name = "adblock";
    plugins[0].enabled = true;

    plugins[1].name = "spellcheck";
    plugins[1].enabled = false;

    plugins[2].name = "pop-up blocker";
    plugins[2].enabled = true;

    /* Test enablePlugin() and disablePlugin() functions */
    enablePlugin("spellcheck");
    disablePlugin("adblock");
    enablePlugin("Not a real plugin");

    return 0;
}