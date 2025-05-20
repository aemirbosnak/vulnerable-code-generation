//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define F_TO_C(x) ((x) - 32.0 * 5.0 / 9.0)
#define C_TO_F(x) ((x) * 9.0 / 5.0 + 32.0)

typedef enum { FAHRENHEIT, CELSIUS } temp_unit_t;

struct temp_conv {
    char str[10];
    temp_unit_t unit;
    double value;
};

void convert_temp(struct temp_conv* temp, temp_unit_t to_unit) {
    if (temp->unit == FAHRENHEIT) {
        temp->value = C_TO_F(temp->value);
    }

    if (temp->unit == CELSIUS) {
        temp->value = F_TO_C(temp->value);
    }

    temp->unit = to_unit;
}

int main(int argc, char* argv[]) {
    int i;
    struct temp_conv temp_arr[] = {
        {"37.5", FAHRENHEIT, 0.0},
        {"100.0", CELSIUS, 0.0},
        {"50.0", FAHRENHEIT, 0.0},
        {"25.0", CELSIUS, 0.0}
    };

    if (argc != 3) {
        printf("Usage: %s <temperature> <unit>\n", argv[0]);
        return 1;
    }

    for (i = 0; i < sizeof(temp_arr) / sizeof(struct temp_conv); i++) {
        if (strcmp(argv[1], temp_arr[i].str) == 0) {
            if (isdigit(argv[2][0])) {
                temp_arr[i].value = atof(argv[2]);
                temp_arr[i].unit = (strcmp(argv[2], "F") == 0) ? FAHRENHEIT : CELSIUS;
            } else {
                printf("Invalid temperature unit '%s'. Use F or C.\n", argv[2]);
                return 1;
            }
            break;
        }
    }

    if (i == sizeof(temp_arr) / sizeof(struct temp_conv)) {
        printf("Temperature '%s' not found.\n", argv[1]);
        return 1;
    }

    printf("Original temperature: %.2f %s\n", temp_arr[i].value,
           temp_arr[i].unit == FAHRENHEIT ? "F" : "C");

    convert_temp(&temp_arr[i], FAHRENHEIT);
    printf("Fahrenheit: %.2f F\n", temp_arr[i].value);

    convert_temp(&temp_arr[i], CELSIUS);
    printf("Celsius: %.2f C\n", temp_arr[i].value);

    return 0;
}