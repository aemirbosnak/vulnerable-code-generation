//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: safe
// Global variables for simple mathematical operations
int add = 0, subtract = 0, multiply = 0, divide = 0;
// Function prototypes
int Add(int a, int b);
int Subtract(int a, int b);
int Multiply(int a, int b);
int Divide(int a, int b);
// Helper function to handle errors
void Error(const char* message) {
  printf("Error: %s\n", message);
  exit(1);
}
// Program entry point
int main(int argc, char** argv) {
  // Validate input arguments
  if (argc != 5) {
    Error("Incorrect number of arguments.");
  }
  // Convert input arguments to integers
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  char op = argv[3][0];
  int expected_result = atoi(argv[4]);
  // Perform the specified operation
  int result = 0;
  switch (op) {
    case '+':
      result = Add(a, b);
      break;
    case '-':
      result = Subtract(a, b);
      break;
    case '*':
      result = Multiply(a, b);
      break;
    case '/':
      result = Divide(a, b);
      break;
    default:
      Error("Invalid operator.");
  }
  // Check if the result matches the expected value
  if (result != expected_result) {
    Error("Incorrect result.");
  }
  printf("Success: The result of %d %c %d is %d.\n", a, op, b, result);
  return 0;
}
// Simple addition function
int Add(int a, int b) {
  add++;
  return a + b;
}
// Simple subtraction function
int Subtract(int a, int b) {
  subtract++;
  return a - b;
}
// Simple multiplication function
int Multiply(int a, int b) {
  multiply++;
  return a * b;
}
// Simple division function
int Divide(int a, int b) {
  divide++;
  // Handle division by zero
  if (b == 0) {
    Error("Division by zero.");
  }
  return a / b;
}