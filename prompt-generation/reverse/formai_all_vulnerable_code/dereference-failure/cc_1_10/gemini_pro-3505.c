//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double x, y, z;
} Vec3;

typedef struct {
    Vec3 pos, vel, acc;
    double mass;
    double (*force)(Vec3*, Vec3*);
} Particle;

double gravity(Vec3 *r1, Vec3 *r2)
{
    double r = sqrt(r1->x*r1->x + r1->y*r1->y + r1->z*r1->z);
    double f = 1.0 / (r * r);
    return f;
}

void init(Particle *p, int num)
{
    srand(time(NULL));
    for (int i = 0; i < num; i++) {
        p[i].pos.x = rand() / (double)RAND_MAX;
        p[i].pos.y = rand() / (double)RAND_MAX;
        p[i].pos.z = rand() / (double)RAND_MAX;
        p[i].vel.x = rand() / (double)RAND_MAX;
        p[i].vel.y = rand() / (double)RAND_MAX;
        p[i].vel.z = rand() / (double)RAND_MAX;
        p[i].acc.x = 0.0;
        p[i].acc.y = 0.0;
        p[i].acc.z = 0.0;
        p[i].mass = rand() / (double)RAND_MAX;
        p[i].force = gravity;
    }
}

void update(Particle *p, int num, double dt)
{
    Vec3 acc_tot;
    for (int i = 0; i < num; i++) {
        acc_tot.x = acc_tot.y = acc_tot.z = 0.0;
        for (int j = 0; j < num; j++) {
            acc_tot.x += p[j].force(&p[i].pos, &p[j].pos) * p[j].mass;
            acc_tot.y += p[j].force(&p[i].pos, &p[j].pos) * p[j].mass;
            acc_tot.z += p[j].force(&p[i].pos, &p[j].pos) * p[j].mass;
        }
        p[i].acc.x = acc_tot.x / p[i].mass;
        p[i].acc.y = acc_tot.y / p[i].mass;
        p[i].acc.z = acc_tot.z / p[i].mass;
        p[i].vel.x += p[i].acc.x * dt;
        p[i].vel.y += p[i].acc.y * dt;
        p[i].vel.z += p[i].acc.z * dt;
        p[i].pos.x += p[i].vel.x * dt;
        p[i].pos.y += p[i].vel.y * dt;
        p[i].pos.z += p[i].vel.z * dt;
    }
}

int main()
{
    int num = 1000;
    Particle *p = malloc(sizeof(Particle) * num);
    init(p, num);
    for (int i = 0; i < 1000; i++) {
        update(p, num, 0.01);
    }
    for (int i = 0; i < num; i++) {
        printf("%f %f %f\n", p[i].pos.x, p[i].pos.y, p[i].pos.z);
    }
    free(p);
    return 0;
}