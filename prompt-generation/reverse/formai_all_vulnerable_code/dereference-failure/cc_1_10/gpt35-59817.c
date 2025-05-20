//FormAI DATASET v1.0 Category: Browser Plugin ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define constants for plugin name and version
#define PLUGIN_NAME "ThoughtfulPlugin"
#define PLUGIN_VERSION "v1.0"

// Define a struct for storing plugin information
typedef struct PluginInfo {
    char* name;
    char* version;
    bool isActive;
} PluginInfo;

// Define a function that initializes the PluginInfo struct
PluginInfo* InitializePluginInfo() {
    PluginInfo* pluginInfo = malloc(sizeof(PluginInfo));
    pluginInfo->name = PLUGIN_NAME;
    pluginInfo->version = PLUGIN_VERSION;
    pluginInfo->isActive = false;

    return pluginInfo;
}

// Define a function that sets the active state of the plugin
void SetPluginActiveState(PluginInfo* pluginInfo, bool isActive) {
    pluginInfo->isActive = isActive;
}

// Define a function that gets the active state of the plugin
bool GetPluginActiveState(PluginInfo* pluginInfo) {
    return pluginInfo->isActive;
}

// Define a function that prints the plugin info to stdout
void PrintPluginInfo(PluginInfo* pluginInfo) {
    printf("Plugin Name: %s\n", pluginInfo->name);
    printf("Version: %s\n", pluginInfo->version);

    if (pluginInfo->isActive) {
        printf("Status: Active\n");
    } else {
        printf("Status: Inactive\n");
    }
}

int main() {
    // Initialize the plugin info struct
    PluginInfo* pluginInfo = InitializePluginInfo();

    // Print the initial plugin info
    printf("Initial Plugin Info:\n");
    PrintPluginInfo(pluginInfo);

    // Activate the plugin and print the updated info
    printf("\nActivating Plugin...\n");
    SetPluginActiveState(pluginInfo, true);
    PrintPluginInfo(pluginInfo);

    // Deactivate the plugin and print the updated info
    printf("\nDeactivating Plugin...\n");
    SetPluginActiveState(pluginInfo, false);
    PrintPluginInfo(pluginInfo);

    return 0;
}