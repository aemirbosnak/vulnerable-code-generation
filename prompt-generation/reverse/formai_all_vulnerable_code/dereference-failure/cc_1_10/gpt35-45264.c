//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>
#include<fcntl.h>

#define MAX_ATTEMPTS 3 // Maximum attempts to enter correct password
#define MAX_USERS 5 // Maximum number of users
#define MAX_NAME_LEN 20 // Maximum name length
#define MAX_EMAIL_LEN 30 // Maximum email length
#define MAX_PASSWORD_LEN 15 // Maximum password length
#define MAX_APPOINTMENTS 10 // Maximum number of appointments per day
#define MAX_TIME_LEN 10 // Maximum length of time string (HH:MM AM/PM)
#define MIN_HOUR 8 // Minimum hour for appointment booking
#define MAX_HOUR 6 // Maximum hour for appointment booking (after 12 AM)

// Struct for storing user information
struct User{
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char password[MAX_PASSWORD_LEN];
    int appointments[MAX_APPOINTMENTS];
    int num_appointments;
};

// Function to check if entered email is valid
int is_valid_email(char* email){
    char* at_char = strchr(email, '@');
    if(at_char == NULL) return 0;
    if(strchr(at_char+1, '.') == NULL) return 0;
    return 1;
}

// Function to print the list of available times
void print_available_times(){
    printf("\nAvailable Times:\n");
    printf("8:00 AM\n");
    printf("9:00 AM\n");
    printf("10:00 AM\n");
    printf("11:00 AM\n");
    printf("12:00 PM\n");
    printf("1:00 PM\n");
    printf("2:00 PM\n");
    printf("3:00 PM\n");
    printf("4:00 PM\n");
    printf("5:00 PM\n");
}

// Function to check if the entered time is valid and available 
int is_valid_time(char* time, int* index){
    char temp_time[MAX_TIME_LEN];
    strcpy(temp_time, time);
    char* token = strtok(temp_time, ":");
    int hour = atoi(token);
    if(hour < MIN_HOUR || hour > (MAX_HOUR+12)) return 0;
    if(strchr(token+2, ' ') == NULL) return 0;
    token = strtok(NULL, " ");
    if(strcmp(token, "AM") != 0 && strcmp(token, "PM") != 0) return 0;
    if(strcmp(token, "PM") == 0) hour += 12;
    *index = hour - MIN_HOUR;
    return 1;
}

// Function to print the list of appointments for a given day
void print_appointments(int* appointments){
    printf("\nAppointments:\n");
    for(int i=0; i<MAX_APPOINTMENTS; i++){
        printf("%d. ", i+1);
        if(appointments[i] == 0) printf("Available\n");
        else printf("Booked by user %d\n",appointments[i]);
    }
}

// Function to book an appointment for a given user
void book_appointment(int* appointments, int index, int user_index){
    if(appointments[index] == 0){
        appointments[index] = user_index+1;
        printf("\nAppointment booked successfully!\n");
    }
    else printf("\nAppointment already booked. Please choose another time slot.\n");
}

// Function to cancel an appointment for a given user
void cancel_appointment(int* appointments, int index, int user_index){
    if(appointments[index] == user_index+1){
        appointments[index] = 0;
        printf("\nAppointment cancelled successfully!\n");
    }
    else printf("\nThis appointment was not booked by you and cannot be cancelled.\n");
}

// Function to add a new user to the system
int add_user(struct User* users, int num_users){
    if(num_users+1 > MAX_USERS){
        printf("\nCannot add more than %d users.\n", MAX_USERS);
        return num_users;
    }
    printf("\nEnter user details:\n");
    printf("Name: ");
    scanf("%s", users[num_users].name);
    printf("Email: ");
    scanf("%s", users[num_users].email);
    while(!is_valid_email(users[num_users].email)){
        printf("Invalid email. Please enter a valid email: ");
        scanf("%s", users[num_users].email);
    }
    printf("Password (maximum length %d characters): ", MAX_PASSWORD_LEN);
    scanf("%s", users[num_users].password);
    users[num_users].num_appointments = 0;
    return num_users+1;
}

// Function to login an existing user
int login_user(struct User* users, int num_users){
    printf("\nEnter email: ");
    char email[MAX_EMAIL_LEN];
    scanf("%s", email);
    int user_index;
    for(user_index=0; user_index<num_users; user_index++){
        if(strcmp(email, users[user_index].email) == 0) break;
    }
    if(user_index == num_users){
        printf("\nUser with email %s not found.\n", email);
        return -1;
    }
    char entered_password[MAX_PASSWORD_LEN];
    int attempts = 0;
    while(attempts < MAX_ATTEMPTS){
        printf("Enter password: ");
        scanf("%s", entered_password);
        if(strcmp(entered_password, users[user_index].password) == 0) return user_index;
        printf("Incorrect password. %d attempts remaining.\n", MAX_ATTEMPTS-attempts-1);
        attempts++;
    }
    return -1;
}

// Function to print the user menu
void print_user_menu(struct User* users, int user_index, int* appointments){
    printf("\nWelcome, %s!\n", users[user_index].name);
    printf("\nPlease choose an option:\n");
    printf("1. View Appointments\n");
    printf("2. Book Appointment\n");
    printf("3. Cancel Appointment\n");
    printf("4. Logout\n");
    int option;
    scanf("%d", &option);
    switch(option){
        case 1:
            print_appointments(appointments);
            print_user_menu(users, user_index, appointments);
            break;
        case 2:
            print_available_times();
            printf("\nEnter appointment time (HH:MM AM/PM): ");
            char time[MAX_TIME_LEN];
            scanf("%s", time);
            int index;
            if(!is_valid_time(time, &index)){
                printf("\nInvalid time. Please try again.\n");
                print_user_menu(users, user_index, appointments);
            }
            else{
                book_appointment(appointments, index, user_index);
                users[user_index].appointments[users[user_index].num_appointments] = index+1;
                users[user_index].num_appointments++;
                print_user_menu(users, user_index, appointments);
            }
            break;
        case 3:
            printf("\nEnter appointment number to cancel: ");
            int app_num;
            scanf("%d", &app_num);
            if(app_num < 1 || app_num > MAX_APPOINTMENTS){
                printf("\nInvalid appointment number. Please try again.\n");
                print_user_menu(users, user_index, appointments);
            }
            else{
                int index = app_num-1;
                cancel_appointment(appointments, index, user_index);
                int found = 0;
                for(int i=0; i<users[user_index].num_appointments; i++){
                    if(users[user_index].appointments[i] == app_num){
                        found = 1;
                        for(int j=i; j<users[user_index].num_appointments-1; j++){
                            users[user_index].appointments[j] = users[user_index].appointments[j+1];
                        }
                        users[user_index].num_appointments--;
                        break;
                    }
                }
                if(!found){
                    printf("\nThis appointment was not booked by you and cannot be cancelled.\n");
                }
                print_user_menu(users, user_index, appointments);
            }
            break;
        case 4:
            return;
        default:
            printf("\nInvalid option. Please try again.\n");
            print_user_menu(users, user_index, appointments);
    }    
}

// Function to print the main menu
int print_main_menu(struct User* users, int num_users, int* appointments){
    printf("\nWelcome to Appointment Scheduler!\n");
    printf("\nPlease choose an option:\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n");
    int option;
    scanf("%d", &option);
    switch(option){
        case 1:
            return login_user(users, num_users);
        case 2:
            return add_user(users, num_users);
        case 3:
            return -1;
        default:
            printf("\nInvalid option. Please try again.\n");
            return print_main_menu(users, num_users, appointments);
    }
}

int main(){
    struct User users[MAX_USERS];
    int num_users = 0;
    int appointments[MAX_APPOINTMENTS] = {0};
    while(1){
        int user_index = print_main_menu(users, num_users, appointments);
        if(user_index == -1) break;
        print_user_menu(users, user_index, appointments);
    }
    printf("\nGoodbye!\n");
    return 0;
}