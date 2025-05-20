//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 100

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the binomial coefficient
int binomial(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to generate a random string of length n
char *random_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}

// Function to count the number of occurrences of a character in a string
int count_char(const char *str, char c) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

// Function to find the mode of a string
char mode(const char *str) {
    int max_count = 0;
    char mode_char;
    for (int i = 0; str[i] != '\0'; i++) {
        int count = count_char(str, str[i]);
        if (count > max_count) {
            max_count = count;
            mode_char = str[i];
        }
    }
    return mode_char;
}

// Function to find the median of a string
char median(const char *str) {
    int len = strlen(str);
    if (len % 2 == 0) {
        return str[len / 2 - 1];
    } else {
        return str[len / 2];
    }
}

// Function to find the mean of a string
double mean(const char *str) {
    int sum = 0;
    int len = strlen(str);
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i] - 'a' + 1;
    }
    return (double)sum / len;
}

// Function to find the standard deviation of a string
double standard_deviation(const char *str) {
    double mean_val = mean(str);
    int sum_of_squared_differences = 0;
    int len = strlen(str);
    for (int i = 0; str[i] != '\0'; i++) {
        sum_of_squared_differences += pow(str[i] - 'a' + 1 - mean_val, 2);
    }
    return sqrt((double)sum_of_squared_differences / len);
}

// Function to print the frequency distribution of a string
void frequency_distribution(const char *str) {
    int len = strlen(str);
    int frequency[26] = {0};
    for (int i = 0; i < len; i++) {
        frequency[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, frequency[i]);
    }
}

int main() {
    // Generate a random string
    char *str = random_string(MAX_LEN);

    // Print the original string
    printf("Original string: %s\n", str);

    // Calculate the factorial of the length of the string
    int n = strlen(str);
    int factorial_n = factorial(n);
    printf("Factorial of the length of the string: %d\n", factorial_n);

    // Calculate the binomial coefficient of the length of the string
    int k = n / 2;
    int binomial_nk = binomial(n, k);
    printf("Binomial coefficient of the length of the string: %d\n", binomial_nk);

    // Count the number of occurrences of the first character in the string
    char c = str[0];
    int count_c = count_char(str, c);
    printf("Number of occurrences of the first character in the string: %d\n", count_c);

    // Find the mode of the string
    char mode_char = mode(str);
    printf("Mode of the string: %c\n", mode_char);

    // Find the median of the string
    char median_char = median(str);
    printf("Median of the string: %c\n", median_char);

    // Find the mean of the string
    double mean_val = mean(str);
    printf("Mean of the string: %.2f\n", mean_val);

    // Find the standard deviation of the string
    double standard_deviation_val = standard_deviation(str);
    printf("Standard deviation of the string: %.2f\n", standard_deviation_val);

    // Print the frequency distribution of the string
    printf("Frequency distribution of the string:\n");
    frequency_distribution(str);

    // Free the allocated memory
    free(str);

    return 0;
}