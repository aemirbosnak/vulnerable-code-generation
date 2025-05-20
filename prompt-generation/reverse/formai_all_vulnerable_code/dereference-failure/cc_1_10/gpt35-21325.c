//FormAI DATASET v1.0 Category: Browser Plugin ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct browser_plugin {
    char *name;
    char *version;
    char *author;
    char *description;
    bool is_enabled;
} BrowserPlugin;

BrowserPlugin *init_browser_plugin(char *name, char *version, char *author, char *description, bool is_enabled) {
    BrowserPlugin *plugin = (BrowserPlugin *)malloc(sizeof(BrowserPlugin));
    plugin->name = (char *)malloc(strlen(name) + 1);
    plugin->version = (char *)malloc(strlen(version) + 1);
    plugin->author = (char *)malloc(strlen(author) + 1);
    plugin->description = (char *)malloc(strlen(description) + 1);
    
    strcpy(plugin->name, name);
    strcpy(plugin->version, version);
    strcpy(plugin->author, author);
    strcpy(plugin->description, description);
    
    plugin->is_enabled = is_enabled;
    
    return plugin;
}

void enable_plugin(BrowserPlugin *plugin) {
    plugin->is_enabled = true;
    printf("Plugin %s enabled.\n", plugin->name);
}

void disable_plugin(BrowserPlugin *plugin) {
    plugin->is_enabled = false;
    printf("Plugin %s disabled.\n", plugin->name);
}

void print_plugin_info(BrowserPlugin *plugin) {
    printf("Name: %s\nVersion: %s\nAuthor: %s\nDescription: %s\nEnabled: %s\n", 
            plugin->name, plugin->version, plugin->author, plugin->description, 
            plugin->is_enabled ? "true" : "false");
}

int main() {
    BrowserPlugin *plugin1 = init_browser_plugin("AdBlocker", "1.0.0", "John Doe", "Block ads on web pages.", true);
    BrowserPlugin *plugin2 = init_browser_plugin("Password Manager", "1.2.3", "Jane Smith", "Store and autofill login credentials.", false);
    BrowserPlugin *plugin3 = init_browser_plugin("Cookie Manager", "2.5.1", "Bob Johnson", "Manage cookies for each website you visit.", true);
    
    print_plugin_info(plugin1);
    print_plugin_info(plugin2);
    print_plugin_info(plugin3);
    
    disable_plugin(plugin1);
    enable_plugin(plugin2);
    
    print_plugin_info(plugin1);
    print_plugin_info(plugin2);
    print_plugin_info(plugin3);
    
    free(plugin1->name);
    free(plugin1->version);
    free(plugin1->author);
    free(plugin1->description);
    free(plugin1);
    
    free(plugin2->name);
    free(plugin2->version);
    free(plugin2->author);
    free(plugin2->description);
    free(plugin2);
    
    free(plugin3->name);
    free(plugin3->version);
    free(plugin3->author);
    free(plugin3->description);
    free(plugin3);
    
    return 0;
}