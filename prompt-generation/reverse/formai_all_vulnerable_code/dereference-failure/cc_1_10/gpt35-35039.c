//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// JSON data structure
typedef struct json_object {
    int type;
    void* data;
} json_object_t;

typedef struct json_array {
    int size;
    json_object_t** items;
} json_array_t;

typedef struct json_string {
    int size;
    char* data;
} json_string_t;

typedef struct json_number {
    double data;
} json_number_t;

typedef struct json_boolean {
    int data;
} json_boolean_t;

// JSON parser
json_object_t* json_parse(char* json_str) {
    // TODO: implement JSON parser
}

// JSON serializer
char* json_serialize(json_object_t* json_obj) {
    // TODO: implement JSON serializer
}

// Example usage
int main() {
    char* json_str = "{ \"name\": \"John\", \"age\": 30, \"isMarried\": true, \"hobbies\": [ \"reading\", \"programming\" ] }";
    json_object_t* json_obj = json_parse(json_str);

    printf("Name: %s\n", ((json_string_t*)json_obj->data)->data);
    printf("Age: %g\n", ((json_number_t*)json_obj->data)->data);
    printf("Marital status: %s\n", ((json_boolean_t*)json_obj->data)->data ? "married" : "single");
    
    json_array_t* hobbies = (json_array_t*)json_obj->data;
    printf("Hobbies: ");
    for (int i=0; i<hobbies->size; i++) {
        printf("%s", ((json_string_t*)hobbies->items[i]->data)->data);
        if (i != hobbies->size - 1) {
            printf(", ");
        }
    }
    printf("\n");

    char* json_str2 = json_serialize(json_obj);
    printf("Serialized JSON string: %s\n", json_str2);

    return 0;
}