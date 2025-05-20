//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <dlfcn.h>

#define BROWSER_PLUGIN_VERSION "1.0"

static bool plugin_initialized = false;
static void *plugin_handle = NULL;
static int (*plugin_get_version)(void);
static int (*plugin_process_request)(const char *request, char **response);

static int plugin_init(const char *plugin_path) {
    plugin_handle = dlopen(plugin_path, RTLD_LAZY);
    if (!plugin_handle) {
        fprintf(stderr, "Error loading plugin: %s\n", dlerror());
        return -1;
    }

    plugin_get_version = (int (*)(void))dlsym(plugin_handle, "get_version");
    if (!plugin_get_version) {
        fprintf(stderr, "Error getting plugin version symbol: %s\n", dlerror());
        return -1;
    }

    plugin_process_request = (int (*)(const char *request, char **response))dlsym(plugin_handle, "process_request");
    if (!plugin_process_request) {
        fprintf(stderr, "Error getting plugin process_request symbol: %s\n", dlerror());
        return -1;
    }

    plugin_initialized = true;
    return 0;
}

static void plugin_fini(void) {
    if (plugin_initialized) {
        dlclose(plugin_handle);
        plugin_initialized = false;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <plugin path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (plugin_init(argv[1]) != 0) {
        return EXIT_FAILURE;
    }

    printf("Plugin version: %d\n", plugin_get_version());

    char *response = NULL;
    int ret = plugin_process_request("Hello, world!", &response);
    if (ret != 0 || !response) {
        fprintf(stderr, "Error processing request: %d\n", ret);
        return EXIT_FAILURE;
    }

    printf("Response: %s\n", response);
    free(response);

    plugin_fini();
    return EXIT_SUCCESS;
}