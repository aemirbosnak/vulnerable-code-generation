//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // generating a random temperature value
    int temp = rand() % 101; // temperature value between 0 and 100 (inclusive)
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int hour = tm->tm_hour;

    // display a unique message based on the temperature and time of day
    if (temp <= 32) {
        if (hour >= 6 && hour <= 11) {
            printf("Good morning! The temperature is currently %d degrees Fahrenheit. It's freezing outside, remember to wear a warm jacket.\n", temp);
        } else if (hour >= 12 && hour <= 17) {
            printf("Good afternoon! The temperature is currently %d degrees Fahrenheit. It's freezing outside, remember to wear a warm jacket.\n", temp);
        } else if (hour >= 18 && hour <= 23) {
            printf("Good evening! The temperature is currently %d degrees Fahrenheit. It's freezing outside, remember to wear a warm jacket.\n", temp);
        } else {
            printf("Good night! The temperature is currently %d degrees Fahrenheit. It's freezing outside, remember to wear a warm jacket.\n", temp);
        }
    } else if (temp >= 33 && temp <= 50) {
        if (hour >= 6 && hour <= 11) {
            printf("Good morning! The temperature is currently %d degrees Fahrenheit. It's a bit chilly outside, you might want to consider wearing a light jacket.\n", temp);
        } else if (hour >= 12 && hour <= 17) {
            printf("Good afternoon! The temperature is currently %d degrees Fahrenheit. It's a bit chilly outside, you might want to consider wearing a light jacket.\n", temp);
        } else if (hour >= 18 && hour <= 23) {
            printf("Good evening! The temperature is currently %d degrees Fahrenheit. It's a bit chilly outside, you might want to consider wearing a light jacket.\n", temp);
        } else {
            printf("Good night! The temperature is currently %d degrees Fahrenheit. It's a bit chilly outside, you might want to consider wearing a light jacket.\n", temp);
        }
    } else if (temp >= 51 && temp <= 70) {
        if (hour >= 6 && hour <= 11) {
            printf("Good morning! The temperature is currently %d degrees Fahrenheit. It's a nice comfortable temperature outside, perfect for a morning walk.\n", temp);
        } else if (hour >= 12 && hour <= 17) {
            printf("Good afternoon! The temperature is currently %d degrees Fahrenheit. It's a nice comfortable temperature outside, perfect for a midday stroll.\n", temp);
        } else if (hour >= 18 && hour <= 23) {
            printf("Good evening! The temperature is currently %d degrees Fahrenheit. It's a nice comfortable temperature outside, perfect for an evening walk.\n", temp);
        } else {
            printf("Good night! The temperature is currently %d degrees Fahrenheit. It's a nice comfortable temperature outside, perfect for sleeping with the windows open.\n", temp);
        }
    } else if (temp >= 71 && temp <= 90) {
        if (hour >= 6 && hour <= 11) {
            printf("Good morning! The temperature is currently %d degrees Fahrenheit. It's getting warm outside, make sure to stay hydrated if you're planning on being out for a while.\n", temp);
        } else if (hour >= 12 && hour <= 17) {
            printf("Good afternoon! The temperature is currently %d degrees Fahrenheit. It's getting warm outside, make sure to stay hydrated if you're planning on being out for a while.\n", temp);
        } else if (hour >= 18 && hour <= 23) {
            printf("Good evening! The temperature is currently %d degrees Fahrenheit. It's getting warm outside, make sure to stay hydrated if you're planning on being out for a while.\n", temp);
        } else {
            printf("Good night! The temperature is currently %d degrees Fahrenheit. It's getting warm outside, make sure to keep the fan or air conditioning on to ensure comfort.\n", temp);
        }
    } else {
        if (hour >= 6 && hour <= 11) {
            printf("Good morning! The temperature is currently %d degrees Fahrenheit. It's hot outside, make sure to stay cool and wear loose clothing.\n", temp);
        } else if (hour >= 12 && hour <= 17) {
            printf("Good afternoon! The temperature is currently %d degrees Fahrenheit. It's hot outside, make sure to stay cool and wear loose clothing.\n", temp);
        } else if (hour >= 18 && hour <= 23) {
            printf("Good evening! The temperature is currently %d degrees Fahrenheit. It's hot outside, make sure to stay cool and wear loose clothing.\n", temp);
        } else {
            printf("Good night! The temperature is currently %d degrees Fahrenheit. It's hot outside, make sure to keep the air conditioning on to ensure comfort while sleeping.\n", temp);
        }
    }

    return 0;
}