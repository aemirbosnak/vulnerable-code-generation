//FormAI DATASET v1.0 Category: Browser Plugin ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Plugin structure
typedef struct {
    char* name;
    char* description;
    char* version;
    bool enabled;
} Plugin;

// Define the Plugin Manager structure
typedef struct {
    Plugin** plugins;
    int num_plugins;
} PluginManager;

// Function to create a new plugin
Plugin* create_plugin(char* name, char* description, char* version) {
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    plugin->name = strdup(name);
    plugin->description = strdup(description);
    plugin->version = strdup(version);
    plugin->enabled = false;
    return plugin;
}

// Function to enable/disable a plugin
void set_plugin_enabled(Plugin* plugin, bool enabled) {
    plugin->enabled = enabled;
}

// Function to print a plugin's information
void display_plugin_info(Plugin* plugin) {
    printf("Name: %s\n", plugin->name);
    printf("Description: %s\n", plugin->description);
    printf("Version: %s\n", plugin->version);
    printf("Enabled: %s\n", plugin->enabled ? "true" : "false");
}

// Function to create the Plugin Manager and add plugins
PluginManager* create_plugin_manager() {
    PluginManager* pm = (PluginManager*)malloc(sizeof(PluginManager));
    pm->num_plugins = 0;
    pm->plugins = NULL;
    pm->plugins = (Plugin**)realloc(pm->plugins, sizeof(Plugin*) * (pm->num_plugins + 1));
    pm->plugins[pm->num_plugins++] = create_plugin("Example Plugin 1", "This is an example plugin", "1.0");
    pm->plugins = (Plugin**)realloc(pm->plugins, sizeof(Plugin*) * (pm->num_plugins + 1));
    pm->plugins[pm->num_plugins++] = create_plugin("Example Plugin 2", "This is another example plugin", "2.0");
    return pm;
}

// Function to display all the plugins in the Plugin Manager
void display_plugin_manager(PluginManager* pm) {
    for(int i = 0; i < pm->num_plugins; i++) {
        printf("Plugin %d:\n", i + 1);
        display_plugin_info(pm->plugins[i]);
        printf("\n");
    }
}

int main() {
    PluginManager* pm = create_plugin_manager();
    printf("Plugins:\n\n");
    display_plugin_manager(pm);

    // Enable the first plugin
    set_plugin_enabled(pm->plugins[0], true);
    printf("Enabled Plugin 1:\n\n");
    display_plugin_manager(pm);

    // Enable the second plugin
    set_plugin_enabled(pm->plugins[1], true);
    printf("Enabled Plugin 1 and 2:\n\n");
    display_plugin_manager(pm);

    return 0;
}