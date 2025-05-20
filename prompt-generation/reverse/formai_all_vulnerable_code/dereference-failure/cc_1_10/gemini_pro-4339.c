//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the temperature string.
#define MAX_TEMP_STR_SIZE 10

// Define the conversion formula.
#define FAHRENHEIT_TO_CELSIUS(f) ((f - 32) * 5 / 9)
#define CELSIUS_TO_FAHRENHEIT(c) ((c * 9 / 5) + 32)

// Define the error messages.
#define ERR_INVALID_TEMP_STR "Invalid temperature string."
#define ERR_INVALID_CONVERSION_TYPE "Invalid conversion type."

// Define the conversion types.
#define CONVERSION_TYPE_FAHRENHEIT_TO_CELSIUS "FtoC"
#define CONVERSION_TYPE_CELSIUS_TO_FAHRENHEIT "CtoF"

// Define the help message.
#define HELP_MESSAGE "Usage: temp_converter <temperature> <conversion_type>\n" \
                     "  temperature: The temperature to convert.\n" \
                     "  conversion_type: The conversion type (FtoC or CtoF).\n"

// Define the main function.
int main(int argc, char *argv[]) {
  // Check if the number of arguments is correct.
  if (argc != 3) {
    fprintf(stderr, "%s", HELP_MESSAGE);
    return EXIT_FAILURE;
  }

  // Get the temperature string and the conversion type.
  char *temp_str = argv[1];
  char *conversion_type = argv[2];

  // Check if the temperature string is valid.
  if (strlen(temp_str) > MAX_TEMP_STR_SIZE) {
    fprintf(stderr, "%s", ERR_INVALID_TEMP_STR);
    return EXIT_FAILURE;
  }

  // Check if the conversion type is valid.
  if (strcmp(conversion_type, CONVERSION_TYPE_FAHRENHEIT_TO_CELSIUS) != 0 && strcmp(conversion_type, CONVERSION_TYPE_CELSIUS_TO_FAHRENHEIT) != 0) {
    fprintf(stderr, "%s", ERR_INVALID_CONVERSION_TYPE);
    return EXIT_FAILURE;
  }

  // Convert the temperature.
  float temp;
  if (strcmp(conversion_type, CONVERSION_TYPE_FAHRENHEIT_TO_CELSIUS) == 0) {
    temp = FAHRENHEIT_TO_CELSIUS(atof(temp_str));
  } else {
    temp = CELSIUS_TO_FAHRENHEIT(atof(temp_str));
  }

  // Print the converted temperature.
  printf("%.2f\n", temp);

  return EXIT_SUCCESS;
}