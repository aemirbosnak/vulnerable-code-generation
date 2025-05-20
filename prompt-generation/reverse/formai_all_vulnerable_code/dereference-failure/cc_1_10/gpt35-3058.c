//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.67430e-11

typedef struct {
    double x, y, z;
} vector_t;

typedef struct {
    double mass;
    vector_t position;
    vector_t velocity;
} body_t;

typedef struct octree {
    body_t *body;
    vector_t position;
    vector_t size;
    struct octree *children[8];
} octree_t;

// function to calculate the distance between two vectors
double distance(vector_t a, vector_t b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

// function to calculate the force exerted on a body by an external force
vector_t calculate_force(body_t *a, body_t *b) {
    double dist = distance(a->position, b->position);
    double magnitude = (GRAVITATIONAL_CONSTANT * a->mass * b->mass) / pow(dist, 2);
    vector_t force = {
        .x = magnitude * (b->position.x - a->position.x) / dist,
        .y = magnitude * (b->position.y - a->position.y) / dist,
        .z = magnitude * (b->position.z - a->position.z) / dist
    };
    return force;
}

// function to update the velocity and position of a body based on the force exerted on it
void update_state(body_t *body, vector_t force, double time_step) {
    vector_t acceleration = {
        .x = force.x / body->mass,
        .y = force.y / body->mass,
        .z = force.z / body->mass
    };
    body->velocity.x += acceleration.x * time_step;
    body->velocity.y += acceleration.y * time_step;
    body->velocity.z += acceleration.z * time_step;
    body->position.x += body->velocity.x * time_step;
    body->position.y += body->velocity.y * time_step;
    body->position.z += body->velocity.z * time_step;
}

// function to create a new octree node
octree_t *create_node(vector_t position, vector_t size) {
    octree_t *node = malloc(sizeof(octree_t));
    node->body = NULL;
    node->position = position;
    node->size = size;
    for (int i = 0; i < 8; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// helper function to determine which octant a body belongs to
int get_octant(body_t *body, vector_t position) {
    int octant = 0;
    if (body->position.x > position.x) octant |= 4;
    if (body->position.y > position.y) octant |= 2;
    if (body->position.z > position.z) octant |= 1;
    return octant;
}

// function to insert a body into an octree
void insert_body(octree_t *node, body_t *body) {
    if (node->body == NULL) {
        node->body = body;
    } else {
        int octant = get_octant(node->body, node->position);
        if (node->children[octant] == NULL) {
            vector_t child_size = {
                .x = node->size.x / 2,
                .y = node->size.y / 2,
                .z = node->size.z / 2
            };
            vector_t child_position = node->position;
            child_position.x += (octant & 4) ? child_size.x : 0;
            child_position.y += (octant & 2) ? child_size.y : 0;
            child_position.z += (octant & 1) ? child_size.z : 0;
            node->children[octant] = create_node(child_position, child_size);
        }
        insert_body(node->children[octant], body);
    }
}

// function to traverse an octree and calculate the force exerted on a body by other bodies in the tree
vector_t calculate_total_force(octree_t *node, body_t *body, double theta) {
    if (node->body == NULL || node->body == body) {
        return (vector_t){0, 0, 0};
    }
    double dist = distance(node->body->position, body->position);
    if (node->size.x / dist < theta) {
        return calculate_force(body, node->body);
    } else {
        vector_t force = {0, 0, 0};
        for (int i = 0; i < 8; i++) {
            if (node->children[i] != NULL) {
                vector_t subforce = calculate_total_force(node->children[i], body, theta);
                force.x += subforce.x;
                force.y += subforce.y;
                force.z += subforce.z;
            }
        }
        return force;
    }
}

int main() {
    int num_bodies = 1000;
    int sim_steps = 10000;
    double time_step = 0.001;
    double theta = 1;
    double sim_size = 100;
    body_t *bodies = malloc(num_bodies * sizeof(body_t));
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].mass = rand() / (double)RAND_MAX * 10;
        bodies[i].position.x = rand() / (double)RAND_MAX * sim_size;
        bodies[i].position.y = rand() / (double)RAND_MAX * sim_size;
        bodies[i].position.z = rand() / (double)RAND_MAX * sim_size;
        bodies[i].velocity.x = rand() / (double)RAND_MAX * 10 - 5;
        bodies[i].velocity.y = rand() / (double)RAND_MAX * 10 - 5;
        bodies[i].velocity.z = rand() / (double)RAND_MAX * 10 - 5;
    }
    octree_t *root = create_node((vector_t){0, 0, 0}, (vector_t){sim_size, sim_size, sim_size});
    for (int i = 0; i < num_bodies; i++) {
        insert_body(root, &bodies[i]);
    }
    for (int step = 0; step < sim_steps; step++) {
        for (int i = 0; i < num_bodies; i++) {
            vector_t force = calculate_total_force(root, &bodies[i], theta);
            update_state(&bodies[i], force, time_step);
        }
    }
    free(bodies);
    return 0;
}