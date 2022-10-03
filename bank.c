#include<stdio.h>
int main(){
	int m,n,i,j,k,y,flag=0;
	int alloc[20][20],max[20][20],avail[50], ind=0;
	printf("\n Enter the number of processes \n");
	scanf("%d",&n);
	printf("\n Enter the number of resources \n");
	scanf("%d",&m);
	printf("\n Enter the allocation matrix\n:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("\n Enter the Max matrix\n :");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("\n Enter available vector\n :");
	for(i=0;i<m;i++)
		scanf("%d",&avail[i]);
	int finish[n],need[n][m],safe[n],work[m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			need[i][j]=max[i][j]-alloc[i][j];
	printf("\n Need matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		 printf("\t %d",need[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
	 work[i]=avail[i];
	}
	for(i=0;i<n;i++)
	{
	 finish[i]=0;
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(finish[i]==0)
			{
			 flag=0;
			 for(j=0;j<m;j++)
			 {
			 	if(need[i][j]>work[j])
			 	{
			 		flag=1;
			 		break;
			 	}
			 }
			 if(flag==0)
			 {
			 safe[ind++]=i;
			 for(y=0;y<m;y++)
			 {	
			 	work[y]+=alloc[i][y];
			 }
			 finish[i]=1;
			}
		}
	}
	
	}
	printf(" \nsafe sequence:");
	for(i=0;i<n-1;i++)
	{
		printf(" p%d ",safe[i]);
	}
	printf(" p%d ",safe[n-1]);
}