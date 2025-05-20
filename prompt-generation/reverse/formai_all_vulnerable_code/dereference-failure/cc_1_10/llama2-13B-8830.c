//LLAMA2-13B DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define NUM_VARIABLES 5
#define NUM_EQNS 4

typedef struct {
    double x[NUM_VARIABLES];
    double b[NUM_EQNS];
} system_t;

system_t* create_system(void);
void solve_system(system_t* sys);
void print_solution(system_t* sys);

int main(void) {
    system_t* sys = create_system();
    solve_system(sys);
    print_solution(sys);
    return 0;
}

system_t* create_system(void) {
    system_t* sys = (system_t*) malloc(sizeof(system_t));
    for (int i = 0; i < NUM_VARIABLES; i++) {
        sys->x[i] = (double) rand() / RAND_MAX;
    }
    for (int i = 0; i < NUM_EQNS; i++) {
        sys->b[i] = (double) rand() / RAND_MAX;
    }
    return sys;
}

void solve_system(system_t* sys) {
    for (int i = 0; i < NUM_VARIABLES; i++) {
        for (int j = 0; j < NUM_EQNS; j++) {
            sys->x[i] = sys->x[i] - sys->b[j] * sys->x[j];
        }
    }
}

void print_solution(system_t* sys) {
    for (int i = 0; i < NUM_VARIABLES; i++) {
        printf("%.2f", sys->x[i]);
    }
    printf("\n");
}