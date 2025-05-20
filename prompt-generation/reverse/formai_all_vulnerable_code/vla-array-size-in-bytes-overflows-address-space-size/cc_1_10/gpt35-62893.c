//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: interoperable
#include <stdio.h>
#include <math.h>
#define G 6.67408e-11 // Gravitational constant

struct vector{
    double x;
    double y;
};

struct body{
    char name[20];
    double mass;
    struct vector position;
    struct vector velocity;
    struct vector acceleration;
};

int main(){
    int num_bodies;
    printf("Enter the number of bodies in the solar system: ");
    scanf("%d", &num_bodies);

    struct body bodies[num_bodies];
    for(int i=0; i<num_bodies; i++){
        printf("Enter the name of body %d: ", i+1);
        scanf("%s", bodies[i].name);
        printf("Enter the mass of body %d in kg: ", i+1);
        scanf("%lf", &bodies[i].mass);
        printf("Enter the x coordinate of body %d's position in m: ", i+1);
        scanf("%lf", &bodies[i].position.x);
        printf("Enter the y coordinate of body %d's position in m: ", i+1);
        scanf("%lf", &bodies[i].position.y);
        printf("Enter the x component of body %d's velocity in m/s: ", i+1);
        scanf("%lf", &bodies[i].velocity.x);
        printf("Enter the y component of body %d's velocity in m/s: ", i+1);
        scanf("%lf", &bodies[i].velocity.y);
    }

    double time_step = 0.001; // Time step of 1 ms
    double total_time = 10; // Total simulation time of 10 seconds
    int num_steps = round(total_time / time_step); // Number of time steps
    for(int i=0; i<num_steps; i++){
        // Calculate acceleration of each body
        for(int j=0; j<num_bodies; j++){
            double net_force_x = 0;
            double net_force_y = 0;
            for(int k=0; k<num_bodies; k++){
                if(j == k){
                    continue; // Skip self
                }
                double distance_x = bodies[k].position.x - bodies[j].position.x;
                double distance_y = bodies[k].position.y - bodies[j].position.y;
                double distance = sqrt(distance_x*distance_x + distance_y*distance_y);
                double force = G * bodies[k].mass * bodies[j].mass / (distance*distance);
                double force_x = force * distance_x / distance;
                double force_y = force * distance_y / distance;
                net_force_x += force_x;
                net_force_y += force_y;
            }
            bodies[j].acceleration.x = net_force_x / bodies[j].mass;
            bodies[j].acceleration.y = net_force_y / bodies[j].mass;
        }

        // Update velocities and positions of each body
        for(int j=0; j<num_bodies; j++){
            bodies[j].velocity.x += bodies[j].acceleration.x * time_step;
            bodies[j].velocity.y += bodies[j].acceleration.y * time_step;
            bodies[j].position.x += bodies[j].velocity.x * time_step;
            bodies[j].position.y += bodies[j].velocity.y * time_step;

            printf("%s position: (%f, %f)\n", bodies[j].name, bodies[j].position.x, bodies[j].position.y);
        }

        // Add extra newline for separation between time steps
        printf("\n");
    }

    return 0;
}