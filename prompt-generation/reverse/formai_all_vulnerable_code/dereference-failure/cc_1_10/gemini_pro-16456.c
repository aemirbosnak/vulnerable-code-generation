//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef void (*BrowserPluginInitFunc)(void);
typedef void (*BrowserPluginQuitFunc)(void);
typedef char* (*BrowserPluginGetMetadataFunc)(const char* key);
typedef int (*BrowserPluginHandleEventFunc)(const char* event_name, const char* data);

static void* pluginHandle = NULL;
static BrowserPluginInitFunc BrowserPluginInit = NULL;
static BrowserPluginQuitFunc BrowserPluginQuit = NULL;
static BrowserPluginGetMetadataFunc BrowserPluginGetMetadata = NULL;
static BrowserPluginHandleEventFunc BrowserPluginHandleEvent = NULL;

int PluginInit(const char* pluginPath) {
  // Load the plugin
  pluginHandle = dlopen(pluginPath, RTLD_NOW);
  if (!pluginHandle) {
    fprintf(stderr, "Error: failed to load plugin: %s\n", dlerror());
    return -1;
  }

  // Get function pointers
  BrowserPluginInit = dlsym(pluginHandle, "BrowserPluginInit");
  BrowserPluginQuit = dlsym(pluginHandle, "BrowserPluginQuit");
  BrowserPluginGetMetadata = dlsym(pluginHandle, "BrowserPluginGetMetadata");
  BrowserPluginHandleEvent = dlsym(pluginHandle, "BrowserPluginHandleEvent");

  if (!BrowserPluginInit || !BrowserPluginQuit || !BrowserPluginGetMetadata ||
      !BrowserPluginHandleEvent) {
    fprintf(stderr, "Error: failed to get function pointers from plugin\n");
    PluginQuit();
    return -1;
  }

  // Initialize the plugin
  BrowserPluginInit();

  return 0;
}

int PluginQuit() {
  if (BrowserPluginQuit) {
    BrowserPluginQuit();
  }

  if (pluginHandle) {
    dlclose(pluginHandle);
    pluginHandle = NULL;
  }

  return 0;
}

char* PluginGetMetadata(const char* key) {
  if (BrowserPluginGetMetadata) {
    return BrowserPluginGetMetadata(key);
  }

  return NULL;
}

int PluginHandleEvent(const char* event_name, const char* data) {
  if (BrowserPluginHandleEvent) {
    return BrowserPluginHandleEvent(event_name, data);
  }

  return -1;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <plugin path>\n", argv[0]);
    return -1;
  }

  if (PluginInit(argv[1]) != 0) {
    return -1;
  }

  // Plugin is initialized and ready to use

  // Get plugin metadata
  char* metadata = PluginGetMetadata("name");
  if (metadata) {
    printf("Plugin name: %s\n", metadata);
  }

  // Handle events from the browser
  while (1) {
    // Get event data from the browser
    char* event_name = NULL;
    char* data = NULL;
    if (BrowserPluginHandleEvent(event_name, data) != 0) {
      break;
    }

    // Handle the event
    if (strcmp(event_name, "new_tab") == 0) {
      printf("Event: new tab\n");
    } else if (strcmp(event_name, "url_changed") == 0) {
      printf("Event: URL changed\n");
    } else if (strcmp(event_name, "quit") == 0) {
      printf("Event: quit\n");
      break;
    }
  }

  // Quit the plugin
  PluginQuit();

  return 0;
}