//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *key;
    char *value;
} ConfigPair;

typedef struct {
    ConfigPair *pairs;
    int num_pairs;
} Config;

Config *read_config(FILE *fp) {
    Config *config = malloc(sizeof(Config));
    config->pairs = NULL;
    config->num_pairs = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "\n");

        ConfigPair *pair = malloc(sizeof(ConfigPair));
        pair->key = strdup(key);
        pair->value = strdup(value);

        config->pairs = realloc(config->pairs, sizeof(ConfigPair) * (config->num_pairs + 1));
        config->pairs[config->num_pairs++] = *pair;
    }

    return config;
}

void write_config(FILE *fp, Config *config) {
    for (int i = 0; i < config->num_pairs; i++) {
        fprintf(fp, "%s=%s\n", config->pairs[i].key, config->pairs[i].value);
    }
}

void free_config(Config *config) {
    for (int i = 0; i < config->num_pairs; i++) {
        free(config->pairs[i].key);
        free(config->pairs[i].value);
    }
    free(config->pairs);
    free(config);
}

int main() {
    FILE *fp = fopen("config.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open config file.\n");
        return 1;
    }

    Config *config = read_config(fp);
    fclose(fp);

    // Modify config as needed...

    fp = fopen("config.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open config file for writing.\n");
        free_config(config);
        return 1;
    }

    write_config(fp, config);
    fclose(fp);

    free_config(config);
    return 0;
}