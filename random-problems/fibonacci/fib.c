#include <stdio.h>

int recursive_fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
    }
}

int main()
{
    printf("Hello, World\n");
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        printf("Fibonacci(%d): %d\n", i, recursive_fibonacci(i));
    }
}
