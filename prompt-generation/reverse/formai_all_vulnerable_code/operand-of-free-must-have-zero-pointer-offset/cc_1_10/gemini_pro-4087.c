//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: irregular
// # Whatever the hell you want, this is a playground. Buckle up, buttercup!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// What is a unit converter? Who cares, let's make it rain!

// Yea yea, I know what you're thinking, "This is a mess!"
// But hey, who said a unit converter has to be neat?

// What is a unit anyway? It's just a fancy word for "number".
// So let's just convert some numbers, shall we?

// First, we need a way to organize all these conversion factors.
typedef struct {
    char *name;
    double factor;
} conversion_factor;

// Here are some common units:
conversion_factor units[] = {
    { .name = "feet", .factor = 0.3048 },
    { .name = "inches", .factor = 0.0254 },
    { .name = "miles", .factor = 1609.34 },
    { .name = "kilometers", .factor = 1000.0 },
    { .name = "pounds", .factor = 0.453592 },
    { .name = "kilograms", .factor = 1.0 },
    { .name = "fahrenheit", .factor = (5.0/9.0) },
    { .name = "celsius", .factor = 1.0 },
    { .name = "gallons", .factor = 3.78541 },
    { .name = "liters", .factor = 1.0 },
};

// How many units do we have? Who knows, let's count them!
int num_units = sizeof(units) / sizeof(units[0]);

// Now, let's get user input. But first, let's confuse them with some fancy schmancy options.

typedef enum {
    ONE,
    TWO,
    LIST,
    CONVERT,
    QUIT
} menu_option;

menu_option get_menu_option() {
    int option;
    printf("1. Enter a new unit\n2. Enter a conversion factor\n3. List all units\n4. Convert a value\n5. Quit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    return option;
}

// Now, let's get the actual data from the user.

void get_new_unit(char *name, double *factor) {
    printf("Enter the name of the new unit: ");
    scanf("%s", name);
    printf("Enter the conversion factor for the new unit: ");
    scanf("%lf", factor);
}

void get_conversion_factor(char *source, char *target, double *factor) {
    printf("Enter the source unit: ");
    scanf("%s", source);
    printf("Enter the target unit: ");
    scanf("%s", target);
    printf("Enter the conversion factor: ");
    scanf("%lf", factor);
}

// Let's not forget to free some memory later.

void free_memory(char *name, double *factor) {
    free(name);
    free(factor);
}

// Now, let's actually convert some values!

void convert_value() {
    char source[100], target[100];
    double value, converted_value;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the source unit: ");
    scanf("%s", source);
    printf("Enter the target unit: ");
    scanf("%s", target);

    // Let's find the corresponding units.
    int source_index = -1, target_index = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, source) == 0) {
            source_index = i;
        } else if (strcmp(units[i].name, target) == 0) {
            target_index = i;
        }
    }

    // Did we find them? If not, let's bail.
    if (source_index == -1 || target_index == -1) {
        printf("Invalid unit(s) entered.\n");
        return;
    }

    // Let's do the conversion!
    converted_value = value * units[source_index].factor / units[target_index].factor;

    // And finally, let's show the result.
    printf("%lf %s is equal to %lf %s\n", value, source, converted_value, target);
}

// And now, the main event!

int main() {

    menu_option option;
    char name[100];
    double factor;

    while ((option = get_menu_option()) != QUIT) {
        switch (option) {
            case ONE:
                get_new_unit(name, &factor);
                units[num_units].name = malloc(strlen(name) + 1);
                strcpy(units[num_units].name, name);
                units[num_units].factor = factor;
                num_units++;
                printf("New unit added.\n");
                break;
            case TWO:
                get_conversion_factor(name, name, &factor);
                printf("Conversion factor updated.\n");
                break;
            case LIST:
                printf("Available units:\n");
                for (int i = 0; i < num_units; i++) {
                    printf("%s\n", units[i].name);
                }
                break;
            case CONVERT:
                convert_value();
                break;
            case QUIT:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option entered.\n");
        }
    }

    // Let's clean up before we leave.
    for (int i = 0; i < num_units; i++) {
        free_memory(units[i].name, &units[i].factor);
    }

    return 0;
}