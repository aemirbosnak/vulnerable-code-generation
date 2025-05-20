//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 100

int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 2 || argc > 3)
    {
        printf("Usage: temp_monitor <device_file> [--verbose]\n");
        return 1;
    }

    // Open device file
    char *device_file = argv[1];
    FILE *device = fopen(device_file, "r");
    if (!device)
    {
        printf("Failed to open device file %s\n", device_file);
        return 2;
    }

    // Check verbose flag
    int verbose = 0;
    if (argc == 3 && strcmp(argv[2], "--verbose") == 0)
    {
        verbose = 1;
    }

    // Read temperature from device file
    char temp_str[MAX_TEMP];
    if (fgets(temp_str, MAX_TEMP, device) == NULL)
    {
        printf("Failed to read temperature from device file\n");
        fclose(device);
        return 3;
    }

    // Convert temperature string to integer
    int temp = atoi(temp_str);

    // Print temperature
    if (verbose)
    {
        printf("Temperature read from %s: %d\n", device_file, temp);
    }
    else
    {
        printf("%d\n", temp);
    }

    fclose(device);
    return 0;
}