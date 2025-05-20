//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SHAPES 100
#define GRID_SIZE 20

typedef enum {
    POINT,
    SQUARE,
    CIRCLE
} ShapeType;

typedef struct {
    ShapeType type;
    int x;
    int y;
    int size;  // Used for square and radius for circle
} Shape;

typedef struct {
    Shape* shapes[MAX_SHAPES];
    int count;
} ShapeCollection;

void initShapeCollection(ShapeCollection* collection) {
    collection->count = 0;
}

void addShape(ShapeCollection* collection, ShapeType type, int x, int y, int size) {
    if (collection->count < MAX_SHAPES) {
        Shape* newShape = malloc(sizeof(Shape));
        newShape->type = type;
        newShape->x = x;
        newShape->y = y;
        newShape->size = size;
        collection->shapes[collection->count++] = newShape;
    } else {
        printf("Shape collection full!\n");
    }
}

void freeShapeCollection(ShapeCollection* collection) {
    for (int i = 0; i < collection->count; i++) {
        free(collection->shapes[i]);
    }
}

void drawGrid(ShapeCollection* collection) {
    char grid[GRID_SIZE][GRID_SIZE];
    
    // Initialize grid with blank spaces
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // Place shapes in grid
    for (int i = 0; i < collection->count; i++) {
        Shape* shape = collection->shapes[i];
        switch (shape->type) {
            case POINT:
                if (shape->x < GRID_SIZE && shape->y < GRID_SIZE) {
                    grid[shape->y][shape->x] = '*';
                }
                break;
            case SQUARE:
                for (int dy = -shape->size; dy <= shape->size; dy++) {
                    for (int dx = -shape->size; dx <= shape->size; dx++) {
                        int x = shape->x + dx;
                        int y = shape->y + dy;
                        if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
                            grid[y][x] = '#';
                        }
                    }
                }
                break;
            case CIRCLE:
                for (int dy = -shape->size; dy <= shape->size; dy++) {
                    for (int dx = -shape->size; dx <= shape->size; dx++) {
                        if (dx * dx + dy * dy <= shape->size * shape->size) { // Circle equation
                            int x = shape->x + dx;
                            int y = shape->y + dy;
                            if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
                                grid[y][x] = 'O';
                            }
                        }
                    }
                }
                break;
        }
    }

    // Print out grid
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            printf("%c ", grid[y][x]);
        }
        printf("\n");
    }
}

int main() {
    ShapeCollection collection;
    initShapeCollection(&collection);
    
    addShape(&collection, POINT, 5, 5, 0);
    addShape(&collection, SQUARE, 10, 10, 2);
    addShape(&collection, CIRCLE, 15, 3, 3);
    
    printf("Shape Grid Visualization:\n");
    drawGrid(&collection);
    
    freeShapeCollection(&collection);
    return 0;
}