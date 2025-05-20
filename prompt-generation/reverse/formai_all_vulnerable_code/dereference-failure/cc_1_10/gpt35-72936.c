//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

/* Constants for the simulation */
#define GRAVITY 6.67e-11
#define TIMESTEP 10000.0
#define SCALE 2e-11

/* Constants for the viewport */
#define WIDTH 800
#define HEIGHT 600
#define ORBIT_RADIUS 50

/* Structure to hold information about a celestial body */
typedef struct {
    char* name;
    double mass;
    double x;
    double y;
    double vx;
    double vy;
    double color_r;
    double color_g;
    double color_b;
} Body;

/* Global variables */
Body* bodies;
int num_bodies;

/* Function to read in the initial conditions from the input file */
void read_input_file(char* file_name) {
    FILE* fp;
    int i;

    /* Open the input file */
    fp = fopen(file_name, "r");

    /* Read in number of bodies */
    fscanf(fp, "%d", &num_bodies);

    /* Allocate memory for all the bodies */
    bodies = (Body*)malloc(num_bodies * sizeof(Body));

    /* Read in all the bodies */
    for (i = 0; i < num_bodies; i++) {
        /* Read in the name */
        bodies[i].name = (char*)malloc(50 * sizeof(char));
        fscanf(fp, "%s", bodies[i].name);
        
        /* Read in the mass */
        fscanf(fp, "%lf", &(bodies[i].mass));

        /* Read in the position */
        fscanf(fp, "%lf", &(bodies[i].x));
        fscanf(fp, "%lf", &(bodies[i].y));
        
        /* Read in the velocity */
        fscanf(fp, "%lf", &(bodies[i].vx));
        fscanf(fp, "%lf", &(bodies[i].vy));

        /* Read in the color */
        fscanf(fp, "%lf", &(bodies[i].color_r));
        fscanf(fp, "%lf", &(bodies[i].color_g));
        fscanf(fp, "%lf", &(bodies[i].color_b));
    }

    /* Close the input file */
    fclose(fp);
}

/* Function to calculate the force between two bodies */
void calculate_force(int i, int j, double* f_x, double* f_y) {
    double dx = bodies[j].x - bodies[i].x;
    double dy = bodies[j].y - bodies[i].y;
    double dist = sqrt(dx*dx + dy*dy);
    double force = GRAVITY * bodies[i].mass * bodies[j].mass / (dist*dist);

    *f_x = force * dx / dist;
    *f_y = force * dy / dist;
}

/* Function to update the positions and velocities of all the bodies */
void update_positions_and_velocities() {
    int i, j;
    double f_x, f_y;

    /* Calculate all the forces between all the bodies */
    for (i = 0; i < num_bodies; i++) {
        for (j = 0; j < num_bodies; j++) {
            if (i != j) {
                double f_x_ij, f_y_ij;
                calculate_force(i, j, &f_x_ij, &f_y_ij);
                f_x += f_x_ij;
                f_y += f_y_ij;
            }
        }

        /* Update the position and velocity of the body */
        bodies[i].x += bodies[i].vx * TIMESTEP + 0.5 * f_x * TIMESTEP * TIMESTEP / bodies[i].mass;
        bodies[i].y += bodies[i].vy * TIMESTEP + 0.5 * f_y * TIMESTEP * TIMESTEP / bodies[i].mass;
        bodies[i].vx += f_x * TIMESTEP / bodies[i].mass;
        bodies[i].vy += f_y * TIMESTEP / bodies[i].mass;
    }
}

/* Function to draw the celestial bodies in OpenGL */
void draw_bodies() {
    int i;
    for (i = 0; i < num_bodies; i++) {
        glColor3d(bodies[i].color_r, bodies[i].color_g, bodies[i].color_b);
        glPointSize(bodies[i].mass * SCALE);
        glBegin(GL_POINTS);
            glVertex2d(bodies[i].x / ORBIT_RADIUS, bodies[i].y / ORBIT_RADIUS);
        glEnd();
    }
}

/* Function to display the simulation */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-WIDTH/2, WIDTH/2, -HEIGHT/2, HEIGHT/2);
    draw_bodies();
    update_positions_and_velocities();
    glutSwapBuffers();
}

/* Function to set up the viewport */
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

/* Main function */
int main(int argc, char** argv) {
    /* Read in the initial conditions */
    read_input_file(argv[1]);

    /* Initialize OpenGL and GLUT */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Simulation of the Solar System");
    init();

    /* Enter the main loop */
    glutDisplayFunc(display);
    glutMainLoop();

    /* Free memory */
    int i;
    for (i = 0; i < num_bodies; i++) {
        free(bodies[i].name);
    }
    free(bodies);

    return 0;
}