//FormAI DATASET v1.0 Category: Browser Plugin ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PLUGIN_NAME "AwesomePlugin"
#define PLUGIN_VERSION "1.0"

typedef struct {
    char *name;
    char *version;
    bool enabled;
} Plugin;

Plugin *create_plugin(char *name, char *version) {
    Plugin *plugin = malloc(sizeof(Plugin));
    plugin->name = strdup(name);
    plugin->version = strdup(version);
    plugin->enabled = true;
    return plugin;
}

void destroy_plugin(Plugin *plugin) {
    free(plugin->name);
    free(plugin->version);
    free(plugin);
}

bool is_plugin_enabled(Plugin *plugin) {
    return plugin->enabled;
}

void disable_plugin(Plugin *plugin) {
    plugin->enabled = false;
}

void enable_plugin(Plugin *plugin) {
    plugin->enabled = true;
}

int main(void) {
    Plugin *awesome_plugin = create_plugin(PLUGIN_NAME, PLUGIN_VERSION);

    printf("%s version %s loaded successfully!\n", awesome_plugin->name, awesome_plugin->version);

    if (is_plugin_enabled(awesome_plugin)) {
        printf("Disabling %s...\n", awesome_plugin->name);
        disable_plugin(awesome_plugin);
        printf("%s disabled!\n", awesome_plugin->name);
    }

    printf("Enabling %s...\n", awesome_plugin->name);
    enable_plugin(awesome_plugin);
    printf("%s enabled!\n", awesome_plugin->name);

    destroy_plugin(awesome_plugin);

    return 0;
}