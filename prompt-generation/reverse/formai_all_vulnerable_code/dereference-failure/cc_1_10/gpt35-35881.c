//FormAI DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define struct to hold data
typedef struct {
  int age;
  char gender;
  float height;
  float weight;
} Person;

int main() {
  int num_people = 5;
  
  // Allocate memory for array of Person structs
  Person* people = malloc(num_people * sizeof(Person));
  
  // Fill array with random data
  for(int i=0; i<num_people; i++) {
    people[i].age = rand() % 50 + 10;
    people[i].gender = rand() % 2 == 0 ? 'M' : 'F';
    people[i].height = (float)(rand() % 40 + 140) / 100;
    people[i].weight = (float)(rand() % 60 + 40) / 10;
  }
  
  // Print out data before filtering
  printf("Before filtering:\n");
  for(int i=0; i<num_people; i++) {
    printf("Person %d:\n", i+1);
    printf("Age: %d\n", people[i].age);
    printf("Gender: %c\n", people[i].gender);
    printf("Height: %.2f m\n", people[i].height);
    printf("Weight: %.2f kg\n", people[i].weight);
    printf("\n");
  }
  
  // Filter out people who are under 18 or over 30 and print out remaining data
  printf("After filtering:\n");
  int filtered_count = 0;
  for(int i=0; i<num_people; i++) {
    if(people[i].age >= 18 && people[i].age <= 30) {
      printf("Person %d:\n", i+1);
      printf("Age: %d\n", people[i].age);
      printf("Gender: %c\n", people[i].gender);
      printf("Height: %.2f m\n", people[i].height);
      printf("Weight: %.2f kg\n", people[i].weight);
      printf("\n");
      filtered_count++;
    }
  }
  
  // Print out number of people filtered
  printf("%d people were filtered out.\n", num_people - filtered_count);
  
  // Free allocated memory
  free(people);
  
  return 0;
}