//Gemma-7B DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define TEMP_FILE "/tmp/temperature.txt"

int main()
{
    FILE *fp;
    char temp_buffer[1024];
    char *temp_reading;
    int temp_value;
    struct stat sb;

    if ((fp = fopen(TEMP_FILE, "r")) == NULL)
    {
        fprintf(stderr, "Error opening file: %s", TEMP_FILE);
        exit(1);
    }

    if (stat(TEMP_FILE, &sb) != 0)
    {
        fprintf(stderr, "Error checking file status: %s", TEMP_FILE);
        exit(1);
    }

    if (sb.st_size == 0)
    {
        fprintf(stderr, "File is empty: %s", TEMP_FILE);
        exit(1);
    }

    rewind(fp);
    temp_reading = fgets(temp_buffer, 1024, fp);

    if (temp_reading == NULL)
    {
        fprintf(stderr, "Error reading file: %s", TEMP_FILE);
        exit(1);
    }

    temp_value = atoi(temp_reading);

    printf("Current temperature: %d degrees Celsius\n", temp_value);

    fclose(fp);

    return 0;
}