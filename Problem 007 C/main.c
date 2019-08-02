#include <stdio.h>
#include <math.h>

int isPrime(int test)
{
    int calculateTo = (int) sqrt(test);

    for(int i=3; i<=calculateTo; i+=2)
    {
        if(test%i==0)
            return 0;
    }

    return 1;
}

int main()
{
    int max=10001;
    int counter=1;

    while (1)
    {
        for(int i=3; ; i+=2)
        {
            if( isPrime(i) )
                counter++;

            if(counter==max)
            {
                printf("%d\n", i);
                return 0;
            }
        }

    }

    return 1;
}