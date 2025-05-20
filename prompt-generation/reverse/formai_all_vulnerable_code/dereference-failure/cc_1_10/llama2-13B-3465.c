//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Function to read a name and age from the user
void get_name_age(char **name, int *age) {
    printf("Welcome to the Intelligent File Handling Program! Please enter your name: ");
    fgets(*name, MAX_NAME_LENGTH, stdin);
    *age = get_age();
}

// Function to get the user's age
int get_age() {
    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);
    return age;
}

// Function to create a file with the user's name and age
void create_file(char *name, int age) {
    char *filename = malloc(sizeof(name) + sizeof(age));
    sprintf(filename, "%s%d.txt", name, age);
    FILE *file = fopen(filename, "w");
    fprintf(file, "%s%d\n", name, age);
    fclose(file);
}

// Function to read a file and print the name and age
void read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[100];
    fgets(line, 100, file);
    char *name = strtok(line, " ");
    int age = atoi(name + strlen(name) - 1);
    printf("Name: %s, Age: %d\n", name, age);
    fclose(file);
}

int main() {
    char *name;
    int age;
    get_name_age(&name, &age);
    create_file(name, age);
    read_file(name);
    return 0;
}