//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>

#define G 6.67408e-11 // Gravitational constant
#define THREAD_COUNT 10 // number of threads used
#define TIMESTEP 0.01 // simulation timestep

// Mass, position and velocity struct
typedef struct {
    double m; // mass
    double x; // position x
    double y; // position y
    double vx; // velocity x
    double vy; // velocity y
} body_t;

// Thread struct
typedef struct {
    int id; // thread id
    int start; // body array start index
    int end; // body array end index
    body_t *bodies; // body array pointer
    int n; // number of bodies in the array
} thread_t;

// Calculate force of body b2 on b1
void force(body_t *b1, body_t *b2, double *fx, double *fy) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double r = sqrt(dx*dx + dy*dy);
    double f = G * b1->m * b2->m / (r*r);
    *fx += f * dx / r;
    *fy += f * dy / r;
}

// Thread function to update body velocities and positions
void *update(void *param) {
    thread_t *thread = (thread_t*)param;
    int i, j;
    double fx, fy;
    for (i = thread->start; i < thread->end; i++) {
        fx = 0.0;
        fy = 0.0;
        for (j = 0; j < thread->n; j++) {
            if (i != j) {
                force(&thread->bodies[i], &thread->bodies[j], &fx, &fy);
            }
        }
        double ax = fx / thread->bodies[i].m;
        double ay = fy / thread->bodies[i].m;
        thread->bodies[i].vx += ax * TIMESTEP;
        thread->bodies[i].vy += ay * TIMESTEP;
        thread->bodies[i].x += thread->bodies[i].vx * TIMESTEP;
        thread->bodies[i].y += thread->bodies[i].vy * TIMESTEP;
    }
    return NULL;
}

int main() {
    int i, j;
    int n = 100; // number of bodies
    body_t *bodies = (body_t*)malloc(sizeof(body_t) * n);
    pthread_t *threads = (pthread_t*)malloc(sizeof(pthread_t) * THREAD_COUNT);
    thread_t *thread_data = (thread_t*)malloc(sizeof(thread_t) * THREAD_COUNT);

    // Initialize bodies
    for (i = 0; i < n; i++) {
        bodies[i].m = rand() / (double)RAND_MAX * 100.0 + 1.0;
        bodies[i].x = rand() / (double)RAND_MAX * 100.0 - 50.0;
        bodies[i].y = rand() / (double)RAND_MAX * 100.0 - 50.0;
        bodies[i].vx = rand() / (double)RAND_MAX * 10.0 - 5.0;
        bodies[i].vy = rand() / (double)RAND_MAX * 10.0 - 5.0;
    }

    // Create threads and divide bodies equally
    for (i = 0; i < THREAD_COUNT; i++) {
        thread_data[i].id = i;
        thread_data[i].start = i * n / THREAD_COUNT;
        thread_data[i].end = (i+1) * n / THREAD_COUNT;
        thread_data[i].bodies = bodies;
        thread_data[i].n = n;
        pthread_create(&threads[i], NULL, update, &thread_data[i]);
    }

    // Join threads and print body positions
    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    for (i = 0; i < n; i++) {
        printf("%f %f\n", bodies[i].x, bodies[i].y);
    }

    free(bodies);
    free(threads);
    free(thread_data);
    return 0;
}