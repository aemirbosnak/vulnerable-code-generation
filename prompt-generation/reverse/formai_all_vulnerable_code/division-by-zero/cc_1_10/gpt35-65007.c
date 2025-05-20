//FormAI DATASET v1.0 Category: Memory management ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
   int userInput, *dynamicArray, i, upperBound, temp, j;
   float squareRoot;

// User Input to determine size of dynamic array and upper bound for random numbers
   printf("Enter the size of the dynamic array: ");
   scanf("%d", &userInput);
   printf("\nEnter the upper bound for the random numbers: ");
   scanf("%d", &upperBound);

// Dynamically allocating memory for the array
   dynamicArray = (int*)malloc(userInput * sizeof(int));

// Random number generation and insertion into the dynamic array
   for(i = 0; i < userInput; i++){
      *(dynamicArray + i) = rand() % upperBound + 1;
   }

//Displaying the unsorted dynamic array
   printf("\nUnsorted Dynamic Array:\n");
   for(i = 0; i < userInput; i++){
      printf("%d ", *(dynamicArray + i));
   }


//Bubble Sorting the dynamic array
   for(i = 0; i < userInput - 1; i++){
      for(j = 0; j < userInput - i - 1; j++){
         if(*(dynamicArray + j) > *(dynamicArray + (j+1))){
            temp = *(dynamicArray + j);
            *(dynamicArray + j) = *(dynamicArray + (j+1));
            *(dynamicArray + (j+1)) = temp;
         }
      }
   }

//Displaying the sorted dynamic array
   printf("\n\nSorted Dynamic Array:\n");
   for(i = 0; i < userInput; i++){
      printf("%d ", *(dynamicArray + i));
   }

//Calculating and displaying the square roots of all elements in the array
  printf("\n\nSquare Roots of all elements in the Dynamic Array:\n");
  for(i = 0; i < userInput; i++){
     squareRoot = sqrt(*(dynamicArray + i));
     printf("%.2f ", squareRoot);
  }

//Freeing up the dynamically allocated memory of the array
   free(dynamicArray);
   return 0;
}