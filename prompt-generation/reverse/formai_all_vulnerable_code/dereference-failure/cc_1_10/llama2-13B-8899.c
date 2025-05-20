//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100
#define M 10

// Graph structure
typedef struct node {
    int label; // node label
    struct node* neighbors[M]; // neighboring nodes
} node;

// Graph functions
node* new_node(int label);
void add_edge(node* u, node* v);
void print_graph(node* g);

// Statistical functions
double mean(node* g);
double variance(node* g);
double standard_deviation(node* g);
double covariance(node* u, node* v, node* g);

int main() {
    srand(time(NULL));

    // Create a random graph
    node* g = new_node(0);
    for (int i = 0; i < N; i++) {
        node* u = new_node(i % M);
        for (int j = 0; j < M; j++) {
            node* v = new_node(i % M + j * N / M);
            add_edge(u, v);
            add_edge(v, u);
        }
        g->neighbors[i % M] = u;
    }

    // Calculate statistical properties
    double mean_degree = mean(g);
    double variance_degree = variance(g);
    double standard_deviation_degree = standard_deviation(g);
    double covariance_degree = covariance(g, 0, 1);

    printf("Mean degree: %f\n", mean_degree);
    printf("Variance degree: %f\n", variance_degree);
    printf("Standard deviation degree: %f\n", standard_deviation_degree);
    printf("Covariance degree: %f\n", covariance_degree);

    return 0;
}

// Graph structure functions
node* new_node(int label) {
    node* n = (node*) malloc(sizeof(struct node));
    n->label = label;
    for (int i = 0; i < M; i++) {
        n->neighbors[i] = NULL;
    }
    return n;
}

void add_edge(node* u, node* v) {
    u->neighbors[u->label % M] = v;
    v->neighbors[v->label % M] = u;
}

void print_graph(node* g) {
    for (int i = 0; i < N; i++) {
        printf("%d:", g->label);
        for (int j = 0; j < M; j++) {
            if (g->neighbors[i * M + j] != NULL) {
                printf(" %d", g->neighbors[i * M + j]->label);
            }
        }
        printf("\n");
    }
}

// Statistical functions
double mean(node* g) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += g->neighbors[i * M + j]->label;
        }
    }
    return sum / (N * M);
}

double variance(node* g) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += (g->neighbors[i * M + j]->label - mean(g)) * (g->neighbors[i * M + j]->label - mean(g));
        }
    }
    return sum / (N * M);
}

double standard_deviation(node* g) {
    return sqrt(variance(g));
}

double covariance(node* u, node* v, node* g) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += (g->neighbors[i * M + j]->label - mean(g)) * (u->neighbors[i * M + j]->label - mean(g));
        }
    }
    return sum / (N * M);
}