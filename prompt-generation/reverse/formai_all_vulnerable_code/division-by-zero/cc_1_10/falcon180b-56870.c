//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURES 100

typedef struct {
    int index;
    int temperature;
} Temperature;

void print_temperatures(Temperature *temperatures, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d: %d\n", i, temperatures[i].temperature);
    }
}

int get_temperature() {
    return rand() % 100;
}

void add_temperature(Temperature *temperatures, int count, int temperature) {
    if (count >= MAX_TEMPERATURES) {
        return;
    }

    int index = rand() % count;
    int new_index = count - 1;

    for (int i = count - 1; i >= index; i--) {
        temperatures[i] = temperatures[i - 1];
    }

    temperatures[index] = (Temperature) {
       .index = index,
       .temperature = temperature
    };

    count++;
}

int main() {
    srand(time(NULL));

    Temperature temperatures[MAX_TEMPERATURES];
    int count = 0;

    add_temperature(temperatures, count, get_temperature());
    add_temperature(temperatures, count, get_temperature());
    add_temperature(temperatures, count, get_temperature());

    printf("Initial temperatures:\n");
    print_temperatures(temperatures, count);

    for (int i = 0; i < count; i++) {
        add_temperature(temperatures, count, get_temperature());
    }

    printf("\nNew temperatures:\n");
    print_temperatures(temperatures, count);

    return 0;
}