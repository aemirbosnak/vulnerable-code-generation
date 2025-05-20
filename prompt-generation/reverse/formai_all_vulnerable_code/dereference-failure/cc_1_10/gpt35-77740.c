//FormAI DATASET v1.0 Category: Browser Plugin ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PLUGIN_NAME "DynamicPlugin"
#define PLUGIN_DESCRIPTION "This is a dynamic browser plugin example"
#define PLUGIN_VERSION "1.0.0"

typedef struct Plugin {
    char* name;
    char* description;
    char* version;
    bool enabled;
} Plugin;

char* getPluginName() {
    return PLUGIN_NAME;
}

char* getPluginDescription() {
    return PLUGIN_DESCRIPTION;
}

char* getPluginVersion() {
    return PLUGIN_VERSION;
}

static Plugin* newPlugin(char* name, char* description, char* version) {
    Plugin* plugin = malloc(sizeof (Plugin));
    plugin->name = name;
    plugin->description = description;
    plugin->version = version;
    plugin->enabled = false;
    return plugin;
}

static void enablePlugin(Plugin* plugin) {
    plugin->enabled = true;
    printf("Plugin '%s' has been enabled.\n", plugin->name);
}

static void disablePlugin(Plugin* plugin) {
    plugin->enabled = false;
    printf("Plugin '%s' has been disabled.\n", plugin->name);
}

int main(int argc, char** argv) {
    Plugin* myPlugin = newPlugin("MyPlugin", "This is a sample plugin", "1.0.0");

    enablePlugin(myPlugin); // enable the plugin

    disablePlugin(myPlugin); // disable the plugin

    free(myPlugin); // free the memory allocated for the plugin

    return 0;
}