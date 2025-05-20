//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RESISTOR 0
#define CAPACITOR 1
#define INDUCTOR 2

struct circuit_element {
    int type;
    double value;
    double capacitance;
    double inductance;
    double voltage;
    double current;
};

struct circuit_element * circuit;
int circuit_size = 0;

struct data_point {
    double time;
    double voltage;
    double current;
};

struct data_point * simulation_data;
int simulation_size = 0;

double resistor_formula(double r, double i, double v)
{
    return (v - i * r) / r;
}

double capacitor_formula(double c, double i, double v)
{
    return i * c;
}

double inductor_formula(double l, double i, double v)
{
    return (v - i * l) / l;
}

void add_element(int type, double value, double c, double l)
{
    if (circuit_size == 0) {
        circuit = (struct circuit_element *) malloc(sizeof(struct circuit_element));
    } else {
        circuit = (struct circuit_element *) realloc(circuit, (circuit_size + 1) * sizeof(struct circuit_element));
    }

    struct circuit_element new_element;

    new_element.type = type;
    new_element.value = value;
    new_element.capacitance = c;
    new_element.inductance = l;
    new_element.voltage = 0;
    new_element.current = 0;

    circuit[circuit_size] = new_element;
    circuit_size++;
}

void simulate(double time_step, double total_time)
{
    int num_pts = (int) ceil(total_time / time_step);

    if (simulation_size == 0) {
        simulation_data = (struct data_point *) malloc(num_pts * sizeof(struct data_point));
    } else {
        simulation_data = (struct data_point *) realloc(simulation_data, num_pts * sizeof(struct data_point));
    }

    for (int i = 0; i < num_pts; i++) {

        double time = i * time_step;

        for (int j = 0; j < circuit_size; j++) {

            struct circuit_element e = circuit[j];

            switch (e.type) {
                case RESISTOR:
                    e.current = resistor_formula(e.value, e.current, e.voltage);
                    break;
                case CAPACITOR:
                    e.current = capacitor_formula(e.capacitance, e.current, e.voltage);
                    break;
                case INDUCTOR:
                    e.current = inductor_formula(e.inductance, e.current, e.voltage);
                    break;
            }

            if (e.type != RESISTOR) {
                double prev_voltage = e.voltage;
                e.voltage += e.current * time_step / e.value;
                if ((prev_voltage > 0 && e.voltage < 0) || (prev_voltage < 0 && e.voltage > 0)) {
                    e.voltage = 0;
                }
            }

            circuit[j] = e;

        }

        double voltage = circuit[circuit_size - 1].voltage;
        double current = circuit[circuit_size - 1].current;

        struct data_point data;
        data.time = time;
        data.voltage = voltage;
        data.current = current;

        simulation_data[simulation_size] = data;
        simulation_size++;

    }
}

void print_simulation()
{
    for (int i = 0; i < simulation_size; i++) {
        printf("Time: %lf, Voltage: %lf, Current: %lf\n",
               simulation_data[i].time,
               simulation_data[i].voltage,
               simulation_data[i].current);
    }
}

int main()
{
    printf("Welcome to a Simple Classical Circuit Simulator\n\n");

    double time_step;
    double total_time;

    printf("Enter time step (seconds): ");
    scanf("%lf", &time_step);

    printf("Enter total time (seconds): ");
    scanf("%lf", &total_time);

    add_element(RESISTOR, 1000, 0, 0);
    add_element(CAPACITOR, 1.0e-6, 1.0e-6, 0);
    add_element(INDUCTOR, 0.1, 0, 0);

    simulate(time_step, total_time);

    print_simulation();

    free(circuit);
    free(simulation_data);

    return 0;
}