//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <dirent.h>

#define PLUGIN_NAME "SamplePlugin"
#define PLUGIN_VERSION "1.0"

// Function pointer types for hooks
typedef void (*init_func)();
typedef void (*destroy_func)();

// Plugin structure to hold function pointers
typedef struct {
    char name[50];
    char version[10];
    void *handle;
    init_func init;
    destroy_func destroy;
} Plugin;

void load_plugin(Plugin *plugin, const char *path) {
    // Open the plugin shared library
    plugin->handle = dlopen(path, RTLD_LAZY);
    if (!plugin->handle) {
        fprintf(stderr, "Failed to load plugin: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    // Load the init and destroy functions
    plugin->init = (init_func)dlsym(plugin->handle, "init");
    if (!plugin->init) {
        fprintf(stderr, "Failed to load init function: %s\n", dlerror());
        dlclose(plugin->handle);
        exit(EXIT_FAILURE);
    }

    plugin->destroy = (destroy_func)dlsym(plugin->handle, "destroy");
    if (!plugin->destroy) {
        fprintf(stderr, "Failed to load destroy function: %s\n", dlerror());
        dlclose(plugin->handle);
        exit(EXIT_FAILURE);
    }

    // Store plugin information
    strcpy(plugin->name, PLUGIN_NAME);
    strcpy(plugin->version, PLUGIN_VERSION);
}

void unload_plugin(Plugin *plugin) {
    // Call the destroy function if it exists
    if (plugin->destroy) {
        plugin->destroy();
    }
    // Close the plugin handle
    dlclose(plugin->handle);
}

void list_plugins(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Available plugins:\n");
    while ((entry = readdir(dp)) != NULL) {
        if (strstr(entry->d_name, ".so")) {
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

int main() {
    char plugin_path[100];
    Plugin my_plugin;

    printf("=== Plugin Loader ===\n");

    // List available plugins in the current directory
    list_plugins(".");

    // Prompt user for plugin
    printf("Enter plugin filename (with .so): ");
    scanf("%s", plugin_path);

    // Load the specified plugin
    load_plugin(&my_plugin, plugin_path);

    // Initialize the plugin
    my_plugin.init();

    // Let user know the plugin has been initialized
    printf("Plugin '%s' version '%s' loaded and initialized.\n", my_plugin.name, my_plugin.version);

    // Simulate some processing...
    printf("Processing...\n");
    sleep(2);  // Sleep to simulate work

    // Unload the plugin
    unload_plugin(&my_plugin);
    printf("Plugin unloaded successfully.\n");

    return 0;
}