//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int med_id;
    char med_name[50];
    int med_stock;
    float med_price;
    char med_expiry_date[12];
} medicine;

int main(){
    int choice,n=0,i=0,id=0,flag=0;
    char search_name[50];
    float bill=0.0;
    medicine *med_arr;
    printf("\n=================================");
    printf("\n WELCOME TO MEDICAL STORE MANAGEMENT SYSTEM");
    printf("\n=================================");
    while(1){
        printf("\n\nSelect the operation : ");
        printf("\n1. Add a medicine");
        printf("\n2. Edit medicine details");
        printf("\n3. Search for a medicine using name");
        printf("\n4. Display medicine list in ascending order of price");
        printf("\n5. Buy medicine");
        printf("\n6. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\n===========ADD MEDICINE============");
                printf("\nEnter the number of medicines to be added : ");
                scanf("%d",&n);
                med_arr = (medicine*)malloc(n*sizeof(medicine));
                for(i=0; i<n; i++){
                    printf("\nEnter details for medicine %d :",i+1);
                    printf("\nMedicine ID : ");
                    scanf("%d",&med_arr[i].med_id);
                    printf("Medicine Name : ");
                    scanf(" %[^\n]s",med_arr[i].med_name);
                    printf("Stock : ");
                    scanf("%d",&med_arr[i].med_stock);
                    printf("Price : ");
                    scanf("%f",&med_arr[i].med_price);
                    printf("Expiry Date (dd/mm/yyyy) : ");
                    scanf(" %s",med_arr[i].med_expiry_date);
                    printf("\nMedicine added successfully!\n");
                }
                break;
            case 2:
                printf("\n===========EDIT MEDICINE DETAILS============");
                printf("\nEnter the id of medicine whose details to be changed : ");
                scanf("%d",&id);
                for(i=0; i<n; i++){
                    if(med_arr[i].med_id==id){
                        printf("\nMedicine details found!");
                        printf("\nMedicine ID : %d",med_arr[i].med_id);
                        printf("\nMedicine Name : %s",med_arr[i].med_name);
                        printf("\nStock : %d",med_arr[i].med_stock);
                        printf("\nPrice : %f",med_arr[i].med_price);
                        printf("\nExpiry Date : %s",med_arr[i].med_expiry_date);
                        printf("\nEnter new details for medicine %d :",i+1);
                        printf("\nMedicine ID : ");
                        scanf("%d",&med_arr[i].med_id);
                        printf("Medicine Name : ");
                        scanf(" %[^\n]s",med_arr[i].med_name);
                        printf("Stock : ");
                        scanf("%d",&med_arr[i].med_stock);
                        printf("Price : ");
                        scanf("%f",&med_arr[i].med_price);
                        printf("Expiry Date (dd/mm/yyyy) : ");
                        scanf("%s",med_arr[i].med_expiry_date);
                        break;
                    }
                }
                if(i==n){
                    printf("\nMedicine ID not found!");
                }
                break;
            case 3:
                printf("\n===========SEARCH MEDICINE============");
                printf("\nEnter name of medicine to search : ");
                scanf(" %[^\n]s",search_name);
                printf("\nMedicine Details : \n\n");
                for(i=0; i<n; i++){
                    if(strcmp(med_arr[i].med_name,search_name)==0){
                        printf("\nMedicine ID : %d",med_arr[i].med_id);
                        printf("\nMedicine Name : %s",med_arr[i].med_name);
                        printf("\nStock : %d",med_arr[i].med_stock);
                        printf("\nPrice : %f",med_arr[i].med_price);
                        printf("\nExpiry Date : %s",med_arr[i].med_expiry_date);
                        flag=1;
                    }
                }
                if(flag==0){
                    printf("\nMedicine not found!");
                }
                break;
            case 4:
                printf("\n===========MEDICINE LIST============");
                printf("\nMedicine list : \n\n");
                for(i=0; i<n; i++){
                    printf("\nMedicine ID : %d",med_arr[i].med_id);
                    printf("\nMedicine Name : %s",med_arr[i].med_name);
                    printf("\nStock : %d",med_arr[i].med_stock);
                    printf("\nPrice : %f",med_arr[i].med_price);
                    printf("\nExpiry Date : %s",med_arr[i].med_expiry_date);
                }
                break;
            case 5:
                printf("\n===========BUY MEDICINE============");
                printf("\nEnter number of medicines to buy : ");
                scanf("%d",&n);
                for(i=0; i<n; i++){
                    printf("\nEnter name of medicine to buy : ");
                    scanf(" %[^\n]s",search_name);
                    flag=0;
                    for(int j=0; j<n; j++){
                        if(strcmp(med_arr[j].med_name,search_name)==0){
                            flag=1;
                            printf("Enter quantity : ");
                            int quantity;
                            scanf("%d",&quantity);
                            if(quantity<=med_arr[j].med_stock){
                                med_arr[j].med_stock-=quantity;
                                bill+=quantity*med_arr[j].med_price;
                                printf("\nMedicine bought successfully!");
                                break;
                            }
                            else{
                                printf("\nRequired quantity not available!");
                                break;
                            }
                        }
                    }
                    if(flag==0){
                        printf("\nMedicine not found!");
                    }
                }
                printf("\nTotal bill amount : %f",bill);
                break;
            case 6:
                printf("\n===========THANK YOU FOR USING MEDICAL STORE MANAGEMENT SYSTEM!============");
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}