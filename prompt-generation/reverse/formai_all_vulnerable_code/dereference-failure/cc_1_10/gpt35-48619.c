//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define G 6.67430e-11   //Gravitational constant

typedef struct {
    double x, y, z;     //position
    double vx, vy, vz;  //velocity
    double mass;        //mass
} Body;

int main() {
    //initialize bodies
    Body sun = {0, 0, 0, 0, 0, 0, 1.9891e30};
    Body earth = {149.6e9, 0, 0, 0, 29.78e3, 0, 5.97e24};
    Body moon = {149.6e9 + 384.4e6, 0, 0, 0, 29.78e3 + 1.022e3, 0, 7.342e22};

    //time step
    double dt = 3600;

    //simulation duration
    double T = 24*3600*365;

    //number of time steps
    int N = (int) (T/dt);

    //arrays to store positions and velocities - needed for visualization
    double* xs = malloc(N*sizeof(double));
    double* ys = malloc(N*sizeof(double));
    double* zs = malloc(N*sizeof(double));
    double* vxs = malloc(N*sizeof(double));
    double* vys = malloc(N*sizeof(double));
    double* vzs = malloc(N*sizeof(double));

    //simulation loop
    for (int i = 0; i < N; i++) {
        //calculate forces
        double fx_sun = G*sun.mass*earth.mass/(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z) * earth.x/(sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z));
        double fy_sun = G*sun.mass*earth.mass/(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z) * earth.y/(sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z));
        double fz_sun = G*sun.mass*earth.mass/(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z) * earth.z/(sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z));

        double fx_earth_sun = G*sun.mass*earth.mass/(sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z)*sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z)) * -earth.x/(sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z));
        double fy_earth_sun = G*sun.mass*earth.mass/(sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z)*sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z)) * -earth.y/(sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z));
        double fz_earth_sun = G*sun.mass*earth.mass/(sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z)*sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z)) * -earth.z/(sqrt(earth.x*earth.x + earth.y*earth.y + earth.z*earth.z));

        double fx_earth_moon = G*moon.mass*earth.mass/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)*sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)) * (earth.x-moon.x)/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z));
        double fy_earth_moon = G*moon.mass*earth.mass/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)*sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)) * earth.y/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z));
        double fz_earth_moon = G*moon.mass*earth.mass/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)*sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)) * earth.z/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z));

        double fx_moon_earth = G*moon.mass*earth.mass/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)*sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)) * -(earth.x-moon.x)/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z));
        double fy_moon_earth = G*moon.mass*earth.mass/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)*sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)) * -earth.y/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z));
        double fz_moon_earth = G*moon.mass*earth.mass/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)*sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z)) * -earth.z/(sqrt((earth.x-moon.x)*(earth.x-moon.x) + earth.y*earth.y + earth.z*earth.z));

        double fx_moon = G*moon.mass*earth.mass/(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z) * moon.x/(sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z));
        double fy_moon = G*moon.mass*earth.mass/(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z) * moon.y/(sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z));
        double fz_moon = G*moon.mass*earth.mass/(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z) * moon.z/(sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z));

        double fx_moon_sun = G*sun.mass*moon.mass/(sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z)*sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z)) * -moon.x/(sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z));
        double fy_moon_sun = G*sun.mass*moon.mass/(sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z)*sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z)) * -moon.y/(sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z));
        double fz_moon_sun = G*sun.mass*moon.mass/(sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z)*sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z)) * -moon.z/(sqrt(moon.x*moon.x + moon.y*moon.y + moon.z*moon.z));


        //update velocities
        earth.vx += dt*(fx_sun + fx_earth_moon + fx_earth_sun)/earth.mass;
        earth.vy += dt*(fy_sun + fy_earth_moon + fy_earth_sun)/earth.mass;
        earth.vz += dt*(fz_sun + fz_earth_moon + fz_earth_sun)/earth.mass;

        moon.vx += dt*(fx_earth_moon + fx_moon_sun + fx_moon)/moon.mass;
        moon.vy += dt*(fy_earth_moon + fy_moon_sun + fy_moon)/moon.mass;
        moon.vz += dt*(fz_earth_moon + fz_moon_sun + fz_moon)/moon.mass;

        //update positions
        earth.x += dt*earth.vx;
        earth.y += dt*earth.vy;
        earth.z += dt*earth.vz;

        moon.x += dt*moon.vx;
        moon.y += dt*moon.vy;
        moon.z += dt*moon.vz;

        //store positions and velocities
        xs[i] = earth.x;
        ys[i] = earth.y;
        zs[i] = earth.z;
        vxs[i] = earth.vx;
        vys[i] = earth.vy;
        vzs[i] = earth.vz;
    }

    //visualization goes here

    //free memory
    free(xs);
    free(ys);
    free(zs);
    free(vxs);
    free(vys);
    free(vzs);

    return 0;
}