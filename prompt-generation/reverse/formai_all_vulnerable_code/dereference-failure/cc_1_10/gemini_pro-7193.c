//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Declare the data structures
typedef struct {
  int age;
  char gender;
  char occupation[50];
  double salary;
} Person;

typedef struct {
  int num_customers;
  Person *customers;
} Company;

// Declare the functions
void print_person(Person *person);
void print_company(Company *company);
void analyze_data(Company *company);

// Define the main function
int main() {
  // Create a company
  Company company;
  company.num_customers = 5;
  company.customers = (Person *)malloc(sizeof(Person) * company.num_customers);

  // Initialize the customers
  Person customer1 = {25, 'M', "Software Engineer", 100000};
  Person customer2 = {30, 'F', "Doctor", 150000};
  Person customer3 = {35, 'M', "Lawyer", 120000};
  Person customer4 = {40, 'F', "Teacher", 80000};
  Person customer5 = {45, 'M', "Manager", 110000};

  company.customers[0] = customer1;
  company.customers[1] = customer2;
  company.customers[2] = customer3;
  company.customers[3] = customer4;
  company.customers[4] = customer5;

  // Print the company
  printf("Company:\n");
  print_company(&company);

  // Analyze the data
  analyze_data(&company);

  return 0;
}

// Define the function to print a person
void print_person(Person *person) {
  printf("Age: %d\n", person->age);
  printf("Gender: %c\n", person->gender);
  printf("Occupation: %s\n", person->occupation);
  printf("Salary: %.2f\n", person->salary);
}

// Define the function to print a company
void print_company(Company *company) {
  for (int i = 0; i < company->num_customers; i++) {
    print_person(&company->customers[i]);
    printf("\n");
  }
}

/**************************** WARNING: FUNKY CODE AHEAD! ****************************/

// Define the function to analyze the data
void analyze_data(Company *company) {
  // Find the average age
  double average_age = 0;
  for (int i = 0; i < company->num_customers; i++) {
    average_age += company->customers[i].age;
  }
  average_age /= company->num_customers;

  // Find the average salary
  double average_salary = 0;
  for (int i = 0; i < company->num_customers; i++) {
    average_salary += company->customers[i].salary;
  }
  average_salary /= company->num_customers;

  // Find the most common occupation
  char most_common_occupation[50];
  int max_count = 0;
  for (int i = 0; i < company->num_customers; i++) {
    char *occupation = company->customers[i].occupation;
    int count = 0;
    for (int j = 0; j < company->num_customers; j++) {
      if (strcmp(occupation, company->customers[j].occupation) == 0) {
        count++;
      }
    }
    if (count > max_count) {
      max_count = count;
      strcpy(most_common_occupation, occupation);
    }
  }

  // Print the results
  printf("Average age: %.2f\n", average_age);
  printf("Average salary: %.2f\n", average_salary);
  printf("Most common occupation: %s\n", most_common_occupation);
}