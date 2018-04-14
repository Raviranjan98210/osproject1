#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<pthread.h>
int a[100];
int n;
void child()
{
	int i,x;
	printf("Enter the number you want to in fibbonacci series");
	scanf("%d",&x);
	n=x;
	a[0]=0;
	a[1]=1;
	for(i=2;i<n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
}
void parent()
{
	sleep(4);
	int i;
	printf("your series is: ");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
}
void main()
{
	pthread_t th1,th2;
	pthread_create(&th1,NULL,child,NULL);
	pthread_create(&th2,NULL,parent,NULL);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
}