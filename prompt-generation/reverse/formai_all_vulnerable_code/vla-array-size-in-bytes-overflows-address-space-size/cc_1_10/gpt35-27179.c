//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: careful
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 //Gravitational constant
#define INTERVAL 100 //Number of time intervals
#define TIMESTEP 3600 //Time in seconds

typedef struct {
    double x_pos;
    double y_pos;
    double mass;
    double x_vel;
    double y_vel;
} planet;

double distance(planet p1, planet p2) {
    return sqrt(pow(p2.x_pos-p1.x_pos, 2) + pow(p2.y_pos-p1.y_pos, 2));
}

void acceleration(planet *p1, planet *p2) {
    double force = (G*p1->mass*p2->mass)/pow(distance(*p1,*p2),2);
    double angle = atan2((p2->y_pos-p1->y_pos),(p2->x_pos-p1->x_pos));
    double accel = force/p1->mass;
    p1->x_vel += accel*cos(angle)*TIMESTEP; //Updating x velocity
    p1->y_vel += accel*sin(angle)*TIMESTEP; //Updating y velocity
}

void update_position(planet *p) {
    p->x_pos += p->x_vel*TIMESTEP; //Updating x position
    p->y_pos += p->y_vel*TIMESTEP; //Updating y position
}

void simulate(planet *p, int n) {
    int i,j,t;
    for(t=0; t<INTERVAL; t++) {
        printf("==========\nTIME INTERVAL %d\n==========\n", t+1);
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                if(i != j) {
                    printf("Planet %d and Planet %d\n", i+1, j+1);
                    acceleration(&p[i],&p[j]); //Updating acceleration for ith planet
                    printf("Acceleration x: %e m/s^2, Acceleration y: %e m/s^2\n", p[i].x_vel, p[i].y_vel);
                }
            }
        }
        for(i=0; i<n; i++) {
            update_position(&p[i]); //Updating position for ith planet
            printf("Planet %d - New Position - x: %e m, y: %e m\n", i+1, p[i].x_pos, p[i].y_pos);
        }
    }
}

int main() {
    int n;
    printf("Enter number of planets: ");
    scanf("%d",&n);
    planet p[n];
    int i;
    for(i=0; i<n; i++) {
        printf("Enter details of planet %d:\n",i+1);
        printf("Mass (kg): ");
        scanf("%lf",&p[i].mass);
        printf("X Position (m): ");
        scanf("%lf",&p[i].x_pos);
        printf("Y Position (m): ");
        scanf("%lf",&p[i].y_pos);
        printf("X Velocity (m/s): ");
        scanf("%lf",&p[i].x_vel);
        printf("Y Velocity (m/s): ");
        scanf("%lf",&p[i].y_vel);
        printf("\n");
    }
    simulate(p,n);
    return 0;
}