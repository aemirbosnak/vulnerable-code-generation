//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef struct {
  void *handle;
  char *name;
  int (*init)(void);
  void (*fini)(void);
  int (*handleEvent)(void *, void *);
} Plugin;

Plugin plugins[] = {
  { .name = "plugin1.so", .init = NULL, .fini = NULL, .handleEvent = NULL },
  { .name = "plugin2.so", .init = NULL, .fini = NULL, .handleEvent = NULL },
  { .name = "plugin3.so", .init = NULL, .fini = NULL, .handleEvent = NULL },
};

int loadPlugins() {
  for (int i = 0; i < sizeof(plugins) / sizeof(Plugin); i++) {
    plugins[i].handle = dlopen(plugins[i].name, RTLD_LAZY);
    if (!plugins[i].handle) {
      fprintf(stderr, "Error loading plugin %s: %s\n", plugins[i].name, dlerror());
      return -1;
    }
    plugins[i].init = dlsym(plugins[i].handle, "init");
    if (!plugins[i].init) {
      fprintf(stderr, "Error loading init function from plugin %s: %s\n", plugins[i].name, dlerror());
      return -1;
    }
    plugins[i].fini = dlsym(plugins[i].handle, "fini");
    if (!plugins[i].fini) {
      fprintf(stderr, "Error loading fini function from plugin %s: %s\n", plugins[i].name, dlerror());
      return -1;
    }
    plugins[i].handleEvent = dlsym(plugins[i].handle, "handleEvent");
    if (!plugins[i].handleEvent) {
      fprintf(stderr, "Error loading handleEvent function from plugin %s: %s\n", plugins[i].name, dlerror());
      return -1;
    }
    if (plugins[i].init() < 0) {
      fprintf(stderr, "Error initializing plugin %s: %s\n", plugins[i].name, dlerror());
      return -1;
    }
  }
  return 0;
}

int unloadPlugins() {
  for (int i = 0; i < sizeof(plugins) / sizeof(Plugin); i++) {
    if (plugins[i].fini) {
      plugins[i].fini();
    }
    if (plugins[i].handle) {
      dlclose(plugins[i].handle);
    }
  }
  return 0;
}

int handleEvent(void *data, void *event) {
  for (int i = 0; i < sizeof(plugins) / sizeof(Plugin); i++) {
    if (plugins[i].handleEvent) {
      plugins[i].handleEvent(data, event);
    }
  }
  return 0;
}

int main() {
  if (loadPlugins() < 0) {
    return -1;
  }
  handleEvent(NULL, NULL);
  unloadPlugins();
  return 0;
}