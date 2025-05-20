//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

// Dynamically load the browser plugin library
void* load_plugin(char* library_path) {
    void* handle = dlopen(library_path, RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "Error: Unable to load plugin %s: %s\n", library_path, dlerror());
        exit(1);
    }
    return handle;
}

// Get the plugin's initialization function
typedef int (*init_func_t)(void);
init_func_t get_init_func(void* handle) {
    init_func_t init_func = dlsym(handle, "init");
    if (!init_func) {
        fprintf(stderr, "Error: Unable to find init function in plugin: %s\n", dlerror());
        exit(1);
    }
    return init_func;
}

// Get the plugin's execute function
typedef int (*execute_func_t)(const char* url);
execute_func_t get_execute_func(void* handle) {
    execute_func_t execute_func = dlsym(handle, "execute");
    if (!execute_func) {
        fprintf(stderr, "Error: Unable to find execute function in plugin: %s\n", dlerror());
        exit(1);
    }
    return execute_func;
}

// Unload the browser plugin library
void unload_plugin(void* handle) {
    dlclose(handle);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <plugin_library_path> <url>\n", argv[0]);
        exit(1);
    }

    // Load the plugin library
    void* handle = load_plugin(argv[1]);

    // Get the plugin's initialization function
    init_func_t init_func = get_init_func(handle);

    // Initialize the plugin
    int init_status = init_func();
    if (init_status != 0) {
        fprintf(stderr, "Error: Plugin initialization failed: %d\n", init_status);
        unload_plugin(handle);
        exit(1);
    }

    // Get the plugin's execute function
    execute_func_t execute_func = get_execute_func(handle);

    // Execute the plugin with the given URL
    int execute_status = execute_func(argv[2]);
    if (execute_status != 0) {
        fprintf(stderr, "Error: Plugin execution failed: %d\n", execute_status);
        unload_plugin(handle);
        exit(1);
    }

    // Unload the plugin library
    unload_plugin(handle);

    return 0;
}