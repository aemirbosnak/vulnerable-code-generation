//FormAI DATASET v1.0 Category: Banking Record System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bank{
    char name[30];
    int account_no;
    float balance;
    char address[100];
    char contact[15];
};

void add_customer(struct bank *b, int n);
void display_customer(struct bank *b, int n);
void search_customer(struct bank *b, int n);
void update_customer(struct bank *b, int n);

int main()
{
    
    int n, choice;
    
    printf("Welcome to the Ken Thompson Bank record system!\n");
    printf("Please enter number of customers you want to add: ");
    scanf("%d",&n);
    
    struct bank *b = (struct bank*) malloc (n * sizeof(struct bank));
    
    printf("\n1 - Add customer\n2 - Display customer\n3 - Search customer\n4 - Update customer\n0 - Exit\n");
    
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                add_customer(b,n);
                break;
            case 2:
                display_customer(b,n);
                break;
            case 3:
                search_customer(b,n);
                break;
            case 4:
                update_customer(b,n);
                break;
            case 0:
                printf("Thank you for using Ken Thompson Bank record system!\n");
                free(b);
                exit(1);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
            
        }
        
    }
    
    return 0;
}

void add_customer(struct bank *b, int n){
    static int i=0;
    
    if(i==n){
        printf("Sorry, all customers have been added.\n");
    }else{
        printf("\nEnter details for customer %d: \n",i+1);
        printf("Name: ");
        scanf("%s",b[i].name);
        printf("Account no: ");
        scanf("%d",&b[i].account_no);
        printf("Balance: ");
        scanf("%f",&b[i].balance);
        printf("Address: ");
        scanf("\n");
        fgets(b[i].address,100,stdin);
        printf("Contact: ");
        scanf("%s",b[i].contact);
        
        i++;
    }
}

void display_customer(struct bank *b, int n){
    int i;
    printf("\nName\tAccount Number\tBalance\t\tAddress\t\t\tContact\n");
    for(i=0; i<n; i++){
        printf("%s\t%d\t\t%.2f\t%s\t\t%s\n",b[i].name,b[i].account_no,b[i].balance,b[i].address,b[i].contact);
    }
}

void search_customer(struct bank *b, int n){
    int i, account;
    int found=0;
    printf("\nEnter the account number you want to search: ");
    scanf("%d",&account);
    
    for(i=0; i<n; i++){
        if(b[i].account_no == account){
            printf("\nName\tAccount Number\tBalance\t\tAddress\t\t\tContact\n");
            printf("%s\t%d\t\t%.2f\t%s\t\t%s\n",b[i].name,b[i].account_no,b[i].balance,b[i].address,b[i].contact);
            found = 1;
            break;
        }
    }
    
    if(found == 0){
        printf("\nSorry, the account number is not found!\n");
    }
    
}

void update_customer(struct bank *b, int n){
    int i, account;
    int found=0;
    printf("\nEnter the account number you want to update: ");
    scanf("%d",&account);
    
    for(i=0; i<n; i++){
        if(b[i].account_no == account){
            printf("\nEnter the new details for customer %d: \n",i+1);
            printf("Name: ");
            scanf("%s",b[i].name);
            printf("Account no: ");
            scanf("%d",&b[i].account_no);
            printf("Balance: ");
            scanf("%f",&b[i].balance);
            printf("Address: ");
            scanf("\n");
            fgets(b[i].address,100,stdin);
            printf("Contact: ");
            scanf("%s",b[i].contact);
            
            found = 1;
            break;
        }
    }
    
    if(found == 0){
        printf("\nSorry, the account number is not found!\n");
    }
}