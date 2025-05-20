//Falcon2-11B DATASET v1.0 Category: Browser Plugin ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the plugin
struct Plugin {
    char* name;
    int version;
    char* description;
};

// Function to add a new plugin
int add_plugin(struct Plugin* plugins, int size, char* name, int version, char* description) {
    if (size >= 100) {
        return -1; // Plugin list is full
    }
    if (name == NULL || strlen(name) == 0) {
        return -2; // Invalid plugin name
    }
    if (version < 1 || version > 100) {
        return -3; // Invalid plugin version
    }
    if (description == NULL || strlen(description) == 0) {
        return -4; // Invalid plugin description
    }

    // Add the new plugin to the list
    plugins[size].name = strdup(name);
    plugins[size].version = version;
    plugins[size].description = strdup(description);
    size++;

    return size;
}

// Function to remove a plugin by name
int remove_plugin(struct Plugin* plugins, int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(plugins[i].name, name) == 0) {
            // Free memory for the plugin
            free(plugins[i].name);
            free(plugins[i].description);

            // Shift the remaining plugins to fill the gap
            for (int j = i; j < size - 1; j++) {
                plugins[j] = plugins[j + 1];
            }
            size--;

            return size;
        }
    }

    return -1; // Plugin not found
}

// Function to print all plugins
void print_plugins(struct Plugin* plugins, int size) {
    printf("Plugin List:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\nVersion: %d\nDescription: %s\n", plugins[i].name, plugins[i].version, plugins[i].description);
    }
}

// Main function
int main() {
    struct Plugin plugins[100];
    int size = 0;

    // Add some plugins
    add_plugin(plugins, size, "Plugin1", 1, "First plugin");
    add_plugin(plugins, size, "Plugin2", 2, "Second plugin");
    add_plugin(plugins, size, "Plugin3", 3, "Third plugin");

    // Remove a plugin
    remove_plugin(plugins, size, "Plugin2");

    // Print all plugins
    print_plugins(plugins, size);

    return 0;
}