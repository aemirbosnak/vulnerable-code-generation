//FormAI DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  int rating;
  bool isGood = false;
  
  printf("Welcome to the C Movie Rating System!\n");
  printf("Please rate the movie on a scale of 1 to 10: ");
  scanf("%d", &rating);
  
  if(rating >= 7){
    isGood = true;
    
    printf("Excellent! This movie is definitely worth watching again!\n");
    printf("Would you like to leave a review? (Y/N): ");
    
    char choice;
    scanf(" %c", &choice);
    
    if(choice == 'Y' || choice == 'y'){
      char* review = malloc(100 * sizeof(char));
      
      printf("Great! Please leave your review: ");
      scanf("%s", review);
      
      printf("Thank you for your review: %s\n", review);
    }
    else{
      printf("No problem! Enjoy the movie!\n");
    }
  }
  else if(rating >= 4 && rating < 7){
    printf("Not bad, but could be better. Would you like to leave a review? (Y/N): ");
    
    char choice;
    scanf(" %c", &choice);
    
    if(choice == 'Y' || choice == 'y'){
      char* review = malloc(100 * sizeof(char));
      
      printf("Please leave your review: ");
      scanf("%s", review);
      
      printf("Thank you for your review: %s\n", review);
    }
    else{
      printf("No problem! Enjoy the movie!\n");
    }
  }
  else{
    printf("Sorry to hear that the movie wasn't up to your standards. Better luck next time!\n");
  }
  
  return 0;
}