//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#define PLUGIN_API_VERSION 1
#define PLUGIN_API_NAME "my_plugin_api"

typedef struct my_plugin_api {
    int (*hello_world)(const char* name);
} my_plugin_api;

void* handle;
my_plugin_api* api;

void load_plugin(const char* path) {
    handle = dlopen(path, RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "Error loading plugin: %s\n", dlerror());
        exit(1);
    }

    api = dlsym(handle, PLUGIN_API_NAME);

    if (!api) {
        fprintf(stderr, "Error finding plugin API: %s\n", dlerror());
        exit(1);
    }

    if (api->hello_world == NULL) {
        fprintf(stderr, "Plugin does not support required API version\n");
        exit(1);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <plugin_path>\n", argv[0]);
        exit(1);
    }

    load_plugin(argv[1]);

    const char* name = "World";
    printf("Hello, ");
    api->hello_world(name);
    printf("!\n");

    dlclose(handle);
    return 0;
}