#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int sum = 0;
    long n = get_long("Number: ");
    for (long i = 100; i < (10 * n + 1); i = i * 100)
    {
        long a = ((n % i) - n % (i / 10)) / (i / 10);
        if (a < 5)
        {
            sum = sum + 2 * a;
        }
        else
        {
            sum = sum + 1 + (2 * a) % 10;
        }
    }
    for (long i = 10; i < (10 * n + 1); i = i * 100)
    {
        long a = ((n % i) - n % (i / 10)) / (i / 10);
        sum = sum + a;
    }
    if (sum % 10 == 0)
    {
        // gives one digit answer for 13 digit number
        float num = n / 1000000000000;
        // 16 digit
        if (num >= 5100 && num < 5600)
        {
            printf("MASTERCARD\n");
        }
        // 15 digit
        else if ((num >= 340 && num < 350) || (num >= 370 && num < 380))
        {
            printf("AMEX\n");
        }
        else if (num >= 4000 && num < 5000)
        {
            printf("VISA\n");
        }
        else if (num >= 4 && num < 5)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
