//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM_SIZE 100

typedef struct {
    char num[MAX_NUM_SIZE];
    int sign;
} BigNumber;

BigNumber* createBigNumber(char* num, int sign) {
    BigNumber* bn = (BigNumber*)malloc(sizeof(BigNumber));
    strcpy(bn->num, num);
    bn->sign = sign;
    return bn;
}

void printBigNumber(BigNumber* bn) {
    if (bn->sign == -1) {
        printf("-");
    }
    printf("%s", bn->num);
}

BigNumber* addBigNumber(BigNumber* bn1, BigNumber* bn2) {
    int len1 = strlen(bn1->num);
    int len2 = strlen(bn2->num);
    int maxLen = len1 > len2 ? len1 : len2;
    char sum[maxLen + 2];
    int carry = 0;
    int i;
    for (i = maxLen - 1; i >= 0; i--) {
        int digit1 = i < len1 ? bn1->num[i] - '0' : 0;
        int digit2 = i < len2 ? bn2->num[i] - '0' : 0;
        int sumDigit = digit1 + digit2 + carry;
        carry = sumDigit / 10;
        sum[i + 1] = sumDigit % 10 + '0';
    }
    sum[0] = carry + '0';
    return createBigNumber(sum, bn1->sign * bn2->sign);
}

BigNumber* subtractBigNumber(BigNumber* bn1, BigNumber* bn2) {
    int len1 = strlen(bn1->num);
    int len2 = strlen(bn2->num);
    int maxLen = len1 > len2 ? len1 : len2;
    char diff[maxLen + 2];
    int borrow = 0;
    int i;
    for (i = maxLen - 1; i >= 0; i--) {
        int digit1 = i < len1 ? bn1->num[i] - '0' : 0;
        int digit2 = i < len2 ? bn2->num[i] - '0' : 0;
        int diffDigit = digit1 - digit2 - borrow;
        if (diffDigit < 0) {
            diffDigit += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        diff[i + 1] = diffDigit + '0';
    }
    diff[0] = borrow + '0';
    return createBigNumber(diff, bn1->sign * bn2->sign);
}

BigNumber* multiplyBigNumber(BigNumber* bn1, BigNumber* bn2) {
    int len1 = strlen(bn1->num);
    int len2 = strlen(bn2->num);
    int prod[len1 + len2 + 2];
    int i, j;
    for (i = 0; i < len1 + len2 + 2; i++) {
        prod[i] = 0;
    }
    for (i = len2 - 1; i >= 0; i--) {
        int digit2 = bn2->num[i] - '0';
        for (j = len1 - 1; j >= 0; j--) {
            int digit1 = bn1->num[j] - '0';
            int prodDigit = digit1 * digit2 + prod[i + j + 1];
            prod[i + j + 1] = prodDigit % 10;
            prod[i + j] += prodDigit / 10;
        }
    }
    char prodStr[len1 + len2 + 2];
    int k;
    for (k = 0; k < len1 + len2 + 2; k++) {
        prodStr[k] = prod[k] + '0';
    }
    return createBigNumber(prodStr, bn1->sign * bn2->sign);
}

BigNumber* divideBigNumber(BigNumber* bn1, BigNumber* bn2) {
    int len1 = strlen(bn1->num);
    int len2 = strlen(bn2->num);
    char quot[len1 + 2];
    int rem[len1 + 2];
    int i, j;
    for (i = 0; i < len1 + 2; i++) {
        quot[i] = '0';
        rem[i] = 0;
    }
    for (i = len1 - 1; i >= 0; i--) {
        rem[i + 1] = bn1->num[i] - '0';
    }
    for (i = len1 - 1; i >= 0; i--) {
        int digit2 = bn2->num[i] - '0';
        for (j = 1; j <= len1 - i; j++) {
            rem[j - 1] += rem[j] * 10;
            rem[j] = 0;
        }
        int q = rem[len1] / digit2;
        rem[len1] = rem[len1] % digit2;
        quot[i] = q + '0';
        for (j = len1; j >= 1; j--) {
            rem[j] -= q * digit2;
            if (rem[j] < 0) {
                rem[j] += 10;
                rem[j - 1]--;
            }
        }
    }
    return createBigNumber(quot, bn1->sign * bn2->sign);
}

int main() {
    char num1[MAX_NUM_SIZE], num2[MAX_NUM_SIZE];
    int choice;
    BigNumber* bn1, *bn2, *result;
    while (1) {
        printf("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%s %s", num1, num2);
                bn1 = createBigNumber(num1, 1);
                bn2 = createBigNumber(num2, 1);
                result = addBigNumber(bn1, bn2);
                printf("Sum: ");
                printBigNumber(result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%s %s", num1, num2);
                bn1 = createBigNumber(num1, 1);
                bn2 = createBigNumber(num2, 1);
                result = subtractBigNumber(bn1, bn2);
                printf("Difference: ");
                printBigNumber(result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%s %s", num1, num2);
                bn1 = createBigNumber(num1, 1);
                bn2 = createBigNumber(num2, 1);
                result = multiplyBigNumber(bn1, bn2);
                printf("Product: ");
                printBigNumber(result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%s %s", num1, num2);
                bn1 = createBigNumber(num1, 1);
                bn2 = createBigNumber(num2, 1);
                result = divideBigNumber(bn1, bn2);
                printf("Quotient: ");
                printBigNumber(result);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
        }
        printf("\n");
    }
    return 0;
}