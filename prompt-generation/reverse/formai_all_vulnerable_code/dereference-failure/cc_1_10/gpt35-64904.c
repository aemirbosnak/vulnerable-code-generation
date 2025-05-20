//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Medicine{
    char name[20];
    int qty;
    float price;
    int exp_month;
    int exp_year;
    struct Medicine *next;
} Med;

Med *start=NULL;

void create_med();
void display_med();
void search_med();
void update_med();
void delete_med();
void save_med();

int main(){
    int choice;
    while(1){
        printf("\n---- Welcome to the Medical Store Management System ----\n");
        printf("1. Create a new medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Search for a medicine\n");
        printf("4. Update a medicine\n");
        printf("5. Delete a medicine\n");
        printf("6. Save to file\n");
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                create_med();
                break;
            case 2:
                display_med();
                break;
            case 3:
                search_med();
                break;
            case 4:
                update_med();
                break;
            case 5:
                delete_med();
                break;
            case 6:
                save_med();
                break;
            case 7:
                exit(0);
            default:
                printf("Enter a valid choice!\n");
        }
    }
    return 0;
}

void create_med(){
    Med *new_med=(Med*)malloc(sizeof(Med));

    printf("\nEnter the medicine details : \n");
    printf("Name : ");
    scanf("%s",new_med->name);
    printf("Quantity : ");
    scanf("%d",&new_med->qty);
    printf("Price : ");
    scanf("%f",&new_med->price);
    printf("Expiry Month : ");
    scanf("%d",&new_med->exp_month);
    printf("Expiry Year : ");
    scanf("%d",&new_med->exp_year);

    new_med->next=NULL;

    if(start==NULL){
        start=new_med;
    }
    else{
        Med *temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_med;
    }
    printf("\nNew medicine successfully added!\n");
}

void display_med(){
    if(start==NULL){
        printf("\nNo records found!\n");
        return;
    }
    Med *temp=start;
    printf("\nList of all medicines : \n");
    printf("Name\t\tQuantity\t\tPrice\t\tExpiry Date\n");
    while(temp!=NULL){
        printf("%s\t%d\t\t%.2f\t\t%d/%d\n",temp->name,temp->qty,temp->price,temp->exp_month,temp->exp_year);
        temp=temp->next;
    }
}

void search_med(){
    if(start==NULL){
        printf("\nNo records found!\n");
        return;
    }

    char medname[20];
    printf("\nEnter the name of medicine to search : ");
    scanf("%s",medname);

    Med *temp=start;
    while(temp!=NULL){
        if(strcmp(temp->name,medname)==0){
            printf("\nMedicine found : \n");
            printf("Name\t\tQuantity\t\tPrice\t\tExpiry Date\n");
            printf("%s\t%d\t\t%.2f\t\t%d/%d\n",temp->name,temp->qty,temp->price,temp->exp_month,temp->exp_year);
            return;
        }
        temp=temp->next;
    }
    printf("\nMedicine not found!\n");
}

void update_med(){
    if(start==NULL){
        printf("\nNo records found!\n");
        return;
    }

    char medname[20];
    printf("\nEnter the name of medicine to update : ");
    scanf("%s",medname);

    Med *temp=start;
    while(temp!=NULL){
        if(strcmp(temp->name,medname)==0){
            printf("\nEnter new medicine details : \n");
            printf("Name : ");
            scanf("%s",temp->name);
            printf("Quantity : ");
            scanf("%d",&temp->qty);
            printf("Price : ");
            scanf("%f",&temp->price);
            printf("Expiry Month : ");
            scanf("%d",&temp->exp_month);
            printf("Expiry Year : ");
            scanf("%d",&temp->exp_year);
            printf("\nMedicine details updated successfully!\n");
            return;
        }
        temp=temp->next;
    }
    printf("\nMedicine not found!\n");  
}

void delete_med(){
    if(start==NULL){
        printf("\nNo records found!\n");
        return;
    }

    char medname[20];
    printf("Enter the name of medicine to delete : ");
    scanf("%s",medname);

    Med *temp1=start,*temp2=NULL;
    while(temp1!=NULL){
        if(strcmp(temp1->name,medname)==0){
            if(temp1==start){
                start=temp1->next;
            }
            else{
                temp2->next=temp1->next;
            }
            free(temp1);
            printf("\nMedicine deleted successfully!\n");
            return;
        }
        temp2=temp1;
        temp1=temp1->next;
    }
    printf("\nMedicine not found!\n");
}

void save_med(){
    if(start==NULL){
        printf("\nNo records found!\n");
        return;
    }

    FILE *fp;
    fp=fopen("medicines.txt","w");
    if(fp==NULL){
        printf("\nError creating file!\n");
    }

    Med *temp=start;
    while(temp!=NULL){
        fprintf(fp,"%s;%d;%.2f;%d/%d\n",temp->name,temp->qty,temp->price,temp->exp_month,temp->exp_year);
        temp=temp->next;
    }
    fclose(fp);
    printf("\nData saved successfully to file!\n");
}