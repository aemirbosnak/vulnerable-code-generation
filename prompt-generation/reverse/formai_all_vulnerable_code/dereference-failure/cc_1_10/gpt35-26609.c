//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_STR_LEN 100

typedef enum {
    JSON_STRING_VAL,
    JSON_NUM_VAL,
    JSON_BOOL_VAL,
    JSON_ARRAY_VAL,
    JSON_OBJECT_VAL
} json_value_type;

typedef struct {
    char* key;
    json_value_type type;
    union {
        char* string_val;
        int num_val;
        int bool_val;
        struct json_value* array_val;
        struct json_object* object_val;
    } value;
} json_value;

typedef struct json_object {
    int num_of_keys;
    json_value* values;
} json_object;

json_value* parse_json_string(char* json_str);

int main() {
    char json_str[MAX_JSON_STR_LEN+1] = "{\"name\": \"Johnny Silverhand\", \"age\": 37, \"is_alive\": true, \"abilities\": [\"martial arts\", \"hacking\"], \"weapons\": {\"gun\": \"major\", \"knife\": \"legend\"}}";
    json_value* parsed_json = parse_json_string(json_str);
    if (parsed_json != NULL) {
        json_object* json_obj = parsed_json->value.object_val;

        // Accessing string value
        printf("Name: %s\n", json_obj->values[0].value.string_val);

        // Accessing number value
        printf("Age: %d\n", json_obj->values[1].value.num_val);

        // Accessing boolean value
        printf("Is alive: %s\n", json_obj->values[2].value.bool_val ? "true" : "false");

        // Accessing array
        printf("Abilities:\n");
        json_value* ability_array = json_obj->values[3].value.array_val;
        for (int i = 0; i < 2; ++i) {
            printf("\t%s\n", ability_array[i].value.string_val);
        }

        // Accessing object
        printf("Weapons:\n");
        json_object* weapon_obj = json_obj->values[4].value.object_val;
        printf("\tGun: %s\n", weapon_obj->values[0].value.string_val);
        printf("\tKnife: %s\n", weapon_obj->values[1].value.string_val);
    }

    return 0;
}

json_value* parse_json_string(char* json_str) {
    // Parsing logic here
}