//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    int value;
} ConfigItem;

typedef struct {
    ConfigItem *items;
    int count;
} Config;

void config_init(Config *config) {
    config->items = NULL;
    config->count = 0;
}

void config_add_item(Config *config, char *key, int value) {
    ConfigItem *item = malloc(sizeof(ConfigItem));
    item->key = strdup(key);
    item->value = value;
    config->items = realloc(config->items, sizeof(ConfigItem) * (config->count + 1));
    config->items[config->count++] = *item;
}

int config_get_value(Config *config, char *key) {
    for (int i = 0; i < config->count; i++) {
        if (strcmp(config->items[i].key, key) == 0) {
            return config->items[i].value;
        }
    }
    return -1;
}

void config_free(Config *config) {
    for (int i = 0; i < config->count; i++) {
        free(config->items[i].key);
    }
    free(config->items);
}

void read_config_file(Config *config, FILE *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *key = strtok(line, "=");
        char *value_str = strtok(NULL, "\n");
        int value = atoi(value_str);
        config_add_item(config, key, value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening config file: %s\n", argv[1]);
        return 1;
    }

    Config config;
    config_init(&config);
    read_config_file(&config, file);
    fclose(file);

    int value1 = config_get_value(&config, "value1");
    int value2 = config_get_value(&config, "value2");

    printf("value1=%d, value2=%d\n", value1, value2);

    config_free(&config);

    return 0;
}