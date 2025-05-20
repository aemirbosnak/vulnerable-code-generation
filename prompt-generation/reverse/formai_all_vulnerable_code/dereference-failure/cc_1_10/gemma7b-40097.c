//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Circuit {
  int numNodes;
  double **adjMatrix;
  double *nodeValues;
  double *nodeBiases;
} Circuit;

Circuit *createCircuit(int numNodes) {
  Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
  circuit->numNodes = numNodes;
  circuit->adjMatrix = (double **)malloc(numNodes * sizeof(double *));
  for (int i = 0; i < numNodes; i++) {
    circuit->adjMatrix[i] = (double *)malloc(numNodes * sizeof(double));
  }
  circuit->nodeValues = (double *)malloc(numNodes * sizeof(double));
  circuit->nodeBiases = (double *)malloc(numNodes * sizeof(double));
  return circuit;
}

void simulateCircuit(Circuit *circuit) {
  for (int i = 0; i < circuit->numNodes; i++) {
    double sum = 0.0;
    for (int j = 0; j < circuit->numNodes; j++) {
      if (circuit->adjMatrix[i][j] != 0) {
        sum += circuit->nodeValues[j] * circuit->adjMatrix[i][j];
      }
    }
    circuit->nodeValues[i] = sum + circuit->nodeBiases[i];
  }
}

int main() {
  Circuit *circuit = createCircuit(5);
  circuit->adjMatrix[0][1] = 1.0;
  circuit->adjMatrix[0][2] = 2.0;
  circuit->adjMatrix[1][3] = 3.0;
  circuit->adjMatrix[2][4] = 4.0;
  circuit->nodeValues[0] = 5.0;
  circuit->nodeBiases[2] = -1.0;

  simulateCircuit(circuit);

  for (int i = 0; i < circuit->numNodes; i++) {
    printf("Node %d: Value = %.2lf, Bias = %.2lf\n", i, circuit->nodeValues[i], circuit->nodeBiases[i]);
  }

  return 0;
}