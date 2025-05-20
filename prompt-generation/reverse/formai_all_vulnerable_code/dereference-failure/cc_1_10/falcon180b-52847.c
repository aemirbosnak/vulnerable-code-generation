//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_KEY_LEN 32
#define MAX_VALUE_LEN 64

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} config_t;

int load_config(config_t *config, FILE *fp) {
    char line[MAX_LINE_LEN];
    char *key, *value;
    int count = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (count >= MAX_KEY_LEN) {
            printf("Error: Too many keys defined\n");
            return -1;
        }

        key = strtok(line, "=");
        if (key == NULL) {
            printf("Error: Invalid configuration line\n");
            return -1;
        }

        strcpy(config->key, key);

        value = strtok(NULL, "\n");
        if (value == NULL) {
            printf("Error: Invalid configuration line\n");
            return -1;
        }

        strcpy(config->value, value);

        count++;
        config++;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open configuration file\n");
        return -1;
    }

    config_t config[MAX_KEY_LEN];
    if (load_config(config, fp)!= 0) {
        return -1;
    }

    fclose(fp);

    printf("Configuration loaded successfully\n");

    return 0;
}