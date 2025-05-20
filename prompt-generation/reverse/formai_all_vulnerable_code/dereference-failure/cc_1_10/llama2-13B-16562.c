//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct {
    GLfloat x, y, width, height;
} Rectangle;

typedef struct {
    GLfloat r, g, b, a;
} Color;

typedef struct {
    Rectangle bounds;
    Color fillColor, strokeColor;
} Drawing;

Drawing* createDrawing() {
    Drawing* drawing = (Drawing*) malloc(sizeof(Drawing));
    drawing->bounds.x = 0;
    drawing->bounds.y = 0;
    drawing->bounds.width = WINDOW_WIDTH;
    drawing->bounds.height = WINDOW_HEIGHT;
    drawing->fillColor.r = 1.0;
    drawing->fillColor.g = 1.0;
    drawing->fillColor.b = 1.0;
    drawing->fillColor.a = 1.0;
    drawing->strokeColor.r = 0.0;
    drawing->strokeColor.g = 0.0;
    drawing->strokeColor.b = 0.0;
    drawing->strokeColor.a = 1.0;
    return drawing;
}

void drawDrawing(Drawing* drawing) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(drawing->bounds.x, drawing->bounds.y, 0);
    glScalef(drawing->bounds.width, drawing->bounds.height, 1);
    glColor4f(drawing->fillColor.r, drawing->fillColor.g, drawing->fillColor.b, drawing->fillColor.a);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0);
    glVertex2f(drawing->bounds.width, 0);
    glVertex2f(drawing->bounds.width, drawing->bounds.height);
    glVertex2f(0, drawing->bounds.height);
    glEnd();
    glColor4f(drawing->strokeColor.r, drawing->strokeColor.g, drawing->strokeColor.b, drawing->strokeColor.a);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 0);
    glVertex2f(drawing->bounds.width, 0);
    glVertex2f(drawing->bounds.width, drawing->bounds.height);
    glVertex2f(0, drawing->bounds.height);
    glEnd();
}

int main() {
    Drawing* drawing = createDrawing();
    glutInit();
    glutCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutDisplayFunc(drawDrawing);
    glutMainLoop();
    free(drawing);
    return 0;
}