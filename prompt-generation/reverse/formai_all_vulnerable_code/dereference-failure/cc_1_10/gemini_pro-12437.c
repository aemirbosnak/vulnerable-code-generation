//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <assert.h>

typedef struct plugin_entry {
    char *name;
    void (*init)();
    void (*fini)();
    bool (*handle_event)(void *event);
} plugin_entry;

typedef struct browser_plugin {
    char *name;
    void *handle;
    plugin_entry *entry;
} browser_plugin;

typedef struct browser_event {
    int type;
    void *data;
} browser_event;

#define PLUGIN_EVENT_TYPE_LOAD    1
#define PLUGIN_EVENT_TYPE_UNLOAD  2
#define PLUGIN_EVENT_TYPE_MESSAGE 3

static browser_plugin plugins[10];
static int num_plugins = 0;

void register_plugin(browser_plugin *plugin) {
    assert(num_plugins < 10);
    plugins[num_plugins++] = *plugin;
}

void load_plugin(char *name) {
    browser_plugin plugin;
    plugin.name = name;
    plugin.handle = dlopen(name, RTLD_NOW);
    if (!plugin.handle) {
        fprintf(stderr, "Failed to load plugin: %s\n", dlerror());
        return;
    }
    plugin.entry = dlsym(plugin.handle, "plugin_entry");
    if (!plugin.entry) {
        fprintf(stderr, "Failed to find plugin entry point: %s\n", dlerror());
        dlclose(plugin.handle);
        return;
    }
    register_plugin(&plugin);
}

void unload_plugin(browser_plugin *plugin) {
    dlclose(plugin->handle);
    plugin->handle = NULL;
    plugin->entry = NULL;
}

void init_plugins() {
    for (int i = 0; i < num_plugins; i++) {
        if (plugins[i].entry->init) {
            plugins[i].entry->init();
        }
    }
}

void fini_plugins() {
    for (int i = 0; i < num_plugins; i++) {
        if (plugins[i].entry->fini) {
            plugins[i].entry->fini();
        }
    }
}

bool handle_event(browser_event *event) {
    bool handled = false;
    for (int i = 0; i < num_plugins; i++) {
        if (plugins[i].entry->handle_event) {
            handled |= plugins[i].entry->handle_event(event);
        }
    }
    return handled;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <plugin1> <plugin2> ...\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        load_plugin(argv[i]);
    }
    init_plugins();
    browser_event event;
    while (true) {
        if (!handle_event(&event)) {
            break;
        }
    }
    fini_plugins();
    for (int i = 0; i < num_plugins; i++) {
        unload_plugin(&plugins[i]);
    }
    return 0;
}