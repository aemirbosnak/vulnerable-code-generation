//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define appointment struct */
typedef struct {
    char date[10];
    char time[6];
    char name[30];
} Appointment;

/* Define function prototypes */
void print_menu();
int get_selection();
void print_appointments(Appointment *appointments, int num_appointments);
void add_appointment(Appointment *appointments, int *num_appointments);
void save_appointments(Appointment *appointments, int num_appointments);
void load_appointments(Appointment *appointments, int *num_appointments);

/* Main function */
int main() {
    int option, num_appointments = 0;
    Appointment appointments[50];
    
    /* Load appointments from file */
    load_appointments(appointments, &num_appointments);
    
    /* Loop until user selects option 5 (Exit) */
    do {
        print_menu();
        option = get_selection();
        
        switch (option) {
            case 1:
                print_appointments(appointments, num_appointments);
                break;
            case 2:
                add_appointment(appointments, &num_appointments);
                break;
            case 3:
                save_appointments(appointments, num_appointments);
                break;
            case 4:
                load_appointments(appointments, &num_appointments);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid selection, please try again.\n");
                break;
        }
    } while (option != 5);
    
    return 0;
}

/* Print menu options */
void print_menu() {
    printf("\nAppointment Scheduler\n");
    printf("1. View Appointments\n");
    printf("2. Add Appointment\n");
    printf("3. Save Appointments\n");
    printf("4. Load Appointments\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

/* Get user's menu selection */
int get_selection() {
    int selection;
    scanf("%d", &selection);
    getchar(); /* Consume newline character */
    return selection;
}

/* Print all appointments */
void print_appointments(Appointment *appointments, int num_appointments) {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
    } else {
        printf("\nAppointments:\n");
        for (int i = 0; i < num_appointments; i++) {
            printf("%d. Date: %s, Time: %s, Name: %s\n", i+1, appointments[i].date, appointments[i].time, appointments[i].name);
        }
    }
}

/* Add new appointment */
void add_appointment(Appointment *appointments, int *num_appointments) {
    Appointment new_appointment;
    
    /* Get date input and store in new appointment */
    printf("Enter date (MM/DD/YYYY): ");
    fgets(new_appointment.date, 10, stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = '\0'; /* Strip newline character */
    
    /* Get time input and store in new appointment */
    printf("Enter time (HH:MM): ");
    fgets(new_appointment.time, 6, stdin);
    new_appointment.time[strcspn(new_appointment.time, "\n")] = '\0'; /* Strip newline character */
    
    /* Get name input and store in new appointment */
    printf("Enter name: ");
    fgets(new_appointment.name, 30, stdin);
    new_appointment.name[strcspn(new_appointment.name, "\n")] = '\0'; /* Strip newline character */
    
    /* Add new appointment to appointments array */
    appointments[*num_appointments] = new_appointment;
    (*num_appointments)++;
    
    printf("Appointment added successfully.\n");
}

/* Save appointments to file */
void save_appointments(Appointment *appointments, int num_appointments) {
    FILE *fptr;
    
    /* Open file for writing */
    fptr = fopen("appointments.dat", "wb");
    
    /* Write appointments to file */
    fwrite(appointments, sizeof(Appointment), num_appointments, fptr);
    
    /* Close file */
    fclose(fptr);
    
    printf("Appointments saved to file.\n");
}

/* Load appointments from file */
void load_appointments(Appointment *appointments, int *num_appointments) {
    FILE *fptr;
    
    /* Open file for reading */
    fptr = fopen("appointments.dat", "rb");
    
    /* If file does not exist, create empty file */
    if (fptr == NULL) {
        fptr = fopen("appointments.dat", "wb");
        fclose(fptr);
        printf("No appointment file found, creating empty file.\n");
        *num_appointments = 0;
        return;
    }
    
    /* Read appointments from file */
    fseek(fptr, 0, SEEK_END);
    long int num_bytes = ftell(fptr);
    rewind(fptr);
    *num_appointments = num_bytes / sizeof(Appointment);
    fread(appointments, sizeof(Appointment), *num_appointments, fptr);
    
    /* Close file */
    fclose(fptr);
    
    printf("Appointments loaded from file.\n");
}