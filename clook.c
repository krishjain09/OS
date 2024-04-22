//C-LOOk Code

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int queue[20],queue1[20],queue2[20],temp,temp1=0,temp2=0,maxrange,headposition,i,j;
	int difference,seek=0,n;
	float averageSeek=0.0;
	printf("\nEnter maximum range of disk: ");
	scanf("%d",&maxrange);
	printf("\nEnter number of requests: ");
	scanf("%d",&n);
	printf("\nEnter initial head position: ");
	scanf("%d",&headposition);
	printf("\nEnter disk positions to be read(queue): ");
	for(i=1;i<=n;i++){
		scanf("%d",&temp);
		if(temp>headposition){
			queue1[temp1]=temp;
			temp1++;
		}
		else{
			queue2[temp2]=temp;
			temp2++;
		}
	}
	//sort queue1 in ascending order
	for(i=0;i<temp1-1;i++){
		for(j=0;j<temp1-1;j++){
			if(queue1[j]>queue1[j+1]){
				temp=queue1[j];
				queue1[j]=queue1[j+1];
				queue1[j+1]=temp;
			}
		}
	}
	
	//sort queue2 in ascending order
	for(i=0;i<temp2-1;i++){
		for(j=0;j<temp2-1;j++){
			if(queue2[j]>queue2[j+1]){
				temp=queue2[j];
				queue2[j]=queue2[j+1];
				queue2[j+1]=temp;
			}
		}
	}
	//copy contents of queue1 into queue
	for(i=1,j=0;j<temp1;i++,j++){
		queue[i]=queue1[j];
	}
	queue[i]=queue2[0];
	//copy contents of queue2 into queue
	for(i=temp1+2,j=1;j<temp2;i++,j++){
		queue[i]=queue2[j];
	}
	queue[0]=headposition;
	
	for(j=0;j<n;j++){
		difference=abs(queue[j]-queue[j+1]);
		seek=seek+difference;
		printf("\nDisk head moves from position %d to position %d with seek %d ",queue[j],queue[j+1],difference);
	}
	averageSeek=(float) seek/n;
	printf("\nTotal seek time: %d ",seek);
	printf("\nTotal Average seek time : %.2f",averageSeek);
	return 0;
}
