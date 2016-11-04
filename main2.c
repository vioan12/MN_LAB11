#include<stdio.h>
#include<math.h>
int main()
{
    float x[100],f[100],h[100],bb[100][100],aux,a[100],b[100],c[100],t[100],s,piv;
    int i,j,n,k,p;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
        scanf("%f",&x[i]);
    for(i=0;i<=n;i++)
        scanf("%f",&f[i]);
    for(i=1;i<=n;i++)
        h[i]=x[i]-x[i-1];
    for(i=1;i<=n-1;i++)
        a[i]=2*(h[i]+h[i+1]);
    for(i=1;i<=n-2;i++){
        b[i]=h[i+1];
        c[i]=b[i];
    }
    for(i=1;i<=n-1;i++)
        t[i]=6*(f[i+1]-f[i])/h[i+1]-6*(f[i]-f[i-1])/h[i];
    for(i=1;i<=n-1;i++)
        bb[i][i]=0;
    for(i=1;i<=n-1;i++)
        bb[i][i]=a[i];
    for(i=1;i<=n-2;i++)
        bb[i+1][i]=c[i];
    for(i=1;i<=n-2;i++)
        bb[i][i+1]=b[i];
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-1;j++)
        {
            printf("%f",bb[i][j]);
        }
    }
    printf("\n");
if(bb[1][1]==0)
{
    i=1;
    do{
        i++;
    }while(bb[i][1]==0&&i<=n-1);
    if(i>n-1)
    {
        printf("sistemul nu are sol unica");
        return 0;
    }
    for(j=1;j<=n;j++)
    {
        aux=bb[1][j];
        bb[1][j]=bb[i][j];
        bb[i][j]=aux;
    }
}
for(i=2;i<=n-1;i++)
    bb[i][1]=bb[i][1]/bb[1][1];
for(k=2;k<=n-1;k++)
{
    i=k;
    do{

        s=0;
        for(p=1;p<=k-1;p++)
            s=s+bb[i][p]*bb[p][k];
        piv=bb[i][k]-s;
        i=i+1;
    }while(piv==0&&i<=n-1);
    if(piv==0)
    {
        printf("sistemul nu are sol unica");
        return 0;
    }
    if(i!=k+1)
        for(j=1;j<=n;j++)
    {
        aux=bb[k][j];
        bb[k][j]=bb[i-1][j];
        bb[i-1][j]=aux;
    }
    for(j=k;j<=n-1;j++)
    {
        s=0;
        for(p=1;p<=k-2;p++)
            s=s+bb[k][p]*bb[p][j];
        bb[k][j]=bb[k][j]-s;
    }
    for(i=k+1;i<=n-1;i++)
    {
        s=0;
        for(p=1;p<=k-2;p++)
            s=s+bb[i][p]*bb[p][k];
        bb[i][k]=(bb[i][k]-s)/bb[k][k];
    }


}
for(i=2;i<=n-1;i++)
{
    s=0;
    for(j=1;j<=i-2;j++)
        s=s+bb[i][j]*bb[j][n+1];
    bb[i][n+1]=bb[i][n+1]-s;
}
bb[n][n+1]=bb[n][n+1]/bb[n][n];
for(i=n-2;i>=1;i--)
{
    s=0;
    for(j=i+1;j<=n-1;j++)
        s=s+bb[i][j]*bb[j][n+1];
    bb[i][n+1]=(bb[i][n+1]-s)/bb[i][i];
}
for(i=1;i<=n-1;i++)
    printf("x[%d]=[%f]",i,bb[i][n+1]);
    return 0;
}
