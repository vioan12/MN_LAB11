#include <stdio.h>
#include<math.h>
float f(float x)
{
    return 1/(x+1);
}
int main()
{
    float II,h,b,a,IO,s,e;
    int n,i;
    scanf("%f%f%f",&a,&b,&e);
    n=1;
    II=(f(a)+f(b))*(b-a)/n;
    do{
        n=2*n;
        h=(b-a)/n;
        IO=II;
        s=0;
        for(i=1;i<=n-1;i++)
            s=s+f(a+i*h);
        II=(f(a)+2*s+f(b))*h/2;
    }while(fabs(II-IO)>e);
    printf("Valoarea integralei , obtinuta cu precizia %f este %f",e,II);
    return 0;
}
