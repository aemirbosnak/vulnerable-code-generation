//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: immersive
#include<stdio.h>
int main(){
  printf("Welcome to the Checksum Calculator\n");
  printf("===============================\n\n");
  //Prompting the user for input
  printf("Enter the number of elements for which checksum is to be calculated:");
  int n;
  scanf("%d", &n);

  //declaring and initializing the array
  int arr[n];
  printf("\nEnter %d elements:\n", n);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  //calculating the checksum
  int checksum=0;
  for(int i=0; i<n; i++){
    checksum+=arr[i];
  }
  printf("\nThe checksum of the given array is: %d\n", checksum);

  //prompting the user to check another array
  char input;
  printf("\nDo you want to check another array for checksum(y/n):");
  scanf(" %c", &input);
  printf("\n");

  //Another array calculation check
  while(input=='y' || input=='Y'){
    printf("===============================\n\n");
    printf("Enter the number of elements for which checksum is to be calculated:");
    int n1;
    scanf("%d", &n1);

    //declaring and initializing the array
    int arr1[n1];
    printf("\nEnter %d elements:\n", n1);
    for(int i=0; i<n1; i++){
      scanf("%d", &arr1[i]);
    }

    //calculating the checksum
    int checksum1=0;
    for(int i=0; i<n1; i++){
      checksum1+=arr1[i];
    }
    printf("\nThe checksum of the given array is: %d\n", checksum1);

    //prompting the user to check another array
    printf("\nDo you want to check another array for checksum(y/n):");
    scanf(" %c", &input);
    printf("\n");
  }

  printf("Thank you for using the Checksum Calculator!\n");
  return 0;
}