#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct table
{
char var[10];
int value;
};
struct table tb1[20];
int i,j,n;
void create();
void modify();
int search(char variable[],int n);
void insert();
void display();
void main(){
int ch,result=0;
char v[10];

do{
printf("\n1.CREATE\t2.INSERT\t3.MODIFY\t4.SEARCH\t5.DISPLAY\t6.EXIT :");
scanf("%d",&ch);
switch(ch)
{
case 1:create(); break;
case 2:insert(); break;
case 3:modify(); break;
case 4:printf("\nEnter the variable to be searched:"); scanf("%s",&v);
result=search(v,n);
if(result==0)
printf("\nThe variable is not present\n"); else
printf("\nThe location of the variable is %d \n The value of %s is %d.",result,tb1[result].var,tb1[result].value);
break;
case 5:display(); break;
case 6:exit(1);
}
}while(ch!=6);

}
void create(){
printf("\nEnter the no. of entries:"); scanf("%d",&n);
printf("\nEnter the variable and the values:-\n");
for(i=1;i<=n;i++) {
scanf("%s%d",tb1[i].var,&tb1[i].value);
check:
if(tb1[i].var[0]>='0' && tb1[i].var[0]<='9') {
printf("\nVariable should start with alphabet\nEnter correct name\n");
scanf("%s%d",tb1[i].var,&tb1[i].value);
goto check;
}
check1:
for(j=1;j<i;j++) {
if(strcmp(tb1[i].var,tb1[j].var)==0) {
printf("\nThe variable already present. Enter another:");
scanf("%s%d",&tb1[i].var,&tb1[i].value);
goto check1;
} } }
printf("\nThe table after creation is:\n");
display();
}
void insert() {
if(i>=20)
printf("\nCannot insert.table is full\n");
else {
n++;
printf("\nEnter the variable and the value:");
scanf("%s%d",&tb1[n].var,&tb1[n].value); check:

if(tb1[i].var[0]>='0' && tb1[i].var[0]<='9'){
printf("\nVariable should start with alphabet\nEnter correct name\n");
scanf("%s%d",tb1[i].var,&tb1[i].value);
goto check;
}
check1:
for(j=1;j<n;j++){
if(strcmp(tb1[j].var,tb1[i].var)==0){
printf("\nThe variable already present. Enter another:");
scanf("%s%d",&tb1[i].var,&tb1[i].value);
goto check1;
}
}
printf("\nThe table after insertion is:"); display();
}
}
void modify()
{
char variable[10]; int result=0;
printf("\nEnter the variable to be modified:");
scanf("%s",&variable); result=search(variable,n);
if(result==0)
printf("%s not present\n",variable);\
else{
printf("\nThe current value of the variable %s is %d.\nEnter the new variable and its value",tb1[result].var,tb1[result].value);
scanf("%s%d",tb1[result].var,&tb1[result].value);
check:
if(tb1[i].var[0]>='0' && tb1[i].var[0]<='9'){
printf("\nVariable should start with alphabet\nEnter correct name\n");
scanf("%s%d",tb1[i].var,&tb1[i].value);
goto check;
}
}
printf("\nThe table after modification is:"); display();
}

int search(char variable[],int n){
int flag; for(i=1;i<=n;i++)
if(strcmp(tb1[i].var,variable)==0){
flag=1;
break;
}
if(flag==1)
return i;
else
return 0;
}

void display(){
printf("\nVariable\tvalue\n");
for(i=1;i<=n;i++)
printf("%s\t\t%d\n",tb1[i].var,tb1[i].value);
}