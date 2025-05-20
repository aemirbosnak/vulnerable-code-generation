//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: recursive
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

//Function to check if a string is a valid date
int isDate(char* date)
{
    struct tm tm;
    strptime(date, "%d/%m/%Y", &tm);
    return (tm.tm_year + 1900) > 0 && (tm.tm_year + 1900) < 3000 && tm.tm_mon >= 1 && tm.tm_mon <= 12 && tm.tm_mday >= 1 && tm.tm_mday <= 31;
}

//Function to convert a string to a date
struct tm* stringToDate(char* date)
{
    struct tm* result = malloc(sizeof(struct tm));
    strptime(date, "%d/%m/%Y", result);
    return result;
}

//Function to convert a date to a string
char* dateToString(struct tm* date)
{
    char* result = malloc(20);
    strftime(result, 20, "%d/%m/%Y", date);
    return result;
}

//Function to convert a string to a natural language date
char* naturalDate(char* date)
{
    struct tm* t = stringToDate(date);
    char* result = malloc(50);
    strftime(result, 50, "Today is %A, %d %B %Y", t);
    return result;
}

//Function to convert a natural language date to a string
char* stringFromNaturalDate(char* date)
{
    char* result = malloc(20);
    strcpy(result, date);
    char* delimiter = strchr(result, ',');
    *delimiter = '\0';
    strcat(result, ", ");
    strcat(result, naturalDate(result));
    return result;
}

//Main function
int main()
{
    char* input = "25/12/2021, Today is Saturday, 25 December 2021";
    char* output;
    char* token = strtok(input, ",");
    while(token!= NULL)
    {
        if(isDate(token))
        {
            output = realloc(output, strlen(output) + strlen(naturalDate(token)) + 2);
            strcat(output, " ");
            strcat(output, naturalDate(token));
        }
        else
        {
            output = realloc(output, strlen(output) + strlen(stringFromNaturalDate(token)) + 2);
            strcat(output, " ");
            strcat(output, stringFromNaturalDate(token));
        }
        token = strtok(NULL, ",");
    }
    printf("%s\n", output);
    return 0;
}