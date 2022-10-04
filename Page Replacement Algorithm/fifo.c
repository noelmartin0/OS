#include<stdio.h>
void main()
{
    int pg[100],frame[10],n,m,hit=0,miss=0,found,k=0;
    printf("\nEnter the Number of Pages: ");
    scanf("%d",&n);
    printf("\nEnter the Reference String:\n");
    for(int i = 0; i<n; i++)
        scanf("%d",&pg[i]);
    printf("\nEnter the number of frames: ");
    scanf("%d",&m);
    for(int i = 0; i<m; i++)
        frame[i] = -1;
    printf("\nREFERENCE STRING\tPAGE NUMBER\tSTATUS\n");
    printf("-------------------------------------------------\n");
    for(int i = 0; i<n; i++)
    {
        found = 0;
        printf("%d\t\t\t",pg[i]);
        for(int j = 0; j<m; j++)
        {
            if(frame[j]==pg[i])
            {
                found = 1;
            }
        }
        if (found == 0)
        {
            frame[k]=pg[i];
            k = (k+1)%m;
            miss++;
        }
        for(int j = 0; j<m; j++)
        {
            if(frame[j] != -1)
                printf("%d ",frame[j]);
            else
                printf(" ");
        }
        if(found == 1)
        {
            printf("\t\tHIT\n");
            hit++;
        }
        else
        {
            printf("\t\tMISS\n");
        }
    }
    printf("\nHIT : %d\nMISS : %d\nRATIO : %.2f\n",hit,miss,((float)miss/(float)hit));
}
