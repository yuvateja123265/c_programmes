#include<stdio.h>
#include<string.h>
struct student
{
	char n[30];
	int s1,s2,s3,s4,tot;
};
int main(int argc,char*argv[])
{
	struct student a1;
	if(argc>=6)
	{
		strcpy(a1.n,argv[1]);
		a1.s1=atoi(argv[2]);
		a1.s2=atoi(argv[3]);
		a1.s3=atoi(argv[4]);
		a1.s4=atoi(argv[5]);
		a1.tot=a1.s1+a1.s2+a1.s3+a1.s4;
		printf("Student name:%s\nTotal=%d",a1.n,a1.tot);
	}
	else
	{
		printf("please enter required arguments");
	}
	printf("\nR.no-24B11CS487");
	return 0;
}
