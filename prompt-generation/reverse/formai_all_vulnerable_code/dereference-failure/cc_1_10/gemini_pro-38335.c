//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 32
#define MAX_PORTS 16

typedef struct {
    char name[MAX_NAME_LEN];
    int num_ports;
    int ports[MAX_PORTS];
} gate_t;

typedef struct {
    int num_gates;
    gate_t gates[100];
} circuit_t;

circuit_t circuit;

void read_circuit(FILE *fp) {
    int i, j;
    char line[1024];

    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '\n') {
            continue;
        } else if (line[0] == '#') {
            // Comment line
        } else {
            char *token = strtok(line, " ");
            if (strcmp(token, "GATE") == 0) {
                // Gate definition
                gate_t gate;
                token = strtok(NULL, " ");
                strcpy(gate.name, token);
                token = strtok(NULL, " ");
                gate.num_ports = atoi(token);
                for (i = 0; i < gate.num_ports; i++) {
                    token = strtok(NULL, " ");
                    gate.ports[i] = atoi(token);
                }
                circuit.gates[circuit.num_gates++] = gate;
            } else if (strcmp(token, "CONNECT") == 0) {
                // Connection between gates
                int gate1, gate2, port1, port2;
                token = strtok(NULL, " ");
                gate1 = atoi(token);
                token = strtok(NULL, " ");
                port1 = atoi(token);
                token = strtok(NULL, " ");
                gate2 = atoi(token);
                token = strtok(NULL, " ");
                port2 = atoi(token);
                circuit.gates[gate1].ports[port1] = gate2;
                circuit.gates[gate2].ports[port2] = gate1;
            } else {
                // Invalid line
            }
        }
    }
}

void print_circuit() {
    int i, j;

    for (i = 0; i < circuit.num_gates; i++) {
        printf("GATE %s %d", circuit.gates[i].name, circuit.gates[i].num_ports);
        for (j = 0; j < circuit.gates[i].num_ports; j++) {
            printf(" %d", circuit.gates[i].ports[j]);
        }
        printf("\n");
    }

    for (i = 0; i < circuit.num_gates; i++) {
        for (j = 0; j < circuit.gates[i].num_ports; j++) {
            printf("CONNECT %d %d %d %d\n", i, j, circuit.gates[i].ports[j], circuit.gates[circuit.gates[i].ports[j]].num_ports);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc != 2) {
        printf("Usage: %s <circuit_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening circuit file");
        return 1;
    }

    read_circuit(fp);
    fclose(fp);

    print_circuit();

    return 0;
}