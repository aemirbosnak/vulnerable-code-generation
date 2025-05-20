//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: dynamic
/* Browser extension demo: Dynamically loaded JavaScript code */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>

#if defined(_WIN32)
# define DLL_SUFFIX ".dll"
#else
# define DLL_SUFFIX ".so"
#endif

static void *plugin_handle;
static bool (*plugin_init_func)(void);
static bool (*plugin_exec_func)(char **, size_t *);

void *
load_plugin(const char *path)
{
    char *real_path = malloc(strlen(path) + strlen(DLL_SUFFIX) + 1);
    strcpy(real_path, path);
    strcat(real_path, DLL_SUFFIX);

    plugin_handle = dlopen(real_path, RTLD_NOW);
    free(real_path);

    if (!plugin_handle) {
        fprintf(stderr, "Failed to load plugin '%s': %s\n",
                path, dlerror());
        return NULL;
    }

    plugin_init_func = dlsym(plugin_handle, "plugin_init");
    plugin_exec_func = dlsym(plugin_handle, "plugin_exec");

    if (!plugin_init_func || !plugin_exec_func) {
        fprintf(stderr, "Missing required symbols in plugin\n");
        dlclose(plugin_handle);
        return NULL;
    }

    return plugin_handle;
}

void
unload_plugin(void)
{
    if (plugin_handle) {
        dlclose(plugin_handle);
        plugin_handle = NULL;
        plugin_init_func = NULL;
        plugin_exec_func = NULL;
    }
}

int
main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <plugin path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!load_plugin(argv[1])) {
        return EXIT_FAILURE;
    }

    if (!plugin_init_func()) {
        fprintf(stderr, "Failed to initialize plugin\n");
        unload_plugin();
        return EXIT_FAILURE;
    }

    char *code = "alert('Hello from plugin')";
    size_t code_len = strlen(code) + 1;
    char *ret;
    size_t ret_len;

    if (!plugin_exec_func(&code, &code_len)) {
        fprintf(stderr, "Failed to execute plugin code\n");
        unload_plugin();
        return EXIT_FAILURE;
    }

    printf("Plugin return value:\n%s\n", code);

    free(ret);
    unload_plugin();

    return EXIT_SUCCESS;
}