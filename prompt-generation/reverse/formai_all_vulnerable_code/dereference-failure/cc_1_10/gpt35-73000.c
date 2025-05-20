//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_UNITS 5

void displayUnitMenu();
void promptForQuantity(char quantity[], int maxLength);
void promptForConversion(float* value);
void promptForUnit(int* unit);
void convert(float* value, int unitFrom, int unitTo);
float celsiusToFahrenheit(float value);
float fahrenheitToCelsius(float value);
float metersToFeet(float value);
float feetToMeters(float value);
float kilogramsToPounds(float value);
float poundsToKilograms(float value);
float litersToGallons(float value);
float gallonsToLiters(float value);

int main()
{
    int unitFrom, unitTo;
    float value;
    char quantity[20];

    while (1)
    {
        displayUnitMenu();
        promptForQuantity(quantity, 20);

        if (strcmp(quantity, "exit") == 0)
        {
            printf("Exiting...\n");
            break;
        }
        else if (strcmp(quantity, "temperature") == 0)
        {
            promptForConversion(&value);
            promptForUnit(&unitFrom);
            promptForUnit(&unitTo);
            convert(&value, unitFrom, unitTo);
        }
        else if (strcmp(quantity, "length") == 0)
        {
            promptForConversion(&value);
            promptForUnit(&unitFrom);
            promptForUnit(&unitTo);
            convert(&value, unitFrom, unitTo);
        }
        else if (strcmp(quantity, "weight") == 0)
        {
            promptForConversion(&value);
            promptForUnit(&unitFrom);
            promptForUnit(&unitTo);
            convert(&value, unitFrom, unitTo);
        }
        else if (strcmp(quantity, "volume") == 0)
        {
            promptForConversion(&value);
            promptForUnit(&unitFrom);
            promptForUnit(&unitTo);
            convert(&value, unitFrom, unitTo);
        }
        else
        {
            printf("Invalid quantity selected.\n");
        }
    }

    return 0;
}

void displayUnitMenu()
{
    printf("\nAvailable unit conversions:\n");
    printf("1. Temperature\n");
    printf("2. Length\n");
    printf("3. Weight\n");
    printf("4. Volume\n");
    printf("Type \"exit\" to end program.\n");
    printf("\n");
}

void promptForQuantity(char quantity[], int maxLength)
{
    printf("Select the quantity to convert: ");
    fgets(quantity, maxLength, stdin);

    // remove newline character if present
    if (quantity[strlen(quantity) - 1] == '\n')
    {
        quantity[strlen(quantity) - 1] = '\0';
    }

    printf("\n");
}

void promptForConversion(float* value)
{
    printf("Enter the value to convert: ");
    scanf("%f", value);
    getchar(); // clear the input buffer
}

void promptForUnit(int* unit)
{
    printf("Select the unit:\n");

    if (*unit == 0)
    {
        printf("0. Default\n");
    }

    printf("1. ");
    switch (*unit)
    {
    case 0:
        printf("Celsius\n");
        break;
    case 1:
        printf("Fahrenheit\n");
        break;
    case 2:
        printf("Meters\n");
        break;
    case 3:
        printf("Feet\n");
        break;
    case 4:
        printf("Kilograms\n");
        break;
    case 5:
        printf("Pounds\n");
        break;
    case 6:
        printf("Liters\n");
        break;
    case 7:
        printf("Gallons\n");
        break;
    }
    printf("2. ");

    switch (*unit)
    {
    case 0:
        printf("Fahrenheit\n");
        break;
    case 1:
        printf("Celsius\n");
        break;
    case 2:
        printf("Feet\n");
        break;
    case 3:
        printf("Meters\n");
        break;
    case 4:
        printf("Pounds\n");
        break;
    case 5:
        printf("Kilograms\n");
        break;
    case 6:
        printf("Gallons\n");
        break;
    case 7:
        printf("Liters\n");
        break;
    }
    printf("\n");

    printf("Enter the unit number: ");
    scanf("%d", unit);

    if (*unit < 0 || *unit >= NUMBER_OF_UNITS)
    {
        printf("Invalid unit selected. Defaulting to Celsius.\n");
        *unit = 0;
        printf("\n");
        return;
    }

    printf("\n");
}

void convert(float* value, int unitFrom, int unitTo)
{
    float result;

    if (unitFrom == unitTo)
    {
        printf("Conversion not necessary.\n");
        printf("\n");
        return;
    }

    switch (unitFrom)
    {
    case 0:
        if (unitTo == 1)
        {
            result = celsiusToFahrenheit(*value);
        }
        else
        {
            result = metersToFeet(*value);
        }
        break;
    case 1:
        if (unitTo == 0)
        {
            result = fahrenheitToCelsius(*value);
        }
        else
        {
            result = feetToMeters(*value);
        }
        break;
    case 2:
        if (unitTo == 3)
        {
            result = metersToFeet(*value);
        }
        else
        {
            result = kilogramsToPounds(*value);
        }
        break;
    case 3:
        if (unitTo == 2)
        {
            result = feetToMeters(*value);
        }
        else
        {
            result = poundsToKilograms(*value);
        }
        break;
    case 4:
        if (unitTo == 5)
        {
            result = kilogramsToPounds(*value);
        }
        else
        {
            result = litersToGallons(*value);
        }
        break;
    case 5:
        if (unitTo == 4)
        {
            result = poundsToKilograms(*value);
        }
        else
        {
            result = gallonsToLiters(*value);
        }
        break;
    case 6:
        result = gallonsToLiters(*value);
        break;
    case 7:
        result = litersToGallons(*value);
        break;
    }

    printf("%.2f ", *value);

    switch (unitFrom)
    {
    case 0:
        printf("Celsius");
        break;
    case 1:
        printf("Fahrenheit");
        break;
    case 2:
        printf("Meters");
        break;
    case 3:
        printf("Feet");
        break;
    case 4:
        printf("Kilograms");
        break;
    case 5:
        printf("Pounds");
        break;
    case 6:
        printf("Liters");
        break;
    case 7:
        printf("Gallons");
        break;
    }

    printf(" = ");

    printf("%.2f ", result);

    switch (unitTo)
    {
    case 0:
        printf("Celsius");
        break;
    case 1:
        printf("Fahrenheit");
        break;
    case 2:
        printf("Meters");
        break;
    case 3:
        printf("Feet");
        break;
    case 4:
        printf("Kilograms");
        break;
    case 5:
        printf("Pounds");
        break;
    case 6:
        printf("Liters");
        break;
    case 7:
        printf("Gallons");
        break;
    }

    printf("\n");
}

float celsiusToFahrenheit(float value)
{
    return ((value * 9 / 5) + 32);
}

float fahrenheitToCelsius(float value)
{
    return ((value - 32) * 5 / 9);
}

float metersToFeet(float value)
{
    return (value * 3.28084);
}

float feetToMeters(float value)
{
    return (value / 3.28084);
}

float kilogramsToPounds(float value)
{
    return (value * 2.20462);
}

float poundsToKilograms(float value)
{
    return (value / 2.20462);
}

float litersToGallons(float value)
{
    return (value * 0.264172);
}

float gallonsToLiters(float value)
{
    return (value / 0.264172);
}