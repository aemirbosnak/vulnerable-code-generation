//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *type;
    char *name;
} Variable;

typedef struct Node {
    struct Node *next;
    char *line;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Scene;

Scene* createScene() {
    Scene *scene = (Scene *)malloc(sizeof(Scene));
    scene->head = NULL;
    scene->tail = NULL;
    return scene;
}

void addLine(Scene *scene, const char *line) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->line = strdup(line);
    newNode->next = NULL;
    if (scene->tail) {
        scene->tail->next = newNode;
    }
    scene->tail = newNode;
    if (!scene->head) {
        scene->head = newNode;
    }
}

void printScene(Scene *scene) {
    Node *current = scene->head;
    while (current) {
        printf("%s\n", current->line);
        current = current->next;
    }
}

void freeScene(Scene *scene) {
    Node *current = scene->head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp->line);
        free(temp);
    }
    free(scene);
}

Variable* createVariable(const char *type, const char *name) {
    Variable *var = (Variable *)malloc(sizeof(Variable));
    var->type = strdup(type);
    var->name = strdup(name);
    return var;
}

void destroyVariable(Variable *var) {
    free(var->type);
    free(var->name);
    free(var);
}

int main() {
    printf("Enter the stage of love's cruel fate!\n\n");
    
    Scene *scene1 = createScene();
    addLine(scene1, "Romeo: But, soft! What light through yonder window breaks?");
    addLine(scene1, "Juliet: O Romeo, Romeo! wherefore art thou Romeo?");
    addLine(scene1, "Romeo: Call me but love, and I'll be new baptized;");
    addLine(scene1, "Juliet: My bounty is as boundless as the sea,");
    addLine(scene1, "Romeo: I take thee at thy word:");
    
    printf("Act I, Scene I:\n");
    printScene(scene1);
    printf("\n");

    Variable *r_name = createVariable("char*", "Romeo");
    Variable *j_name = createVariable("char*", "Juliet");
    
    printf("Variables created:\n");
    printf("Variable 1: Type: %s, Name: %s\n", r_name->type, r_name->name);
    printf("Variable 2: Type: %s, Name: %s\n", j_name->type, j_name->name);
    
    // Engaging in love's declaration:
    addLine(scene1, "Juliet: Thou art as glorious as the celestial stars,");
    addLine(scene1, "Romeo: And thou, my heart's desire, art my world.");
    
    printf("Act I, Scene II:\n");
    printScene(scene1);
    printf("\n");

    freeScene(scene1);
    destroyVariable(r_name);
    destroyVariable(j_name);
    
    printf("Exit the stage, love's tragedy unfolds...\n");
    return 0;
}