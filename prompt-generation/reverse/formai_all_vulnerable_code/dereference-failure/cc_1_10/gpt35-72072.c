//FormAI DATASET v1.0 Category: Browser Plugin ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the plugin
typedef struct {
    char *name;
    char *description;
    void (*execute)(void);
} Plugin;

Plugin *plugins[10];
int num_plugins = 0;

// Add a plugin to the plugin array
void add_plugin(char *name, char *description, void (*execute)(void)) {
    if (num_plugins < 10) {
        Plugin *plugin = malloc(sizeof(Plugin));
        plugin->name = strdup(name);
        plugin->description = strdup(description);
        plugin->execute = execute;
        plugins[num_plugins++] = plugin;
    } else {
        printf("Error: Maximum number of plugins reached\n");
    }
}

// Greets the user
void greeting(void) {
    printf("Hello, world!\n");
}

// Adds 2 numbers together
void add_numbers(void) {
    int x, y;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &x, &y);
    printf("The sum is %d\n", x + y);
}

int main() {
    add_plugin("Greeting", "Greets the user", greeting);
    add_plugin("Add Numbers", "Adds two numbers together", add_numbers);

    // Execute all of the plugins
    for (int i = 0; i < num_plugins; i++) {
        printf("%d. %s - %s\n", i+1, plugins[i]->name, plugins[i]->description);
        plugins[i]->execute();
        printf("\n");
    }

    return 0;
}