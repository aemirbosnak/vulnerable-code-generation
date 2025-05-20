//FormAI DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to Check if the Database is Full
int isDatabaseFull(int count, int capacity){
  return count == capacity;
}

//Function to Check if the Database is Empty
int isDatabaseEmpty(int count){
  return count == 0;
}

//Function to Add Data to the Database
void addData(int *count, int *capacity, int **database, int data){
  if(isDatabaseFull(*count, *capacity)){
    (*capacity) *= 2;
    *database = realloc(*database, (*capacity) * sizeof(int));
  }
  (*database)[(*count)++] = data;
  printf("Data Added Successfully!\n");
}

//Function to Print Data in the Database
void printData(int *count, int **database){
  if(isDatabaseEmpty(*count)){
    printf("The Database is Empty!\n");
    return;
  }
  printf("Data in the Database:\n");
  for(int i = 0; i < *count; i++){
    printf("%d ", (*database)[i]);
  }
  printf("\n");
}

//Function to Delete Data from the Database
void deleteData(int *count, int **database){
  if(isDatabaseEmpty(*count)){
    printf("The Database is Empty!\n");
    return;
  }
  (*count)--;
  printf("Data Deleted Successfully!\n");
}

int main(){
  int capacity = 5; //Initial Capacity of the Database
  int count = 0; //Counter for Number of Data in the Database
  int *database = malloc(capacity * sizeof(int)); //Dynamic Memory Allocation for Database
  
  //Adding Data to the Database
  addData(&count, &capacity, &database, 10);
  addData(&count, &capacity, &database, 20);
  addData(&count, &capacity, &database, 30);
  addData(&count, &capacity, &database, 40);
  addData(&count, &capacity, &database, 50);
  
  //Printing Data in the Database
  printData(&count, &database);
  
  //Deleting Data from the Database
  deleteData(&count, &database);
  
  //Printing Data in the Database
  printData(&count, &database);
  
  return 0;
}