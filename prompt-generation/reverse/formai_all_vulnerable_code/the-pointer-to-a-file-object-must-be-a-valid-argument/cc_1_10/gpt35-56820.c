//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include<stdio.h>

//function that writes data to a file
void write_to_file() {
    FILE *fp;
    char data[100];

    //opening the file in write mode
    fp = fopen("my_file.txt", "w");

    //getting the user input
    printf("Enter some data to write in file:\n");
    fgets(data, 100, stdin);

    //writing the user input to the file
    fprintf(fp, "%s\n", data);

    printf("Data written to file successfully!\n");

    //closing the file
    fclose(fp);
}

//function that reads data from a file
void read_from_file() {
    FILE *fp;
    char data[100];

    //opening the file in read mode
    fp = fopen("my_file.txt", "r");

    //reading the data from the file
    fgets(data, 100, fp);

    printf("The content of file is:\n%s", data);

    //closing the file
    fclose(fp);
}

int main() {
    printf("Welcome to my_file.txt handling program!\n");

    //calling the function to write data to file
    write_to_file();

    //calling the function to read data from file
    read_from_file();

    printf("Thanks for using my program!\n");

    return 0;
}