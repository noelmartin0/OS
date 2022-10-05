#include<stdio.h>
struct frames
{
    int freq,content;
}frame[100];
void main()
{
    int pg[100],n,m,hit=0,j,id=0,miss=0;
    printf("\nEnter the number of pages: ");
    scanf("%d",&n);
    printf("\nEnter the reference string:\n");
    for(int i = 0; i<n; i++)
        scanf("%d",&pg[i]);
    printf("\nEnter the number of frames: ");
    scanf("%d",&m);
    for(int i = 0; i<m; i++)
    {
        frame[i].content = -1;
        frame[i].freq = 1;
    }
    printf("\nREFERENCE STRING\tSTATUS\tCONTENT\n");
    for(int i = 0; i<n; i++)
    {
        printf("%d\t\t\t",pg[i]);
        for(j = 0;j<m; j++)
        {
            if(frame[j].content == pg[i])
            {
                hit++;
                printf("HIT\t\t");
                frame[j].freq++;
                break;
            }
        }
        if(j == m)
        {
            printf("MISS\t\t");
            if(id<m)
            {
                frame[id].content = pg[i];
                frame[id].freq++;
                id++;
            }
            else
            {
                int min = 0;
                for(int k=0; k<m; k++)
                {
                    if(frame[k].freq<frame[min].freq)
                    min = k;
                }
                frame[min].content = pg[i];
                frame[min].freq++;
            }
            miss++;
        }
        for(int j = 0; j<m; j++)
        {
            if(frame[j].content != -1)
                printf("%d ",frame[j].content);
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\nHIT: %d\nMISS: %d",hit,miss);
}