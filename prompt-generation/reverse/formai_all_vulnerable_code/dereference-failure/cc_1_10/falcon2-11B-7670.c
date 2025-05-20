//Falcon2-11B DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* input = NULL;
    size_t input_size = 0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input_size = strlen(input);

    if (input_size == 0) {
        printf("Invalid input: string is empty.\n");
        return 1;
    }

    int* numbers = NULL;
    int number_count = 0;

    for (int i = 0; i < input_size; i++) {
        char c = input[i];

        if (isdigit(c)) {
            int num = c - '0';

            if (num >= 0 && num <= 9) {
                numbers[number_count] = num;
                number_count++;
            }
        }
    }

    if (number_count == 0) {
        printf("Invalid input: no numbers found.\n");
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < number_count; i++) {
        sum += numbers[i];
    }

    printf("The sum of the numbers is: %d\n", sum);

    free(numbers);

    return 0;
}