//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLUGINS 10
#define MAX_PLUGIN_NAME_LEN 50
#define MAX_PLUGIN_VALUE_LEN 100

typedef struct {
    char name[MAX_PLUGIN_NAME_LEN];
    char value[MAX_PLUGIN_VALUE_LEN];
} Plugin;

int numPlugins;
Plugin plugins[MAX_PLUGINS];

void loadPlugins() {
    FILE *fp;
    char line[MAX_PLUGIN_VALUE_LEN];
    char *token;

    numPlugins = 0;

    if ((fp = fopen("plugins.txt", "r")) == NULL) {
        printf("Error: could not open plugins.txt\n");
        exit(1);
    }

    while (fgets(line, MAX_PLUGIN_VALUE_LEN, fp)!= NULL) {
        if (numPlugins >= MAX_PLUGINS) {
            printf("Error: too many plugins\n");
            exit(1);
        }

        token = strtok(line, ":");
        strcpy(plugins[numPlugins].name, token);

        token = strtok(NULL, ":");
        strcpy(plugins[numPlugins].value, token);

        numPlugins++;
    }

    fclose(fp);
}

void unloadPlugins() {
    int i;

    for (i = 0; i < numPlugins; i++) {
        free(plugins[i].name);
        free(plugins[i].value);
    }

    numPlugins = 0;
}

void *getPluginValue(char *name) {
    int i;

    for (i = 0; i < numPlugins; i++) {
        if (strcmp(name, plugins[i].name) == 0) {
            return plugins[i].value;
        }
    }

    return NULL;
}

void initBrowser() {
    loadPlugins();
}

void destroyBrowser() {
    unloadPlugins();
}

int main() {
    initBrowser();

    char *value = getPluginValue("example_plugin");
    printf("Example plugin value: %s\n", value);

    destroyBrowser();

    return 0;
}