//Scan program
#include<stdio.h>
#include<math.h>

int main(){
	int queue[20],queue1[20],queue2[20],temp,temp1=0,temp2=0,n,difference,seek,maxrange,headposition;
	int i,j;
	float averageSeek=0.0;
	printf("Enter maximum range of disk: ");
	scanf("%d",&maxrange);
	printf("\nEnter current head position: ");
	scanf("%d",&headposition);
	printf("\nEnter number of queue requests: ");
	scanf("%d",&n);
	printf("\nEnter disk positions to be in read queue: ");
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
	
	//sort queue2 in descending order
	for(i=0;i<temp2-1;i++){
		for(j=0;j<temp2-1;j++){
			if(queue2[j]<queue2[j+1]){
				temp=queue2[j];
				queue2[j]=queue2[j+1];
				queue2[j+1]=temp;
			}
		}
	}
	
	for(i=1,j=0;j<temp1;j++,i++){
		queue[i]=queue1[j];
	}
	queue[i]=maxrange;
	
	for(i=temp1+2,j=0;j<temp2;j++,i++){
		queue[i]=queue2[j];
	}
//	queue[i]=0;
	queue[0]=headposition;
	
	for(j=0;j<=n;j++){
		difference=abs(queue[j+1]-queue[j]);
		seek=seek+difference;
		printf("\nDisk head moves from position %d to %d with seek: %d",queue[j],queue[j+1],difference);
	}
	averageSeek=(float)seek/n;
  	printf("\nTotal seek time: %d",seek);
  	printf("\nTotal Average seek time: %.2f",averageSeek);
  	return 0;
}
