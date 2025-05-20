//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Defining the structure for our plugin
struct BrowserPlugin {
    char* name;
    char* version;
    bool enabled;
};

// Function to create a new plugin instance
struct BrowserPlugin* createPlugin(char* name, char* version) {
    // Allocate memory for plugin instance
    struct BrowserPlugin* plugin = malloc(sizeof(struct BrowserPlugin));

    // Set plugin properties
    plugin->name = name;
    plugin->version = version;
    plugin->enabled = false;

    // Return plugin instance
    return plugin;
}

// Function to enable plugin
void enablePlugin(struct BrowserPlugin* plugin) {
    plugin->enabled = true;
    printf("Enabled plugin: %s v%s\n", plugin->name, plugin->version);
}

// Function to disable plugin
void disablePlugin(struct BrowserPlugin* plugin) {
    plugin->enabled = false;
    printf("Disabled plugin: %s v%s\n", plugin->name, plugin->version);
}

int main() {
    // Create sample plugins
    struct BrowserPlugin* adBlock = createPlugin("Ad Blocker", "1.0");
    struct BrowserPlugin* spellChecker = createPlugin("Spell Checker", "2.1");

    // Enable and disable plugins
    enablePlugin(adBlock);
    disablePlugin(spellChecker);

    // Free memory allocated for plugins
    free(adBlock);
    free(spellChecker);

    return 0;
}