//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dlfcn.h>

typedef struct {
  void *handle;
  void *symbol;
} plugin_t;

plugin_t *plugin_load(const char *path) {
  plugin_t *plugin = malloc(sizeof(plugin_t));
  plugin->handle = dlopen(path, RTLD_LAZY);
  if (!plugin->handle) {
    fprintf(stderr, "dlopen() failed: %s\n", dlerror());
    free(plugin);
    return NULL;
  }
  plugin->symbol = dlsym(plugin->handle, "initialize");
  if (!plugin->symbol) {
    fprintf(stderr, "dlsym() failed: %s\n", dlerror());
    dlclose(plugin->handle);
    free(plugin);
    return NULL;
  }
  return plugin;
}

void plugin_unload(plugin_t *plugin) {
  dlclose(plugin->handle);
  free(plugin);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <plugin path>\n", argv[0]);
    return -1;
  }
  plugin_t *plugin = plugin_load(argv[1]);
  if (!plugin) {
    return -1;
  }
  typedef void (*initialize_fn)(void);
  initialize_fn initialize = (initialize_fn)plugin->symbol;
  initialize();
  plugin_unload(plugin);
  return 0;
}