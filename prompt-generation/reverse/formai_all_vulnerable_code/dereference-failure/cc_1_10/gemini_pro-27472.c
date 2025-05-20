//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef int (*BrowserPluginInitFunc)(void);
typedef void (*BrowserPluginFiniFunc)(void);
typedef void (*BrowserPluginNavigateFunc)(const char *url);

struct BrowserPlugin {
    BrowserPluginInitFunc init;
    BrowserPluginFiniFunc fini;
    BrowserPluginNavigateFunc navigate;
};

static struct BrowserPlugin browser_plugin;

static void load_browser_plugin(const char *path)
{
    void *handle = dlopen(path, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error loading browser plugin: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    browser_plugin.init = dlsym(handle, "browser_plugin_init");
    browser_plugin.fini = dlsym(handle, "browser_plugin_fini");
    browser_plugin.navigate = dlsym(handle, "browser_plugin_navigate");

    if (!browser_plugin.init || !browser_plugin.fini || !browser_plugin.navigate) {
        fprintf(stderr, "Error finding browser plugin symbols: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }
}

static void unload_browser_plugin(void)
{
    void *handle = dlopen(NULL, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error unloading browser plugin: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlclose(handle);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path-to-browser-plugin>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_browser_plugin(argv[1]);

    browser_plugin.init();

    browser_plugin.navigate("https://example.com");

    browser_plugin.fini();

    unload_browser_plugin();

    return EXIT_SUCCESS;
}