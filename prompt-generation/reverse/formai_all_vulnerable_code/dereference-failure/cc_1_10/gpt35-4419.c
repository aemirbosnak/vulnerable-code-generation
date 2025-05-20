//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct json_entry {
    char* key;
    char* value;
};

struct json_object {
    struct json_entry* entries;
    int num_entries;
};

struct json_object* parse_json(char* json_str) {
    struct json_object* obj = malloc(sizeof(struct json_object));
    obj->num_entries = 0;
    
    // Parse the string and build the object
    char* token = strtok(json_str, "{}\":, ");
    while (token != NULL) {
        if (strcmp(token, "}") == 0) {
            // End of object, break out of loop
            break;
        }
        if (strcmp(token, "\"") == 0) {
            // Key value pair, parse key
            char* key = strtok(NULL, "\"");
            struct json_entry* entry = malloc(sizeof(struct json_entry));
            entry->key = strdup(key);
            
            // Parse value
            token = strtok(NULL, "{}\":, ");
            char* value = strdup(token);
            entry->value = value;
            
            // Add entry to object
            obj->entries = realloc(obj->entries, (obj->num_entries + 1) * sizeof(struct json_entry));
            obj->entries[obj->num_entries] = *entry;
            obj->num_entries++;
        }
        
        // Get next token
        token = strtok(NULL, "{}\":, ");
    }
    
    return obj;
}

int main() {
    char* json_str = "{ \"name\": \"John Smith\", \"age\": 30, \"city\": \"New York\" }";
    struct json_object* obj = parse_json(json_str);

    printf("Object contains %d entries\n", obj->num_entries);
    for (int i = 0; i < obj->num_entries; i++) {
        printf("Key: %s, Value: %s\n", obj->entries[i].key, obj->entries[i].value);
    }
    
    return 0;
}