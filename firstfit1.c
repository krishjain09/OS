#include<stdio.h>
#include<stdlib.h>

void firstfit(int blockSize[],int m,int processorSize[],int n){
	int i,j,allocation[10];
	
	for(i=0;i<n;i++){
		allocation[i]=-1;
	}
	
	
	for(i=0;i<n;i++){ //n-> no . of processor 
		for(j=0;j<m;j++){
			if(blockSize[j]>=processorSize[i]){
				allocation[i]=j;
				blockSize[j]-=processorSize[i];
				break;
			}
		}
	}
	printf("\nProcess no.\tProcess Size\t\t\tBlock no.\n");
	for(i=0;i<n;i++){
		
		printf("%d\t\t",i+1);
		printf("%d\t\t\t\t",processorSize[i]);
		if (allocation[i]!=-1){
			printf("%d",allocation[i]+1);
		}
		else{
			printf("Not Allocated");
			}
		printf("\n");
		
	}
}


int main(){
	int m,n,blockSize[10],processorSize[10],i,j;
	printf("\nEnter no.of blocks : ");
	scanf("%d",&m);
	printf("\nEnter no.of processors : ");
	scanf("%d",&n);
	
	printf("\nEnter Block size :");
	for(i=0;i<m;i++){
		scanf("%d",&blockSize[i]);
	}
	printf("\nEnter Processor size ");
	for(i=0;i<n;i++){
		scanf("%d",&processorSize[i]);
	}
	
	firstfit(blockSize,m,processorSize,n);
	return 0;
}
