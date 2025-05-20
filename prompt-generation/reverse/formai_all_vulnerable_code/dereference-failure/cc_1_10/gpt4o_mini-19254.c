//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double factor; // Factor to convert to base unit (meters for length, kilograms for weight, etc.)
} Unit;

typedef struct {
    char *category;
    Unit *units;
    size_t count;
} UnitCategory;

void initializeLengthUnits(UnitCategory *lengthCategory) {
    lengthCategory->category = "Length";
    lengthCategory->count = 5;
    lengthCategory->units = malloc(lengthCategory->count * sizeof(Unit));
    
    lengthCategory->units[0] = (Unit){"Meters", 1.0};
    lengthCategory->units[1] = (Unit){"Kilometers", 1000.0};
    lengthCategory->units[2] = (Unit){"Feet", 0.3048};
    lengthCategory->units[3] = (Unit){"Miles", 1609.34};
    lengthCategory->units[4] = (Unit){"Centimeters", 0.01};
}

void initializeWeightUnits(UnitCategory *weightCategory) {
    weightCategory->category = "Weight";
    weightCategory->count = 5;
    weightCategory->units = malloc(weightCategory->count * sizeof(Unit));
    
    weightCategory->units[0] = (Unit){"Kilograms", 1.0};
    weightCategory->units[1] = (Unit){"Grams", 0.001};
    weightCategory->units[2] = (Unit){"Pounds", 0.453592};
    weightCategory->units[3] = (Unit){"Ounces", 0.0283495};
    weightCategory->units[4] = (Unit){"Tons", 1000.0};
}

void initializeVolumeUnits(UnitCategory *volumeCategory) {
    volumeCategory->category = "Volume";
    volumeCategory->count = 5;
    volumeCategory->units = malloc(volumeCategory->count * sizeof(Unit));
    
    volumeCategory->units[0] = (Unit){"Liters", 1.0};
    volumeCategory->units[1] = (Unit){"Milliliters", 0.001};
    volumeCategory->units[2] = (Unit){"Gallons", 3.78541};
    volumeCategory->units[3] = (Unit){"Cubic Meters", 1000.0};
    volumeCategory->units[4] = (Unit){"Cubic Centimeters", 0.001};
}

void freeUnitCategory(UnitCategory *category) {
    free(category->units);
}

void printUnits(const UnitCategory *category) {
    printf("Units of %s:\n", category->category);
    for (size_t i = 0; i < category->count; ++i) {
        printf("%s\n", category->units[i].name);
    }
    printf("\n");
}

double convert(double value, Unit fromUnit, Unit toUnit) {
    // Convert from the 'fromUnit' to the base unit, then from the base to 'toUnit'
    return (value * fromUnit.factor) / toUnit.factor;
}

int main() {
    UnitCategory lengthUnits;
    UnitCategory weightUnits;
    UnitCategory volumeUnits;

    initializeLengthUnits(&lengthUnits);
    initializeWeightUnits(&weightUnits);
    initializeVolumeUnits(&volumeUnits);

    // Print available units
    printUnits(&lengthUnits);
    printUnits(&weightUnits);
    printUnits(&volumeUnits);

    while (1) {
        double value;
        int fromUnitIdx, toUnitIdx;
        char categoryChoice[10];

        printf("Enter the category of conversion (length, weight, volume, exit to quit): ");
        scanf("%s", categoryChoice);
        
        if (strcmp(categoryChoice, "exit") == 0) {
            break;
        }

        if (strcmp(categoryChoice, "length") == 0) {
            printf("Enter value to convert: ");
            scanf("%lf", &value);
            printf("Choose the unit to convert from (0: Meters, 1: Kilometers, 2: Feet, 3: Miles, 4: Centimeters): ");
            scanf("%d", &fromUnitIdx);
            printf("Choose the unit to convert to (0: Meters, 1: Kilometers, 2: Feet, 3: Miles, 4: Centimeters): ");
            scanf("%d", &toUnitIdx);
            double result = convert(value, lengthUnits.units[fromUnitIdx], lengthUnits.units[toUnitIdx]);
            printf("%.2f %s is equal to %.2f %s\n", value, lengthUnits.units[fromUnitIdx].name, result, lengthUnits.units[toUnitIdx].name);
        } else if (strcmp(categoryChoice, "weight") == 0) {
            printf("Enter value to convert: ");
            scanf("%lf", &value);
            printf("Choose the unit to convert from (0: Kilograms, 1: Grams, 2: Pounds, 3: Ounces, 4: Tons): ");
            scanf("%d", &fromUnitIdx);
            printf("Choose the unit to convert to (0: Kilograms, 1: Grams, 2: Pounds, 3: Ounces, 4: Tons): ");
            scanf("%d", &toUnitIdx);
            double result = convert(value, weightUnits.units[fromUnitIdx], weightUnits.units[toUnitIdx]);
            printf("%.2f %s is equal to %.2f %s\n", value, weightUnits.units[fromUnitIdx].name, result, weightUnits.units[toUnitIdx].name);
        } else if (strcmp(categoryChoice, "volume") == 0) {
            printf("Enter value to convert: ");
            scanf("%lf", &value);
            printf("Choose the unit to convert from (0: Liters, 1: Milliliters, 2: Gallons, 3: Cubic Meters, 4: Cubic Centimeters): ");
            scanf("%d", &fromUnitIdx);
            printf("Choose the unit to convert to (0: Liters, 1: Milliliters, 2: Gallons, 3: Cubic Meters, 4: Cubic Centimeters): ");
            scanf("%d", &toUnitIdx);
            double result = convert(value, volumeUnits.units[fromUnitIdx], volumeUnits.units[toUnitIdx]);
            printf("%.2f %s is equal to %.2f %s\n", value, volumeUnits.units[fromUnitIdx].name, result, volumeUnits.units[toUnitIdx].name);
        } else {
            printf("Unknown category. Please try again.\n");
        }
    }

    // Clean up
    freeUnitCategory(&lengthUnits);
    freeUnitCategory(&weightUnits);
    freeUnitCategory(&volumeUnits);
    return 0;
}