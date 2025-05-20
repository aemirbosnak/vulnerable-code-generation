//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824


//function to calculate the directory size
unsigned long long int calculate_directory_size(char *directory_name)
{
    unsigned long long int size = 0;
    char command[400];

    //command to get size of directory using linux command "du -sb"
    sprintf(command, "du -sb %s | awk {'print $1'}", directory_name);
    
    FILE *fp = popen(command, "r");
    char output[20];

    //read the size of the directory from the output of the command
    fgets(output, sizeof(output), fp);
    size = atol(output);
    pclose(fp);
    
    return size;
}


//function to print the size in human readable format
void print_size(unsigned long long int size)
{
    if (size > GB)
        printf("%.2f GB\n", (double)size/GB);
    else if (size > MB)
        printf("%.2f MB\n", (double)size/MB);
    else if (size > KB)
        printf("%.2f KB\n", (double)size/KB);
    else
        printf("%llu Bytes\n", size);
}


int main()
{
    char directory_name[100];

    printf("Enter the path of directory: ");
    scanf("%s", directory_name);

    printf("Calculating Size...\n");
    unsigned long long int size = calculate_directory_size(directory_name);

    printf("\nThe size of directory %s is ", directory_name);
    print_size(size);

    return 0;
}