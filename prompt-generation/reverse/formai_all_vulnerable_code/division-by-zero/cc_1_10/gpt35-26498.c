//FormAI DATASET v1.0 Category: Arithmetic ; Style: optimized
#include<stdio.h>

int main()
{
    int a,b,c,ans;
    char opr;

    printf("Enter the values of a and b: ");
    scanf("%d %d",&a,&b);
    printf("Enter the arithmetic operator (+,-,*,/,%): ");
    scanf(" %c",&opr);

    switch(opr)
    {
        case '+':
            ans=a+b;
            printf("%d + %d = %d\n",a,b,ans);
            break;

        case '-':
            ans=a-b;
            printf("%d - %d = %d\n",a,b,ans);
            break;

        case '*':
            ans=a*b;
            printf("%d * %d = %d\n",a,b,ans);
            break;

        case '/':
            if(b==0)
            {
                printf("Denominator cannot be zero.\n");
            }
            else
            {
                ans=a/b;
                printf("%d / %d = %d\n",a,b,ans);
            }
            break;

        case '%':
            ans=a%b;
            printf("%d %% %d = %d\n",a,b,ans);
            break;

        default:
            printf("Invalid operator!\n");
    }
    return 0;
}