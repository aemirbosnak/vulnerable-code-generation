//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: visionary
#include <stdio.h>

// A recursive function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// A recursive function to calculate the nth Fibonacci number
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

// A recursive function to reverse a string
void reverse_string(char *str) {
  if (*str == '\0') {
    return;
  } else {
    reverse_string(str + 1);
    printf("%c", *str);
  }
}

// A recursive function to print all the subsets of a set
void print_subsets(int *arr, int n) {
  if (n == 0) {
    printf("[]\n");
    return;
  } else {
    print_subsets(arr, n - 1);
    for (int i = 0; i < n; i++) {
      int *new_arr = malloc((n - 1) * sizeof(int));
      for (int j = 0; j < i; j++) {
        new_arr[j] = arr[j];
      }
      for (int j = i + 1; j < n; j++) {
        new_arr[j - 1] = arr[j];
      }
      printf("[");
      for (int j = 0; j < n - 1; j++) {
        printf("%d, ", new_arr[j]);
      }
      printf("%d]\n", new_arr[n - 2]);
      free(new_arr);
    }
  }
}

// A recursive function to find the maximum element in an array
int find_max(int *arr, int n) {
  if (n == 1) {
    return arr[0];
  } else {
    int max = find_max(arr + 1, n - 1);
    if (arr[0] > max) {
      return arr[0];
    } else {
      return max;
    }
  }
}

// A recursive function to find the minimum element in an array
int find_min(int *arr, int n) {
  if (n == 1) {
    return arr[0];
  } else {
    int min = find_min(arr + 1, n - 1);
    if (arr[0] < min) {
      return arr[0];
    } else {
      return min;
    }
  }
}

// A recursive function to find the sum of all the elements in an array
int sum_array(int *arr, int n) {
  if (n == 0) {
    return 0;
  } else {
    return arr[0] + sum_array(arr + 1, n - 1);
  }
}

// A recursive function to find the product of all the elements in an array
int product_array(int *arr, int n) {
  if (n == 0) {
    return 1;
  } else {
    return arr[0] * product_array(arr + 1, n - 1);
  }
}

// A recursive function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// A recursive function to find the least common multiple of two numbers
int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int main() {
  // Print the factorial of 5
  printf("Factorial of 5: %d\n", factorial(5));

  // Print the 10th Fibonacci number
  printf("10th Fibonacci number: %d\n", fibonacci(10));

  // Reverse the string "Hello"
  char str[] = "Hello";
  reverse_string(str);
  printf("\n");

  // Print all the subsets of the set {1, 2, 3}
  int arr[] = {1, 2, 3};
  print_subsets(arr, 3);

  // Find the maximum element in the array {1, 2, 3, 4, 5}
  int arr2[] = {1, 2, 3, 4, 5};
  printf("Maximum element in the array: %d\n", find_max(arr2, 5));

  // Find the minimum element in the array {1, 2, 3, 4, 5}
  printf("Minimum element in the array: %d\n", find_min(arr2, 5));

  // Find the sum of all the elements in the array {1, 2, 3, 4, 5}
  printf("Sum of all the elements in the array: %d\n", sum_array(arr2, 5));

  // Find the product of all the elements in the array {1, 2, 3, 4, 5}
  printf("Product of all the elements in the array: %d\n", product_array(arr2, 5));

  // Find the greatest common divisor of 12 and 18
  printf("Greatest common divisor of 12 and 18: %d\n", gcd(12, 18));

  // Find the least common multiple of 12 and 18
  printf("Least common multiple of 12 and 18: %d\n", lcm(12, 18));

  return 0;
}