#include <stdio.h>

int factorial(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int recursive_factorial(int num)
{
    switch (num)
    {
    case 0:
    case 1:
        return 1;
    default:
        return num * recursive_factorial(num - 1);
    }
}

int main()
{
    printf("Hello, World!\n");
    int num = 5;
    printf("Factorial of %d: %d\n", num, recursive_factorial(num));
    return 0;
}
