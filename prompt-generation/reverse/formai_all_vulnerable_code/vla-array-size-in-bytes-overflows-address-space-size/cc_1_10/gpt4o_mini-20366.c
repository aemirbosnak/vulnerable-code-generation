//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: unmistakable
#include <stdio.h>

// Function to print factorial of a number using recursion
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to check if a number is prime using recursion
int is_prime(int n, int i) {
    if (n <= 2) 
        return (n == 2) ? 1 : 0;
    if (n % i == 0) 
        return 0;
    if (i * i > n) 
        return 1;
    return is_prime(n, i + 1);
}

// Function to find the greatest common divisor using recursion
int gcd(int a, int b) {
    if (b == 0) 
        return a;
    return gcd(b, a % b);
}

// Function to print the elements of an array using recursion
void print_array(int arr[], int size, int index) {
    if (index < size) {
        printf("%d ", arr[index]);
        print_array(arr, size, index + 1);
    }
}

// Function to reverse a string using recursion
void reverse_string(char str[], int start, int end) {
    if (start >= end) 
        return;
    
    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    // Recursive call
    reverse_string(str, start + 1, end - 1);
}

// Main function to test the above functions
int main() {

    // Factorial demonstration
    int num;
    printf("Enter a number for factorial: ");
    scanf("%d", &num);
    printf("Factorial of %d is %llu\n", num, factorial(num));

    // Fibonacci demonstration
    printf("Enter a position in Fibonacci sequence: ");
    scanf("%d", &num);
    printf("Fibonacci number at position %d is %d\n", num, fibonacci(num));

    // Prime number demonstration
    printf("Enter a number to check for primality: ");
    scanf("%d", &num);
    if (is_prime(num, 2)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    // GCD demonstration
    int a, b;
    printf("Enter two numbers to find GCD: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));

    // Array printing demonstration
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are: ");
    print_array(arr, size, 0);
    printf("\n");

    // String reversing demonstration
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    reverse_string(str, 0, len - 1);
    printf("Reversed string is: %s\n", str);

    return 0;
}