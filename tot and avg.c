#include<stdio.h>
struct student
{
	char name[30];
	int s1,s2,s3,s4;
	int rno,tot;
	float avg;
};
int main()
{
	int n,i;
	printf("Enter no of students:");
	scanf("%d",&n);
	struct student std[n];
	for(i=0;i<n;i++)
	{
		printf("Enter student Roll no:");
		scanf("%d",&std[i].rno);
		printf("Enter student name:");
		scanf("%s",&std[i].name);
		printf("Enter marks:");
		scanf("%d%d%d%d",&std[i].s1,&std[i].s2,&std[i].s3,&std[i].s4);
	}
	for(i=0;i<n;i++)
	{
	std[i].tot=std[i].s1+std[i].s2+std[i].s3+std[i].s4;
	std[i].avg=std[i].tot/4.0;
	printf("\nTotal and Average of %d:",std[i].rno);
	printf("\nTotal=%d",std[i].tot);
	printf("\nAverage=%.2f",std[i].avg);
	}
	printf("\nR.no-24B11CS487");
	return 0;
}
