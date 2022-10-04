#include<stdio.h>
struct block{
int no;
int size;
int flag;
}b[10];
struct process{
int no;
int size;
int allocblock;
}p[10];
int bn,pn,temp;

void main(){
printf("\nEnter the no. of blocks : ");
scanf("%d",&bn);

for(int i=1;i<=bn;i++){
printf("\nEnter the Block size : ");
scanf("%d",&b[i].size);
   b[i].no = i;
   b[i].flag=0;
}

printf("\nEnter the no. of processes : ");
scanf("%d",&pn);

for(int i=1;i<=pn;i++){
printf("\nEnter the Process size : ");
scanf("%d",&p[i].size);
p[i].no = i;
p[i].allocblock =0;
}


for(int i=1;i<=pn;i++){
for (int j=1;j<=bn;j++){
if(b[j].flag !=1 && p[i].size<=b[j].size){
b[j].flag=1;
p[i].allocblock = b[j].no;
}
if(p[i].allocblock!=0){
break;
}
}

}
printf("\nFirst Fit\n");
printf("Pno\tPsize\tBno\tBsize\tWastage\n");
for(int i=1;i<=pn;i++){
if(p[i].allocblock!=0){
printf("%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].size,p[i].allocblock,b[p[i].allocblock].size,b[p[i].allocblock].size - p[i].size);
}
else{
printf("%d\t%d\tUnallocated\t\t\n",p[i].no,p[i].size);
}
}
//best fit

for(int i=1;i<=bn;i++){
b[i].flag=0;
}
for(int j=1;j<=pn;j++){
p[j].allocblock=0;
}

for(int i=1;i<=bn;i++){
for(int j=1;j<bn-i+1;j++){
if(b[j+1].size < b[j].size){
temp = b[j].size;
b[j].size = b[j+1].size;
b[j+1].size = temp;

temp = b[j].no;
b[j].no = b[j+1].no;
b[j+1].no = temp;
}
}
}


for(int i=1;i<=pn;i++){
for (int j=1;j<=bn;j++){
if(b[j].flag !=1 && p[i].size<=b[j].size){
b[j].flag=1;
p[i].allocblock = j;
}
if(p[i].allocblock!=0){
break;
}
}

}
printf("\nBest fit\n");
printf("Pno\tPsize\tBno\tBsize\tWastage\n");
for(int i=1;i<=pn;i++){
if(p[i].allocblock!=0){
printf("%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].size,p[i].allocblock,b[p[i].allocblock].size,b[p[i].allocblock].size - p[i].size);
}
else{
printf("%d\t%d\tUnallocated\t\t\n",p[i].no,p[i].size);
}
}

for(int i=1;i<=bn;i++){
b[i].flag=0;
}
for(int j=1;j<=pn;j++){
p[j].allocblock=0;
}

for(int i=1;i<=bn;i++){
for(int j=1;j<bn-i+1;j++){
if(b[j+1].size > b[j].size){
temp = b[j].size;
b[j].size = b[j+1].size;
b[j+1].size = temp;

temp = b[j].no;
b[j].no = b[j+1].no;
b[j+1].no = temp;
}
}
}

for(int i=1;i<=pn;i++){
for (int j=1;j<=bn;j++){
if(b[j].flag !=1 && p[i].size<=b[j].size){
b[j].flag=1;
p[i].allocblock = j;
}
if(p[i].allocblock!=0){
break;
}
}

}
printf("\nWorst fit\n");
printf("Pno\tPsize\tBno\tBsize\tWastage\n");
for(int i=1;i<=pn;i++){
if(p[i].allocblock!=0){
printf("%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].size,p[i].allocblock,b[p[i].allocblock].size,b[p[i].allocblock].size - p[i].size);
}
else{
printf("%d\t%d\tUnallocated\t\t\n",p[i].no,p[i].size);
}
}
}
