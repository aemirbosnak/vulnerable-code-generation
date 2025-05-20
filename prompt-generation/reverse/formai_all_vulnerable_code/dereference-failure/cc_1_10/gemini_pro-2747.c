//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

typedef struct {
    void *handle;
    void *symbol;
} Plugin;

Plugin *plugin_load(const char *path) {
    void *handle = dlopen(path, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen: %s", dlerror());
        return NULL;
    }

    void *symbol = dlsym(handle, "plugin_init");
    if (!symbol) {
        fprintf(stderr, "dlsym: %s", dlerror());
        dlclose(handle);
        return NULL;
    }

    Plugin *plugin = malloc(sizeof(Plugin));
    plugin->handle = handle;
    plugin->symbol = symbol;
    return plugin;
}

void plugin_unload(Plugin *plugin) {
    dlclose(plugin->handle);
    free(plugin);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <plugin>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Plugin *plugin = plugin_load(argv[1]);
    if (!plugin) {
        return EXIT_FAILURE;
    }

    typedef void (*PluginInit)(void);
    PluginInit init = plugin->symbol;
    init();

    plugin_unload(plugin);
    return EXIT_SUCCESS;
}