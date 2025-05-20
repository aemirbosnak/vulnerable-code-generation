//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLUGINS 10
#define MAX_PLUGIN_NAME_LENGTH 64

typedef struct plugin_t {
    char name[MAX_PLUGIN_NAME_LENGTH];
    void (*init)(void);
    void (*destroy)(void);
} Plugin;

typedef struct browser_t {
    Plugin *plugins[MAX_PLUGINS];
    int num_plugins;
} Browser;

void browser_init(Browser *browser) {
    browser->num_plugins = 0;
}

void browser_destroy(Browser *browser) {
    for (int i = 0; i < browser->num_plugins; i++) {
        browser->plugins[i]->destroy();
    }
}

void browser_add_plugin(Browser *browser, Plugin *plugin) {
    if (browser->num_plugins >= MAX_PLUGINS) {
        printf("Error: maximum number of plugins reached.\n");
        return;
    }
    strncpy(browser->plugins[browser->num_plugins]->name, plugin->name, MAX_PLUGIN_NAME_LENGTH);
    browser->plugins[browser->num_plugins++] = plugin;
}

void my_plugin_init(void) {
    printf("My Plugin initialized.\n");
}

void my_plugin_destroy(void) {
    printf("My Plugin destroyed.\n");
}

int main(void) {
    Browser browser;
    browser_init(&browser);

    Plugin my_plugin = {
       .name = "My Plugin",
       .init = my_plugin_init,
       .destroy = my_plugin_destroy
    };

    browser_add_plugin(&browser, &my_plugin);

    for (int i = 0; i < browser.num_plugins; i++) {
        browser.plugins[i]->init();
    }

    for (int i = 0; i < browser.num_plugins; i++) {
        browser.plugins[i]->destroy();
    }

    browser_destroy(&browser);

    return 0;
}