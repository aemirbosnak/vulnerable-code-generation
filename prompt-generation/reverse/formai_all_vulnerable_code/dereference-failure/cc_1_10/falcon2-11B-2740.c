//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval begin, end;

void getTime(void)
{
    gettimeofday(&begin, NULL);
}

float monitorTemperature(int objectID)
{
    float temperature;
    int i = 0;

    getTime();

    while (i < 1000)
    {
        sleep(1);
        getTime();

        if (end.tv_usec - begin.tv_usec < 1000000)
        {
            temperature = ((float)end.tv_sec - begin.tv_sec) * 1000 + (float)end.tv_usec - (float)begin.tv_usec;
            break;
        }
        else
        {
            getTime();
        }
    }

    return temperature;
}

int main(int argc, char **argv)
{
    int objectID = 0;

    if (argc > 1)
    {
        objectID = atoi(argv[1]);
    }

    float temperature = monitorTemperature(objectID);

    printf("Temperature of object %d: %.2f degrees Celsius\n", objectID, temperature);

    return 0;
}