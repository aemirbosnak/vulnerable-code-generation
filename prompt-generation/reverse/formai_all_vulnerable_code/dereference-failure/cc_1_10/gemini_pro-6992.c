//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef struct Plugin {
    void *handle;
    void (*init)(void);
    void (*destroy)(void);
    void (*render)(void);
} Plugin;

Plugin *load_plugin(const char *path) {
    Plugin *plugin = calloc(1, sizeof(Plugin));

    plugin->handle = dlopen(path, RTLD_NOW);
    if (!plugin->handle) {
        fprintf(stderr, "Error loading plugin: %s\n", dlerror());
        return NULL;
    }

    plugin->init = dlsym(plugin->handle, "plugin_init");
    if (!plugin->init) {
        fprintf(stderr, "Error getting symbol \"plugin_init\": %s\n", dlerror());
        dlclose(plugin->handle);
        return NULL;
    }

    plugin->destroy = dlsym(plugin->handle, "plugin_destroy");
    if (!plugin->destroy) {
        fprintf(stderr, "Error getting symbol \"plugin_destroy\": %s\n", dlerror());
        dlclose(plugin->handle);
        return NULL;
    }

    plugin->render = dlsym(plugin->handle, "plugin_render");
    if (!plugin->render) {
        fprintf(stderr, "Error getting symbol \"plugin_render\": %s\n", dlerror());
        dlclose(plugin->handle);
        return NULL;
    }

    plugin->init();

    return plugin;
}

void unload_plugin(Plugin *plugin) {
    plugin->destroy();
    dlclose(plugin->handle);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <plugin path>\n", argv[0]);
        return 1;
    }

    Plugin *plugin = load_plugin(argv[1]);
    if (!plugin) {
        return 1;
    }

    plugin->render();

    unload_plugin(plugin);

    return 0;
}