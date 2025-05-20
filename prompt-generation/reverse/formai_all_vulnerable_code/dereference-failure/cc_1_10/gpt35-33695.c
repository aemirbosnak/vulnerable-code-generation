//FormAI DATASET v1.0 Category: QR code reader ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct qr_code {
    char* content;
    int size;
} QR_Code;

void display(QR_Code code)
{
    printf("QR Code size: %d\n", code.size);
    printf("QR Code content: %s\n", code.content);
}

QR_Code scanQR(char* filePath)
{
    FILE* file = fopen(filePath, "r");

    if(file == NULL)
    {
        printf("File could not be opened!\n");
        QR_Code qr = {"", -1};
        return qr;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)calloc(length + 1, sizeof(char));
    fread(buffer, 1, length, file);
    fclose(file);

    QR_Code qr = {buffer, length};
    return qr;
}

int main()
{
    QR_Code qr = scanQR("example.qr");

    if(qr.size == -1)
    {
        return 1;
    }

    display(qr);
    free(qr.content);

    return 0;
}