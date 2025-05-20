//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>

#define MAX_RSSI -100

typedef struct {
  char *name;
  void *handle;
  int (*init)(void);
  int (*deinit)(void);
  int (*get_rssi)(void);
} wifi_module;

wifi_module modules[] = {
  {"iw", NULL, NULL, NULL, NULL},
  {"nmcli", NULL, NULL, NULL, NULL},
  {"wpa_cli", NULL, NULL, NULL, NULL},
};

int init_modules() {
  for (int i = 0; i < sizeof(modules) / sizeof(wifi_module); i++) {
    wifi_module *module = &modules[i];
    module->handle = dlopen(module->name, RTLD_LAZY);
    if (!module->handle) {
      perror("dlopen");
      return -1;
    }
    module->init = dlsym(module->handle, "init");
    if (!module->init) {
      perror("dlsym init");
      return -1;
    }
    module->deinit = dlsym(module->handle, "deinit");
    if (!module->deinit) {
      perror("dlsym deinit");
      return -1;
    }
    module->get_rssi = dlsym(module->handle, "get_rssi");
    if (!module->get_rssi) {
      perror("dlsym get_rssi");
      return -1;
    }
    if (module->init()) {
      perror("module init");
      return -1;
    }
  }
  return 0;
}

int deinit_modules() {
  for (int i = 0; i < sizeof(modules) / sizeof(wifi_module); i++) {
    wifi_module *module = &modules[i];
    if (module->deinit()) {
      perror("module deinit");
      return -1;
    }
    if (module->handle) {
      dlclose(module->handle);
    }
  }
  return 0;
}

int get_rssi() {
  int rssi = MAX_RSSI;
  for (int i = 0; i < sizeof(modules) / sizeof(wifi_module); i++) {
    wifi_module *module = &modules[i];
    int tmp = module->get_rssi();
    if (tmp > rssi) {
      rssi = tmp;
    }
  }
  return rssi;
}

int main() {
  if (init_modules()) {
    perror("init modules");
    return EXIT_FAILURE;
  }
  int rssi = get_rssi();
  printf("RSSI: %d dBm\n", rssi);
  if (deinit_modules()) {
    perror("deinit modules");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}