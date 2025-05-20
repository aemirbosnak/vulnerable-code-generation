//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 64

typedef struct {
    char *name;
    char *value;
} config_t;

config_t *configs = NULL;
int config_count = 0;

void parse_config(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char *token = strtok(line, "=");
        if (token == NULL) {
            continue;
        }
        config_t *new_config = malloc(sizeof(config_t));
        new_config->name = token;
        token = strtok(NULL, " ");
        if (token == NULL) {
            new_config->value = NULL;
        } else {
            new_config->value = malloc(strlen(token) + 1);
            strcpy(new_config->value, token);
        }
        configs = realloc(configs, (config_count + 1) * sizeof(config_t));
        configs[config_count++] = *new_config;
    }
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return 1;
    }
    parse_config(argv[1]);
    for (int i = 0; i < config_count; i++) {
        printf("%s=%s\n", configs[i].name, configs[i].value);
    }
    return 0;
}