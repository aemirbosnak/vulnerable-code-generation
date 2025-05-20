//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: introspective
#include <stdio.h>

int main() {
   printf("Welcome to the Classical Circuit Simulator\n");
   int numComponents, numNodes, numVoltageSources, numCurrentSources;
   printf("Enter the number of components in the circuit: ");
   scanf("%d", &numComponents);
   printf("Enter the number of nodes in the circuit: ");
   scanf("%d", &numNodes);
   printf("Enter the number of voltage sources in the circuit: ");
   scanf("%d", &numVoltageSources);
   printf("Enter the number of current sources in the circuit: ");
   scanf("%d", &numCurrentSources);

   // Initialize circuit parameters
   float resistances[numComponents];
   float capacitances[numComponents];
   float inductances[numComponents];
   float voltages[numVoltageSources];
   float currents[numCurrentSources];

   // Populate resistance array
   printf("Enter the resistance values for the components: ");
   for (int i = 0; i < numComponents; i++) {
      scanf("%f", &resistances[i]);
   }

   // Populate capacitance array
   printf("Enter the capacitance values for the components: ");
   for (int i = 0; i < numComponents; i++) {
      scanf("%f", &capacitances[i]);
   }

   // Populate inductance array
   printf("Enter the inductance values for the components: ");
   for (int i = 0; i < numComponents; i++) {
      scanf("%f", &inductances[i]);
   }

   // Populate voltage array
   printf("Enter the voltage values for the voltage sources: ");
   for (int i = 0; i < numVoltageSources; i++) {
      scanf("%f", &voltages[i]);
   }

   // Populate current array
   printf("Enter the current values for the current sources: ");
   for (int i = 0; i < numCurrentSources; i++) {
      scanf("%f", &currents[i]);
   }

   // Print circuit parameters
   printf("\nCircuit Parameters:\n");
   for (int i = 0; i < numComponents; i++) {
      printf("Component %d: R=%.2f, C=%.2f, L=%.2f\n", i+1, resistances[i], capacitances[i], inductances[i]);
   }
   for (int i = 0; i < numVoltageSources; i++) {
      printf("Voltage Source %d: V=%.2f\n", i+1, voltages[i]);
   }
   for (int i = 0; i < numCurrentSources; i++) {
      printf("Current Source %d: I=%.2f\n", i+1, currents[i]);
   }

   return 0;
}