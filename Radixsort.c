#include<stdio.h> 
void radixsort(int a[],int n) 
{ 
 	int digits=0,big,i,bucket[10][n],count[10],div=1,j,k,steps,pos; 
 	big=a[0]; 
 	for(i=0;i<n;i++) 
 	{ 
		if(a[i]>big) 
  		big=a[i]; 
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
    int n,a[25],i; 
    printf("Enter number of elements:"); 
    scanf("%d",&n); 
    printf("Enter %d elements\n",n); 
    for(i=0;i<n;i++) 
    { 
        scanf("%d",&a[i]); 
  	} 
    printf("Sorted array is\n"); 
    radixsort(a,n); 
    for(i=0;i<n;i++) 
  	{ 
   		printf("%d ",a[i]); 
  	} 
return 0;
}
