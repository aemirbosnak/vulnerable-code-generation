//FormAI DATASET v1.0 Category: File Synchronizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
* C File Synchronizer Example Program
*
* This program synchronizes two text files line by line, ensuring that each line in each file
* is the same. If a line is missing in either file, it will be added with the value of "0".
* If a line is present in both files, but the values are different, they will be averaged.
*/

int main()
{
    // Open the two files to be synchronized
    FILE *file1, *file2;
    file1 = fopen("file1.txt", "r");
    file2 = fopen("file2.txt", "r");

    // Variables to hold each line from the files
    char line1[100], line2[100];

    // Variable to count the number of lines in each file
    int count1 = 0, count2 = 0;

    // Variables to hold the sum of all values for each file
    double sum1 = 0.0, sum2 = 0.0;

    // Count the number of lines in file1
    while (fgets(line1, 100, file1) != NULL)
    {
        count1++;
        sum1 += atof(line1);
    }

    // Count the number of lines in file2 and adjust sum1 accordingly
    while (fgets(line2, 100, file2) != NULL)
    {
        count2++;
        sum2 += atof(line2);
        if (count2 > count1)
        {
            fprintf(file1, "0\n");
            count1++;
        }
    }

    // Check if file2 had fewer lines than file1
    while (count2 < count1)
    {
        fprintf(file2, "0\n");
        count2++;
    }

    // Go back to the beginning of each file
    fseek(file1, 0, SEEK_SET);
    fseek(file2, 0, SEEK_SET);

    // Variables to hold the averages for each line
    double average1, average2;

    // Synchronize each line in the files
    for (int i = 0; i < count1; i++)
    {
        fgets(line1, 100, file1);
        fgets(line2, 100, file2);

        if (strcmp(line1, line2) != 0)
        {
            average1 = atof(line1);
            average2 = atof(line2);
            if (average1 == 0.0)
            {
                average1 = average2;
            }
            else if (average2 == 0.0)
            {
                average2 = average1;
            }
            else
            {
                average1 = (average1 + average2) / 2.0;
                average2 = average1;
            }
            sprintf(line1, "%.3lf\n", average1);
            sprintf(line2, "%.3lf\n", average2);
            fseek(file1, -strlen(line1), SEEK_CUR);
            fseek(file2, -strlen(line2), SEEK_CUR);
            fputs(line1, file1);
            fputs(line2, file2);
        }
    }

    // Close the files
    fclose(file1);
    fclose(file2);

    // Print a message indicating that synchronization was successful
    printf("Files synchronized successfully!\n");

    return 0;
}