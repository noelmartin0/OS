#include<stdio.h>
void main()
{
    int head,n,tracks[100],temp,traversed[100],k,p=0,total=0,diff;
    printf("\nEnter the number of tracks: ");
    scanf("%d",&n);
    printf("\nEnter the head pointer position: ");
    scanf("%d",&head);
    printf("\nEnter the tracks to be traversed:\n");
    for(int i = 0; i<n; i++)
        scanf("%d",&tracks[i]);
    tracks[n] = head;
    tracks[n+1] = 0;
    tracks[n+2] = 199;
    n = n+3;
    for(int i = 0; i<n-1; i++)
    {
        int min = i;
        for (int  j = i+1; j < n; j++)
        {
            if(tracks[min]>tracks[j])
                min = j;
        }
        temp = tracks[min];
        tracks[min] = tracks[i];
        tracks[i] = temp;
    }
    for(int i = 0; i<n; i++)
    {
        if(tracks[i]==head)
        {
            k=i;
            break;
        }
    }
    if(head<(199-head))
    {
        for(int i=k; i>=0; i--,p++)
            traversed[p]=tracks[i];
        for(int i=k+1; i<n-1; i++,p++)
            traversed[p]=tracks[i];
    }
    else
    {
        for(int i=k; i<n; i++,p++)
            traversed[p]=tracks[i];
        for(int i=k-1; i>0; i--,p++)
            traversed[p]=tracks[i];
    }
    for(int i = 0; i<p; i++)
        printf("%d => ",traversed[i]);
    for(int j = 0; j<p-1; j++)
    {
        diff = 0;
        diff = traversed[j]-traversed[j+1];
        if(diff < 0)
            diff *= -1; //Multiplying diff by -1
        total = total+diff;
    }
    printf("\b\b\b.  \nTotal Head Movement: %d",total);
}