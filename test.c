#include<stdio.h>
void read(int x[][10],int r, int c)
{
    for(int i = 0; i<r; i++)
        for(int j = 0; j<c; j++)
            scanf("%d",&x[i][j]);
}
main()
{
    int i,j,k,y,alloc[10][10],max[10][10],need[10][10],avail[10],work[10],finish[10],safe[10],n,m,ind=0,flag;
    finish[0] = 0;
    printf("\nEnter the number of process: ");
    scanf("%d",&n);
    printf("\nEnter the number of resources: ");
    scanf("%d",&m);
    printf("\nEnter the Allocation Matrix:\n");
    read(alloc,n,m);
    printf("\nEnter the Max Matrix:\n");
    read(max,n,m);
    printf("\nEnter the Available Vector:\n");
    for(i = 0; i<m; i++)
    {
        scanf("%d",&avail[i]);
        work[i] = avail[i];
    }
    printf("\nNEED MATRIX\n");
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<m; j++)
        {
            need[i][j] = max[i][j]-alloc[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
	{
	 finish[i]=0;
	}
    for(k = 0; k<n; k++)
    {
        for(i = 0; i<n; i++)
        {
            if(finish[i]==0)
            {
            int flag = 0;
            for(j = 0; j<m; j++)
            {
                if(need[i][j]>work[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                finish[i] = 1;
                safe[ind++] = i;
                for(y = 0; y<m; y++)
                  work[y] += alloc[i][y];
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