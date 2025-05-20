//FormAI DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define CELSIUS_TO_FAHRENHEIT(celsius) ((celsius * 9.0 / 5.0) + 32.0)
#define FAHRENHEIT_TO_CELSIUS(fahrenheit) ((fahrenheit - 32.0) * 5.0 / 9.0)
#define KILOMETERS_TO_MILES(km) (km * 0.621371)
#define MILES_TO_KILOMETERS(miles) (miles / 0.621371)
#define KILOGRAMS_TO_POUNDS(kg) (kg * 2.20462)
#define POUNDS_TO_KILOGRAMS(pounds) (pounds / 2.20462)

void *do_conversion(void *arg);

int main()
{
    pthread_t threads[3];
    int rc;
    long t;
    float data[3][2] = {{20.0, 35.0}, {10.0, 20.0}, {15.0, 30.0}};

    for(t=0;t<3;t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, do_conversion, (void *)data[t]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for(t=0;t<3;t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads completed\n");

    pthread_exit(NULL);
}

void *do_conversion(void *arg)
{
    float *data;
    data = (float*) arg;

    float celsius = data[0];
    float fahrenheit = CELSIUS_TO_FAHRENHEIT(celsius);
    float km = data[1];
    float miles = KILOMETERS_TO_MILES(km);
    float kg = data[2];
    float pounds = KILOGRAMS_TO_POUNDS(kg);

    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f kilometers is equal to %.2f miles\n", km, miles);
    printf("%.2f kilograms is equal to %.2f pounds\n", kg, pounds);

    pthread_exit(NULL);
}