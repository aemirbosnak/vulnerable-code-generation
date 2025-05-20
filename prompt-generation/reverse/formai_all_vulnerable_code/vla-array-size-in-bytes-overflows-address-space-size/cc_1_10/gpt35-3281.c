//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {
    printf("Welcome to the Medieval Circuit Simulator!\n");
    printf("Please enter the number of resistors in your circuit: ");
    int num_resistors;
    scanf("%d", &num_resistors);
    float resistors[num_resistors];
    for (int i = 0; i < num_resistors; i++) {
        printf("Enter the resistance of resistor %d in ohms: ", i+1);
        scanf("%f", &resistors[i]);
    }
    printf("Please enter the number of capacitors in your circuit: ");
    int num_caps;
    scanf("%d", &num_caps);
    float caps[num_caps];
    for (int i = 0; i < num_caps; i++) {
        printf("Enter the capacitance of capacitor %d in farads: ", i+1);
        scanf("%f", &caps[i]);
    }
    printf("Please enter the number of inductors in your circuit: ");
    int num_inductors;
    scanf("%d", &num_inductors);
    float inductors[num_inductors];
    for (int i = 0; i < num_inductors; i++) {
        printf("Enter the inductance of inductor %d in henrys: ", i+1);
        scanf("%f", &inductors[i]);
    }
    printf("Please enter the voltage of the power source in volts: ");
    float voltage;
    scanf("%f", &voltage);
    printf("Please enter the frequency of the power source in hertz: ");
    float frequency;
    scanf("%f", &frequency);
    printf("Please enter the time period in seconds to simulate: ");
    int num_steps;
    scanf("%d", &num_steps);
    float delta_t = 1.0/frequency/num_steps;
    float time[num_steps+1];
    float current[num_steps+1];
    float voltage_out[num_steps+1];
    float prev_current = 0;
    float prev_voltage_out = 0;
    for (int i = 0; i <= num_steps; i++) {
        time[i] = i*delta_t;
        current[i] = (voltage - prev_voltage_out)/resistors[0];
        for (int j = 1; j < num_resistors; j++) {
            current[i] += (prev_voltage_out - voltage_out[i])/resistors[j];
        }
        for (int j = 0; j < num_caps; j++) {
            voltage_out[i] += (current[i]*delta_t)/caps[j];
        }
        for (int j = 0; j < num_inductors; j++) {
            voltage_out[i] += (time[i] - (i-1)*delta_t)*(1.0/inductors[j])*prev_current;
        }
        voltage_out[i] += prev_voltage_out;
        prev_current = current[i];
        prev_voltage_out = voltage_out[i];
    }
    printf("\nTime(sec)\tCurrent(A)\tVoltage(V)\n");
    for (int i = 0; i <= num_steps; i++) {
        printf("%.2f\t\t%.4f\t\t%.4f\n", time[i], current[i], voltage_out[i]);
    }
    return 0;
}