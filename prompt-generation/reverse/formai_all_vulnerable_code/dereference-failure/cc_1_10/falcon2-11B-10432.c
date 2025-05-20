//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_JSON_SIZE 1024

typedef struct {
    char* key;
    char* value;
} json_t;

typedef struct {
    char* name;
    char* value;
    char* type;
    char* timestamp;
} object_t;

typedef struct {
    char* key;
    json_t* value;
} map_t;

void parse_json(char* json_str, json_t* json) {
    json->key = strtok(json_str, ":");
    json->value = strtok(NULL, ":");
}

void print_json(json_t* json) {
    printf("%s: %s\n", json->key, json->value);
}

void parse_map(char* json_str, map_t* map) {
    char* token = strtok(json_str, ":");
    char* value = strtok(NULL, ":");

    map->key = token;
    map->value = (json_t*)malloc(sizeof(json_t));
    parse_json(value, map->value);
}

void print_map(map_t* map) {
    printf("%s: ", map->key);
    print_json(map->value);
}

int main() {
    char json_str[MAX_JSON_SIZE];
    clock_t start, end;

    srand(time(NULL));

    printf("Enter JSON string:\n");
    fgets(json_str, MAX_JSON_SIZE, stdin);

    json_t json;
    parse_json(json_str, &json);
    print_json(&json);

    map_t map;
    parse_map(json_str, &map);
    print_map(&map);

    return 0;
}