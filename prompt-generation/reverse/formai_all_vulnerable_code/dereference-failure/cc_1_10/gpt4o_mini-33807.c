//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHAPES 10
#define NAME_LENGTH 20

typedef struct Shape Shape;
typedef void (*ShapeAction)(Shape*);

struct Shape {
    char name[NAME_LENGTH];
    int health;
    int attack;
    ShapeAction action;
    Shape* next_shape;
};

void attackAction(Shape* shape) {
    printf("%s attacks with %d power!\n", shape->name, shape->attack);
}

void defendAction(Shape* shape) {
    printf("%s defends, reducing incoming damage!\n", shape->name);
}

void healAction(Shape* shape) {
    printf("%s heals for 10 health points!\n", shape->name);
    shape->health += 10;
}

void printShapeInfo(const Shape* shape) {
    printf("Shape: %s\nHealth: %d\nAttack: %d\n", shape->name, shape->health, shape->attack);
}

Shape* createShape(const char* name, int health, int attack, ShapeAction action) {
    Shape* new_shape = (Shape*)malloc(sizeof(Shape));
    strncpy(new_shape->name, name, NAME_LENGTH);
    new_shape->health = health;
    new_shape->attack = attack;
    new_shape->action = action;
    new_shape->next_shape = NULL;
    return new_shape;
}

void shapeShift(Shape** current_shape, Shape* new_shape) {
    free(*current_shape);
    *current_shape = new_shape;
    printf("%s has shape-shifted!\n", new_shape->name);
}

void cleanupShapes(Shape* shape) {
    Shape* temp;
    while (shape) {
        temp = shape;
        shape = shape->next_shape;
        free(temp);
    }
}

int main() {
    Shape* current_shape = createShape("Normal", 100, 10, attackAction);
    Shape* fire_shape = createShape("Fire", 80, 20, attackAction);
    Shape* water_shape = createShape("Water", 120, 5, defendAction);
    Shape* earth_shape = createShape("Earth", 150, 15, healAction);
    
    // Chain shapes
    current_shape->next_shape = fire_shape;
    fire_shape->next_shape = water_shape;
    water_shape->next_shape = earth_shape;

    // Game loop (for demonstration)
    char choice;
    while (1) {
        printShapeInfo(current_shape);
        printf("Choose action:\n1: Attack\n2: Defend\n3: Heal\n4: Shape Shift (Next)\n5: Exit\n");
        choice = getchar();
        getchar(); // consume the newline

        switch (choice) {
            case '1':
                current_shape->action(current_shape);
                break;
            case '2':
                current_shape->action(current_shape);
                break;
            case '3':
                if (current_shape->action == healAction) {
                    current_shape->action(current_shape);
                } else {
                    printf("%s cannot heal!\n", current_shape->name);
                }
                break;
            case '4':
                if (current_shape->next_shape) {
                    shapeShift(&current_shape, current_shape->next_shape);
                } else {
                    printf("No more shapes to shift to!\n");
                }
                break;
            case '5':
                printf("Exiting game...\n");
                cleanupShapes(current_shape);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}