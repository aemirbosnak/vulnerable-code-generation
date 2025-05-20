//FormAI DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare necessary variables
    char hex[7];
    int r, g, b;

    // Prompt user for hex code input
    printf("Enter a 6-digit hex code: ");
    scanf("%6s", hex);

    // Parse and convert hex code to RGB values
    r = (int)strtol(hex, NULL, 16) >> 16;
    g = (int)strtol(hex + 2, NULL, 16) >> 8;
    b = (int)strtol(hex + 4, NULL, 16);

    // Output RGB values
    printf("RGB: %d, %d, %d\n", r, g, b);

    // Convert RGB values to CMY values
    double c = 1.0 - r / 255.0;
    double m = 1.0 - g / 255.0;
    double y = 1.0 - b / 255.0;

    // Output CMY values
    printf("CMY: %f, %f, %f\n", c, m, y);

    // Convert CMY values to HSV values
    double k = fmin(fmin(c, m), y);
    double h, s, v;
    if (k == 1.0) {
        h = s = v = 0;
    } else {
        double d = (c - k) / (1 - k);
        double e = (m - k) / (1 - k);
        double f = (y - k) / (1 - k);
        if (c == k) {
            h = fmod((5.0 + f - e), 6.0);
        } else if (m == k) {
            h = fmod((1.0 + d - f), 6.0);
        } else {
            h = fmod((3.0 + e - d), 6.0);
        }
        h *= 60.0;
        s = 1.0 - k;
        v = 1.0 - k * s;
    }

    // Output HSV values
    printf("HSV: %f, %f, %f\n", h, s, v);

    return 0;
}