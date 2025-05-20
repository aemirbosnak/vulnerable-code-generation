//FormAI DATASET v1.0 Category: Password management ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to generate a random password
void generatePassword(char *password, int length){
    int i;
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[];/';.,?><";
    for(i = 0; i < length; i++){
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

//function to encrypt a given password
void encryptPassword(char *password){
    int i;
    for(i = 0; i < strlen(password); i++){
        password[i] += 3; //shifting each character by 3 positions
    }
}

//function to decrypt a given password
void decryptPassword(char *password){
    int i;
    for(i = 0; i < strlen(password); i++){
        password[i] -= 3; //shifting each character back by 3 positions
    }
}

int main(){
    char masterPassword[20]; //variable to store the master password
    char website[50], username[50], password[20]; //variables to store website, username and password
    int choice, length;

    printf("Welcome to Password Manager!\n");
    printf("Enter the Master Password: ");
    scanf("%s", masterPassword);

    do{
        printf("\n1. Add Password\n");
        printf("2. View Password\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: //add password
                printf("\nEnter Website Name: ");
                scanf("%s", website);

                printf("Enter Username: ");
                scanf("%s", username);

                printf("Enter Password Length: ");
                scanf("%d", &length);

                generatePassword(password, length);
                encryptPassword(password);
                printf("\nGenerated Password: %s\n", password);

                //save website, username and encrypted password to a file
                FILE *fp;
                fp = fopen("passwords.txt", "a");
                fprintf(fp, "%s:%s:%s\n", website, username, password);
                fclose(fp);

                printf("Password Added Successfully!\n");
                break;
            case 2: //view password
                printf("\nEnter Website Name: ");
                scanf("%s", website);

                //open passwords file for reading
                fp = fopen("passwords.txt", "r");
                char line[100];
                int found = 0;
                while(fgets(line, sizeof(line), fp)){
                    char *w = strtok(line, ":"); //get website from file
                    if(strcmp(w, website) == 0){ //compare with entered website
                        char *u = strtok(NULL, ":"); //get username from file
                        char *p = strtok(NULL, ":"); //get encrypted password from file
                        decryptPassword(p); //decrypt the password
                        printf("\nWebsite: %s\nUsername: %s\nPassword: %s\n", w, u, p);
                        found = 1;
                        break;
                    }
                }
                if(!found){
                    printf("\nWebsite not found!\n");
                }
                fclose(fp);
                break;
            case 3: //exit
                printf("\nExiting Password Manager...\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }while(choice != 3);

    return 0;
}