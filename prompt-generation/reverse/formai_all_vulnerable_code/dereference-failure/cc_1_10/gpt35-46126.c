//FormAI DATASET v1.0 Category: Online Examination System ; Style: innovative
#include<stdio.h>
#include<string.h>

//function to display the menu options
void displayMenu() {
    printf("Welcome to Online Examination System\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Start Exam\n");
    printf("4. View Result\n");
    printf("5. Exit\n");
    printf("Please Enter your Choice: ");
}

//function to register a new user
void registerUser() {
    printf("\n-- Registration Form --\n");
    char username[30], password[30];
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);
    FILE *fp;
    fp = fopen("users.txt","a");
    fprintf(fp,"%s,%s,0\n",username,password);
    fclose(fp);
    printf("Registration Successful!\n\n");
}

//function to check if the given user credentials are valid
int loginUser(char *username, char *password) {
    FILE *fp;
    fp = fopen("users.txt","r");
    char line[100];
    while(fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, ",");
        if(strcmp(token, username)==0) {
            token = strtok(NULL, ",");
            if(strcmp(token, password)==0) {
                fclose(fp);
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}

//function to start the exam
void startExam(char *username) {
    printf("\n-- Exam Started --\n");
    int score = 0;
    printf("Q1. What is the capital of India?\n");
    printf("a. Mumbai\n");
    printf("b. New Delhi\n");
    printf("c. Bangalore\n");
    char answer[10];
    printf("Your Answer: ");
    scanf("%s", answer);
    if(strcmp(answer, "b")==0) {
        score += 5;
    }
    printf("Q2. Who is the CEO of Microsoft?\n");
    printf("a. Satya Nadella\n");
    printf("b. Sundar Pichai\n");
    printf("c. Mark Zuckerberg\n");
    printf("Your Answer: ");
    scanf("%s", answer);
    if(strcmp(answer, "a")==0) {
        score += 5;
    }
    printf("Q3. Which animal is known as the 'Ship of the Desert'?\n");
    printf("a. Goat\n");
    printf("b. Camel\n");
    printf("c. Horse\n");
    printf("Your Answer: ");
    scanf("%s", answer);
    if(strcmp(answer, "b")==0) {
        score += 5;
    }
    printf("Q4. Who is regarded as the 'Father of Computer Science'?\n");
    printf("a. Alan Turing\n");
    printf("b. Tim Berners-Lee\n");
    printf("c. Bill Gates\n");
    printf("Your Answer: ");
    scanf("%s", answer);
    if(strcmp(answer, "a")==0) {
        score += 5;
    }
    printf("Q5. What is the smallest continent in the world?\n");
    printf("a. Africa\n");
    printf("b. Asia\n");
    printf("c. Australia\n");
    printf("Your Answer: ");
    scanf("%s", answer);
    if(strcmp(answer, "c")==0) {
        score += 5;
    }
    printf("Exam Completed!\n");
    FILE *fp;
    fp = fopen("results.txt", "a");
    fprintf(fp, "%s,%d\n", username, score);
    fclose(fp);
    printf("Your Score: %d\n\n", score);
}

//function to view the last result of the logged in user
void viewResult(char *username) {
    FILE *fp;
    fp = fopen("results.txt","r");
    char line[100], lastScore[10];
    while(fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, ",");
        if(strcmp(token, username)==0) {
            token = strtok(NULL, ",");
            strcpy(lastScore, token);
        }
    }
    fclose(fp);
    printf("\n-- Last Result --\n");
    printf("Username: %s\n", username);
    printf("Score: %s\n\n", lastScore);
}

int main() {
    int choice;
    char username[30], password[30];
    while(1) {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                printf("\n-- Login --\n");
                printf("Enter Username: ");
                scanf("%s", username);
                printf("Enter Password: ");
                scanf("%s", password);
                if(loginUser(username, password)) {
                    printf("Login Successful!\n\n");
                } else {
                    printf("Invalid Credentials!\n\n");
                }
                break;
            case 3:
                startExam(username);
                break;
            case 4:
                viewResult(username);
                break;
            case 5:
                printf("Thank you for using Online Examination System. Goodbye!\n");
                return 0;
                break;
            default:
                printf("Invalid Choice!\n\n");
                break;
        }
    }
    return 0;
}