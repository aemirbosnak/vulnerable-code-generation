//FormAI DATASET v1.0 Category: Password management ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store password data
struct password{
    char website[50];
    char username[50];
    char pass[50];
};

//Function to add password to file
void addPassword(struct password pass){
    FILE *fp;
    fp=fopen("passwords.txt","a");
    if(fp==NULL){
        printf("Error opening file!");
        exit(1);
    }
    fprintf(fp,"%s %s %s\n",pass.website,pass.username,pass.pass);
    fclose(fp);
}

//Function to search for passwords by website name
void searchPassword(char* website){
    FILE *fp;
    char line[150];
    fp=fopen("passwords.txt","r");
    if(fp==NULL){
        printf("Error opening file!");
        exit(1);
    }
    int count=0;
    while(fgets(line,sizeof(line),fp)){
        line[strcspn(line,"\n")]=0;
        if(strstr(line,website)){
            printf("%s\n",line);
            count++;
        }
    }
    if(count==0){
        printf("Password not found!\n");
    }
    fclose(fp);
}

//Function to delete password entries by website name
void deletePassword(char* website){
    FILE *fp,*temp;
    char line[150];
    fp=fopen("passwords.txt","r");
    temp=fopen("temp.txt","w");
    if(fp==NULL || temp==NULL){
        printf("Error opening file!");
        exit(1);
    }
    int count=0,flag=0;
    while(fgets(line,sizeof(line),fp)){
        line[strcspn(line,"\n")]=0;
        if(strstr(line,website)){
            count++;
            flag=1;
        }else{
            fprintf(temp,"%s\n",line);
        }
    }
    if(flag==0){
        printf("Password not found!\n");
    }else{
        fclose(fp);
        fclose(temp);
        remove("passwords.txt");
        rename("temp.txt","passwords.txt");
        printf("Password deleted successfully!\n");
    }
}

int main(){

    int choice;
    char website[50];

    while(1){

        printf("\nPassword Manager\n");
        printf("----------------\n");
        printf("1. Add Password\n");
        printf("2. Search Password\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        fflush(stdin);

        struct password pass;

        switch(choice){

            case 1: printf("Enter website name: ");
                    scanf("%s",pass.website);
                    fflush(stdin);
                    printf("Enter username: ");
                    scanf("%s",pass.username);
                    fflush(stdin);
                    printf("Enter password: ");
                    scanf("%s",pass.pass);
                    fflush(stdin);
                    addPassword(pass);
                    printf("Password added successfully!\n");
                    break;

            case 2: printf("Enter website name: ");
                    scanf("%s",website);
                    fflush(stdin);
                    searchPassword(website);
                    break;

            case 3: printf("Enter website name: ");
                    scanf("%s",website);
                    fflush(stdin);
                    deletePassword(website);
                    break;

            case 4: exit(0);

            default: printf("Invalid choice!\n");
                     break;

        }

    }

    return 0;
}