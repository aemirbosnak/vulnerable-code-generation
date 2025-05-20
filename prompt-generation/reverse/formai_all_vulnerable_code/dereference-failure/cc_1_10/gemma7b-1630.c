//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct QRCode {
    Node* head;
    int size;
    char data[MAX];
};

void insert(struct QRCode* qrcode, char data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (qrcode->head == NULL)
    {
        qrcode->head = newNode;
    }
    else
    {
        qrcode->head->next = newNode;
    }

    qrcode->size++;
}

void generate(struct QRCode* qrcode)
{
    qrcode->size = 0;
    qrcode->head = NULL;

    printf("Enter data: ");
    scanf("%s", qrcode->data);

    char* data = qrcode->data;
    for (int i = 0; data[i] != '\0'; i++)
    {
        insert(qrcode, data[i]);
    }

    printf("QRCode generated:\n");
    for (Node* node = qrcode->head; node != NULL; node = node->next)
    {
        printf("%c ", node->data);
    }
    printf("\n");
}

int main()
{
    struct QRCode* qrcode = malloc(sizeof(struct QRCode));
    qrcode->head = NULL;
    qrcode->size = 0;

    generate(qrcode);

    return 0;
}