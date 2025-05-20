//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} ConfigItem;

typedef struct {
    ConfigItem *items;
    int count;
} Config;

Config *config_create() {
    Config *config = malloc(sizeof(Config));
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

void config_add_item(Config *config, char *key, char *value) {
    ConfigItem *item = malloc(sizeof(ConfigItem));
    item->key = strdup(key);
    item->value = strdup(value);
    config->items = realloc(config->items, sizeof(ConfigItem) * (config->count + 1));
    config->items[config->count] = *item;
    config->count++;
}

char *config_get_value(Config *config, char *key) {
    int i;
    for (i = 0; i < config->count; i++) {
        if (strcmp(config->items[i].key, key) == 0) {
            return config->items[i].value;
        }
    }
    return NULL;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    Config *config = config_create();

    fp = fopen("example.cfg", "r");
    if (fp == NULL) {
        printf("Error: could not open configuration file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *key, *value;
        if ((key = strtok(line, "=")) == NULL || (value = strtok(NULL, "\n")) == NULL) {
            continue;
        }
        config_add_item(config, key, value);
    }

    fclose(fp);

    printf("Configuration:\n");
    int i;
    for (i = 0; i < config->count; i++) {
        printf("%s=%s\n", config->items[i].key, config->items[i].value);
    }

    config_destroy(config);
    return 0;
}