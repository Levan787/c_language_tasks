#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
int main()
{
    int m;
    int i;

    bool primeCheck=true;

    printf("Enter value of m : ");
    scanf("%d", &m);
    i<sqrt(m);

    for(i=2; i<=sqrt(m); i++){
        if(m%i==0) primeCheck=false;
    }

    (primeCheck) ? printf("\n%d is prime\n", m) : printf("\n%d is not prime\n", m);

    return 0;
}


