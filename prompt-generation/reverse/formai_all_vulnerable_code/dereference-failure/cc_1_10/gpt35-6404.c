//FormAI DATASET v1.0 Category: Browser Plugin ; Style: thoughtful
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Define the browser plugin struct
typedef struct browser_plugin_t {
    char* name;
    char* description;
    bool enabled;
} browser_plugin_t;

// Define the browser plugin list struct
typedef struct browser_plugin_list_t {
    int size;
    browser_plugin_t** plugins;
} browser_plugin_list_t;

// Create a new browser plugin
browser_plugin_t* create_plugin(char* name, char* description) {
    browser_plugin_t* plugin = (browser_plugin_t*) malloc(sizeof(browser_plugin_t));
    plugin->name = name;
    plugin->description = description;
    plugin->enabled = true;

    return plugin;
}

// Create a new browser plugin list
browser_plugin_list_t* create_plugin_list() {
    browser_plugin_list_t* plugin_list = (browser_plugin_list_t*) malloc(sizeof(browser_plugin_list_t));
    plugin_list->size = 0;
    plugin_list->plugins = (browser_plugin_t**) malloc(sizeof(browser_plugin_t*));

    return plugin_list;
}

// Add a plugin to the plugin list
void add_plugin_to_list(browser_plugin_list_t* plugin_list, browser_plugin_t* plugin) {
    plugin_list->size++;
    plugin_list->plugins = (browser_plugin_t**) realloc(plugin_list->plugins, plugin_list->size * sizeof(browser_plugin_t*));
    plugin_list->plugins[plugin_list->size-1] = plugin;
}

// Find a plugin by name in the plugin list
browser_plugin_t* find_plugin_by_name(browser_plugin_list_t* plugin_list, char* name) {
    for (int i = 0; i < plugin_list->size; i++) {
        if (strcmp(plugin_list->plugins[i]->name, name) == 0) {
            return plugin_list->plugins[i];
        }
    }
    return NULL;
}

// Enable or disable a plugin
void toggle_plugin(browser_plugin_t* plugin) {
    plugin->enabled = !plugin->enabled;
}

// Print the list of plugins
void print_plugin_list(browser_plugin_list_t* plugin_list) {
    for (int i = 0; i < plugin_list->size; i++) {
        printf("%d. %s - %s [%s]\n", i+1, plugin_list->plugins[i]->name, 
            plugin_list->plugins[i]->description, plugin_list->plugins[i]->enabled ? "Enabled" : "Disabled");
    }
}

// Test the plugin functions
int main() {
    browser_plugin_list_t* plugin_list = create_plugin_list();

    // Create some plugins
    browser_plugin_t* plugin1 = create_plugin("AdBlock", "Block ads on websites");
    browser_plugin_t* plugin2 = create_plugin("Password Manager", "Manage all your passwords in one place");
    browser_plugin_t* plugin3 = create_plugin("Grammar Checker", "Check your grammar and spelling as you type");

    // Add plugins to list
    add_plugin_to_list(plugin_list, plugin1);
    add_plugin_to_list(plugin_list, plugin2);
    add_plugin_to_list(plugin_list, plugin3);

    // Find a plugin by name and toggle its enabled status
    browser_plugin_t* found_plugin = find_plugin_by_name(plugin_list, "Password Manager");
    if (found_plugin != NULL) {
        toggle_plugin(found_plugin);
    }

    // Print the list of plugins
    print_plugin_list(plugin_list);

    // Free memory
    free(plugin1);
    free(plugin2);
    free(plugin3);
    free(plugin_list->plugins);
    free(plugin_list);

    return 0;
}