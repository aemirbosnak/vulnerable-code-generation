//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 50
#define MAX_CONVERTERS 10

typedef struct {
    char unit_from[MAX_INPUT_SIZE];
    char unit_to[MAX_INPUT_SIZE];
    double value;
} ConversionRequest;

void* convert_units(void* arg) {
    ConversionRequest* request = (ConversionRequest*)arg;
    double result = 0;

    if (strcmp(request->unit_from, "meters") == 0 && strcmp(request->unit_to, "kilometers") == 0) {
        result = request->value / 1000.0;
    } else if (strcmp(request->unit_from, "kilometers") == 0 && strcmp(request->unit_to, "meters") == 0) {
        result = request->value * 1000.0;
    } else if (strcmp(request->unit_from, "celsius") == 0 && strcmp(request->unit_to, "fahrenheit") == 0) {
        result = (request->value * 9.0 / 5.0) + 32.0;
    } else if (strcmp(request->unit_from, "fahrenheit") == 0 && strcmp(request->unit_to, "celsius") == 0) {
        result = (request->value - 32.0) * 5.0 / 9.0;
    } else if (strcmp(request->unit_from, "grams") == 0 && strcmp(request->unit_to, "kilograms") == 0) {
        result = request->value / 1000.0;
    } else if (strcmp(request->unit_from, "kilograms") == 0 && strcmp(request->unit_to, "grams") == 0) {
        result = request->value * 1000.0;
    } else {
        printf("Invalid conversion request from %s to %s.\n", request->unit_from, request->unit_to);
        free(request);
        pthread_exit(NULL);
    }

    printf("Converted %.2f %s to %.2f %s\n", request->value, request->unit_from, result, request->unit_to);
    free(request);
    pthread_exit(NULL);
}

void get_conversion_input() {
    while (1) {
        ConversionRequest* request = malloc(sizeof(ConversionRequest));
        
        printf("Enter the value to convert (or type 'exit' to quit): ");
        char input_value[MAX_INPUT_SIZE];
        fgets(input_value, MAX_INPUT_SIZE, stdin);
        
        if (strncmp(input_value, "exit", 4) == 0) {
            free(request);
            break;
        }
        
        request->value = atof(input_value);
        
        printf("Enter unit to convert from: ");
        fgets(request->unit_from, MAX_INPUT_SIZE, stdin);
        request->unit_from[strcspn(request->unit_from, "\n")] = 0; // remove newline
        
        printf("Enter unit to convert to: ");
        fgets(request->unit_to, MAX_INPUT_SIZE, stdin);
        request->unit_to[strcspn(request->unit_to, "\n")] = 0; // remove newline
        
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, convert_units, (void*)request);
        pthread_detach(thread_id); // Automatically clean up the thread when finished
    }
}

int main() {
    printf("Welcome to the Asynchronous Unit Converter!\n");
    get_conversion_input();
    printf("Thank you for using the unit converter. Goodbye!\n");
    return 0;
}