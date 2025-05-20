//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare some funny variables
#define MAX_NAME_LENGTH 255
#define MIN_AGE 18
#define MAX_AGE 100
#define MIN_INCOME 10000
#define MAX_INCOME 100000

// Funny function to generate a name
char *generate_name(void)
{
    char *name = malloc(MAX_NAME_LENGTH * sizeof(char));
    int i = 0;

    // Generate a name that's a little too long
    while (i < MAX_NAME_LENGTH) {
        name[i] = (i % 2) ? 'A' : 'a';
        i++;
    }

    name[MAX_NAME_LENGTH] = '\0';
    return name;
}

// Funny function to generate an age
int generate_age(void)
{
    int age = rand() % (MAX_AGE - MIN_AGE) + MIN_AGE;

    // Make sure the age is at least 18 and less than 100
    if (age < MIN_AGE || age > MAX_AGE) {
        age = rand() % (MAX_AGE - MIN_AGE) + MIN_AGE;
    }

    return age;
}

// Funny function to generate an income
int generate_income(void)
{
    int income = rand() % (MAX_INCOME - MIN_INCOME) + MIN_INCOME;

    // Make sure the income is at least 10000 and less than 100000
    if (income < MIN_INCOME || income > MAX_INCOME) {
        income = rand() % (MAX_INCOME - MIN_INCOME) + MIN_INCOME;
    }

    return income;
}

int main(void)
{
    // Declare some funny variables
    char *name = generate_name();
    int age = generate_age();
    int income = generate_income();

    // Print out the funny details
    printf("Hey there, my name is %s, and I'm %d years old. I make %d dollars a year! \n", name, age, income);

    // Free the funny memory
    free(name);

    return 0;
}