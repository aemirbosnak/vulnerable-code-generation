//FormAI DATASET v1.0 Category: Browser Plugin ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the function signature for the plugin */
typedef void (*PluginFunction)(const char*);

/* Define plugin struct */
typedef struct Plugin {
  char name[64];
  PluginFunction func;
  struct Plugin* next;
} Plugin;

/* Define global plugin list */
Plugin* plugin_list = NULL;

/* Register a plugin */
void RegisterPlugin(const char* name, PluginFunction func) {
  /* Create new plugin */
  Plugin* plugin = malloc(sizeof(Plugin));
  strcpy(plugin->name, name);
  plugin->func = func;
  plugin->next = NULL;

  /* Add to plugin list */
  if (plugin_list == NULL) {
    plugin_list = plugin;
  } else {
    Plugin* curr = plugin_list;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = plugin;
  }
}

/* Invoke a plugin by name */
void InvokePlugin(const char* name, const char* message) {
  /* Search for plugin */
  Plugin* curr = plugin_list;
  while (curr != NULL) {
    if (strcmp(curr->name, name) == 0) {
      curr->func(message);
      return;
    }
    curr = curr->next;
  }

  /* Plugin not found */
  printf("Plugin not found: %s\n", name);
}

/* Example plugin function */
void ExamplePlugin(const char* message) {
  printf("Example plugin: %s\n", message);
}

int main(void) {
  /* Register example plugin */
  RegisterPlugin("example", ExamplePlugin);

  /* Invoke example plugin */
  InvokePlugin("example", "Hello, world!");

  return 0;
}