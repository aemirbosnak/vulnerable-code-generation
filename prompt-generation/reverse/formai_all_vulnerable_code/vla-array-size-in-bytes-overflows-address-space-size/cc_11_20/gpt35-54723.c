//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine{
  char name[100];
  float price;
  int quantity;
  char manufacturer[100];
};

int main(){
  int n, choice, i, flag = 0;
  printf("Enter the number of medicines: ");
  scanf("%d", &n);
  struct medicine m[n];

  for(i = 0; i < n; i++){
    printf("Enter name of medicine %d: ", i+1);
    scanf("%s", m[i].name);
    printf("Enter price of medicine %d: ", i+1);
    scanf("%f", &m[i].price);
    printf("Enter quantity of medicine %d: ", i+1);
    scanf("%d", &m[i].quantity);
    printf("Enter manufacturer of medicine %d: ", i+1);
    scanf("%s", m[i].manufacturer);
  }

  while(1){
    printf("\nWhat would you like to do?\n1. Search for a medicine\n2. Add a new medicine\n3. Remove a medicine\n4. Display all medicines\n5. Exit\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:{
        char search[100];
        printf("Enter the name of medicine to search: ");
        scanf("%s", search);
        for(i = 0; i < n; i++){
          if(strcmp(search, m[i].name)==0){
            printf("\nMedicine Found!\nName: %s\nPrice: %f\nQuantity: %d\nManufacturer: %s", m[i].name, m[i].price, m[i].quantity, m[i].manufacturer);
            flag = 1;
            break;
          }
        }
        if(flag == 0) printf("\nMedicine not found!");
        break;
      }

      case 2:{
        n++;
        printf("Enter name of new medicine: ");
        scanf("%s", m[n-1].name);
        printf("Enter price of new medicine: ");
        scanf("%f", &m[n-1].price);
        printf("Enter quantity of new medicine: ");
        scanf("%d", &m[n-1].quantity);
        printf("Enter manufacturer of new medicine: ");
        scanf("%s", m[n-1].manufacturer);
        printf("\nNew medicine added successfully!");
        break;
      }

      case 3:{
        char del[100];
        printf("Enter the name of medicine to delete: ");
        scanf("%s", del);
        for(i = 0; i < n; i++){
          if(strcmp(del, m[i].name)==0){
            while(i < n-1){
              m[i] = m[i+1];
              i++;
            }
            n--;
            printf("\nMedicine deleted successfully!");
            break;
          }
        }
        if(i == n) printf("\nMedicine not found!");
        break;
      }

      case 4:{
        printf("\nList of all medicines:\n");
        for(i = 0; i < n; i++){
          printf("Name: %s\nPrice: %f\nQuantity: %d\nManufacturer: %s\n\n", m[i].name, m[i].price, m[i].quantity, m[i].manufacturer);
        }
        break;
      }

      case 5:{
        exit(0);
      }

      default:{
        printf("\nInvalid choice!");
      }
    }
  }
  return 0;
}