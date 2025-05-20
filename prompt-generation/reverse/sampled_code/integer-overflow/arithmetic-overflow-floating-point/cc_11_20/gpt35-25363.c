//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>

int main() {
    float input_val, output_val;
    int input_type, output_type;
    printf("Welcome to the Futuristic Unit Converter\n");
    printf("Enter input value: ");
    scanf("%f", &input_val);
    printf("Select input type:\n");
    printf("1. meters\n2. kilograms\n3. seconds\n");
    scanf("%d", &input_type);
    printf("Select output type:\n");
    printf("1. miles\n2. pounds\n3. minutes\n");
    scanf("%d", &output_type);
    switch (input_type) {
        case 1:
            // convert meters to miles
            output_val = input_val * 0.000621371;
            break;
        case 2:
            // convert kilograms to pounds
            output_val = input_val * 2.20462;
            break;
        case 3:
            // convert seconds to minutes
            output_val = input_val / 60;
            break;
        default:
            printf("Invalid input type\n");
            return 0;
    }
    switch (output_type) {
        case 1:
            // convert miles to meters
            output_val /= 0.000621371;
            break;
        case 2:
            // convert pounds to kilograms
            output_val /= 2.20462;
            break;
        case 3:
            // convert minutes to seconds
            output_val *= 60;
            break;
        default:
            printf("Invalid output type\n");
            return 0;
    }
    printf("Input: %.2f ", input_val);
    switch (input_type) {
        case 1: printf("meters\n"); break;
        case 2: printf("kilograms\n"); break;
        case 3: printf("seconds\n"); break;
    }
    printf("Output: %.2f ", output_val);
    switch (output_type) {
        case 1: printf("miles\n"); break;
        case 2: printf("pounds\n"); break;
        case 3: printf("minutes\n"); break;
    }
    return 0;
}