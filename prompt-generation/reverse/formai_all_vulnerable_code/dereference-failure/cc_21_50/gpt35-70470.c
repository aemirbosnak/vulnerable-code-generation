//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char name[50];
    int id;
    float price;
    int quantity;
};

typedef struct medicine MEDICINE;

int main(){
    int choice, id, quantity;
    float price;
    char name[50];
    MEDICINE med;
    FILE *fp, *temp;

    while(1){
        printf("\nWelcome to Medical Store Management System\n");
        printf("1. Add a new medicine\n2. Search a medicine\n3. Update a medicine\n4. Delete a medicine\n5. Display all medicine\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the name of the medicine: ");
                scanf("%s", med.name);
                printf("Enter the id of the medicine: ");
                scanf("%d", &med.id);
                printf("Enter the price of the medicine: ");
                scanf("%f", &med.price);
                printf("Enter the quantity of the medicine: ");
                scanf("%d", &med.quantity);

                fp = fopen("medicine.dat", "ab");
                if(fp==NULL){
                    printf("Error in opening file!");
                    exit(1);
                }
                fwrite(&med, sizeof(MEDICINE), 1, fp);
                printf("Medicine added successfully.\n");
                fclose(fp);
                break;

            case 2:
                printf("Enter the id of the medicine you want to search: ");
                scanf("%d", &id);

                fp = fopen("medicine.dat", "rb");
                if(fp==NULL){
                    printf("Error in opening file!");
                    exit(1);
                }
                while(fread(&med, sizeof(MEDICINE), 1, fp)){
                    if(med.id==id){
                        printf("Name: %s\n", med.name);
                        printf("Price: %.2f\n", med.price);
                        printf("Quantity: %d\n", med.quantity);
                        break;
                    }
                }
                if(feof(fp)){
                    printf("Medicine not found!\n");
                }
                fclose(fp);
                break;

            case 3:
                printf("Enter the id of the medicine you want to update: ");
                scanf("%d", &id);

                fp = fopen("medicine.dat", "rb");
                if(fp==NULL){
                    printf("Error in opening file!");
                    exit(1);
                }
                temp = fopen("temp.dat", "wb");
                if(temp==NULL){
                    printf("Error in opening file!");
                    exit(1);
                }
                while(fread(&med, sizeof(MEDICINE), 1, fp)){
                    if(med.id!=id) fwrite(&med, sizeof(MEDICINE), 1, temp);
                    else{
                        printf("Enter the new name of the medicine (previous: %s): ", med.name);
                        scanf("%s", med.name);
                        printf("Enter the new price of the medicine (previous: %.2f): ", med.price);
                        scanf("%f", &med.price);
                        printf("Enter the new quantity of the medicine (previous: %d): ", med.quantity);
                        scanf("%d", &med.quantity);
                        fwrite(&med, sizeof(MEDICINE), 1, temp);
                    }
                }
                fclose(fp);
                fclose(temp);

                remove("medicine.dat");
                rename("temp.dat", "medicine.dat");
                printf("Medicine updated successfully.\n");
                break;

            case 4:
                printf("Enter the id of the medicine you want to delete: ");
                scanf("%d", &id);

                fp = fopen("medicine.dat", "rb");
                if(fp==NULL){
                    printf("Error in opening file!");
                    exit(1);
                }
                temp = fopen("temp.dat", "wb");
                if(temp==NULL){
                    printf("Error in opening file!");
                    exit(1);
                }
                while(fread(&med, sizeof(MEDICINE), 1, fp)){
                    if(med.id!=id) fwrite(&med, sizeof(MEDICINE), 1, temp);
                }
                fclose(fp);
                fclose(temp);
                remove("medicine.dat");
                rename("temp.dat", "medicine.dat");
                printf("Medicine deleted successfully.\n");
                break;

            case 5:
                fp = fopen("medicine.dat", "rb");
                if(fp==NULL){
                    printf("Error in opening file!");
                    exit(1);
                }
                while(fread(&med, sizeof(MEDICINE), 1, fp)){
                    printf("Name: %s\n", med.name);
                    printf("Id: %d\n", med.id);
                    printf("Price: %.2f\n", med.price);
                    printf("Quantity: %d\n", med.quantity);
                    printf("------------------\n");
                }
                fclose(fp);
                break;

            case 6:
                printf("Thank you for using Medical Store Management System.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 0;
}