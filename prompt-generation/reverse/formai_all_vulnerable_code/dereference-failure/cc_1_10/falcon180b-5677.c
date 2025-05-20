//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.674e-11 //Gravitational constant

//Struct for planets
typedef struct {
    double x,y,z; //Position
    double vx,vy,vz; //Velocity
    double ax,ay,az; //Acceleration
    double m; //Mass
} Planet;

//Function to calculate distance between two planets
double distance(Planet p1, Planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

//Function to calculate gravitational force between two planets
void gravity(Planet p1, Planet p2) {
    double r = distance(p1, p2);
    double F = G * p1.m * p2.m / (r*r);
    p1.ax -= F*p2.x/r;
    p1.ay -= F*p2.y/r;
    p1.az -= F*p2.z/r;
    p2.ax += F*p1.x/r;
    p2.ay += F*p1.y/r;
    p2.az += F*p1.z/r;
}

//Function to update position and velocity of planets
void update(Planet *planets, int n, double dt) {
    for(int i=0;i<n;i++) {
        planets[i].vx += planets[i].ax*dt;
        planets[i].vy += planets[i].ay*dt;
        planets[i].vz += planets[i].az*dt;
        planets[i].x += planets[i].vx*dt;
        planets[i].y += planets[i].vy*dt;
        planets[i].z += planets[i].vz*dt;
    }
}

//Main function
int main() {
    srand(time(NULL));
    int n = 10; //Number of planets
    Planet *planets = malloc(n*sizeof(Planet));
    for(int i=0;i<n;i++) {
        planets[i].x = rand()%1000;
        planets[i].y = rand()%1000;
        planets[i].z = rand()%1000;
        planets[i].vx = rand()%10 - 5;
        planets[i].vy = rand()%10 - 5;
        planets[i].vz = rand()%10 - 5;
        planets[i].m = rand()%100;
    }
    while(1) {
        update(planets, n, 0.01);
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                gravity(planets[i], planets[j]);
            }
        }
    }
    return 0;
}