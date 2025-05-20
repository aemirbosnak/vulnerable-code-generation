//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 256

struct patient {
    char name[MAX_LENGTH];
    int age;
    char gender[MAX_LENGTH];
    char contact[MAX_LENGTH];
    char email[MAX_LENGTH];
    char appointmentDate[MAX_LENGTH];
    char doctor[MAX_LENGTH];
    struct patient *next;
};

struct patient *start = NULL;

void createPatientRecord() {
    struct patient *newPatient = (struct patient*)malloc(sizeof(struct patient));
    printf("\nEnter the patient's name: ");
    scanf("%[^\n]%*c", newPatient->name);
    printf("Enter the patient's age: ");
    scanf("%d", &newPatient->age);
    printf("Enter the patient's gender: ");
    scanf("%s", newPatient->gender);
    printf("Enter the patient's contact number: ");
    scanf("%s", newPatient->contact);
    printf("Enter the patient's email address: ");
    scanf("%s", newPatient->email);
    printf("Enter the appointment date (YYYY-MM-DD): ");
    scanf("%s", newPatient->appointmentDate);
    printf("Enter the doctor's name: ");
    scanf("%s", newPatient->doctor);
    newPatient->next = NULL;

    if(start == NULL) {
        start = newPatient;
    } else {
        struct patient *temp = start;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }
}

void printPatientRecord(struct patient *patientData) {
    printf("\nName: %s\nAge: %d\nGender: %s\nContact: %s\nEmail: %s\nAppointment date: %s\nDoctor: %s", patientData->name, patientData->age, patientData->gender, patientData->contact, patientData->email, patientData->appointmentDate, patientData->doctor);
}

void viewPatientRecord() {
    struct patient *temp = start;
    if(temp == NULL) {
        printf("\nNo patient records found!");
    } else {
        while(temp != NULL) {
            printPatientRecord(temp);
            temp = temp->next;
            printf("\n----------------------------\n");
        }
    }
}

void searchPatientRecord() {
    char name[MAX_LENGTH];
    printf("\nEnter the patient's name to search: ");
    scanf("%[^\n]%*c", name);
    struct patient *temp = start;
    int found = 0;
    while(temp != NULL) {
        if(strcmp(temp->name, name) == 0) {
            found = 1;
            printf("\nSearch result for %s:\n\n", name);
            printPatientRecord(temp);
            break;
        }
        temp = temp->next;
    }
    if(!found) {
        printf("\nNo records found for %s\n", name);
    }
}

void deletePatientRecord() {
    char name[MAX_LENGTH];
    printf("\nEnter the patient's name to delete: ");
    scanf("%[^\n]%*c", name);
    struct patient *temp = start, *prev;
    int found = 0;
    if(temp != NULL && strcmp(temp->name, name) == 0) {
        start = temp->next;
        free(temp);
        found = 1;
    } else {
        while(temp != NULL) {
            if(strcmp(temp->name, name) == 0) {
                found = 1;
                prev->next = temp->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    if(found) {
        printf("\nRecord for %s deleted successfully!\n", name);
    } else {
        printf("\nNo records found for %s\n", name);
    }
}

int menu() {
    int choice;
    printf("\n\n****Appointment Scheduler****\n");
    printf("\n\n1. Create new patient record");
    printf("\n2. View all patient records");
    printf("\n3. Search for a patient record");
    printf("\n4. Delete a patient record");
    printf("\n5. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    while(1) {
        int choice = menu();
        switch (choice) {
            case 1:
                createPatientRecord();
                break;
            case 2:
                viewPatientRecord();
                break;
            case 3:
                searchPatientRecord();
                break;
            case 4:
                deletePatientRecord();
                break;
            case 5:
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}