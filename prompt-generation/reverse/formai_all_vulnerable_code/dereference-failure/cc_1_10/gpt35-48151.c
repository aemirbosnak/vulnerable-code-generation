//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for storing medicine details
struct medicine{
    int id;
    char name[20];
    float price;
    int stock;
};

// Function to add new medicines to the store
void addMedicine(struct medicine *m, int count){
    printf("Enter details of medicine %d:\n", count+1);

    printf("Enter ID: ");
    scanf("%d", &(m+count)->id);

    printf("Enter name: ");
    scanf("%s", (m+count)->name);

    printf("Enter price per unit: ");
    scanf("%f", &(m+count)->price);

    printf("Enter available stock: ");
    scanf("%d", &(m+count)->stock);

    printf("Medicine added successfully!\n\n");
}

// Function to display all medicine details
void displayMedicines(struct medicine *m, int count){
    printf("ID    NAME              PRICE PER UNIT    AVAILABLE STOCK\n");
    printf("--------------------------------------------------------\n");

    for(int i=0; i<count; i++){
        printf("%-5d %-20s %-16.2f %-5d\n", (m+i)->id, (m+i)->name, (m+i)->price, (m+i)->stock);
    }
    printf("\n");
}

// Function to search for a medicine by ID
void searchMedicineById(struct medicine *m, int count){
    int id, found=0;
    printf("Enter ID of the medicine: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++){
        if((m+i)->id == id){
            printf("ID    NAME              PRICE PER UNIT    AVAILABLE STOCK\n");
            printf("--------------------------------------------------------\n");
            printf("%-5d %-20s %-16.2f %-5d\n", (m+i)->id, (m+i)->name, (m+i)->price, (m+i)->stock);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("No medicine found with the given ID.\n\n");
}

// Function to search for a medicine by name
void searchMedicineByName(struct medicine *m, int count){
    char name[20];
    int found=0;
    printf("Enter name of the medicine: ");
    scanf("%s", name);

    for(int i=0; i<count; i++){
        if(strcmp((m+i)->name, name) == 0){
            printf("ID    NAME              PRICE PER UNIT    AVAILABLE STOCK\n");
            printf("--------------------------------------------------------\n");
            printf("%-5d %-20s %-16.2f %-5d\n", (m+i)->id, (m+i)->name, (m+i)->price, (m+i)->stock);
            found = 1;
        }
    }

    if(!found)
        printf("No medicine found with the given name.\n\n");
}

// Function to update medicine details
void updateMedicine(struct medicine *m, int count){
    int id, choice, found=0;
    printf("Enter ID of the medicine: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++){
        if((m+i)->id == id){
            printf("Enter new details of medicine %d:\n", id);

            printf("1. Name\n");
            printf("2. Price per unit\n");
            printf("3. Available stock\n");
            printf("4. All of the above\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch(choice){
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", (m+i)->name);
                    printf("Name updated successfully!\n\n");
                    break;
                case 2:
                    printf("Enter new price: ");
                    scanf("%f", &(m+i)->price);
                    printf("Price updated successfully!\n\n");
                    break;
                case 3:
                    printf("Enter new stock: ");
                    scanf("%d", &(m+i)->stock);
                    printf("Stock updated successfully!\n\n");
                    break;
                case 4:
                    printf("Enter new name: ");
                    scanf("%s", (m+i)->name);
                    printf("Enter new price: ");
                    scanf("%f", &(m+i)->price);
                    printf("Enter new stock: ");
                    scanf("%d", &(m+i)->stock);
                    printf("Details updated successfully!\n\n");
                    break;
                default:
                    printf("Invalid choice.\n\n");
            }
            found = 1;
            break;
        }
    }

    if(!found)
        printf("No medicine found with the given ID.\n\n");
}

// Function to delete a medicine
void deleteMedicine(struct medicine *m, int *count){
    int id, found=0;
    printf("Enter ID of the medicine: ");
    scanf("%d", &id);

    for(int i=0; i<*count; i++){
        if((m+i)->id == id){
            for(int j=i; j<*count-1; j++){
                *(m+j) = *(m+j+1);
            }
            *count -= 1;
            found = 1;
            printf("Medicine deleted successfully!\n\n");
            break;
        }
    }

    if(!found)
        printf("No medicine found with the given ID.\n\n");
}

int main(){
    struct medicine *med;
    int choice, count=0;

    // Allocating memory for storing upto 50 medicines
    med = (struct medicine *) malloc(sizeof(struct medicine) * 50);

    while(1){
        printf("Medical Store Management System\n");
        printf("--------------------------------\n");
        printf("1. Add new medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Search for a medicine by ID\n");
        printf("4. Search for a medicine by name\n");
        printf("5. Update medicine details\n");
        printf("6. Delete a medicine\n");
        printf("7. Exit program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                if(count < 50){
                    addMedicine(med, count);
                    count++;
                }
                else{
                    printf("Cannot add medicine. Maximum limit reached.\n\n");
                }
                break;
            case 2:
                if(count > 0){
                    displayMedicines(med, count);
                }
                else{
                    printf("No medicines in the store.\n\n");
                }
                break;
            case 3:
                if(count > 0){
                    searchMedicineById(med, count);
                }
                else{
                    printf("No medicines in the store.\n\n");
                }
                break;
            case 4:
                if(count > 0){
                    searchMedicineByName(med, count);
                }
                else{
                    printf("No medicines in the store.\n\n");
                }
                break;
            case 5:
                if(count > 0){
                    updateMedicine(med, count);
                }
                else{
                    printf("No medicines in the store.\n\n");
                }
                break;
            case 6:
                if(count > 0){
                    deleteMedicine(med, &count);
                }
                else{
                    printf("No medicines in the store.\n\n");
                }
                break;
            case 7:
                printf("Exiting program. Thank you for using our system!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    free(med);
    return 0;
}