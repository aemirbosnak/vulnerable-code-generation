//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double r;
    double i;
} complex_t;

complex_t cmplx_add(complex_t, complex_t);
complex_t cmplx_sub(complex_t, complex_t);
complex_t cmplx_mult(complex_t, complex_t);
complex_t cmplx_div(complex_t, complex_t);
complex_t cmplx_conj(complex_t);
complex_t cmplx_exp(double);
void circuit_simulator(double[], int);

/* Complex number addition (a + b) */
complex_t cmplx_add(complex_t a, complex_t b) {
    complex_t res;
    res.r = a.r + b.r;
    res.i = a.i + b.i;
    return res;
}

/* Complex number subtraction (a - b) */
complex_t cmplx_sub(complex_t a, complex_t b) {
    complex_t res;
    res.r = a.r - b.r;
    res.i = a.i - b.i;
    return res;
}

/* Complex number multiplication (a * b) */
complex_t cmplx_mult(complex_t a, complex_t b) {
    complex_t res;
    res.r = a.r * b.r - a.i * b.i;
    res.i = a.r * b.i + a.i * b.r;
    return res;
}

/* Complex number division (a / b) */
complex_t cmplx_div(complex_t a, complex_t b) {
    complex_t res;
    double denom = b.r * b.r + b.i * b.i;
    res.r = (a.r * b.r + a.i * b.i) / denom;
    res.i = (a.i * b.r - a.r * b.i) / denom;
    return res;
}

/* Complex number conjugate */
complex_t cmplx_conj(complex_t a) {
    complex_t res;
    res.r = a.r;
    res.i = -a.i;
    return res;
}

/* Complex exponential */
complex_t cmplx_exp(double x) {
    complex_t res;
    res.r = cos(x);
    res.i = sin(x);
    return res;
}

/* Circuit Simulator */
void circuit_simulator(double values[], int num_values) {
    /* Check the number of values supplied and set up the circuit accordingly */
    int num_resistors, num_capacitors, num_inductors;
    
    if (num_values % 2 != 0) {
        printf("Invalid number of values\n");
        exit(0);
    }
    else {
        num_resistors = num_values / 2;
        num_capacitors = num_values / 2;
        num_inductors = num_values / 2;
    }
    
    /* Calculate the impedance of each component based on the supplied value */
    complex_t *resistor_impedances = malloc(num_resistors * sizeof(complex_t));
    complex_t *capacitor_impedances = malloc(num_capacitors * sizeof(complex_t));
    complex_t *inductor_impedances = malloc(num_inductors * sizeof(complex_t));
    
    for (int i = 0; i < num_resistors; i++) {
        resistor_impedances[i].r = values[2*i];
        resistor_impedances[i].i = 0.0;
    }
    
    for (int i = 0; i < num_capacitors; i++) {
        capacitor_impedances[i].r = 0.0;
        capacitor_impedances[i].i = -1.0 / (2 * PI * values[2*i+1]);
    }
    
    for (int i = 0; i < num_inductors; i++) {
        inductor_impedances[i].r = 0.0;
        inductor_impedances[i].i = 2 * PI * values[2*i+1];
    }
    
    /* Calculate the total impedance */
    complex_t circuit_impedance = {0.0, 0.0};
    for (int i = 0; i < num_resistors; i++) {
        circuit_impedance = cmplx_add(circuit_impedance, resistor_impedances[i]);
    }
    for (int i = 0; i < num_capacitors; i++) {
        circuit_impedance = cmplx_add(circuit_impedance, capacitor_impedances[i]);
    }
    for (int i = 0; i < num_inductors; i++) {
        circuit_impedance = cmplx_add(circuit_impedance, inductor_impedances[i]);
    }
    
    /* Calculate the current and voltage */
    complex_t source_voltage = {10.0, 0.0};
    complex_t current = cmplx_div(source_voltage, circuit_impedance);
    printf("Voltage: %.2fV\n", sqrt(source_voltage.r*source_voltage.r + source_voltage.i*source_voltage.i));
    printf("Current: %.2fA\n", sqrt(current.r*current.r + current.i*current.i));
    
    free(resistor_impedances);
    free(capacitor_impedances);
    free(inductor_impedances);
}

int main() {
    double values[] = {1000, 1e-6, 100, 10e-6, 10, 1e-6}; // R = 1kΩ, C = 1μF, L = 10μH
    circuit_simulator(values, 6);
    return 0;
}