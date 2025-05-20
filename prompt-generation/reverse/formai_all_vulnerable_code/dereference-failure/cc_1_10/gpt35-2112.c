//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year, month, day;
} Date;

typedef struct {
    char name[20];
    float weight, height;
    Date birthdate;
} Person;

typedef struct {
    Date date;
    float weight;
} Measurement;

typedef struct {
    int max_size, size;
    Measurement* measurements;
} Measurements;

void add_measurement(Measurements* measurements, Measurement measurement) {
    if (measurements->size + 1 > measurements->max_size) {
        int new_max_size = measurements->max_size * 2;
        measurements->measurements = realloc(measurements->measurements, new_max_size * sizeof(Measurement));
        measurements->max_size = new_max_size;
    }
    measurements->measurements[measurements->size] = measurement;
    measurements->size++;
}

float get_bmi(float weight, float height) {
    return weight / (height * height);
}

void print_measurement(Measurement measurement) {
    printf("%d/%d/%d: %.2f kg\n", measurement.date.day, measurement.date.month, measurement.date.year, measurement.weight);
}

void print_measurements(Measurements measurements) {
    for (int i = 0; i < measurements.size; i++) {
        print_measurement(measurements.measurements[i]);
    }
}

void check_weight_change(Person person, Measurements measurements) {
    if (measurements.size < 2) {
        printf("Not enough measurements to calculate weight change.\n");
        return;
    }
    float first_weight = measurements.measurements[0].weight;
    float last_weight = measurements.measurements[measurements.size - 1].weight;
    float difference = last_weight - first_weight;
    if (difference > 0) {
        printf("%s gained %.2f kg.\n", person.name, difference);
    } else if (difference < 0) {
        printf("%s lost %.2f kg.\n", person.name, -difference);
    } else {
        printf("%s did not change weight.\n", person.name);
    }
}

int main() {
    Person person = {"John", 80, 1.8, {1995, 8, 23}};
    Measurements measurements = {10, 0, malloc(10 * sizeof(Measurement))};
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    Measurement measurement1 = {{tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900}, 79.5};
    add_measurement(&measurements, measurement1);
    Measurement measurement2 = {{tm->tm_mday-7, tm->tm_mon+1, tm->tm_year+1900}, 78.2};
    add_measurement(&measurements, measurement2);
    printf("Welcome, %s!\n", person.name);
    printf("Your BMI is %.2f.\n", get_bmi(person.weight, person.height));
    printf("Here are your measurements:\n");
    print_measurements(measurements);
    check_weight_change(person, measurements);
    return 0;
}