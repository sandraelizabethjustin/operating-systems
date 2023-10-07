#include<stdio.h>
#include<stdlib.h>

int initial,size,n,r[20];

void fcfs(){
    int i,thead=0,init=initial;
    for(i=0;i<n;i++){
        thead+=abs(r[i]-init);
        init=r[i];
    }
    printf("in fcfs:total head movements is %d\n",thead);
}
void scan(){
    int i,thead=0,j,temp,index,current=initial;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(r[j]>r[j+1]){
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",r[i]);
    }
    for(i=0;i<n;i++){
        if(current<r[i]){
            index=i;
            printf("\nthe value of index is %d\n",index);
            break;
        }
    }
    for(i=index;i<n;i++){
        printf("%d->",r[i]);//reaches till 190->
        thead=thead+abs(r[i]-current);
        current=r[i];//the value of current at last is 190
    }
    //thead=thead+abs(size-r[i-1]-1);
    thead+=abs(current-(size));
    printf("%d->",size);
    current=size;
    for(i=(index-1);i>=0;i--){
        printf("%d->",r[i]);
        thead=thead+abs(current-r[i]);
        current=r[i];
    }
    printf("\nin scan total head=%d\n",thead);
}
void cscan(){
    int i,thead=0,j,temp,index,current=initial;
      for(i=0;i<n;i++){
        if(current<r[i]){
            index=i;
            break;
        }
    }
    for(i=index;i<n;i++){
        printf("%d->",r[i]);
        thead=thead+abs(r[i]-current);
        current=r[i];//after the end of the loop current=190
    }
    thead+=abs(current-(size));
    printf("%d->",size);
    current=size;//reached till 199
    //thead=thead+abs(size-r[i-1]-1);

    thead+=abs(current-0);
    printf("%d->",0);
    //thead=thead+abs(size-1-0);
    current=0;
    for(i=0;i<index;i++){
        printf("%d->",r[i]);//first val is 16
        thead=thead+abs(r[i]-current);
        current=r[i];
    }
    printf("\nin cscan total head=%d\n",thead);

}
void look(){
    printf("\n------------LOOK--------\n");
    int i,thead=0,j,temp,index,current=initial;
    for(i=0;i<n;i++){
        if(current<r[i]){
            index=i;
            printf("\nthe value of index is %d\n",index);
            break;
        }
    }
    for(i=index;i<n;i++){
        printf("%d->",r[i]);//reaches till 190->
        thead=thead+abs(r[i]-current);
        current=r[i];//the value of current at last is 190
    }
   
    for(i=(index-1);i>=0;i--){
        printf("%d->",r[i]);
        thead=thead+abs(current-r[i]);
        current=r[i];
    }
    printf("\nin scan total head=%d\n",thead);
}
void clook(){
    printf("\n-----------------CLOOK--------------\n");
    int i,thead=0,j,temp,index,current=initial;
      for(i=0;i<n;i++){
        if(current<r[i]){
            index=i;
            break;
        }
    }
    for(i=index;i<n;i++){
        printf("%d->",r[i]);
        thead=thead+abs(r[i]-current);
        current=r[i];//after the end of the loop current=190
    }
    thead+=abs(current-(r[0]));
    printf("%d->",r[0]);
    current=r[0];

   
    for(i=0;i<index;i++){
        printf("%d->",r[i]);//first val is 16
        thead=thead+abs(r[i]-current);
        current=r[i];
    }
    printf("\nin cscan total head=%d\n",thead);
}
int main(){
    int i;
    printf("enter the number of requests");
    scanf("%d",&n);
    printf("enter the sequence");
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }
    printf("enter the initial head position");
    scanf("%d",&initial);
    printf("enter the total disk time");
    scanf("%d",&size);
    fcfs();
    scan();
    cscan();
    look();
    clook();
}