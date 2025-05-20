//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef struct {
    void *handle;
    void *init_func;
    void *fini_func;
    void *get_icon_func;
    void *get_name_func;
    void *get_desc_func;
    void *get_version_func;
    void *get_author_func;
} BrowserPlugin;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <plugin.so>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the plugin
    BrowserPlugin plugin;
    plugin.handle = dlopen(argv[1], RTLD_NOW);
    if (!plugin.handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    // Get the plugin's functions
    plugin.init_func = dlsym(plugin.handle, "init");
    if (!plugin.init_func) {
        fprintf(stderr, "dlsym failed: %s\n", dlerror());
        dlclose(plugin.handle);
        return EXIT_FAILURE;
    }

    plugin.fini_func = dlsym(plugin.handle, "fini");
    if (!plugin.fini_func) {
        fprintf(stderr, "dlsym failed: %s\n", dlerror());
        dlclose(plugin.handle);
        return EXIT_FAILURE;
    }

    plugin.get_icon_func = dlsym(plugin.handle, "get_icon");
    if (!plugin.get_icon_func) {
        fprintf(stderr, "dlsym failed: %s\n", dlerror());
        dlclose(plugin.handle);
        return EXIT_FAILURE;
    }

    plugin.get_name_func = dlsym(plugin.handle, "get_name");
    if (!plugin.get_name_func) {
        fprintf(stderr, "dlsym failed: %s\n", dlerror());
        dlclose(plugin.handle);
        return EXIT_FAILURE;
    }

    plugin.get_desc_func = dlsym(plugin.handle, "get_desc");
    if (!plugin.get_desc_func) {
        fprintf(stderr, "dlsym failed: %s\n", dlerror());
        dlclose(plugin.handle);
        return EXIT_FAILURE;
    }

    plugin.get_version_func = dlsym(plugin.handle, "get_version");
    if (!plugin.get_version_func) {
        fprintf(stderr, "dlsym failed: %s\n", dlerror());
        dlclose(plugin.handle);
        return EXIT_FAILURE;
    }

    plugin.get_author_func = dlsym(plugin.handle, "get_author");
    if (!plugin.get_author_func) {
        fprintf(stderr, "dlsym failed: %s\n", dlerror());
        dlclose(plugin.handle);
        return EXIT_FAILURE;
    }

    // Initialize the plugin
    ((void (*)(void))plugin.init_func)();

    // Get the plugin's information
    printf("Icon: %s\n", ((char *(*)())plugin.get_icon_func)());
    printf("Name: %s\n", ((char *(*)())plugin.get_name_func)());
    printf("Description: %s\n", ((char *(*)())plugin.get_desc_func)());
    printf("Version: %s\n", ((char *(*)())plugin.get_version_func)());
    printf("Author: %s\n", ((char *(*)())plugin.get_author_func)());

    // Finalize the plugin
    ((void (*)(void))plugin.fini_func)();

    // Unload the plugin
    dlclose(plugin.handle);

    return EXIT_SUCCESS;
}