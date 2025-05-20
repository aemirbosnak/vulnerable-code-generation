//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining the candidate structure
typedef struct{
  char name[50];
  int votes;
}Candidate;

//Display the menu to the user
void display_menu(){
  printf("Welcome to the Electronic Voting System!\n");
  printf("1. Add Candidate\n");
  printf("2. Vote for Candidate\n");
  printf("3. View Results\n");
  printf("4. Exit System\n");
  printf("Enter your choice: ");
}

int main(){
  int num_candidates = 0;
  int num_votes = 0;

  //Getting the total number of candidates
  printf("Enter the number of candidates: ");
  scanf("%d", &num_candidates);
  
  //Creating an array of candidates
  Candidate candidates[num_candidates];
  
  //Initializing the candidates array
  for(int i = 0; i < num_candidates; i++){
    strcpy(candidates[i].name, "");
    candidates[i].votes = 0;
  }

  //Displaying the menu to the user
  int choice;
  do{
    display_menu();
    scanf("%d", &choice);

    switch(choice){
      case 1:
        //Add a candidate
        printf("Enter the name of the candidate: ");
        char name[50];
        scanf("%s", name);

        //Checking if the candidate already exists
        int already_exists = 0;
        for(int i = 0; i < num_candidates; i++){
          if(strcmp(candidates[i].name, name) == 0){
            already_exists = 1;
            printf("Candidate already exists!\n");
            break;
          }
        }

        if(!already_exists){
          strcpy(candidates[num_votes].name, name);
          num_votes++;
          printf("Candidate added successfully!\n");
        }
        break;

      case 2:
        //Vote for a candidate
        printf("Enter the name of the candidate you want to vote for: ");
        char cname[50];
        scanf("%s", cname);

        //Checking if the candidate exists
        int exists = 0;
        for(int i = 0; i < num_candidates; i++){
          if(strcmp(candidates[i].name, cname) == 0){
            candidates[i].votes++;
            exists = 1;
            printf("Vote recorded successfully!\n");
            break;
          }
        }

        if(!exists){
          printf("Candidate does not exist!\n");
        }
        else{
          num_votes++;
        }
        break;

      case 3:
        //View the results
        printf("Candidate - Votes\n");
        for(int i = 0; i < num_candidates; i++){
          printf("%s - %d\n", candidates[i].name, candidates[i].votes);
        }
        break;

      case 4:
        //Exit the system
        printf("Exiting Electronic Voting System...\n");
        break;

      default:
        printf("Invalid choice! Try again.\n");
    }
  }while(choice != 4);

  return 0;
}