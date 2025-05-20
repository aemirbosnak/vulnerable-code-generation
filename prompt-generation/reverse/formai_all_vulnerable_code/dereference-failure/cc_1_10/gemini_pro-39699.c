//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libgen.h>
#include <dlfcn.h>

#define MAX_BUFLEN 1024

static char *plugin_path = NULL;
static void *plugin_handle = NULL;
static int (*plugin_init)(void);
static int (*plugin_deinit)(void);
static int (*plugin_process)(char *buf, int len);

static int load_plugin(void)
{
    struct stat st;

    if (stat(plugin_path, &st) == -1) {
        perror("stat");
        return -1;
    }

    if (!S_ISREG(st.st_mode)) {
        fprintf(stderr, "%s is not a regular file\n", plugin_path);
        return -1;
    }

    plugin_handle = dlopen(plugin_path, RTLD_NOW | RTLD_LOCAL);
    if (plugin_handle == NULL) {
        fprintf(stderr, "dlopen: %s\n", dlerror());
        return -1;
    }

    plugin_init = dlsym(plugin_handle, "plugin_init");
    if (plugin_init == NULL) {
        fprintf(stderr, "dlsym: %s\n", dlerror());
        dlclose(plugin_handle);
        return -1;
    }

    plugin_deinit = dlsym(plugin_handle, "plugin_deinit");
    if (plugin_deinit == NULL) {
        fprintf(stderr, "dlsym: %s\n", dlerror());
        dlclose(plugin_handle);
        return -1;
    }

    plugin_process = dlsym(plugin_handle, "plugin_process");
    if (plugin_process == NULL) {
        fprintf(stderr, "dlsym: %s\n", dlerror());
        dlclose(plugin_handle);
        return -1;
    }

    if (plugin_init() == -1) {
        fprintf(stderr, "plugin_init: %s\n", dlerror());
        dlclose(plugin_handle);
        return -1;
    }

    return 0;
}

static void unload_plugin(void)
{
    if (plugin_process != NULL) {
        plugin_deinit();
    }

    if (plugin_handle != NULL) {
        dlclose(plugin_handle);
    }
}

static int process_stdin(void)
{
    char buf[MAX_BUFLEN];
    int len;

    while ((len = read(0, buf, sizeof(buf))) > 0) {
        if (plugin_process(buf, len) == -1) {
            return -1;
        }
    }

    if (len == -1) {
        perror("read");
        return -1;
    }

    return 0;
}

int main(int argc, char **argv)
{
    int ret;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <plugin path>\n", argv[0]);
        return -1;
    }

    plugin_path = argv[1];

    if (load_plugin() == -1) {
        return -1;
    }

    ret = process_stdin();

    unload_plugin();

    return ret;
}