//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 5000       // Maximum number of nodes 
#define MAX_VAL 999999999    // Maximum value for resistance, voltage and current
#define TOLERANCE 0.0001     // Tolerance for convergence
#define MAX_ITERATIONS 1000  // Maximum iterations for convergence

const char* netlist = "example.net"; // Netlist file name
 
/***** Structure Declarations *****/

typedef struct element_tag {       // component structure
  char type;
  int node[2];
  double value;
  char name[10];
  double vi;
  double vc;
  double vp;
  double gc;
  double gn;
  double gec;
  double gen;
} element;

typedef struct node_tag {    // node data structure
  int num;
  char name[10];
} node;

/***** Function Declarations *****/

void circuit_simulator();
void get_netlist();
void parse_netlist();
void print_elements();
void gauss_jordan();
void matrix_multiply(int m, int n, int p, double a[m][n], double b[n][p], double c[m][p]);
void print_matrix(int m, int n, double a[m][n]);
double max_val(double a, double b);
double min_val(double a, double b);
int find_node(char *s);
void add_node(int num, char *s, int count);
void print_nodes();

/***** Global Variables *****/

element e[MAX_NODES];    // Storage for component data
int element_count = 0;   // Number of components in circuit
int node_count = 0;      // Total number of unique nodes
node nodes[MAX_NODES];   // Storage for node data

int main(int argc, char *argv[]) {
    circuit_simulator();
    return 0;
}

/***** Function Definitions *****/

void circuit_simulator() {
    get_netlist();
    parse_netlist();
    print_elements();

    int num_iterations = 0;
    int max_node = 0;
    double a[MAX_NODES][MAX_NODES];
    double b[MAX_NODES][1];
    double x[MAX_NODES][1];
    double old_x[MAX_NODES][1];

    while (num_iterations++ < MAX_ITERATIONS) {
        for (int i = 0; i < MAX_NODES; i++) {
            for (int j = 0; j < MAX_NODES; j++) {
                a[i][j] = 0.0;
            }
            b[i][0] = 0.0;
            x[i][0] = 0.0;
            old_x[i][0] = 0.0;
        }

        max_node = 0;
        for (int i = 0; i < element_count; i++) {   // Loop through all the elements in the circuit
            int n1 = e[i].node[0];   
            int n2 = e[i].node[1];

            if (n1 > max_node) max_node = n1;
            if (n2 > max_node) max_node = n2;

            switch (e[i].type) {   // Determine the type of the element
                case 'R':   // Resistance
                    a[n1][n1] += e[i].value;
                    a[n1][n2] -= e[i].value;
                    a[n2][n1] -= e[i].value;
                    a[n2][n2] += e[i].value;
                    break;
                case 'V':   // Voltage source
                    if (n1 != 0) {
                        b[n1][0] -= e[i].value;
                    }
                    if (n2 != 0) {
                        b[n2][0] += e[i].value;
                    }
                    break;
                case 'I':   // Current source
                    if (n1 != 0) {
                        b[n1][0] += e[i].value;
                    }
                    if (n2 != 0) {
                        b[n2][0] -= e[i].value;
                    }
                    break;
                case 'C':   // Capacitor
                    if (num_iterations == 1) {   // Only need to do this once, at the beginning of the simulation
                        e[i].vi = 0.0;
                        e[i].vc = 0.0;
                        e[i].vp = 0.0;
                    }

                    double gec = e[i].value / TOLERANCE;
                    double gen = e[i].value * TOLERANCE;
                    double vc = e[i].vc * (1 + gec * TOLERANCE);
                    
                    a[n1][n1] += gec + e[i].gen;
                    a[n1][n2] += -gec;
                    a[n2][n1] += -gec;
                    a[n2][n2] += gec + e[i].gen;
                    b[n1][0] += (gec * vc) - e[i].gn;
                    b[n2][0] += -(gec * vc) - e[i].gn;

                    e[i].gc = gec;
                    e[i].gn = gen;
                    e[i].gec = gec;
                    e[i].gen = gen;
                    e[i].vc = vc;
                    break;
                default:
                    break;
            }
        }

        gauss_jordan(element_count, a, b, x);

        double max_error = 0.0;
        int converged = 1;
        for (int i = 1; i <= max_node; i++) {
            double error = fabs(x[i][0] - old_x[i][0]);
            if (error > TOLERANCE) {
                converged = 0;
            }
            if (error > max_error) {
                max_error = error;
            }
            old_x[i][0] = x[i][0];
        }

        if (converged == 1 || max_error < TOLERANCE) break;
    }

    print_nodes();
    printf("\n\nSolution:\n");
    for (int i = 1; i <= max_node; i++) {
        printf("Node %d: %lf\n", i, x[i][0]);
    }
}

// Parse the netlist file
void parse_netlist() {
    char line[100];
    char *tok;
    int node_nums[2];
    int component_count = 0;

    FILE *fp = fopen(netlist, "r");
    while (fgets(line, sizeof(line), fp)) {
        tok = strtok(line, " \t\n");

        if (tok == NULL || tok[0] == '*' || tok[0] == '$') {
            continue;
        } else if (isdigit(tok[0])) {   // Node definition line
            node_nums[0] = atoi(tok);
            tok = strtok(NULL, " \t\n");
            node_nums[1] = atoi(tok);

            add_node(node_nums[0], "", component_count);
            add_node(node_nums[1], "", component_count);
        } else {   // Component definition line
            e[component_count].type = toupper(tok[0]);
            strcpy(e[component_count].name, tok);

            tok = strtok(NULL, " \t\n");
            e[component_count].node[0] = find_node(tok);

            tok = strtok(NULL, " \t\n");
            e[component_count].node[1] = find_node(tok);

            tok = strtok(NULL, " \t\n");
            e[component_count].value = atof(tok);

            component_count++;
        }
    }
    fclose(fp);
    element_count = component_count;
}

// Print nodes and their names
void print_nodes() {
    printf("Nodes:\n");
    for (int i = 1; i <= node_count; i++) {
        printf("Node %d: %s\n", nodes[i].num, nodes[i].name);
    }
}

// Add a node to the list of nodes
void add_node(int num, char *s, int count) {
    for (int i = 1; i <= node_count; i++) {
        if (nodes[i].num == num) {
            return;
        }
    }
    node_count++;
    nodes[node_count].num = num;
    strcpy(nodes[node_count].name, s);
}

// Find a node by its name
int find_node(char *s) {
    for (int i = 1; i <= node_count; i++) {
        if (strcmp(nodes[i].name, s) == 0) {
            return nodes[i].num;
        }
    }
    add_node(node_count + 1, s, 0);
    return node_count;
}

// Perform Gaussian elimination to solve the system of linear equations
void gauss_jordan(int n, double a[MAX_NODES][MAX_NODES], double b[MAX_NODES][1], double x[MAX_NODES][1]) {
    for (int k = 1; k < n; k++) {
        for (int i = k + 1; i <= n; i++) {
            double factor = a[i][k] / a[k][k];
            b[i][0] -= factor * b[k][0];
            for (int j = k + 1; j <= n; j++) {
                a[i][j] -= factor * a[k][j];
            }
        }
    }

    // Back substitution
    for (int i = n; i >= 1; i--) {
        double sum = 0.0;
        for (int j = i + 1; j <= n; j++) {
            sum += a[i][j] * x[j][0];
        }
        x[i][0] = (b[i][0] - sum) / a[i][i];
    }
}

// Matrix multiplication
void matrix_multiply(int m, int n, int p, double a[m][n], double b[n][p], double c[m][p]) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++) {
            c[i][j] = 0.0;
            for (int k = 1; k <= n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Print a matrix
void print_matrix(int m, int n, double a[m][n]) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%0.2lf ", a[i][j]);
        }
        printf("\n");
    }
}

// Get the netlist file
void get_netlist() {
    printf("Enter the name of the netlist file: ");
    scanf("%s", netlist);
}

// Print the elements in the circuit
void print_elements() {
    printf("Elements in the circuit:\n");
    for (int i = 0; i < element_count; i++) {
        printf("%c %d %d %lf\n", e[i].type, e[i].node[0], e[i].node[1], e[i].value);
    }
}

// Find maximum value
double max_val(double a, double b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Find minimum value
double min_val(double a, double b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}