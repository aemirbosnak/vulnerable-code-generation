//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_MONTHS 12
#define MAX_DAYS 31

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

char *months[MAX_MONTHS] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};

char *days[MAX_DAYS] = {"First", "Second", "Third", "Fourth", "Fifth",
                        "Sixth", "Seventh", "Eighth", "Ninth", "Tenth",
                        "Eleventh", "Twelfth", "Thirteenth", "Fourteenth", "Fifteenth",
                        "Sixteenth", "Seventeenth", "Eighteenth", "Nineteenth", "Twentieth",
                        "Twenty-first", "Twenty-second", "Twenty-third", "Twenty-fourth", "Twenty-fifth",
                        "Twenty-sixth", "Twenty-seventh", "Twenty-eighth", "Twenty-ninth", "Thirtieth",
                        "Thirty-first"};

int is_leap_year(int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int convert_month_to_number(char *month) {
    for(int i = 0; i < MAX_MONTHS; i++) {
        if(strcmp(month, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1;
}

char *convert_number_to_month(int n) {
    return months[n - 1];
}

void *convert_date(void* args) {
    pthread_mutex_lock(&mutex);

    char *input = (char *) args;

    char *month_str = strtok(input, " ");
    char *day_str = strtok(NULL, " ");
    char *year_str = strtok(NULL, " ");

    int month = convert_month_to_number(month_str);
    int day = atoi(day_str);
    int year = atoi(year_str);

    struct tm date = {0};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;

    time_t t = mktime(&date);

    char *output = ctime(&t);
    output[strlen(output) - 1] = '\0';

    printf("%s --> %s\n", input, output);

    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_DAYS];
    int thread_count = 0;

    char input[100];

    while(1) {
        printf("Enter a date in natural language (e.g. January Fifth Two Thousand Ten): ");
        fgets(input, sizeof(input), stdin);

        if(strcmp(input, "quit\n") == 0) {
            break;
        }

        pthread_create(&threads[thread_count], NULL, convert_date, input);
        thread_count++;

        pthread_join(threads[thread_count - 1], NULL);

        printf("Thread %d exited.\n", thread_count - 1);

        if(thread_count == MAX_DAYS) {
            printf("Maximum number of threads reached.\n");
            break;
        }
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}