//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int (*func)(void* arg);
} Plugin;

typedef struct {
    Plugin *plugins;
    int num_plugins;
} Browser;

void browser_init(Browser *b) {
    b->num_plugins = 0;
    b->plugins = NULL;
}

void browser_add_plugin(Browser *b, Plugin p) {
    b->plugins = realloc(b->plugins, sizeof(Plugin) * ++b->num_plugins);
    b->plugins[b->num_plugins - 1] = p;
}

int browser_run_plugins(Browser *b, void *arg) {
    for (int i = 0; i < b->num_plugins; i++) {
        b->plugins[i].func(arg);
    }
    return 0;
}

int hello_world(void *arg) {
    printf("Hello, world!\n");
    return 0;
}

int main() {
    Browser b;
    browser_init(&b);

    b.plugins = malloc(sizeof(Plugin));
    b.plugins[0].name = "hello_world";
    b.plugins[0].func = hello_world;

    browser_add_plugin(&b, b.plugins[0]);

    void *arg = NULL;
    browser_run_plugins(&b, arg);

    return 0;
}