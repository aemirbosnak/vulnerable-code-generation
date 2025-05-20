//FormAI DATASET v1.0 Category: Browser Plugin ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLUGIN_VERSION 1.0

// The function that will be called when the plugin is loaded
void init_plugin() {
    printf("My Browser Plugin %0.1f has been loaded!\n", PLUGIN_VERSION);
}

// A sample function that can be called by the browser
void calculate(int x, int y) {
    printf("Calculating %d + %d = %d\n", x, y, x+y);
}

// A sample function that can be called by the browser
void search(char* query) {
    printf("Searching for '%s'...\n", query);
    // Code to perform search algorithm
}

// The function that will be called when the plugin is unloaded
void deinit_plugin() {
    printf("My Browser Plugin %0.1f has been unloaded!\n", PLUGIN_VERSION);
}

// The main function of the plugin
int main() {
    // Initialize the plugin
    init_plugin();
    
    // Loop indefinitely, waiting for commands from the browser
    while(1) {
        // Read the message from the browser
        char* message = (char*) malloc(sizeof(char) * 256);
        scanf("%s", message);
        
        // Check the message and call the appropriate function
        if(strcmp(message, "calculate") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            calculate(x, y);
        }
        else if(strcmp(message, "search") == 0) {
            char* query = (char*) malloc(sizeof(char) * 256);
            scanf("%s", query);
            search(query);
        }
        else if(strcmp(message, "exit") == 0) {
            // Free memory and exit the program
            free(message);
            deinit_plugin();
            return 0;
        }
        
        // Free memory used by the message
        free(message);
    }
}