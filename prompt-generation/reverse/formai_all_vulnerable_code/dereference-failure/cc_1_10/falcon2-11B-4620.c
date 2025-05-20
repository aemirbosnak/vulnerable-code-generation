//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/ioctl.h>

#define TEMP_FILE "/sys/bus/w1/devices/28-000005b01d00/w1_slave"
#define TEMP_CMP_FLAG '='
#define TEMP_CMP_DELIM ','

int main(void)
{
    struct stat st;
    char buffer[128];
    float temperature;

    // Open the file
    if (stat(TEMP_FILE, &st) == -1)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    // Read the first two lines from the file
    FILE *f = fopen(TEMP_FILE, "r");
    if (f == NULL)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }
    if (fgets(buffer, 128, f) == NULL)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        fclose(f);
        return 1;
    }
    if (fgets(buffer, 128, f) == NULL)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        fclose(f);
        return 1;
    }

    // Extract the temperature
    fclose(f);
    sscanf(buffer, "%s %f\n", buffer, &temperature);

    // Display the temperature
    printf("Temperature: %.2f\n", temperature);

    return 0;
}