//FormAI DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

//function to display options menu
void displayMenu() {
    printf("----------------------------\n");
    printf("Digital Diary\n");
    printf("----------------------------\n");
    printf("1. View diary entries\n");
    printf("2. Add a new diary entry\n");
    printf("3. Delete a diary entry\n");
    printf("4. Search diary entries\n");
    printf("5. Exit\n");
}

int main() {
    int n, i, choice;
    char text[1000];
    FILE *fptr;

    printf("Welcome to your Digital Diary!\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            //View diary entries
            case 1:
                fptr = fopen("diary.txt", "r");
                if (fptr == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }
                while (fgets(text, 1000, fptr)) {
                    printf("%s", text);
                }
                fclose(fptr);
                break;
            
            //Add a new diary entry
            case 2:
                fptr = fopen("diary.txt", "a");
                if (fptr == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }
                printf("Enter your diary entry:\n");
                getchar();
                fgets(text, 1000, stdin);
                fprintf(fptr, "%s\n", text);
                printf("Diary entry added successfully!\n");
                fclose(fptr);
                break;

            //Delete a diary entry
            case 3:
                fptr = fopen("diary.txt", "r");
                FILE *temp = fopen("temp.txt", "w");
                if (fptr == NULL || temp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }
                printf("Enter the line number of the entry you want to delete: ");
                scanf("%d", &n);
                for (i = 1; fgets(text, 1000, fptr); i++) {
                    if (i != n) {
                        fprintf(temp, "%s", text);
                    }
                }
                fclose(fptr);
                fclose(temp);
                remove("diary.txt");
                rename("temp.txt", "diary.txt");
                printf("Diary entry deleted successfully!\n");
                break;

            //Search diary entries
            case 4:
                fptr = fopen("diary.txt", "r");
                if (fptr == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }
                printf("Enter the search term: ");
                scanf("%s", text);
                for (i = 1; fgets(text, 1000, fptr); i++) {
                    if (strstr(text, text) != NULL) {
                        printf("%d. %s", i, text);
                    }
                }
                fclose(fptr);
                break;

            //Exit the program
            case 5:
                printf("Thank you for using Digital Diary!\n");
                break;

            //Invalid choice
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}