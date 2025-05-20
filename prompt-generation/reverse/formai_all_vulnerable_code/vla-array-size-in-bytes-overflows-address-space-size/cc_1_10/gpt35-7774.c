//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: introspective
#include<stdio.h>
struct Warehouse{
   char product_name[50];
   int product_id;
   int quantity;
   float cost;
};
int main(){
   int i, n;
   printf("Enter the number of products: ");
   scanf("%d",&n);
   struct Warehouse ware[n];
   for(i=0; i<n; i++){
      printf("\nEnter product name, id, quantity, cost of product %d:\n", i+1);
      scanf("%s %d %d %f", &ware[i].product_name, &ware[i].product_id, &ware[i].quantity, &ware[i].cost);
   }
   printf("\n\n");
   printf("Product Name\t\tProduct ID\t\tQuantity\t\tCost\n");
   for(i=0; i<n; i++){
      printf("%s\t\t\t%d\t\t\t%d\t\t\t%.2f\n", ware[i].product_name, ware[i].product_id, ware[i].quantity, ware[i].cost);
   }
   printf("\n\n");
   
   int id;
   float new_cost;
   printf("Enter the id of the product to update cost: ");
   scanf("%d",&id);
   for(i=0; i<n; i++){
     if(ware[i].product_id==id){
        printf("Enter new cost of the product with id %d: ",id);
        scanf("%f",&new_cost);
        ware[i].cost = new_cost;
        printf("\nProduct details after cost update:\n\n");
        printf("Product Name\t\tProduct ID\t\tQuantity\t\tCost\n");
        printf("%s\t\t\t%d\t\t\t%d\t\t\t%.2f\n", ware[i].product_name, ware[i].product_id, ware[i].quantity, ware[i].cost);
        break;
     }
   }
   printf("\n\n");
   int del_id, flag=0;
   printf("Enter the id of the product to delete: ");
   scanf("%d",&del_id);
   for(i=0; i<n; i++){
      if(ware[i].product_id==del_id){
         for(int j=i; j<n-1; j++){
            ware[j] = ware[j+1];
         }
         flag = 1;
         break;
      }
   }
   if(flag==0){
      printf("\n\nProduct with id %d not found!",del_id);
   }else{
      printf("\n\nDetails after deleting product with id %d:\n\n", del_id);
      printf("Product Name\t\tProduct ID\t\tQuantity\t\tCost\n");
      for(i=0; i<n-1; i++){
         printf("%s\t\t\t%d\t\t\t%d\t\t\t%.2f\n", ware[i].product_name, ware[i].product_id, ware[i].quantity, ware[i].cost);
      }
   }
   return 0;
}