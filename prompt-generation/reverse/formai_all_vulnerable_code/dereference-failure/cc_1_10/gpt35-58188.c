//FormAI DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>

typedef struct ConversionData
{
    float degrees;
    char unit;
}ConversionData;

void displayMenu(void)
{
    printf("Enter the type of conversion you'd like to do:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("5. Kelvin to Fahrenheit\n");
    printf("6. Fahrenheit to Kelvin\n");
}

void convertCelsiusToFahrenheit(float degreesCelsius)
{
    float degreesFahrenheit = (degreesCelsius * 9/5) + 32;

    printf("%f degrees Celsius is equal to %f degrees Fahrenheit\n", degreesCelsius, degreesFahrenheit);
}

void convertFahrenheitToCelsius(float degreesFahrenheit)
{
    float degreesCelsius = (degreesFahrenheit - 32) * 5/9;

    printf("%f degrees Fahrenheit is equal to %f degrees Celsius\n", degreesFahrenheit, degreesCelsius);
}

void convertKelvinToCelsius(float degreesKelvin)
{
    float degreesCelsius = degreesKelvin - 273.15;

    printf("%f degrees Kelvin is equal to %f degrees Celsius\n", degreesKelvin, degreesCelsius);
}

void convertCelsiusToKelvin(float degreesCelsius)
{
    float degreesKelvin = degreesCelsius + 273.15;

    printf("%f degrees Celsius is equal to %f degrees Kelvin\n", degreesCelsius, degreesKelvin);
}

void convertKelvinToFahrenheit(float degreesKelvin)
{
    float degreesFahrenheit = (degreesKelvin - 273.15) * 9/5 + 32;

    printf("%f degrees Kelvin is equal to %f degrees Fahrenheit\n", degreesKelvin, degreesFahrenheit);
}

void convertFahrenheitToKelvin(float degreesFahrenheit)
{
    float degreesKelvin = (degreesFahrenheit - 32) * 5/9 + 273.15;

    printf("%f degrees Fahrenheit is equal to %f degrees Kelvin\n", degreesFahrenheit, degreesKelvin);
}

void parseConversionData(ConversionData* data)
{
    printf("Enter degrees:\n");
    scanf("%f", &data->degrees);

    printf("Enter unit (C, F, K):\n");
    scanf(" %c", &data->unit);
}

void convert(ConversionData* data)
{
    switch(data->unit)
    {
        case 'C':
        case 'c':
            convertCelsiusToFahrenheit(data->degrees);
            convertCelsiusToKelvin(data->degrees);
            break;
        case 'F':
        case 'f':
            convertFahrenheitToCelsius(data->degrees);
            convertFahrenheitToKelvin(data->degrees);
            break;
        case 'K':
        case 'k':
            convertKelvinToCelsius(data->degrees);
            convertKelvinToFahrenheit(data->degrees);
            break;
        default:
            printf("Invalid unit of measurement.\n");
            break;
    }
}

void asyncConvert(void* arg)
{
    ConversionData* data = (ConversionData*)arg;

    convert(data);

    free(data);
}

int main(void)
{
    int conversionType;
    ConversionData* data;
    while(1)
    {
        displayMenu();
        scanf("%d", &conversionType);

        if(conversionType < 1 || conversionType > 6)
        {
            printf("Invalid selection.\n");
            continue;
        }

        data = (ConversionData*)malloc(sizeof(ConversionData));

        parseConversionData(data);

        switch (conversionType)
        {
            case 1:
                asyncConvert(data);
                break;
            case 2:
                asyncConvert(data);
                break;
            case 3:
                asyncConvert(data);
                break;
            case 4:
                asyncConvert(data);
                break;
            case 5:
                asyncConvert(data);
                break;
            case 6:
                asyncConvert(data);
                break;
            default:
                break;
        }
    }

    return 0;
}