//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

typedef struct {
    double x, y, z;
} vec3;

vec3 add(vec3 a, vec3 b) {
    vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

vec3 sub(vec3 a, vec3 b) {
    vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

vec3 mul(vec3 a, double b) {
    vec3 r;
    r.x = a.x * b;
    r.y = a.y * b;
    r.z = a.z * b;
    return r;
}

double dot(vec3 a, vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 cross(vec3 a, vec3 b) {
    vec3 r;
    r.x = a.y * b.z - a.z * b.y;
    r.y = a.z * b.x - a.x * b.z;
    r.z = a.x * b.y - a.y * b.x;
    return r;
}

double mag(vec3 a) {
    return sqrt(dot(a, a));
}

vec3 norm(vec3 a) {
    double m = mag(a);
    if (m == 0) {
        return a;
    }
    return mul(a, 1 / m);
}

typedef struct {
    double m;
    vec3 r;
    vec3 v;
    vec3 a;
} body;

body *bodies;
int nbodies;

void addBody(double m, vec3 r, vec3 v) {
    bodies = realloc(bodies, (nbodies + 1) * sizeof(body));
    bodies[nbodies].m = m;
    bodies[nbodies].r = r;
    bodies[nbodies].v = v;
    bodies[nbodies].a = (vec3){0, 0, 0};
    nbodies++;
}

void update(double dt) {
    for (int i = 0; i < nbodies; i++) {
        for (int j = i + 1; j < nbodies; j++) {
            vec3 r = sub(bodies[j].r, bodies[i].r);
            double d = mag(r);
            if (d < 0.01) {
                d = 0.01;
            }
            vec3 a = mul(norm(r), bodies[j].m * bodies[i].m / (d * d));
            bodies[i].a = add(bodies[i].a, a);
            bodies[j].a = sub(bodies[j].a, a);
        }
    }

    for (int i = 0; i < nbodies; i++) {
        bodies[i].v = add(bodies[i].v, mul(bodies[i].a, dt));
        bodies[i].r = add(bodies[i].r, mul(bodies[i].v, dt));
    }
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int i = 0; i < nbodies; i++) {
        glPushMatrix();
        glTranslatef(bodies[i].r.x, bodies[i].r.y, bodies[i].r.z);
        glutSolidSphere(bodies[i].m, 10, 10);
        glPopMatrix();
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (double)w / h, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

void timer(int v) {
    update(0.01);
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Physics Simulation");

    glEnable(GL_DEPTH_TEST);

    addBody(1, (vec3){0, 0, 0}, (vec3){0, 0, 0});
    addBody(1, (vec3){1, 0, 0}, (vec3){0, 1, 0});
    addBody(1, (vec3){0, 1, 0}, (vec3){0, 0, 1});

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutTimerFunc(10, timer, 0);

    glutMainLoop();

    return 0;
}