//Falcon-180B DATASET v1.0 Category: Password management ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct password{
    char username[20];
    char password[20];
};

void main(){
    int choice, i, n;
    char ch;
    struct password pass[MAX];
    FILE *fp;

    system("cls");
    printf("\n\n\t\t\t\t Password Manager\n\n");
    printf("Enter the number of passwords you want to store: ");
    scanf("%d", &n);

    fp = fopen("passwords.txt", "wb");

    if(fp == NULL){
        printf("\nCannot create file!");
        exit(0);
    }

    for(i=0; i<n; i++){
        printf("\nEnter username for password %d: ", i+1);
        scanf("%s", pass[i].username);
        printf("Enter password for %s: ", pass[i].username);
        scanf("%s", pass[i].password);

        fprintf(fp, "%s|%s\n", pass[i].username, pass[i].password);
    }

    fclose(fp);

    printf("\n\nFiles saved successfully!");
    system("pause");

    fp = fopen("passwords.txt", "rb");

    if(fp == NULL){
        printf("\nCannot open file!");
        exit(0);
    }

    printf("\n\n\t\t\t\t Password Manager\n\n");
    printf("Enter your username: ");
    scanf("%s", ch);
    printf("Enter your password: ");
    scanf("%s", ch);

    rewind(fp);

    while(fscanf(fp, "%s|%s", pass[0].username, pass[0].password)!= EOF){
        if(strcmp(pass[0].username, ch) == 0 && strcmp(pass[0].password, ch) == 0){
            printf("\nLogin successful!");
            system("pause");
            break;
        }
        else{
            printf("\nLogin failed!");
            system("pause");
        }
    }

    fclose(fp);
}