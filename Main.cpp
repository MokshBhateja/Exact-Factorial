#include<iostream>
#include<math.h>

using namespace std;

#define Fac_Length 36000
#define N_Digits 6

long len(long a[])
{
    long i=Fac_Length;
    for(;i>=0;i--)
        if(a[i]!=0)
            break;
    return i+1;
}

long Len_n(long n)
{
    long i;
    for(i=1;n!=0;i++)
        n=n/10;
    return i-1;
}

int main()
{
	long a[N_Digits+1][Fac_Length+1];
	long n,nn;
	long i,j;
	long LEN_n,m;
	long len_a;
	long N;
	cin>>N;
	for(i=0;i<=Fac_Length;i++)
	    a[0][i]=0;
	a[0][0]=1;
	for(nn=1;nn<=N;nn++)
	{
	    n=nn;
	    for(j=1;j<=N_Digits;j++)
    	{
        	for(i=0;i<=Fac_Length;i++)
        	    a[j][i]=0;
    	}
    	LEN_n=Len_n(n);
    	for(j=1;j<=LEN_n;j++)
    	{
    	    len_a=len(a[0]);
        	for(i=0;i<len_a;i++)
        	{
        	    a[j][i+j-1]+=a[0][i]*(n%10);
        	    a[j][i+1+j-1]=a[j][i+j-1]/10;
        	    a[j][i+j-1]=a[j][i+j-1]%10;
        	}
        	n=n/10;
    	}
    	for(i=0;i<=Fac_Length;i++)
	        a[0][i]=0;
    	for(i=0;i<=Fac_Length;i++)
    	{
    	    for(int k=1;k<=N_Digits;k++)
    	        a[0][i]+=a[k][i];
    	    a[0][i+1]=a[0][i]/10;
    	    a[0][i]=a[0][i]%10;
    	}
	}
	cout<<N<<"!\n\n";
	for(i=len(a[0])-1;i>=0;i--)
	    cout<<a[0][i];
}
