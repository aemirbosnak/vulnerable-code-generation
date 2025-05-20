//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct DateConverter
{
    char buffer[MAX_BUFFER_SIZE];
    time_t timestamp;
    struct DateConverter* next;
} DateConverter;

DateConverter* createDateConverter()
{
    DateConverter* converter = malloc(sizeof(DateConverter));
    converter->timestamp = time(NULL);
    converter->next = NULL;
    return converter;
}

void addDateConverter(DateConverter* head, char* date)
{
    DateConverter* converter = createDateConverter();
    strcpy(converter->buffer, date);
    converter->next = head;
    head = converter;
}

void convertDate(DateConverter* head)
{
    for (DateConverter* converter = head; converter; converter = converter->next)
    {
        char* date = converter->buffer;
        time_t timestamp = converter->timestamp;
        struct tm* tm = localtime(&timestamp);
        printf("%d-%d-%d %d:%d:%d %s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, asctime(tm));
    }
}

int main()
{
    DateConverter* head = NULL;
    addDateConverter(head, "2023-06-01");
    addDateConverter(head, "2023-06-02");
    addDateConverter(head, "2023-06-03");
    convertDate(head);

    return 0;
}