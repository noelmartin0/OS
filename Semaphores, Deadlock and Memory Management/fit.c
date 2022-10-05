#include<stdio.h>
struct block
{
   int no;
   int size;
   int flag;
}b[10],temp;
struct process
{
   int no;
   int size;
   int allocblock;
}p[10];
int pn,bn;
void display() //To Display the content
{
   printf("Pno\tPsize\tBno\tBsize\tWastage\n");
   for(int i=1;i<=pn;i++)
   {
      if(p[i].allocblock!=0)
         printf("%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].size,p[i].allocblock,b[p[i].allocblock].size,b[p[i].allocblock].size - p[i].size);
      else
         printf("%d\t%d\tUnallocated\t\t\n",p[i].no,p[i].size);
   }
}
void check() //To allocate the process
{
   for(int i=1;i<=pn;i++)
   {  
      for (int j=1;j<=bn;j++)
      {
         if(b[j].flag !=1 && p[i].size<=b[j].size)
         {
            b[j].flag=1;
            p[i].allocblock = j;
         }
         if(p[i].allocblock!=0)
            break;
      }
   }
}
void reset() //To clear the values to 0
{
    for(int i=1;i<=bn;i++)
      b[i].flag=0;
   for(int j=1;j<=pn;j++)
      p[j].allocblock=0;
}
void main()
{
   printf("\nEnter the no. of blocks : ");
   scanf("%d",&bn);
   for(int i=1;i<=bn;i++)
   {
      printf("\nEnter the Block size : ");
      scanf("%d",&b[i].size);
      b[i].no = i;
      b[i].flag=0;
   }
   printf("\nEnter the no. of processes : ");
   scanf("%d",&pn);
   for(int i=1;i<=pn;i++)
   {
      printf("\nEnter the Process size : ");
      scanf("%d",&p[i].size);
      p[i].no = i;
      p[i].allocblock =0;
   }

   //FIRST FIT

   check();
   printf("\nFirst Fit\n");
   display();

   //BEST FIT

  reset();
   for(int i=1;i<=bn;i++)
   {
      for(int j=1;j<bn-i+1;j++)
      {
         if(b[j+1].size < b[j].size)
         {
            temp = b[j];
            b[j] = b[j+1];
            b[j+1] = temp;
         }
      }
   }
   check();
   printf("\nBest fit\n");
   display();

   //WORST FIT

   reset();
   for(int i=1;i<=bn;i++)
   {
      for(int j=1;j<bn-i+1;j++)
      {
         if(b[j+1].size > b[j].size)
         {
            temp = b[j];
            b[j] = b[j+1];
            b[j+1] = temp;
         }
      }
   }
   check();
   printf("\nWorst fit\n");
   display();
}
