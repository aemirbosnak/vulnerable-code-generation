//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining a structure for our JSON object
typedef struct JSON_Object {
    char* name;
    char* type;
    struct JSON_Object* child;
    struct JSON_Object* sibling;
} JSON_Object;

// Function to read file content
char* readFile(char* path) {
    FILE* file = fopen(path, "r");
    if(file == NULL) {
        printf("Failed to open file.");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    char* content = calloc(size + 1, sizeof(char));
    rewind(file);
    fread(content, sizeof(char), size, file);
    fclose(file);
    return content;
}

// Function to create a new JSON object
JSON_Object* createJSON(char* name, char* type) {
    JSON_Object* obj = malloc(sizeof(JSON_Object));
    obj->name = name;
    obj->type = type;
    obj->child = NULL;
    obj->sibling = NULL;
    return obj;
}

// Function to add a child object to a JSON object
void addChild(JSON_Object* parent, JSON_Object* child) {
    if(parent->child == NULL) {
        parent->child = child;
    } else {
        JSON_Object* current = parent->child;
        while(current->sibling != NULL) {
            current = current->sibling;
        }
        current->sibling = child;
    }
}

// Function to parse JSON content
JSON_Object* parseJSON(char* content) {
    JSON_Object* root = NULL;
    JSON_Object* parent = NULL;
    int i = 0, j = 0;
    int length = strlen(content);
    char* token = malloc(sizeof(char) * length);
    char* name = NULL, *type = NULL;
    while(i < length) {
        i++;
        char current = content[i];
        if(current == '{') {
            if(root == NULL) {
                root = createJSON("", "");
                parent = root;
            } else {
                JSON_Object* child = createJSON(name, type);
                addChild(parent, child);
                parent = child;
                name = NULL;
                type = NULL;
            }
        } else if(current == '}') {
            if(name != NULL && type != NULL) {
                JSON_Object* child = createJSON(name, type);
                addChild(parent, child);
                name = NULL;
                type = NULL;
            }
            if(parent != root) {
                parent = parent->sibling;
            }
        } else if(current == ':') {
            name = token;
            token = malloc(sizeof(char) * length);
            j = 0;
        } else if(current == ',' || current == '\n') {
            type = token;
            token = malloc(sizeof(char) * length);
            j = 0;
        } else if(current != '"' && current != ' ' ) {
            token[j++] = current;
        }
    }
    return root;
}

int main() {
    char* content = readFile("example.json");
    JSON_Object* obj = parseJSON(content);
    printf("Parsed JSON object:\n");
    printf("{\n\tname: %s,\n\ttype: %s,\n\tchild: {\n\t\tname: %s,\n\t\ttype: %s\n\t}\n}\n",
            obj->name, obj->type, obj->child->name, obj->child->type);
    return 0;
}