//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int main(){
  int length, i, option, temp;
  char password[101], characters[63];
  srand(time(NULL));

  printf("Welcome to the Password Generator!\n");
  
  while(1){
    printf("\nChoose an option:\n");
    printf("1. Generate a password\n");
    printf("2. Exit\n");
    printf("Option: ");
    scanf("%d", &option);
    printf("\n");
    
    if(option == 2)
      break;
    
    printf("Enter the length of the password (1-100): ");
    scanf("%d", &length);
    if(length > 100)
      length = 100;
    else if(length < 1)
      length = 1;
    
    printf("\nChoose the type of password:\n");
    printf("1. Alphanumeric (lowercase letters and numbers)\n");
    printf("2. Alphanumeric (uppercase letters and numbers)\n");
    printf("3. Alphanumeric (mixed case letters and numbers)\n");
    printf("4. Alphabetic (lowercase letters only)\n");
    printf("5. Alphabetic (uppercase letters only)\n");
    printf("6. Alphabetic (mixed case letters only)\n");
    printf("7. Numeric (numbers only)\n");
    printf("Option: ");
    scanf("%d", &option);
    printf("\n");
    
    switch(option){
      case 1:
        for(i = 0; i < 26; i++)
          characters[i] = 'a' + i;
        for(i = 26; i < 36; i++)
          characters[i] = '0' + (i - 26);
        break;
      case 2:
        for(i = 0; i < 26; i++)
          characters[i] = 'A' + i;
        for(i = 26; i < 36; i++)
          characters[i] = '0' + (i - 26);
        break;
      case 3:
        for(i = 0; i < 26; i++){
          characters[i] = 'a' + i;
          characters[i + 26] = 'A' + i;
        }
        for(i = 52; i < 62; i++)
          characters[i] = '0' + (i - 52);
        break;
      case 4:
        for(i = 0; i < 26; i++)
          characters[i] = 'a' + i;
        break;
      case 5:
        for(i = 0; i < 26; i++)
          characters[i] = 'A' + i;
        break;
      case 6:
        for(i = 0; i < 26; i++){
          characters[i] = 'a' + i;
          characters[i + 26] = 'A' + i;
        }
        break;
      case 7:
        for(i = 0; i < 10; i++)
          characters[i] = '0' + i;
        break;
      default:
        break;
    }
    
    for(i = 0; i < length; i++){
      temp = rand() % strlen(characters);
      password[i] = characters[temp];
    }
    password[length] = '\0';
    
    printf("Your password is: %s", password);
  }
  
  return 0;
}