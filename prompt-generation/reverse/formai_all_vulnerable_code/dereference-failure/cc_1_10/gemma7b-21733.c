//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store data
typedef struct Patient
{
    char name[50];
    int age;
    char address[100];
    float weight;
    float height;
    char blood_group[2];
    struct Patient* next;
} Patient;

// Create a linked list of patients
Patient* head = NULL;

// Function to insert a new patient into the linked list
void insert_patient(char* name, int age, char* address, float weight, float height, char* blood_group)
{
    // Allocate memory for a new patient node
    Patient* new_patient = (Patient*)malloc(sizeof(Patient));

    // Copy the patient's data into the node
    strcpy(new_patient->name, name);
    new_patient->age = age;
    strcpy(new_patient->address, address);
    new_patient->weight = weight;
    new_patient->height = height;
    strcpy(new_patient->blood_group, blood_group);

    // If the linked list is empty, make the new node the head
    if (head == NULL)
    {
        head = new_patient;
    }
    else
    {
        // Traverse the linked list until the last node is reached
        Patient* last_patient = head;
        while (last_patient->next != NULL)
        {
            last_patient = last_patient->next;
        }

        // Insert the new node at the end of the list
        last_patient->next = new_patient;
    }
}

// Function to search for a patient by name
Patient* search_patient(char* name)
{
    // Traverse the linked list to find the patient
    Patient* patient = head;
    while (patient)
    {
        if (strcmp(patient->name, name) == 0)
        {
            return patient;
        }
        patient = patient->next;
    }

    // Patient not found
    return NULL;
}

// Function to update a patient's information
void update_patient(char* name, int new_age, char* new_address, float new_weight, float new_height)
{
    // Search for the patient and update their information
    Patient* patient = search_patient(name);
    if (patient)
    {
        patient->age = new_age;
        strcpy(patient->address, new_address);
        patient->weight = new_weight;
        patient->height = new_height;
    }
}

// Function to delete a patient from the linked list
void delete_patient(char* name)
{
    // Search for the patient and remove them from the list
    Patient* patient = search_patient(name);
    if (patient)
    {
        Patient* prev_patient = NULL;
        Patient* current_patient = head;

        // If the patient is the first node in the list, update the head
        if (prev_patient == NULL)
        {
            head = patient->next;
        }
        else
        {
            // Traverse the linked list to find the patient's previous node
            while (current_patient->next != NULL && current_patient->next->name != name)
            {
                prev_patient = current_patient;
                current_patient = current_patient->next;
            }

            // If the patient is found, delete them from the list
            if (current_patient)
            {
                prev_patient->next = current_patient->next;
                free(current_patient);
            }
        }
    }
}

int main()
{
    // Insert some patients into the linked list
    insert_patient("John Doe", 25, "123 Main St.", 80.0, 1.8, "AB");
    insert_patient("Jane Doe", 30, "456 Oak Ave.", 75.0, 1.6, "O");
    insert_patient("Peter Pan", 12, "Neverland", 50.0, 1.5, "B");

    // Search for a patient by name
    Patient* patient = search_patient("Jane Doe");
    if (patient)
    {
        printf("Name: %s\n", patient->name);
        printf("Age: %d\n", patient->age);
        printf("Address: %s\n", patient->address);
        printf("Weight: %.2f\n", patient->weight);
        printf("Height: %.2f\n", patient->height);
        printf("Blood group: %s\n", patient->blood_group);
    }

    // Update a patient's information
    update_patient("John Doe", 35, "567 Oak Ave.", 85.0, 1.9);

    // Delete a patient from the linked list
    delete_patient("Peter Pan");

    return 0;
}