#include <stdio.h>
#include <stdlib.h>

int main()
{ int RedID;
scanf("%d", &RedID);

printf("%d\n",RedID/100000000);
RedID %= 100000000;
printf("%d\n",RedID/10000000);
RedID %= 10000000;
printf("%d\n",RedID/1000000);
RedID %= 1000000;
printf("%d\n",RedID/100000);
RedID %= 100000;
printf("%d\n",RedID/10000);
RedID %= 10000;
printf("%d\n",RedID/1000);
RedID %= 1000;
printf("%d\n",RedID/100);
RedID %= 100;
printf("%d\n",RedID/10);
RedID %= 10;
printf("%d\n",RedID);
printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 8,2,3,4,5,3,0,7,9);

    return 0;
}
