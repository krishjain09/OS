//Best Fit

#include<stdio.h>

void worstfit(int blockSize[],int m,int processorSize[],int n){
	int i,j,allocation[10];
	for(i=0;i<n;i++){
		allocation[i]=-1;
	}
	for(i=0;i<n;i++){
		int wrstIdx=-1;
		for(j=0;j<m;j++){
			if(blockSize[j]>=processorSize[i]){
				if(wrstIdx==-1){
					wrstIdx=j;
				}
				else if(blockSize[wrstIdx]<blockSize[j]){
					wrstIdx=j;
				}
			}
		}
		if(wrstIdx!=-1){
			allocation[i]=wrstIdx;
			blockSize[wrstIdx]-=processorSize[i];
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
	
	worstfit(blockSize,m,processorSize,n);
	return 0;
}
