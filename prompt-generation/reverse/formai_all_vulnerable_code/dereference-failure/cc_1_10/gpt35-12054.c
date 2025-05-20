//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine{
    int code;
    char name[20];
    float price;
    int quantity;
};

void displayMedicine(struct Medicine m){
    printf("%-15d%-20s%-15.2f%-10d\n",m.code,m.name,m.price,m.quantity);
}

int searchMedicine(struct Medicine m[],int n,int code){
    int i;
    for(i=0;i<n;i++){
        if(m[i].code==code){
            return i;
        }
    }
    return -1;
}

void addMedicine(struct Medicine m[],int n){
    struct Medicine newMedicine;
    printf("Enter Medicine Details\nCode:");
    scanf("%d",&newMedicine.code);
    printf("Name:");
    scanf("%s",newMedicine.name);
    printf("Price:");
    scanf("%f",&newMedicine.price);
    printf("Quantity:");
    scanf("%d",&newMedicine.quantity);
    if(searchMedicine(m,n,newMedicine.code)==-1){
        m[n]=newMedicine;
        printf("\nMedicine added successfully\n");
    }
    else{
        printf("\nMedicine already exists\n");
    }
}

void updateMedicine(struct Medicine m[],int n){
    int code,index;
    printf("Enter code of Medicine to Update:");
    scanf("%d",&code);
    index=searchMedicine(m,n,code);
    if(index==-1){
        printf("\nMedicine not found\n");
        return;
    }
    printf("Enter new details\n");
    printf("Name:");
    scanf("%s",m[index].name);
    printf("Price:");
    scanf("%f",&m[index].price);
    printf("Quantity:");
    scanf("%d",&m[index].quantity);
    printf("\nMedicine updated successfully\n");
}

void deleteMedicine(struct Medicine m[],int n){
    int code,index,i;
    printf("Enter code of Medicine to Delete:");
    scanf("%d",&code);
    index=searchMedicine(m,n,code);
    if(index==-1){
        printf("\nMedicine not found\n");
        return;
    }
    for(i=index;i<n-1;i++){
        m[i]=m[i+1];
    }
    printf("\nMedicine deleted successfully\n");
}

void displayAll(struct Medicine m[],int n){
    int i;
    printf("%-15s%-20s%-15s%-10s\n","Code","Name","Price","Quantity");
    for(i=0;i<n;i++){
        displayMedicine(m[i]);
    }
}

int main(){
    struct Medicine *medicines;
    int n=0,choice;
    printf("Welcome to C Medical Store Management System\n");
    while(1){
        printf("\nMENU\n");
        printf("1. ADD MEDICINE\n2. UPDATE MEDICINE\n3. DELETE MEDICINE\n4. VIEW ALL MEDICINES\n5. EXIT\n");
        printf("Enter Choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                n++;
                medicines=(struct Medicine*)realloc(medicines,n*sizeof(struct Medicine));
                addMedicine(medicines,n-1);
                break;
            case 2:
                updateMedicine(medicines,n);
                break;
            case 3:
                deleteMedicine(medicines,n);
                n--;
                medicines=(struct Medicine*)realloc(medicines,n*sizeof(struct Medicine));
                break;
            case 4:
                displayAll(medicines,n);
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice, try again\n");
        }
    }
    return 0;
}