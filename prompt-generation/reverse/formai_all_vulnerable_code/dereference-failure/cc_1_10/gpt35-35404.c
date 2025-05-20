//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: careful
#include<stdio.h>
#include<stdlib.h>

/* Defining and initializing the components of the circuit */
double R1 = 1000;
double R2 = 2000;
double C1 = 1e-6;
double C2 = 0.5e-6;

double Vin = 10; /* Input voltage */
double Vout = 0; /* Output voltage */
double I1,I2; /* Currents through the resistors */

double dt = 0.01; /* Time step */
double tmax = 1.0; /* Total simulation time */
int n_samples; /* Number of samples */

int main() {

  n_samples = (int)(tmax/dt); /* Calculating the number of samples */

  double *voltage; /* Array to store output voltage */
  voltage = (double*)malloc(n_samples*sizeof(double)); /* Dynamic allocation of memory for voltage array */

  double t = 0; /* Initial time */

  /* Loop for simulating the circuit */
  for(int i=0; i<n_samples; i++) {

    I1 = (Vin-Vout)/(R1+R2); /* Calculating current through resistor R1 */
    I2 = I1; /* Current through R1 equals current through R2 */

    /* Updating voltage across capacitors using Euler method */
    double dv1 = I1*dt/C1;
    double dv2 = -I2*dt/C2;
    Vout += dv1+dv2;
    
    voltage[i] = Vout; /* Adding Vout to voltage array */
    
    t += dt; /* Updating time */
    
  }
  
  /* Printing the output voltage at each time step */
  printf("Time (s)     Output voltage (V)\n");
  for(int i=0; i<n_samples; i++) {
    printf("%6.2f       %6.4f\n", i*dt, voltage[i]);
  }
  
  free(voltage); /* Freeing the memory allocated to voltage array */

  return 0;
}