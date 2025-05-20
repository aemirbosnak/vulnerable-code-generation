//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure of a fitness tracker record
typedef struct {
    int timestamp;          // Timestamp of the record in seconds since epoch
    int steps;             // Number of steps taken
    double distance;       // Distance traveled in meters
    double calories;       // Calories burned
    double heart_rate;     // Heart rate in beats per minute
} FitnessRecord;

// Function to create a new fitness tracker record
FitnessRecord* create_record(int timestamp, int steps, double distance, double calories, double heart_rate) {
    FitnessRecord* record = malloc(sizeof(FitnessRecord));
    record->timestamp = timestamp;
    record->steps = steps;
    record->distance = distance;
    record->calories = calories;
    record->heart_rate = heart_rate;
    return record;
}

// Function to print a fitness tracker record
void print_record(FitnessRecord* record) {
    printf("Timestamp: %d\n", record->timestamp);
    printf("Steps: %d\n", record->steps);
    printf("Distance: %.2f meters\n", record->distance);
    printf("Calories: %.2f\n", record->calories);
    printf("Heart rate: %.2f bpm\n", record->heart_rate);
    printf("\n");
}

// Function to calculate the average heart rate from a list of records
double calculate_average_heart_rate(FitnessRecord** records, int num_records) {
    double sum = 0;
    for (int i = 0; i < num_records; i++) {
        sum += records[i]->heart_rate;
    }
    return sum / num_records;
}

// Function to find the highest heart rate from a list of records
double find_highest_heart_rate(FitnessRecord** records, int num_records) {
    double highest_heart_rate = -1;
    for (int i = 0; i < num_records; i++) {
        if (records[i]->heart_rate > highest_heart_rate) {
            highest_heart_rate = records[i]->heart_rate;
        }
    }
    return highest_heart_rate;
}

// Function to find the lowest heart rate from a list of records
double find_lowest_heart_rate(FitnessRecord** records, int num_records) {
    double lowest_heart_rate = -1;
    for (int i = 0; i < num_records; i++) {
        if (records[i]->heart_rate < lowest_heart_rate) {
            lowest_heart_rate = records[i]->heart_rate;
        }
    }
    return lowest_heart_rate;
}

// Function to find the total distance traveled from a list of records
double calculate_total_distance(FitnessRecord** records, int num_records) {
    double total_distance = 0;
    for (int i = 0; i < num_records; i++) {
        total_distance += records[i]->distance;
    }
    return total_distance;
}

// Function to find the total calories burned from a list of records
double calculate_total_calories(FitnessRecord** records, int num_records) {
    double total_calories = 0;
    for (int i = 0; i < num_records; i++) {
        total_calories += records[i]->calories;
    }
    return total_calories;
}

int main() {
    // Create a list of fitness tracker records
    FitnessRecord* records[] = {
        create_record(1652390400, 10000, 8000, 500, 75),
        create_record(1652476800, 12000, 9000, 600, 80),
        create_record(1652563200, 14000, 10000, 700, 85),
        create_record(1652649600, 16000, 11000, 800, 90),
        create_record(1652736000, 18000, 12000, 900, 95),
    };

    // Print the list of records
    printf("Fitness Tracker Records:\n\n");
    for (int i = 0; i < 5; i++) {
        print_record(records[i]);
    }

    // Calculate and print the average heart rate
    double average_heart_rate = calculate_average_heart_rate(records, 5);
    printf("Average heart rate: %.2f bpm\n\n", average_heart_rate);

    // Find and print the highest heart rate
    double highest_heart_rate = find_highest_heart_rate(records, 5);
    printf("Highest heart rate: %.2f bpm\n\n", highest_heart_rate);

    // Find and print the lowest heart rate
    double lowest_heart_rate = find_lowest_heart_rate(records, 5);
    printf("Lowest heart rate: %.2f bpm\n\n", lowest_heart_rate);

    // Calculate and print the total distance traveled
    double total_distance = calculate_total_distance(records, 5);
    printf("Total distance traveled: %.2f meters\n\n", total_distance);

    // Calculate and print the total calories burned
    double total_calories = calculate_total_calories(records, 5);
    printf("Total calories burned: %.2f\n\n", total_calories);

    return 0;
}