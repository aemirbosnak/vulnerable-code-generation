//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef struct {
  void *handle;
  void (*init)(void);
  void (*quit)(void);
  char **(*get_urls)(void);
} browser_plugin;

browser_plugin *load_plugin(const char *name) {
  void *handle = dlopen(name, RTLD_NOW);
  if (handle == NULL) {
    fprintf(stderr, "dlopen failed: %s\n", dlerror());
    return NULL;
  }

  void (*init)(void) = dlsym(handle, "init");
  if (init == NULL) {
    fprintf(stderr, "dlsym failed: %s\n", dlerror());
    dlclose(handle);
    return NULL;
  }

  void (*quit)(void) = dlsym(handle, "quit");
  if (quit == NULL) {
    fprintf(stderr, "dlsym failed: %s\n", dlerror());
    dlclose(handle);
    return NULL;
  }

  char **(*get_urls)(void) = dlsym(handle, "get_urls");
  if (get_urls == NULL) {
    fprintf(stderr, "dlsym failed: %s\n", dlerror());
    dlclose(handle);
    return NULL;
  }

  browser_plugin *plugin = malloc(sizeof(browser_plugin));
  plugin->handle = handle;
  plugin->init = init;
  plugin->quit = quit;
  plugin->get_urls = get_urls;

  return plugin;
}

void unload_plugin(browser_plugin *plugin) {
  dlclose(plugin->handle);
  free(plugin);
}

int main(void) {
  browser_plugin *plugin = load_plugin("my_plugin.so");
  if (plugin == NULL) {
    return EXIT_FAILURE;
  }

  plugin->init();

  char **urls = plugin->get_urls();
  for (char **url = urls; *url != NULL; url++) {
    printf("%s\n", *url);
  }

  plugin->quit();
  unload_plugin(plugin);

  return EXIT_SUCCESS;
}