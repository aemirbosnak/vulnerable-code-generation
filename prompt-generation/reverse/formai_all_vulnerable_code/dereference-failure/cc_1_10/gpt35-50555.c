//FormAI DATASET v1.0 Category: Password management ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
 
void main()
{
    FILE *fp;
    int i=0;
    char p[MAX],pass[MAX],newpass[MAX];
    printf("\t\t-----------------------------\n");
    printf("\t\t   Password Manager Program\n");
    printf("\t\t-----------------------------\n\n");
    printf("\t\t\tWelcome User!\n\n");
    fp=fopen("stored_password.txt","r"); //opening a text file containing previously saved password
    fgets(p,MAX,fp);
    printf("\t\tPlease Enter your Current Password: ");
    scanf("%s",pass);
    if(strcmp(pass,p)==0) //checking whether current password matches the stored password
    {
        printf("\n\t\tYou have Successfully Logged In!");
        printf("\n\t\t---------------------------------\n");
        printf("\t\tPress 1 to Change your Password\n");
        printf("\t\tPress 2 to Display Stored Password\n");
        printf("\t\tPress 3 to Exit\n");
        printf("\t\t---------------------------------\n");
        printf("\t\tEnter your choice: ");
        scanf("%d",&i);
        switch(i)
        {
            case 1:printf("\n\t\tPlease Enter Your New Password: ");
                   scanf("%s",newpass);
                   fp=fopen("stored_password.txt","w");
                   fputs(newpass,fp); //storing new password in the mentioned text file
                   printf("\n\t\tYour Password has been Successfully Changed!\n");
                   fclose(fp);
                   main();
                   break;
            case 2:printf("\n\t\tYour Stored Password is %s\n",p);
                   printf("\n\t\tThank You for using Our Application!");
                   printf("\n\t\tHope to see you soon!");
                   break;
            case 3:printf("\n\t\tThank You for using Our Application!");
                   printf("\n\t\tHope to see you soon!");
                   break;
            default:printf("\n\t\tPlease Enter a Valid Choice!");
        }
    }
    else
    {
        printf("\n\t\tYour Current Password is Incorrect! Please Try Again.");
        main();
    }
}