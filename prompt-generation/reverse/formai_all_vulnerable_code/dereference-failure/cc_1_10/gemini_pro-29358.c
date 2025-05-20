//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#if defined(__APPLE__)
#define PLUGIN_EXT "dylib"
#elif defined(__linux__)
#define PLUGIN_EXT "so"
#elif defined(_WIN32)
#define PLUGIN_EXT "dll"
#else
#error "Unsupported platform!"
#endif

typedef struct {
    void* handle;
    void* init_func;
    void* destroy_func;
    void* get_browser_info_func;
    void* get_page_info_func;
} Plugin;

Plugin* load_plugin(const char* path) {
    Plugin* plugin = malloc(sizeof(Plugin));

    plugin->handle = dlopen(path, RTLD_LAZY);
    if (!plugin->handle) {
        free(plugin);
        return NULL;
    }

    plugin->init_func = dlsym(plugin->handle, "init");
    plugin->destroy_func = dlsym(plugin->handle, "destroy");
    plugin->get_browser_info_func = dlsym(plugin->handle, "get_browser_info");
    plugin->get_page_info_func = dlsym(plugin->handle, "get_page_info");

    if (!plugin->init_func || !plugin->destroy_func || !plugin->get_browser_info_func || !plugin->get_page_info_func) {
        dlclose(plugin->handle);
        free(plugin);
        return NULL;
    }

    return plugin;
}

void unload_plugin(Plugin* plugin) {
    if (plugin->handle) {
        dlclose(plugin->handle);
    }

    free(plugin);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <plugin path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Plugin* plugin = load_plugin(argv[1]);
    if (!plugin) {
        printf("Failed to load plugin!\n");
        return EXIT_FAILURE;
    }

    // Initialize the plugin.
    ((void(*)(void))plugin->init_func)();

    // Get browser information.
    const char* browser_name = ((const char*(*)())plugin->get_browser_info_func)();
    const char* browser_version = ((const char*(*)())plugin->get_browser_info_func)();

    // Get page information.
    const char* page_title = ((const char*(*)())plugin->get_page_info_func)();
    const char* page_url = ((const char*(*)())plugin->get_page_info_func)();

    // Print the information.
    printf("Browser: %s %s\n", browser_name, browser_version);
    printf("Page: %s (%s)\n", page_title, page_url);

    // Destroy the plugin.
    ((void(*)(void))plugin->destroy_func)();

    unload_plugin(plugin);

    return EXIT_SUCCESS;
}