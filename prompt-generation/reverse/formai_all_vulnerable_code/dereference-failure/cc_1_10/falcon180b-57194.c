//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *name;
    int (*func)(char *data);
} plugin_t;

int default_func(char *data) {
    printf("Default plugin: %s\n", data);
    return 0;
}

int main() {
    char line[MAX_LINE_SIZE];
    char *data;
    char *token;
    int i;
    int num_plugins = 0;
    plugin_t *plugins = NULL;

    // Load plugins
    while (fgets(line, MAX_LINE_SIZE, stdin)) {
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }
        data = strtok(NULL, ":");
        if (data == NULL) {
            continue;
        }
        plugins = realloc(plugins, sizeof(plugin_t) * ++num_plugins);
        plugins[num_plugins - 1].name = strdup(token);
        plugins[num_plugins - 1].func = default_func;
    }

    // Process input
    while (fgets(line, MAX_LINE_SIZE, stdin)) {
        data = line;
        for (i = 0; i < num_plugins; i++) {
            if (plugins[i].func!= default_func) {
                data = plugins[i].func(data);
            }
        }
        printf("%s\n", data);
    }

    return 0;
}