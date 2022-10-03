#include<stdio.h>
int rq[20],front=0,rear=0,n=3;
void enqueue(int i)
{
  if(front == 0)  front = rear= 1;
  else rear = (rear%n)+1;
  rq[rear] = i;
}
int dequeue()
{
   int temp;
   temp = rq[front];
   if(front==rear) front = rear = 0;
   else front = (front%n)+1;
   return temp;
}
struct process
{
    int pid;
    int bt,rem_bt,at;
    int tat,wt;
}p[6],temp;
void main()
{
  int id,tq,gt[50],k1=0,k2=0,runned[50];
  //gt array for gantt chart time runned for process in cpu
  char str[100];
  float ttat = 0,twt=0;
  printf("\nEnter the number of process: ");
  scanf("%d",&n);
  printf("\nEnter the Arrival Time and Burst Time for each process: \n");
  for(int i = 1; i<=n; i++)
  {
    p[i].pid = i; 
    scanf("%d",&p[i].bt);
    p[i].rem_bt = p[i].bt;
    enqueue(p[i].pid);
  }
  printf("\nEnter the time quanta: ");
  scanf("%d",&tq);
  id = dequeue();
  if(p[id].rem_bt>=tq)
    {
         runned[k2++]=id;
         gt[k1++]=tq;
         p[id].rem_bt -= tq;
         p[id].wt = 0;
         p[id].tat += tq;
         enqueue(id);
    }
    else
    {
         runned[k2++]=id;
         gt[k1++]=p[id].bt;
         p[id].tat += p[id].bt;
         p[id].wt = 0;
         p[id].rem_bt = 0;
    }
  while(1)
  {
    id = dequeue();
    if(p[id].rem_bt>=tq)
    {
         p[id].wt = 0;
         runned[k2++]=id;
         gt[k1]= gt[k1-1]+ tq;
         p[id].rem_bt -= tq;
         p[id].tat = gt[k1];
         p[id].wt  = p[id].tat-p[id].bt;
         k1++;
         enqueue(id);
    }
    else if(p[id].rem_bt != 0)
    {
         p[id].wt = 0;
         runned[k2++]=id;
         gt[k1] =gt[k1-1]+p[id].rem_bt;
         p[id].tat = gt[k1];
         p[id].wt = p[id].tat-p[id].bt;
         k1++;
         p[id].rem_bt = 0;
         printf("\n%d %d",id,p[id].rem_bt);
    }
    int count = 0;
    for(int i = 1; i<=n; i++)
    {
        if(p[i].rem_bt == 0)
            count++;
    }
    if(count == n)
    {
        runned[k1++] = -1;
        gt[k2++] = -1;
        break;
    }
  }
  printf("\nPID\tWT\tTAT");
  for(int i = 1; i<=n; i++)
  {
    printf("\n%d\t%d\t%d",p[i].pid,p[i].wt,p[i].tat);
    ttat += p[i].tat;
    twt += p[i].wt;
  }
  printf("\n\nAverage Waiting Time = %f\nAverage Turn Around Time = %f\n",(twt/n),(ttat/n));
   for(int i = 0; i<(n*12)-3; i++)
        str[i] = '-';
    printf("%s\n",str);
    printf("| P%d |",runned[0]);
    for(int i = 1; runned[i] != -1; i++)
     printf(" P%d |",runned[i]);
    printf("\n");
    printf("%s\n",str);
    for(int i = 0; gt[i] != -1; i++)
    {
        if(i == 0) 
        printf("0    %d    ",gt[i]);
        else
        printf("%d   ",gt[i]);
    }
}