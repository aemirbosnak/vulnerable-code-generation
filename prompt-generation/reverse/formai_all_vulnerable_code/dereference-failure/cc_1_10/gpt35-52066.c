//FormAI DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_NUM_PASSWORDS 10

char* password_list[MAX_NUM_PASSWORDS]; // Declare array of password strings
int num_passwords = 0; // Initialize number of passwords to 0

// Function to add password to the list
bool add_password(char* password){
  // Check if the list is not full
  if(num_passwords < MAX_NUM_PASSWORDS){
    // Allocate memory for the password
    password_list[num_passwords] = (char*) malloc(strlen(password) + 1);
    // Copy password to allocated memory
    strcpy(password_list[num_passwords], password);
    num_passwords++; // Increment number of passwords
    return true; // Return success
  }
  
  return false; // Return failure
}

// Function to check if password is in the list
bool check_password(char* password){
  // Loop through the password list
  for(int i = 0; i < num_passwords; i++){
    // Check if the current password matches
    if(strcmp(password, password_list[i]) == 0){
      return true; // Return password match
    }
  }
  
  return false; // Return no match
}

int main(){
  char password[MAX_PASSWORD_LENGTH];
  bool success;
  
  printf("Welcome to Password Manager Paranoia!\n");
  printf("I'm only allowing a maximum of %d passwords\n", MAX_NUM_PASSWORDS);
  printf("Be sure to pick a strong password. Ready to get started?\n");
  
  do{
    printf("\nEnter a password to add to your list: ");
    scanf("%s", password);
    success = add_password(password); // Attempt to add password
    
    // Check if password addition was successful
    if(success){
      printf("Your password has been added to the list.\n");
    }else{
      printf("Your password was not added to the list. The list is full.\n");
    }
    
  }while(num_passwords < MAX_NUM_PASSWORDS); // Loop until max number of passwords is reached
  
  printf("\nNow you have %d passwords in your list.\n", num_passwords);
  
  while(true){
    printf("\nEnter a password to check: ");
    scanf("%s", password);
    
    // Check if password is in the list
    if(check_password(password)){
      printf("The password is in your list.\n");
    }else{
      printf("The password is not in your list.\n");
    }
  }
  
  // Free allocated memory
  for(int i = 0; i < num_passwords; i++){
    free(password_list[i]);
  }
  
  return 0;
}