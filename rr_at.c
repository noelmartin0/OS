#include<stdio.h> 
struct process
{
       int pid,at,bt,wt,tat,rem_bt;
}p[100];
void sortart(struct process p[],int n)
{
       int i,j;
       struct process temp;
       for(i=0;i<n;i++)
       {
              for(j=i+1;j<n;j++)
              {
                     if(p[i].at > p[j].at)
                     {
                           temp = p[i];
                           p[i] = p[j];
                           p[j] = temp;
                     }
              }
       }
} 
int main()
{
       int i,j,n,time=0,remain,flag=0,tq,gt[100],k=0;
       char str[1000];
       float avgwt=0,avgtt=0;
       printf("\nRound Robin Scheduling Algorithm\n----------------------------------");
       printf("\nEnter Number Of Processes : ");
       scanf("%d",&n);
       remain=n;
       printf("\nEnter arrival time and Burst time for each process\n");
       for(i=0;i<n;i++)
       {
              scanf("%d%d",&p[i].at,&p[i].bt);
              p[i].pid = i;
              p[i].rem_bt = p[i].bt;
       }
       sortart(p,n);
       printf("\nEnter Quantum Number : ");
       scanf("%d",&tq);
       printf("\nGANTT CHART\n***********\n");
       for(int i = 0; i<(n*22)-3; i++)
        str[i] = '-';
       printf("%s\n",str);
       printf("|");
       gt[k++] = 0;
       for(i=0;remain!=0;)
       {
              if(p[i].rem_bt<=tq && p[i].rem_bt>0)
              {
                     time = time + p[i].rem_bt;
                     gt[k++] = time;
                     printf(" P%d |",p[i].pid);
                     p[i].rem_bt=0;
                     flag=1;
              }
              else if(p[i].rem_bt > 0)
              {
                     p[i].rem_bt = p[i].rem_bt - tq;
                     time = time + tq;
                     gt[k++] = time;
                     printf(" P%d |",p[i].pid);
              }
              if(p[i].rem_bt==0 && flag==1)
              {
                     remain--;
                     p[i].tat = time-p[i].at;
                     p[i].wt = time-p[i].at-p[i].bt;
                     avgwt = avgwt + time-p[i].at-p[i].bt;
                     avgtt = avgtt + time-p[i].at;
                     flag=0;
              }
              if(i==n-1)
                     i=0;
              else if(p[i+1].at <= time)
                     i++;
              else
                     i=0;
       }
       gt[k++]=-1;
       printf("\n%s\n",str);
       if(gt[0]== 0)
       printf("%d    %d",gt[0],gt[1]);
       for(i=2;gt[i]!=-1;i++)
       {
              printf("    %d",gt[i]);
       }
       printf("\n\n");
       printf("PID\tAT\tBT\tTT\tWT\n");
       for(i=0;i<n;i++)
       {
              printf("P%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].wt);
       }
       avgwt = avgwt/n;
       avgtt = avgtt/n;
       printf("\nAverage Waiting Time : %.2f\n",avgwt);
       printf("Average Turnaround Time : %.2f\n",avgtt);
       return 0;
}