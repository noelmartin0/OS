#include<stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat,wt;
}p[5],temp;
void main()
{
    int n,k=0;
    float ttat=0,twt=0;
    char str[100];
    printf("\nEnter the number of process: ");
    scanf("%d",&n);
    printf("\nEnter the Arrival Time, Burst Time for each process: \n");
    for(int i = 0; i<n; i++)
    {
        p[i].pid = i+1; p[i].ct = 0;
        scanf("%d %d",&p[i].at,&p[i].bt);
    }
    for(int i = 0; i<n; i++)
    {
        int min = i;
        for(int j = i+1; j<n; j++)
        {
            if(p[j].at < p[min].at)
            {
                min = j;
            }
        }
        temp = p[min];
        p[min] = p[i];
        p[i] = temp;
        if(k == 0)
        {
         p[k].ct = p[k].bt;
         p[k].wt = 0;
         p[k].tat = p[k].ct-p[k].at;
         ttat = p[k].tat;
         twt = p[k].wt;
        }
        else
        {
         p[k].ct = p[k-1].ct+p[k].bt;
         p[k].wt = 0;
         p[k].tat = p[k].ct-p[k].at;
         p[k].wt = p[k].tat-p[k].bt;
         ttat += p[k].tat;
         twt += p[k].wt;
        }
        k++;
    }
    printf("\nPID\tTAT\tWT\n");
    for(int i = 0; i<n; i++)
        printf("%d\t%d\t%d\n",p[i].pid,p[i].tat,p[i].wt);
    //GANTT CHART
    printf("\nAverage Waiting Time = %f\nAverage Turn Around Time = %f\n",(ttat/n),(twt/n));
    for(int i = 0; i<n*6; i++)
        str[i] = '-';
    printf("%s\n",str);
    printf("| P%d |",p[0].pid);
    for(int i = 1; i<n; i++)
     printf(" P%d |",p[i].pid);
    printf("\n");
    printf("%s\n",str);
    for(int i = 0; i<n; i++)
    {
        if(i == 0) 
        printf("0    %d    ",p[i].ct);
        else
        printf("%d   ",p[i].ct);
    }
}