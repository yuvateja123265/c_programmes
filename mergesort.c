#include<stdio.h>
void merge(int arr[],int left,int mid,int right)
{
	int temp[right-left+1];
	int i=left,j=mid+1,k=0;
	while(i<=mid&&j<=right)
	{
		if(arr[i]<arr[j])
		{
			temp[k]=arr[i];
			i++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=right)
	{
		temp[k]=arr[j];
		j++;k++;
	}
	for(i=left,k=0;i<=right;k++,i++)
	{
		arr[i]=temp[k];
	}
}
void mergesort(int arr[],int left, int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
int main()
{
	int n,a[20],i;
	printf("Enter n=");
	scanf("%d",&n);
	printf("Enter elements=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("After sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
