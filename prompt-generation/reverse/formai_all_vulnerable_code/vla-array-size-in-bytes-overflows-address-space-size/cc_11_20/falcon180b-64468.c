//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

int main(){
   int n, i, j, k, temp, choice;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   int arr[n];

   printf("Enter the elements:\n");
   for(i=0; i<n; i++){
      scanf("%d", &arr[i]);
   }

   printf("\nBitwise Operations:\n");

   while(1){
      printf("\nEnter your choice:\n");
      printf("1. Bitwise AND\n");
      printf("2. Bitwise OR\n");
      printf("3. Bitwise XOR\n");
      printf("4. Bitwise NOT\n");
      printf("5. Exit\n");

      scanf("%d", &choice);

      switch(choice){
         case 1:{
            printf("\nEnter the position to start from: ");
            scanf("%d", &k);
            printf("Enter the number of elements to perform bitwise AND: ");
            scanf("%d", &temp);

            for(i=k-1; i<k-1+temp; i++){
               printf("%d ", arr[i]);
            }

            printf("\nBitwise AND of elements from position %d to %d is: %d\n", k, k+temp-1, arr[k-1] & arr[k-1+temp-1]);
            break;
         }

         case 2:{
            printf("\nEnter the position to start from: ");
            scanf("%d", &k);
            printf("Enter the number of elements to perform bitwise OR: ");
            scanf("%d", &temp);

            for(i=k-1; i<k-1+temp; i++){
               printf("%d ", arr[i]);
            }

            printf("\nBitwise OR of elements from position %d to %d is: %d\n", k, k+temp-1, arr[k-1] | arr[k-1+temp-1]);
            break;
         }

         case 3:{
            printf("\nEnter the position to start from: ");
            scanf("%d", &k);
            printf("Enter the number of elements to perform bitwise XOR: ");
            scanf("%d", &temp);

            for(i=k-1; i<k-1+temp; i++){
               printf("%d ", arr[i]);
            }

            printf("\nBitwise XOR of elements from position %d to %d is: %d\n", k, k+temp-1, arr[k-1] ^ arr[k-1+temp-1]);
            break;
         }

         case 4:{
            printf("\nEnter the position to start from: ");
            scanf("%d", &k);
            printf("Enter the number of elements to perform bitwise NOT: ");
            scanf("%d", &temp);

            for(i=k-1; i<k-1+temp; i++){
               printf("%d ", arr[i]);
            }

            printf("\nBitwise NOT of elements from position %d to %d is: ", k, k+temp-1);

            for(i=k-1; i<k-1+temp; i++){
               printf("%d ", ~arr[i]);
            }

            break;
         }

         case 5:{
            exit(0);
         }

         default:{
            printf("\nInvalid choice! Please try again.\n");
         }
      }
   }

   return 0;
}