//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
#include <stdio.h>

void print_welcome_message() {
    printf("Welcome to the Ultimate Arithmetic Calculator!\n");
    printf("This program will allow you to perform basic arithmetic operations.\n");
    printf("Let's get started!\n\n");
}

void get_user_input(float* num1, float* num2) {
    printf("Enter the first number: ");
    scanf("%f", num1);
    printf("Enter the second number: ");
    scanf("%f", num2);
}

void perform_arithmetic_operations(float num1, float num2) {
    float sum = num1 + num2;
    float difference = num1 - num2;
    float product = num1 * num2;
    float quotient = num2 != 0 ? num1 / num2 : 0; // Avoid division by zero
    float modulus = (int)num1 % (int)num2; // Only valid for integer parts
    
    printf("\n--- Arithmetic Results ---\n");
    printf("Addition: %.2f + %.2f = %.2f\n", num1, num2, sum);
    printf("Subtraction: %.2f - %.2f = %.2f\n", num1, num2, difference);
    printf("Multiplication: %.2f * %.2f = %.2f\n", num1, num2, product);
    
    if (num2 != 0) {
        printf("Division: %.2f / %.2f = %.2f\n", num1, num2, quotient);
    } else {
        printf("Division: Division by zero is undefined.\n");
    }

    if (num2 != 0) {
        printf("Modulus: (int)%.2f %% (int)%.2f = %d\n", num1, num2, (int)modulus);
    } else {
        printf("Modulus: Modulus by zero is undefined.\n");
    }
    
    printf("--- End of Results ---\n\n");
}

void ask_for_another_calculation() {
    char choice;
    printf("Would you like to perform another calculation? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        main(); // Recall main to restart the process
    } else {
        printf("Thank you for using the Ultimate Arithmetic Calculator. Goodbye!\n");
    }
}

int main() {
    print_welcome_message();
    
    float num1, num2;
    
    while (1) {
        get_user_input(&num1, &num2);
        perform_arithmetic_operations(num1, num2);
        ask_for_another_calculation();
    }
    
    return 0;
}