//FormAI DATASET v1.0 Category: Browser Plugin ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define plugin structure
typedef struct {
    char* name;
    char* version;
    char* author;
    bool enabled;
} Plugin;

// Define browser structure
typedef struct {
    char* name;
    char* version;
    Plugin** plugins;
    int numPlugins;
} Browser;

// Function to enable/disable plugin
void togglePlugin(Plugin* p) {
    if(p->enabled) {
        p->enabled = false;
        printf("%s plugin has been disabled\n", p->name);
    } else {
        p->enabled = true;
        printf("%s plugin has been enabled\n", p->name);
    }
}

int main() {
    // Initialize browser
    Browser myBrowser = {
        .name = "My Browser",
        .version = "1.0",
        .plugins = NULL,
        .numPlugins = 0
    };
    
    // Create plugins
    Plugin* adBlock = (Plugin*)malloc(sizeof(Plugin));
    adBlock->name = "Ad Block";
    adBlock->version = "2.0";
    adBlock->author = "Me";
    adBlock->enabled = true;
    
    Plugin* darkMode = (Plugin*)malloc(sizeof(Plugin));
    darkMode->name = "Dark Mode";
    darkMode->version = "1.5";
    darkMode->author = "Me";
    darkMode->enabled = false;
    
    // Add plugins to browser
    myBrowser.plugins = (Plugin**)malloc(2*sizeof(Plugin*));
    myBrowser.plugins[0] = adBlock;
    myBrowser.plugins[1] = darkMode;
    myBrowser.numPlugins = 2;
    
    // Test plugin functionality
    togglePlugin(adBlock); // Should disable Ad Block
    togglePlugin(darkMode); // Should enable Dark Mode
    togglePlugin(adBlock); // Should enable Ad Block
    
    return 0;
}