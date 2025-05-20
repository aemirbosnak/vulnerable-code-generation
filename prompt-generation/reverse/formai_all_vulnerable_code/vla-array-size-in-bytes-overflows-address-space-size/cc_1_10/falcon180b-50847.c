//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    char phone[15];
    char email[50];
    time_t appointment_time;
} appointment;

void add_appointment(appointment* app) {
    printf("Enter name: ");
    scanf("%s", app->name);
    printf("Enter age: ");
    scanf("%d", &app->age);
    printf("Enter phone number: ");
    scanf("%s", app->phone);
    printf("Enter email: ");
    scanf("%s", app->email);
    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", app->appointment_time);
}

void display_appointment(appointment* app) {
    printf("Name: %s\n", app->name);
    printf("Age: %d\n", app->age);
    printf("Phone: %s\n", app->phone);
    printf("Email: %s\n", app->email);
    printf("Appointment time: %s\n", ctime(&app->appointment_time));
}

void sort_appointments(appointment* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].appointment_time > arr[j].appointment_time) {
                appointment temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of appointments: ");
    scanf("%d", &n);
    appointment arr[n];
    for (int i = 0; i < n; i++) {
        add_appointment(&arr[i]);
    }
    sort_appointments(arr, n);
    printf("Appointments sorted by time:\n");
    for (int i = 0; i < n; i++) {
        display_appointment(&arr[i]);
    }
    return 0;
}