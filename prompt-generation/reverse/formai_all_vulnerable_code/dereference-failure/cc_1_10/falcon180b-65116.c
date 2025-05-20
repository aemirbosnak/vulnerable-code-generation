//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

typedef struct {
    char *key;
    char *value;
} ConfigItem;

typedef struct {
    ConfigItem *items;
    int count;
} Config;

Config *config_create(void) {
    Config *config = (Config *) malloc(sizeof(Config));
    config->items = NULL;
    config->count = 0;
    return config;
}

void config_destroy(Config *config) {
    int i;
    for (i = 0; i < config->count; i++) {
        free(config->items[i].key);
        free(config->items[i].value);
    }
    free(config->items);
    free(config);
}

int config_add(Config *config, const char *key, const char *value) {
    ConfigItem *item = (ConfigItem *) malloc(sizeof(ConfigItem));
    if (item == NULL) {
        return -1;
    }
    item->key = strdup(key);
    item->value = strdup(value);
    config->items = (ConfigItem *) realloc(config->items, sizeof(ConfigItem) * (config->count + 1));
    if (config->items == NULL) {
        free(item->key);
        free(item->value);
        free(item);
        return -1;
    }
    config->items[config->count++] = *item;
    return 0;
}

int config_get(Config *config, const char *key, char *value, int value_len) {
    int i;
    for (i = 0; i < config->count; i++) {
        if (strcmp(config->items[i].key, key) == 0) {
            if (strlen(config->items[i].value) > value_len - 1) {
                return -1;
            }
            strcpy(value, config->items[i].value);
            return 0;
        }
    }
    return -1;
}

int main() {
    Config *config = config_create();
    config_add(config, "name", "John Doe");
    config_add(config, "age", "30");
    char name[MAX_LEN];
    config_get(config, "name", name, sizeof(name));
    printf("Name: %s\n", name);
    config_destroy(config);
    return 0;
}