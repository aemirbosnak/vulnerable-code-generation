//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_item_t {
    int type;  // 0: null, 1: boolean, 2: integer, 3: floating-point, 4: string, 5: array, 6: object
    union {
        int boolean_val;
        int int_val;
        double fp_val;
        char *string_val;
        struct json_item_t **array_val;
        struct json_item_t **object_val;
    } data;
} json_item;

json_item *parse_json(char *json) {
    // TODO: implement JSON parsing algorithm
}

void free_json(json_item *root) {
    if (!root) return;
    switch (root->type) {
        case 0: break;
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: free(root->data.string_val); break;
        case 5: {
            for (int i = 0; root->data.array_val[i]; i++) {
                free_json(root->data.array_val[i]);
            }
            free(root->data.array_val);
            break;
        }
        case 6: {
            for (int i = 0; root->data.object_val[i]; i += 2) {
                free(root->data.object_val[i]);
                free_json(root->data.object_val[i + 1]);
            }
            free(root->data.object_val);
            break;
        }
    }
    free(root);
}

int main() {
    char *json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    json_item *root = parse_json(json);
    printf("Name: %s\n", root->data.object_val[1]->data.string_val);
    printf("Age: %d\n", root->data.object_val[3]->data.int_val);
    printf("City: %s\n", root->data.object_val[5]->data.string_val);
    free_json(root);
    return 0;
}