#include<stdio.h>
struct Sales
{
	char name[30];
	int pr,no;
}s1,s2;
int main()
{
	/*printf("Enter Item name:");
	scanf("%s",&s1.name);
	printf("Enter price:");
	scanf("%d",&s1.pr);
	printf("Enter no of products sold:");
	scanf("%d",&s1.no);*/
	struct Sales s1={"TV",10000,50};
	s2=s1;
	printf("\nItem name:%s",s2.name);
	printf("\nPrice:%d",s2.pr);
	printf("\nNo.of Items Sold:%d",s2.no);
	printf("\nR.no-24B11CS487");
	return 0;
}
