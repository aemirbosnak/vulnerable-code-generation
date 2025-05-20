//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector3D;

typedef struct {
    Vector3D pos;
    float vel;
    float acc;
    int max_acc;
    float max_vel;
    float max_dist;
    int num_objects;
    Vector3D *objects;
    float *object_vels;
    float *object_accs;
    float *object_max_accs;
    float *object_max_vels;
    float *object_max_dists;
} Space;

void init_space(Space *s, int num_objects) {
    s->num_objects = num_objects;
    s->objects = (Vector3D*)malloc(num_objects * sizeof(Vector3D));
    s->object_vels = (float*)malloc(num_objects * sizeof(float));
    s->object_accs = (float*)malloc(num_objects * sizeof(float));
    s->object_max_accs = (float*)malloc(num_objects * sizeof(float));
    s->object_max_vels = (float*)malloc(num_objects * sizeof(float));
    s->object_max_dists = (float*)malloc(num_objects * sizeof(float));

    for (int i = 0; i < num_objects; i++) {
        s->objects[i].x = (rand() % 100) - 50;
        s->objects[i].y = (rand() % 100) - 50;
        s->objects[i].z = (rand() % 100) - 50;
        s->object_vels[i] = 0.0;
        s->object_accs[i] = 0.0;
        s->object_max_accs[i] = 0.0;
        s->object_max_vels[i] = 0.0;
        s->object_max_dists[i] = 0.0;
    }

    s->pos.x = 0;
    s->pos.y = 0;
    s->pos.z = 0;
    s->vel = 0.0;
    s->acc = 0.0;
    s->max_acc = 0.0;
    s->max_vel = 0.0;
    s->max_dist = 0.0;
}

void update_space(Space *s, float dt) {
    s->pos.x += s->vel * dt;
    s->pos.y += s->vel * dt;
    s->pos.z += s->vel * dt;

    for (int i = 0; i < s->num_objects; i++) {
        s->objects[i].x += s->object_vels[i] * dt;
        s->objects[i].y += s->object_vels[i] * dt;
        s->objects[i].z += s->object_vels[i] * dt;

        s->object_vels[i] += s->object_accs[i] * dt;

        if (s->object_vels[i] > s->object_max_vels[i])
            s->object_vels[i] = s->object_max_vels[i];

        if (s->object_vels[i] < -s->object_max_vels[i])
            s->object_vels[i] = -s->object_max_vels[i];

        if (s->object_vels[i] > s->object_max_dists[i])
            s->object_vels[i] = s->object_max_dists[i];

        s->object_accs[i] += s->max_acc;

        if (s->object_accs[i] > s->max_acc)
            s->object_accs[i] = s->max_acc;

        if (s->object_accs[i] < -s->max_acc)
            s->object_accs[i] = -s->max_acc;
    }

    s->vel += s->acc * dt;

    if (s->vel > s->max_vel)
        s->vel = s->max_vel;

    if (s->vel < -s->max_vel)
        s->vel = -s->max_vel;

    if (s->vel > s->max_dist)
        s->vel = s->max_dist;

    s->acc += s->max_acc;

    if (s->acc > s->max_acc)
        s->acc = s->max_acc;

    if (s->acc < -s->max_acc)
        s->acc = -s->max_acc;
}

void draw_space(Space *s) {
    printf("x: %d, y: %d, z: %d\n", s->pos.x, s->pos.y, s->pos.z);
    printf("vel: %f, acc: %f\n", s->vel, s->acc);

    for (int i = 0; i < s->num_objects; i++) {
        printf("Object %d\n", i);
        printf("x: %d, y: %d, z: %d\n", s->objects[i].x, s->objects[i].y, s->objects[i].z);
        printf("vel: %f, acc: %f\n", s->object_vels[i], s->object_accs[i]);
        printf("max vel: %f, max dist: %f\n", s->object_max_vels[i], s->object_max_dists[i]);
    }
}

int main() {
    Space s;
    init_space(&s, 10);

    for (int i = 0; i < 10000; i++) {
        update_space(&s, 0.01);
        draw_space(&s);
    }

    return 0;
}