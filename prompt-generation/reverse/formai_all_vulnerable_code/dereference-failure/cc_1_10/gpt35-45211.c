//FormAI DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    FILE *diary;
    int choice, password, user_password, existing_user=0;
    char date[100], entry[1000];

    // Check if user has an existing diary or not
    diary = fopen("password.txt", "r");
    if(diary!=NULL){
        printf("Welcome back! Do you want to continue your earlier diary entry or start a new one? \n");
        printf("Enter 1 for continue, 2 for new entry: ");
        scanf("%d", &choice);
        printf("\n");

        // Logging in if the user has an existing diary
        if(choice==1){
            existing_user = 1;
            printf("Enter your password: ");
            scanf("%d", &user_password);

            // Password verification
            fscanf(diary, "%d", &password);
            while(!feof(diary)){
                if(password==user_password){
                    printf("\nWelcome back to your diary! Write your entry:\n");
                    break;
                }
                fscanf(diary, "%d", &password);
            }
            if(feof(diary)){
                printf("\nWrong password. Please try again later.");
                exit(0);
            }
        }
    }

    // Creating a new diary or adding an entry to an existing one
    diary = fopen("diary.txt", "a");
    printf("What's the date today (dd/mm/yyyy)? ");
    scanf("%s", date);
    printf("Write your entry:\n");
    scanf("%[^'\n']", entry);

    // Encrypting the diary password
    if(existing_user==0){
        srand(time(NULL));
        password = rand()%10000; // Random password generation
        printf("\nYour diary password is: %d. Keep it safe!\n", password);
        fprintf(diary, "%d\n", password);
        fclose(diary);
        diary = fopen("diary.txt", "a");
    }

    // Writing the diary entry in the file
    fprintf(diary, "%s\n%s\n\n", date, entry);
    fclose(diary);

    return 0;
}