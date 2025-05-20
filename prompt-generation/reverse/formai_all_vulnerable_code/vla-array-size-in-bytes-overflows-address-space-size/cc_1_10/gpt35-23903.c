//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: high level of detail
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant

struct Planet {
    char name[20];
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double ax;
    double ay;
    double az;
    double force_x;
    double force_y;
    double force_z;
};

int main() {
    int num_planets;
    printf("Enter number of planets: ");
    scanf("%d", &num_planets);

    struct Planet planets[num_planets];
    
    for(int i=0; i<num_planets; i++) {
        printf("\nEnter the details of planet %d:\n", i+1);
        printf("Name: ");
        scanf("%s", &planets[i].name);
        printf("Mass (in kg): ");
        scanf("%lf", &planets[i].mass);
        printf("Radius (in m): ");
        scanf("%lf", &planets[i].radius);
        printf("Position (x, y, z) in m: ");
        scanf("%lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].z);
        printf("Initial velocity (vx, vy, vz) in m/s: ");
        scanf("%lf %lf %lf", &planets[i].vx, &planets[i].vy, &planets[i].vz);
    }

    double time_step = 3600; // in seconds
    double duration;
    printf("\nEnter the duration of simulation (in seconds): ");
    scanf("%lf", &duration);

    int num_steps = duration/time_step;

    for(int i=0; i<num_steps; i++) {
        // Reset forces on each planet
        for(int j=0; j<num_planets; j++) {
            planets[j].force_x = 0;
            planets[j].force_y = 0;
            planets[j].force_z = 0;
        }
        
        // Calculate forces between planets
        for(int j=0; j<num_planets; j++) {
            for(int k=j+1; k<num_planets; k++) {
                double dx = planets[k].x - planets[j].x;
                double dy = planets[k].y - planets[j].y;
                double dz = planets[k].z - planets[j].z;
                double distance = sqrt(dx*dx + dy*dy + dz*dz);
                double force = G * planets[j].mass * planets[k].mass / (distance * distance);
                double fx = force * dx / distance;
                double fy = force * dy / distance;
                double fz = force * dz / distance;
                planets[j].force_x += fx;
                planets[j].force_y += fy;
                planets[j].force_z += fz;
                planets[k].force_x -= fx;
                planets[k].force_y -= fy;
                planets[k].force_z -= fz;
            }
        }

        // Update positions and velocities of planets
        for(int j=0; j<num_planets; j++) {
            planets[j].ax = planets[j].force_x / planets[j].mass;
            planets[j].ay = planets[j].force_y / planets[j].mass;
            planets[j].az = planets[j].force_z / planets[j].mass;
            planets[j].vx += planets[j].ax * time_step;
            planets[j].vy += planets[j].ay * time_step;
            planets[j].vz += planets[j].az * time_step;
            planets[j].x += planets[j].vx * time_step;
            planets[j].y += planets[j].vy * time_step;
            planets[j].z += planets[j].vz * time_step;
        }
    }

    // Print final positions of planets
    printf("\nFinal positions of planets:\n");
    for(int i=0; i<num_planets; i++) {
        printf("%s: (%lf, %lf, %lf)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}