//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_TEMP_ENTRIES 1000

typedef struct {
    char *name;
    double celsius;
    double fahrenheit;
} TempEntry;

int main() {
    int num_entries = 0;
    TempEntry *temp_entries = malloc(MAX_TEMP_ENTRIES * sizeof(TempEntry));

    while (num_entries < MAX_TEMP_ENTRIES) {
        printf("Enter a temperature (in Celsius or Fahrenheit): ");
        char temp_input[100];
        fgets(temp_input, 100, stdin);

        char *temp_type = strtok(temp_input, " ");
        double temp_value = strtod(strtok(NULL, " "), NULL);

        if (strcmp(temp_type, "Celsius") == 0) {
            temp_entries[num_entries].name = strdup("Celsius");
            temp_entries[num_entries].celsius = temp_value;
            temp_entries[num_entries].fahrenheit = (temp_value * 9/5) + 32;
        } else if (strcmp(temp_type, "Fahrenheit") == 0) {
            temp_entries[num_entries].name = strdup("Fahrenheit");
            temp_entries[num_entries].fahrenheit = temp_value;
            temp_entries[num_entries].celsius = (temp_value - 32) * 5/9;
        } else {
            printf("Invalid temperature type.\n");
            continue;
        }

        num_entries++;
    }

    printf("\nTemperature Conversion Table:\n");
    printf("=============================================================\n");
    printf("|  Temperature  | Celsius | Fahrenheit |\n");
    printf("=============================================================\n");

    for (int i = 0; i < num_entries; i++) {
        printf("| %-15s | %.2f | %.2f |\n", temp_entries[i].name, temp_entries[i].celsius, temp_entries[i].fahrenheit);
    }

    free(temp_entries);
    return 0;
}