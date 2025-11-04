#include<stdio.h>
void QuickSort(int a[],int left,int right)
{
	int i,j,t,pivot;
	if(left<right)
	{
	    pivot=left;
		i=left+1;
		j=right;
		while(i<j)
		{
			while(a[i]<=a[left]&&i<right)
			i++;
			while(a[j]>a[left])
			j--;
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		t=a[j];
		a[j]=a[left];
		a[left]=t;
		QuickSort(a,left,j-1);
		QuickSort(a,j+1,right);
	}
}
int main()
{
	int arr[25],n,i;
	printf("Enter n value: ");
	scanf("%d",&n);
	printf("Enter %d values: ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	QuickSort(arr,0,n-1);
	printf("Sorted array is: ");
	for(i=0;i<n;i++)
	{
		printf(" %d",arr[i]);
	}
	return 0;
}
