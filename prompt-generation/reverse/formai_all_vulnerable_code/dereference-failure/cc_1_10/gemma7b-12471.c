//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the parameters for the two families
#define FAMILY_A 0
#define FAMILY_B 1

// Define the structure of a family member
typedef struct FamilyMember {
    char name[20];
    int age;
    double income;
    struct FamilyMember* next;
} FamilyMember;

// Create a linked list of family members for each family
FamilyMember* familyA = NULL;
FamilyMember* familyB = NULL;

// Function to add a family member to the list
void addFamilyMember(FamilyMember* family, char* name, int age, double income) {
    FamilyMember* newMember = (FamilyMember*)malloc(sizeof(FamilyMember));
    strcpy(newMember->name, name);
    newMember->age = age;
    newMember->income = income;
    newMember->next = NULL;

    if (family == NULL) {
        family = newMember;
    } else {
        family->next = newMember;
        family = newMember;
    }
}

// Function to calculate the total income of a family
double calculateTotalIncome(FamilyMember* family) {
    double totalIncome = 0.0;
    FamilyMember* currentMember = family;

    while (currentMember) {
        totalIncome += currentMember->income;
        currentMember = currentMember->next;
    }

    return totalIncome;
}

// Function to compare the total income of two families
int compareTotalIncome(FamilyMember* familyA, FamilyMember* familyB) {
    double totalIncomeA = calculateTotalIncome(familyA);
    double totalIncomeB = calculateTotalIncome(familyB);

    if (totalIncomeA > totalIncomeB) {
        return 1;
    } else if (totalIncomeA < totalIncomeB) {
        return -1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Add family members to both families
    addFamilyMember(familyA, "Romeo", 20, 50000);
    addFamilyMember(familyA, "Juliet", 18, 40000);
    addFamilyMember(familyA, "Benvolio", 22, 60000);
    addFamilyMember(familyB, "Mercutio", 21, 45000);
    addFamilyMember(familyB, "Tybalt", 19, 30000);
    addFamilyMember(familyB, "Escalation", 23, 50000);

    // Compare the total income of the two families
    int comparisonResult = compareTotalIncome(familyA, familyB);

    // Print the result
    if (comparisonResult == 1) {
        printf("Family A has a higher total income than Family B.\n");
    } else if (comparisonResult == -1) {
        printf("Family B has a higher total income than Family A.\n");
    } else {
        printf("The two families have an equal total income.\n");
    }

    return 0;
}