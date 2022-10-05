#include<stdio.h>
void main()
{
    int n,ptr,tracks[100],diff,sum = 0;
    printf("\nEnter the number of Tracks: ");
    scanf("%d",&n);
    printf("\nEnter the hed pointer position: ");
    scanf("%d",&ptr);
    printf("\nEnter the tracks to be traversed:\n");
    for(int i = 0; i<n; i++)
    {
        diff = 0;
        scanf("%d",&tracks[i]);
        diff = ptr-tracks[i];
        if(diff < 0)
            diff *= -1; //Multiplying diff by -1
        ptr = tracks[i];
        sum = sum+diff;
    }
    printf("\nTraversed Order\n---------------\n");
    for (int i = 0; i < n; i++)
        printf("%d => ",tracks[i]);
    printf("\b\b\b.  \nTotal Head Movement: %d",sum);
}