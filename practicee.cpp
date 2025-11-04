#include<stdio.h>
void Radixsort(int a[],int n)
{
	int digits=0,i,k,j,count[10],bucket[10][10],big,steps,pos,div=1;
	big=a[1];
	for(i=0;i<n;i++)
	{
		if(big<a[i])
		{
			big=a[i];
		}
	}
	while(big>0)
	{
		digits++;
		big=big/10;
	}
	for(steps=1;steps<=digits;steps++)
	{
		for(j=0;j<10;j++)
		{
			count[j]=0;
		}
		for(i=0;i<n;i++)
		{
			pos=(a[i]/div)%10;
			bucket[pos][count[pos]++]=a[i];
		}
		k=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<count[i];j++,k++)
			{
				a[k]=bucket[i][j];
			}
		}
		div=div*10;
	}
}
int main()
{
	int i,a[100];
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	Radixsort(a,n);
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
	return 0;
}
