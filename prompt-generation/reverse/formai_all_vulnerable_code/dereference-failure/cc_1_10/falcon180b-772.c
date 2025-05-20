//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a medicine
struct medicine {
    char name[50];
    char company[50];
    int quantity;
    float price;
};

// Function to add a medicine
void addMedicine(struct medicine *m, int n) {
    printf("\nEnter medicine details:\n");
    printf("Name: ");
    scanf("%s", m[n].name);
    printf("Company: ");
    scanf("%s", m[n].company);
    printf("Quantity: ");
    scanf("%d", &m[n].quantity);
    printf("Price: ");
    scanf("%f", &m[n].price);
}

// Function to display all medicines
void displayMedicines(struct medicine m[], int n) {
    printf("\nList of medicines:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s (%s) - %d units - $%.2f\n", i+1, m[i].name, m[i].company, m[i].quantity, m[i].price);
    }
}

// Function to search for a medicine
int searchMedicine(struct medicine m[], int n, char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(m[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to update the quantity of a medicine
void updateQuantity(struct medicine m[], int n, int index, int quantity) {
    m[index].quantity += quantity;
}

// Function to delete a medicine
void deleteMedicine(struct medicine m[], int *n, int index) {
    for (int i = index; i < (*n)-1; i++) {
        m[i] = m[i+1];
    }
    (*n)--;
}

// Function to calculate total sales
float calculateTotalSales(struct medicine m[], int n) {
    float totalSales = 0;
    for (int i = 0; i < n; i++) {
        totalSales += m[i].price * m[i].quantity;
    }
    return totalSales;
}

int main() {
    int n;
    printf("Enter the number of medicines: ");
    scanf("%d", &n);

    struct medicine m[n];

    // Add medicines
    for (int i = 0; i < n; i++) {
        addMedicine(m, i);
    }

    // Display medicines
    displayMedicines(m, n);

    // Search for a medicine
    char name[50];
    printf("\nEnter medicine name to search: ");
    scanf("%s", name);
    int index = searchMedicine(m, n, name);
    if (index!= -1) {
        printf("\n%s found at index %d\n", name, index+1);
    } else {
        printf("\n%s not found\n", name);
    }

    // Update quantity
    int quantity;
    printf("\nEnter quantity to update: ");
    scanf("%d", &quantity);
    int index2;
    printf("\nEnter medicine index to update: ");
    scanf("%d", &index2);
    updateQuantity(m, n, index2, quantity);

    // Delete a medicine
    int index3;
    printf("\nEnter medicine index to delete: ");
    scanf("%d", &index3);
    deleteMedicine(m, &n, index3);

    // Display updated list of medicines
    displayMedicines(m, n);

    // Calculate total sales
    float totalSales = calculateTotalSales(m, n);
    printf("\nTotal sales: $%.2f\n", totalSales);

    return 0;
}