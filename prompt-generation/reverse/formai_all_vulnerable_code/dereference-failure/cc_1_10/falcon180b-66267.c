//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function to encrypt the password
void encrypt(char *password) {
    int i,j;
    for(i=0,j=0;password[i]!='\0';i++,j++) {
        if(j==3) {
            j=0;
        }
        password[i] = password[i] + j;
    }
}

//Function to decrypt the password
void decrypt(char *password) {
    int i,j;
    for(i=0,j=0;password[i]!='\0';i++,j++) {
        if(j==3) {
            j=0;
        }
        password[i] = password[i] - j;
    }
}

//Function to check if the password is correct
int check_password(char *password) {
    char correct_password[10] = "password";
    int i,flag=0;
    for(i=0;i<strlen(password);i++) {
        if(password[i]!= correct_password[i]) {
            flag = 1;
            break;
        }
    }
    return flag;
}

//Function to create a new user
void create_user() {
    char name[20],password[10];
    printf("Enter your name: ");
    scanf("%s",name);
    printf("Enter your password: ");
    scanf("%s",password);
    encrypt(password);
    FILE *fp;
    fp = fopen("users.txt","a");
    fprintf(fp,"%s %s\n",name,password);
    fclose(fp);
    printf("User created successfully!\n");
}

//Function to login
void login() {
    char name[20],password[10];
    printf("Enter your name: ");
    scanf("%s",name);
    printf("Enter your password: ");
    scanf("%s",password);
    decrypt(password);
    FILE *fp;
    fp = fopen("users.txt","r");
    char ch;
    while((ch=fgetc(fp))!=EOF) {
        if(ch=='\n') {
            continue;
        }
        if(strcmp(name,ch)==0) {
            if(check_password(password)==0) {
                printf("Login successful!\n");
                system("clear");
                main();
            }
            else {
                printf("Incorrect password.\n");
            }
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    printf("User not found.\n");
}

//Main function
int main() {
    int choice;
    while(1) {
        printf("\n\n\t\t\t Electronic Voting System\n");
        printf("\n1. Create a new user\n2. Login\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                create_user();
                break;
            case 2:
                login();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}