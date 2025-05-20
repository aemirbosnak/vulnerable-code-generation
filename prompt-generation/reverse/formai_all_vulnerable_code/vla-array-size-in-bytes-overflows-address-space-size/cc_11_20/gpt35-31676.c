//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include<stdio.h>
int main(){
  // Welcome Message
  printf("Hello there, I am a curious program that will sort your numbers in an interesting way! Let's get started!\n");

  // Prompt user to enter the number of elements
  printf("Please enter the number of numbers that you want to sort: ");
  
  int n;
  scanf("%d",&n);

  int arr[n];

  // Prompt user to enter the elements
  printf("\nPlease start entering the %d numbers one by one: ",n);

  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  // Sorting Algorithm
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(arr[i]%2==0 && arr[j]%2==1){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
      else if(arr[i]%2==0 && arr[j]%2==0){
        if(arr[i]<arr[j]){
          int temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
        }
      }
      else if(arr[i]%2==1 && arr[j]%2==1){
        if(arr[i]>arr[j]){
          int temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
        }
      }
      else{
        continue;
      }
    }
  }

  // Printing the sorted array
  printf("\nTa-Da! Here's your sorted array : ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }

  return 0;
}