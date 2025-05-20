//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLUGINS 10
#define MAX_PLUGIN_NAME_LENGTH 100
#define MAX_PLUGIN_FILE_LENGTH 1000
#define MAX_PLUGIN_COMMAND_LENGTH 100

typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
    char file[MAX_PLUGIN_FILE_LENGTH];
    char command[MAX_PLUGIN_COMMAND_LENGTH];
} Plugin;

int num_plugins;
Plugin *plugins;

void add_plugin(char *name, char *file, char *command) {
    if (num_plugins >= MAX_PLUGINS) {
        printf("Error: Maximum number of plugins reached.\n");
        return;
    }

    strncpy(plugins[num_plugins].name, name, MAX_PLUGIN_NAME_LENGTH);
    strncpy(plugins[num_plugins].file, file, MAX_PLUGIN_FILE_LENGTH);
    strncpy(plugins[num_plugins].command, command, MAX_PLUGIN_COMMAND_LENGTH);

    num_plugins++;
}

void list_plugins() {
    printf("Plugins:\n");
    for (int i = 0; i < num_plugins; i++) {
        printf("%s (%s, %s)\n", plugins[i].name, plugins[i].file, plugins[i].command);
    }
}

void run_plugin(char *name) {
    for (int i = 0; i < num_plugins; i++) {
        if (strcmp(plugins[i].name, name) == 0) {
            system(plugins[i].command);
            break;
        }
    }
}

int main() {
    add_plugin("Hello", "hello.txt", "echo Hello World");
    add_plugin("Goodbye", "goodbye.txt", "echo Goodbye World");

    list_plugins();

    run_plugin("Hello");
    run_plugin("Goodbye");

    return 0;
}