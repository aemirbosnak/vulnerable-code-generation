//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: cheerful
#include<stdio.h>
#include<math.h>

//function to calculate gravitational force
double gravitational_force(double m1, double m2, double r) {
    double G = 6.67E-11; //gravitational constant
    return G*m1*m2/(r*r); //return force value
}

int main() {
    printf("\n----Welcome to Super Fun Gravity Simulator!----\n\n");
    printf("Enter the number of planets you want to simulate: ");
    int count;
    scanf("%d", &count);

    //initialize arrays for planet data
    double mass[count];
    double position[count][3];
    double velocity[count][3];

    //take input for planet data
    for(int i=0; i<count; i++) {
        printf("\nEnter data for Planet %d:\n", i+1);
        printf("Mass (in kg): ");
        scanf("%lf", &mass[i]);
        printf("Position (x,y,z) (in m): ");
        scanf("%lf %lf %lf", &position[i][0], &position[i][1], &position[i][2]);
        printf("Velocity (x,y,z) (in m/s): ");
        scanf("%lf %lf %lf", &velocity[i][0], &velocity[i][1], &velocity[i][2]);
    }

    //set simulation parameters
    double time_interval = 10; //in seconds
    double max_time = 100; //in seconds
    int steps = max_time/time_interval;

    //simulate planetary motion
    for(int i=0; i<steps; i++) {
        printf("\n----Time Step %d----\n", i+1);
        //calculate gravitational force and update velocities
        for(int j=0; j<count; j++) {
            double net_force[3] = {0, 0, 0};
            for(int k=0; k<count; k++) {
                if(j==k) continue;
                double dist = sqrt(pow(position[j][0]-position[k][0], 2) + pow(position[j][1]-position[k][1], 2) + pow(position[j][2]-position[k][2], 2));
                double force = gravitational_force(mass[j], mass[k], dist);
                for(int l=0; l<3; l++) {
                    net_force[l] += force*(position[k][l]-position[j][l])/dist;
                }
            }
            for(int l=0; l<3; l++) {
                velocity[j][l] += net_force[l]*time_interval/mass[j];
            }
        }
        //update positions
        for(int j=0; j<count; j++) {
            for(int l=0; l<3; l++) {
                position[j][l] += velocity[j][l]*time_interval;
            }
            printf("Planet %d: Position: (%.2lf, %.2lf, %.2lf) Velocity: (%.2lf, %.2lf, %.2lf)\n", j+1, position[j][0], position[j][1], position[j][2], velocity[j][0], velocity[j][1], velocity[j][2]);
        }
    }

    return 0;
}