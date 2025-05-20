//FormAI DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct bank_record {
    char name[20];
    int account_no;
    float balance;
};

void display_records(struct bank_record *rec, int size){
    printf("\n*********************************************\n");
    printf("Name\t\tAccount No.\tBalance\n");
    printf("*********************************************\n");
    for(int i=0;i<size;i++){
        printf("%s\t\t%d\t\t%.2f\n", rec[i].name, rec[i].account_no, rec[i].balance);
    }
    printf("*********************************************\n");
}

void update_records(struct bank_record *rec, int size){
    int accno, amt, flag=0;
    printf("\nEnter Account No. to be updated: ");
    scanf("%d", &accno);
    for(int i=0;i<size;i++){
        if(rec[i].account_no==accno){
            flag=1;
            printf("\nEnter Amount to be deposited/withdrawn:");
            scanf("%d", &amt);
            if(amt<0){
                if((rec[i].balance+amt)<0){
                    printf("\nInsufficient balance to withdraw amount!");
                }
                else{
                    rec[i].balance+=amt;
                    printf("\nAmount successfully withdrawn!");
                    display_records(rec, size);
                }
            }
            else{
                rec[i].balance+=amt;
                printf("\nAmount successfully deposited!");
                display_records(rec, size);
            }
            break;
        }
    }
    if(flag==0){
        printf("\nAccount No. not found!");
    }
}

void search_records(struct bank_record *rec, int size){
    int accno, flag=0;
    printf("\nEnter Account No. to search: ");
    scanf("%d", &accno);
    printf("\n*********************************************\n");
    printf("Name\t\tAccount No.\tBalance\n");
    printf("*********************************************\n");
    for(int i=0;i<size;i++){
        if(rec[i].account_no==accno){
            printf("%s\t\t%d\t\t%.2f\n", rec[i].name, rec[i].account_no, rec[i].balance);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\nAccount No. not found!");
    }
    printf("*********************************************\n");
}

void add_records(struct bank_record *rec, int size){
    printf("\nEnter Name: ");
    scanf("%s", rec[size].name);
    printf("\nEnter Account No.: ");
    scanf("%d", &rec[size].account_no);
    printf("\nEnter Balance: ");
    scanf("%f", &rec[size].balance);
    printf("\nRecord added successfully!");
}

void remove_records(struct bank_record *rec, int size){
    int accno, flag=0;
    printf("\nEnter Account No. to remove: ");
    scanf("%d", &accno);
    for(int i=0;i<size;i++){
        if(rec[i].account_no==accno){
            flag=1;
            for(int j=i;j<size-1;j++){
                strcpy(rec[j].name, rec[j+1].name);
                rec[j].account_no=rec[j+1].account_no;
                rec[j].balance=rec[j+1].balance;
            }
            printf("\nRecord removed successfully!");
            display_records(rec, size-1);
            break;
        }
    }
    if(flag==0){
        printf("\nAccount No. not found!");
    }
}

int main(){
    srand(time(NULL));
    int size=5, choice;
    struct bank_record *records=(struct bank_record *)malloc(size*sizeof(struct bank_record));
    for(int i=0;i<size;i++){
        strcpy(records[i].name, "User");
        records[i].account_no=rand()%1000+100;
        records[i].balance=rand()%10000+1000;
    }
    printf("Welcome to the Banking Record System\n");
    while(1){
        printf("\n****************************************************\n");
        printf("Choose an option:\n1. Display Records\n2. Update Records\n3. Search Records\n4. Add Record\n5. Remove Record\n6. Exit\n");
        printf("****************************************************\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: display_records(records, size); break;
            case 2: update_records(records, size); break;
            case 3: search_records(records, size); break;
            case 4: if(size>=10){
                        printf("\nCannot add more records, capacity full!");
                    }
                    else{
                        add_records(records, size);
                        size++;
                    }
                    break;
            case 5: if(size<=1){
                        printf("\nCannot remove records, only one record left!");
                    }
                    else{
                        remove_records(records, size);
                        size--;
                    }
                    break;
            case 6: printf("\nExiting program...");
                    free(records);
                    exit(0);
                    break;
            default: printf("\nInvalid choice!");
        }
    }
    return 0;
}