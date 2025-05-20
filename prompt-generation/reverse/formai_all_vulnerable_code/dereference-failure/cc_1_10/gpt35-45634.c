//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine
{
    int id;
    char name[50];
    double price;
    int stock;
};

void display_menu()
{
  printf("\n\n*** MEDICAL STORE MANAGEMENT SYSTEM ***\n");
  printf("\n1. Add New Medicine");
  printf("\n2. Remove Medicine");
  printf("\n3. Search Medicine");
  printf("\n4. View All Medicines");
  printf("\n5. Update Medicine Price");
  printf("\n6. Update Medicine Stock");
  printf("\n0. Exit");
}

void add_medicine(struct medicine *m)
{
    printf("\nEnter medicine ID: ");
    scanf("%d",&m->id);
    printf("\nEnter medicine Name: ");
    scanf("%s",m->name);
    printf("\nEnter medicine Price: ");
    scanf("%lf",&m->price);
    printf("\nEnter medicine Stock: ");
    scanf("%d",&m->stock);
}

void remove_medicine(struct medicine *m, int size, int id)
{
    int i,flag=0;
    for(i=0;i<size;i++)
    {
        if(m[i].id==id)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        for(int j=i;j<size-1;j++)
        {
            m[j]=m[j+1];
        }
        printf("\nMedicine Removed Successfully!");
    }
    else
    {
        printf("\nMedicine ID not found!");
    }
}

int search_medicine(struct medicine *m, int size, int id)
{
    int i,flag=0;
    for(i=0;i<size;i++)
    {
        if(m[i].id==id)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("\nFOUND!\n");
        printf("\nMedicine ID: %d",m[i].id);
        printf("\nMedicine Name: %s",m[i].name);
        printf("\nMedicine Price: %0.2lf",m[i].price);
        printf("\nMedicine Stock: %d",m[i].stock);
    }
    else
    {
        printf("\nMedicine ID not found!");
    }
}

void view_all_medicines(struct medicine *m, int size)
{
    printf("\n\nMEDICINES AVAILABLE IN THE STORE:\n\n");
    printf("| Medicine ID | Medicine Name | Medicine Price | Medicine Stock |\n");
    for(int i=0;i<size;i++)
    {
        printf("| %11d | %13s | %14.2lf | %14d |\n",m[i].id,m[i].name,m[i].price,m[i].stock);
    }
}

void update_medicine_price(struct medicine *m, int size, int id, double new_price)
{
    int i,flag=0;
    for(i=0;i<size;i++)
    {
        if(m[i].id==id)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        m[i].price = new_price;
        printf("\nPrice updated successfully!");
    }
    else
    {
        printf("\nMedicine ID not found!");
    }
}

void update_medicine_stock(struct medicine *m, int size, int id, int new_stock)
{
    int i,flag=0;
    for(i=0;i<size;i++)
    {
        if(m[i].id==id)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        m[i].stock = new_stock;
        printf("\nStock updated successfully!");
    }
    else
    {
        printf("\nMedicine ID not found!");
    }
}

int main()
{
    int choice, exit_program=0, size=0;
    struct medicine *m = NULL;
    printf("\nEnter the number of medicines to be stored: ");
    scanf("%d",&size);
    m = (struct medicine*)malloc(size*sizeof(struct medicine));
    do
    {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\n Adding a new medicine:\n");
                add_medicine(&m[size]);
                size++;
                break;
            case 2:
                printf("\nEnter ID of medicine to be removed: ");
                int id_remove;
                scanf("%d",&id_remove);
                remove_medicine(m,size,id_remove);
                size--;
                break;
            case 3:
                printf("\nEnter ID of medicine to be searched: ");
                int id_search;
                scanf("%d",&id_search);
                search_medicine(m,size,id_search);
                break;
            case 4:
                view_all_medicines(m,size);
                break;
            case 5:
                printf("\nEnter ID of medicine to be updated: ");
                int id_update;
                scanf("%d",&id_update);
                printf("\nEnter New Price: ");
                double new_price;
                scanf("%lf",&new_price);
                update_medicine_price(m,size,id_update,new_price);
                break;
            case 6:
                printf("\nEnter ID of medicine to be updated: ");
                int id_update_stock;
                scanf("%d",&id_update_stock);
                printf("\nEnter New Stock: ");
                int new_stock;
                scanf("%d",&new_stock);
                update_medicine_stock(m,size,id_update_stock,new_stock);
                break;
            case 0:
                printf("\nExiting the program\n");
                exit_program=1;
                break;
            default:
                printf("\nInvalid input. Try again!\n");
        }
    }while(exit_program!=1);
    return 0;
}