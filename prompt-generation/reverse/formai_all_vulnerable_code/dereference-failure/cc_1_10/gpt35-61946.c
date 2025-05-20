//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate random conspiracy theory
char* generate_theory() {
    char* theories[10] = {"The moon landing was faked!", 
                        "The earth is actually flat!", 
                        "The government is hiding evidence of aliens!", 
                        "The Illuminati controls the world!", 
                        "The Titanic was sunk on purpose!", 
                        "Climate change is a hoax!", 
                        "9/11 was an inside job!", 
                        "COVID-19 was created in a lab!", 
                        "The Bermuda Triangle is actually a gateway to another dimension!", 
                        "The government is hiding the cure for cancer!"};
                        
    int random_num = rand() % 10;
    char* theory = malloc(strlen(theories[random_num]) + 1);
    strcpy(theory, theories[random_num]);
    return theory;
}

// Function to generate a random year
int generate_year() {
    int start_year = 1900;
    int current_year = 2021;
    int range = current_year - start_year + 1;
    int random_num = rand() % range;
    int year = start_year + random_num;
    return year;
}

// Function to generate a random name
char* generate_name() {
    char* names[10] = {"John", "Mary", "David", "Jessica", "Michael", "Linda", "Brian", "Emily", "Thomas", "Sophie"};
    int random_num = rand() % 10;
    char* name = malloc(strlen(names[random_num]) + 1);
    strcpy(name, names[random_num]);
    return name;
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Generate a random conspiracy theory
    char* theory = generate_theory();
    
    // Generate a random year
    int year = generate_year();
    
    // Generate a random name
    char* name = generate_name();
    
    // Print the conspiracy theory, year, and name
    printf("%s\n", theory);
    printf("This theory was first proposed in %d by %s.\n", year, name);
    
    // Free allocated memory
    free(theory);
    free(name);
    
    return 0;
}