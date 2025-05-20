//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__)
#include <dlfcn.h>
#elif defined(__APPLE__)
#include <dlfcn.h>
#endif

typedef void (*PluginStartFunc)(void);
typedef void (*PluginStopFunc)(void);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <plugin library>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *libraryPath = argv[1];

#ifdef _WIN32
    HMODULE library = LoadLibraryA(libraryPath);
    if (library == NULL) {
        fprintf(stderr, "Could not load library: %s\n", GetLastError());
        return EXIT_FAILURE;
    }

    PluginStartFunc startFunc = (PluginStartFunc)GetProcAddress(library, "PluginStart");
    PluginStopFunc stopFunc = (PluginStopFunc)GetProcAddress(library, "PluginStop");
#elif defined(__linux__) || defined(__APPLE__)
    void *library = dlopen(libraryPath, RTLD_LAZY);
    if (library == NULL) {
        fprintf(stderr, "Could not load library: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    PluginStartFunc startFunc = (PluginStartFunc)dlsym(library, "PluginStart");
    PluginStopFunc stopFunc = (PluginStopFunc)dlsym(library, "PluginStop");
#endif

    if (startFunc == NULL || stopFunc == NULL) {
        fprintf(stderr, "Could not find PluginStart or PluginStop functions in library\n");
        return EXIT_FAILURE;
    }

    startFunc();

    // Do some stuff with the plugin...

    stopFunc();

#ifdef _WIN32
    FreeLibrary(library);
#elif defined(__linux__) || defined(__APPLE__)
    dlclose(library);
#endif

    return EXIT_SUCCESS;
}