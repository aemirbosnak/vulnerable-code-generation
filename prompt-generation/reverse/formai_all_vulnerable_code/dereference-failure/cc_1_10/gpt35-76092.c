//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multiplayer
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

#define G 6.673e-11
#define TIME_STEP 1000
#define INIT_SPEED 1000
#define INIT_POS 500

// Structure to hold planet data
typedef struct planet {
    double mass;  // Mass of Planet
    double x;  // X-coordinate of Planet
    double y;  // Y-coordinate of Planet
    double vx; // X-velocity of Planet
    double vy; // Y-velocity of Planet
} planet_t;

// Function to fetch random double within specified range
double frand(double min, double max){
    return min + (((double) rand()) / RAND_MAX) * (max - min);
}

// Function to calculate gravitational force between two planets
void calc_gravity_force(double m1, double m2, double x1, double y1, double x2, double y2, double *fx, double *fy) {
    double dx = x2 - x1;
    double dy = y2 - y1;    
    double r = sqrt(dx*dx + dy*dy + 0.1);
    double f = G * (m1 * m2) / (r*r);
    *fx = f * dx / r;
    *fy = f * dy / r;
}

// Function to update planet's position and velocity based on net force acting on it
void update_planet(planet_t *p, double fx, double fy) {
    double ax = fx / p->mass;
    double ay = fy / p->mass;
    p->vx += ax * TIME_STEP;
    p->vy += ay * TIME_STEP;
    p->x += p->vx * TIME_STEP;
    p->y += p->vy * TIME_STEP;
}

int main(void){
    srand(time(NULL)); // Initialize random number generator
    int num_planets;  
    printf("Enter number of planets to simulate: ");
    scanf("%d",&num_planets);
    planet_t *planets = calloc(num_planets, sizeof(planet_t)); // Allocate memory for planets
    
    // Initialize planets
    for(int i = 0; i < num_planets; i++){
        planet_t *p = &planets[i];
        p->mass = frand(1e5, 1e10);
        p->x = frand(0, INIT_POS);
        p->y = frand(0, INIT_POS);
        p->vx = frand(-INIT_SPEED, INIT_SPEED);
        p->vy = frand(-INIT_SPEED, INIT_SPEED);
    }

    // Start Simulation
    while(1){
        // Calculate Gravitational Forces between planets
        for(int i = 0; i < num_planets; i++){
            planet_t *p1 = &planets[i];
            double fx_sum = 0;
            double fy_sum = 0;
            for(int j = 0; j < num_planets; j++){
                if(i == j) continue;
                planet_t *p2 = &planets[j];
                double fx, fy;
                calc_gravity_force(p1->mass, p2->mass, p1->x, p1->y, p2->x, p2->y, &fx, &fy);
                fx_sum += fx;
                fy_sum += fy;
            }
            update_planet(p1, fx_sum, fy_sum);
        }

        // Print Planet Positions
        printf("Planet Positions:\n");
        for(int i = 0; i < num_planets; i++){
            planet_t *p = &planets[i];
            printf("Planet %d: (%.2lf, %.2lf)\n", i+1, p->x, p->y);
        }

        // Sleep for 1 second before next simulation step
        sleep(1);
    }
    return 0;
}