//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
  char name[50];
  int quantity;
  float price;
  float dosage;
  char side_effects[100];
} medicine;

typedef struct customer {
  char name[50];
  int age;
  char gender[10];
  char address[100];
  long int contact;
  char prescription[100];
} customer;

void add_medicine(medicine *med_arr, int num_meds) {
  for(int i = 0; i < num_meds; i++) {
    printf("\nEnter Name of Medicine %d: ", i+1);
    scanf("%s", med_arr[i].name);
    printf("Enter Quantity of Medicine %d: ", i+1);
    scanf("%d", &med_arr[i].quantity);
    printf("Enter Price of Medicine %d: ", i+1);
    scanf("%f", &med_arr[i].price);
    printf("Enter Dosage of Medicine %d: ", i+1);
    scanf("%f", &med_arr[i].dosage);
    printf("Enter Side Effects of Medicine %d: ", i+1);
    scanf("%s", med_arr[i].side_effects);
  }
}

void view_medicines(medicine *med_arr, int num_meds) {
  printf("\nName\tQuantity\tPrice\tDosage\tSide Effects\n------------------------------------------------------\n");
  for(int i = 0; i < num_meds; i++) {
    printf("%s\t%d\t\t%.2f\t%.2f\t%s\n", med_arr[i].name, med_arr[i].quantity, med_arr[i].price, med_arr[i].dosage, med_arr[i].side_effects);
  }
  printf("------------------------------------------------------\n");
}

int sell_medicine(medicine *med_arr, int num_meds, char *med_name, int med_quant) {
  int found_flag = 0;
  for(int i = 0; i < num_meds; i++) {
    if(strcmp(med_arr[i].name, med_name) == 0 && med_arr[i].quantity >= med_quant) {
      med_arr[i].quantity -= med_quant;
      printf("\nMedicine Sold Successfully!\n");
      printf("Medicine: %s\tQuantity: %d\tTotal Cost: %.2f\n", med_name, med_quant, (med_arr[i].price * med_quant));
      found_flag = 1;
      break;
    }
  }
  if(!found_flag) {
    printf("\nMedicine Not Available or Required Quantity is not Available!\n");
  }
  return found_flag;
}

void view_customers(customer *cust_arr, int num_cust) {
  printf("\nName\tAge\tGender\tAddress\t\t\tContact\tPrescription\n-------------------------------------------------------------------------------------------\n");
  for(int i = 0; i < num_cust; i++) {
    printf("%s\t%d\t%s\t%s\t%ld\t%s\n", cust_arr[i].name, cust_arr[i].age, cust_arr[i].gender,
      cust_arr[i].address, cust_arr[i].contact, cust_arr[i].prescription);
  }
  printf("-------------------------------------------------------------------------------------------\n");
}

void add_customer(customer *cust_arr, int num_cust) {
  for(int i = 0; i < num_cust; i++) {
    printf("\nEnter Customer Name %d: ", i+1);
    scanf("%s", cust_arr[i].name);
    printf("Enter Customer Age %d: ", i+1);
    scanf("%d", &cust_arr[i].age);
    printf("Enter Customer Gender %d: ", i+1);
    scanf("%s", cust_arr[i].gender);
    printf("Enter Customer Address %d: ", i+1);
    scanf("%s", cust_arr[i].address);
    printf("Enter Customer Contact %d: ", i+1);
    scanf("%ld", &cust_arr[i].contact);
    printf("Enter Customer Prescription %d: ", i+1);
    scanf("%s", cust_arr[i].prescription);
  }
}

int main() {
  printf("Welcome to the Surreal Medical Store Management System!\n");

  int num_meds, num_cust, user_choice;
  char med_name[50];
  int med_quant;
  
  printf("\nEnter Total Number of Medicines: ");
  scanf("%d", &num_meds);

  medicine *med_arr = (medicine *)malloc(num_meds * sizeof(medicine));
  add_medicine(med_arr, num_meds);

  printf("\nEnter Total Number of Customers: ");
  scanf("%d", &num_cust);

  customer *cust_arr = (customer *)malloc(num_cust * sizeof(customer));
  add_customer(cust_arr, num_cust);

  while(1) {
    printf("\nSelect Operation:\n1. View Medicines\n2. Sell Medicine\n3. View Customers\n4. Exit\n");
    scanf("%d", &user_choice);
    switch(user_choice) {
      case 1:
        view_medicines(med_arr, num_meds);
        break;
      case 2:
        printf("\nEnter Name of Medicine: ");
        scanf("%s", med_name);
        printf("Enter Quantity: ");
        scanf("%d", &med_quant);
        sell_medicine(med_arr, num_meds, med_name, med_quant);
        break;
      case 3:
        view_customers(cust_arr, num_cust);
        break;
      case 4:
        printf("\nThank you for choosing Surreal Medical Store! Exiting...\n");
        exit(0);
      default:
        printf("\nInvalid Choice! Try Again.\n");
    }
  }
  
  free(med_arr);
  free(cust_arr);

  return 0;
}