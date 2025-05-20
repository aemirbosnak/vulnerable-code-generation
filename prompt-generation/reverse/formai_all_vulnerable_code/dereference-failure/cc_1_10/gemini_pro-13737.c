//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

enum {
  CM_TO_INCH = 1,
  INCH_TO_CM = 2,
  KG_TO_POUND = 3,
  POUND_TO_KG = 4,
  CELSIUS_TO_FAHRENHEIT = 5,
  FAHRENHEIT_TO_CELSIUS = 6,
  LITRE_TO_GALLON = 7,
  GALLON_TO_LITRE = 8,
};

struct unit_converter {
  char *name;
  double (*converter)(double);
};

double cm_to_inch(double cm) {
  return cm * 0.393701;
}

double inch_to_cm(double inch) {
  return inch * 2.54;
}

double kg_to_pound(double kg) {
  return kg * 2.20462;
}

double pound_to_kg(double pound) {
  return pound * 0.453592;
}

double celsius_to_fahrenheit(double celsius) {
  return celsius * 9 / 5 + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double litre_to_gallon(double litre) {
  return litre * 0.264172;
}

double gallon_to_litre(double gallon) {
  return gallon * 3.78541;
}

struct unit_converter converters[] = {
  { "Centimeters to Inches", cm_to_inch },
  { "Inches to Centimeters", inch_to_cm },
  { "Kilograms to Pounds", kg_to_pound },
  { "Pounds to Kilograms", pound_to_kg },
  { "Celsius to Fahrenheit", celsius_to_fahrenheit },
  { "Fahrenheit to Celsius", fahrenheit_to_celsius },
  { "Litres to Gallons", litre_to_gallon },
  { "Gallons to Litres", gallon_to_litre },
};

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value> <from> <to>\n", argv[0]);
    return EXIT_FAILURE;
  }

  double value = atof(argv[1]);
  int from = atoi(argv[2]);
  int to = atoi(argv[3]);

  if (from < 1 || from > 8 || to < 1 || to > 8) {
    printf("Invalid unit conversion specified\n");
    return EXIT_FAILURE;
  }

  double result = converters[from - 1].converter(value);
  result = converters[to - 1].converter(result);

  printf("%f %s is equal to %f %s\n", value, converters[from - 1].name, result, converters[to - 1].name);

  return EXIT_SUCCESS;
}