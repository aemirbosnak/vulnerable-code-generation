//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: grateful
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define G 6.673e-11      //Gravitational constant
#define dt 86400         //Time interval
#define mass_sun 1.99e30 //Mass of the sun

typedef struct 
{
    double x,y;         //x,y position of the planet
    double vx,vy;       //x,y velocity of the planet
    double ax,ay;       //x,y acceleration of the planet
    double mass;        //mass of the planet
}Planet;

void calculate_Total_Acceleration(Planet *planet, Planet *sun, double *ax_sum, double *ay_sum)
{
    double dx, dy, r; //dx,dy are distance between two planets and r is the magnitude of the distance vector
    double F;         //Gravitational force between two planets
    double fx, fy;    //Vector forces acting on the planets

    dx = (sun->x - planet->x);
    dy = (sun->y - planet->y);
    r = sqrt(dx*dx+dy*dy);

    F = G*sun->mass*planet->mass/(r*r);

    fx = F*dx/r;
    fy = F*dy/r;

    *ax_sum += fx/planet->mass;
    *ay_sum += fy/planet->mass;
}

int main()
{
    int num_planets = 8;

    Planet *planets = (Planet*)malloc(sizeof(Planet)*num_planets);

    //set initial position, velocity and mass of each planet
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].mass = 1.9e27;

    planets[1].x = 57900000;
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 47400;
    planets[1].mass = 3.3e22;

    planets[2].x = 0;
    planets[2].y = 108208930;
    planets[2].vx = 30292;
    planets[2].vy = 0;
    planets[2].mass = 4.8e24;

    planets[3].x = -778500000;
    planets[3].y = 0;
    planets[3].vx = 0;
    planets[3].vy = -13060;
    planets[3].mass = 5.7e26;

    planets[4].x = 0;
    planets[4].y = -149600000000;
    planets[4].vx = -30300;
    planets[4].vy = 0;
    planets[4].mass = 0.072e24;

    planets[5].x = 0;
    planets[5].y = 778000000000;
    planets[5].vx = -13060;
    planets[5].vy = 0;
    planets[5].mass = 8.7e25;

    planets[6].x = 0;
    planets[6].y = -2871000000;
    planets[6].vx = 47362;
    planets[6].vy = 0;
    planets[6].mass = 1.05e23;

    planets[7].x = 0;
    planets[7].y = 4503000000;
    planets[7].vx = -35000;
    planets[7].vy = 0;
    planets[7].mass = 1.48e22;

    //set up the Sun
    Planet sun;
    sun.x = 0;
    sun.y = 0;
    sun.vx = 0;
    sun.vy = 0;
    sun.mass = mass_sun;

    //simulation loop
    int steps = 365*10; //Simulation will run for 10 years (3650 days)
    double ax_sum, ay_sum; //total acceleration sums
    double x,y,vx,vy,ax,ay; //temporary variables

    int i,j,k;
    for(k=0; k<steps+1; k++)
    {
        //Update each planet
        for(i=0; i<num_planets; i++)
        {
            //Reset the acceleration values to 0
            ax_sum = 0;
            ay_sum = 0;

            //Calculate the total acceleration of the planet due to gravitational force between the Sun and other planets
            for(j=0; j<num_planets; j++)
            {
                if(i!=j)
                {
                    calculate_Total_Acceleration(&planets[i],&planets[j],&ax_sum,&ay_sum);
                }
            }
            calculate_Total_Acceleration(&planets[i],&sun,&ax_sum,&ay_sum);

            //Calculate new position, velocity and acceleration of the planet
            vx = planets[i].vx + ax_sum*dt;
            vy = planets[i].vy + ay_sum*dt;

            x = planets[i].x + vx*dt;
            y = planets[i].y + vy*dt;

            ax = ax_sum;
            ay = ay_sum;

            //Update the planet properties with new values
            planets[i].vx = vx;
            planets[i].vy = vy;
            planets[i].x = x;
            planets[i].y = y;
            planets[i].ax = ax;
            planets[i].ay = ay;
        }

        //Output the position of each planet
        for(i=0; i<num_planets; i++)
        {
            printf("Planet %d X Position: %lf Y Position: %lf\n",i+1,planets[i].x,planets[i].y);
        }
    }

    free(planets);

    return 0;
}