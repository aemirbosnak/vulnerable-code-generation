//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTITIES 100
#define NAME_LENGTH 50

typedef enum { FILE_TYPE, DIR_TYPE } Type;

typedef struct {
    char name[NAME_LENGTH];
    Type type;
} Entity;

typedef struct {
    char name[NAME_LENGTH];
    Entity *entities[MAX_ENTITIES];
    int entity_count;
} Directory;

Directory *root;

void init_file_system() {
    root = (Directory *)malloc(sizeof(Directory));
    strcpy(root->name, "root");
    root->entity_count = 0;
}

void create_entity(char *name, Type type) {
    if (root->entity_count >= MAX_ENTITIES) {
        printf("Cannot add more entities in the root directory.\n");
        return;
    }
    
    Entity *new_entity = (Entity *)malloc(sizeof(Entity));
    strcpy(new_entity->name, name);
    new_entity->type = type;
    
    root->entities[root->entity_count++] = new_entity;
}

void list_entities() {
    printf("Listing entities in '%s':\n", root->name);
    for (int i = 0; i < root->entity_count; i++) {
        printf("- %s [%s]\n", root->entities[i]->name, 
               root->entities[i]->type == FILE_TYPE ? "File" : "Directory");
    }
}

void delete_entity(char *name) {
    for (int i = 0; i < root->entity_count; i++) {
        if (strcmp(root->entities[i]->name, name) == 0) {
            free(root->entities[i]);
            for (int j = i; j < root->entity_count - 1; j++) {
                root->entities[j] = root->entities[j + 1];
            }
            root->entity_count--;
            printf("Deleted entity: %s\n", name);
            return;
        }
    }
    printf("Entity not found: %s\n", name);
}

void clean_up() {
    for (int i = 0; i < root->entity_count; i++) {
        free(root->entities[i]);
    }
    free(root);
}

int main() {
    init_file_system();
    
    create_entity("file1.txt", FILE_TYPE);
    create_entity("file2.txt", FILE_TYPE);
    create_entity("documents", DIR_TYPE);
    create_entity("music", DIR_TYPE);
    
    list_entities();
    
    delete_entity("file1.txt");
    list_entities();
    
    create_entity("picture.png", FILE_TYPE);
    list_entities();
    
    delete_entity("non_existing.txt");
    
    clean_up();
    return 0;
}