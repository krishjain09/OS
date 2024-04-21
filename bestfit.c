//Best Fit

#include<stdio.h>

void bestfit(int blockSize[],int m,int processorSize[],int n){
	int i,j,allocation[10];
	for(i=0;i<n;i++){
		allocation[i]=-1;
	}
	for(i=0;i<n;i++){
		int bestIdx=-1;
		for(j=0;j<m;j++){
			if(blockSize[j]>=processorSize[i]){
				if(bestIdx==-1){
					bestIdx=j;
				}
				else if(blockSize[bestIdx]>blockSize[j]){
					bestIdx=j;
				}
			}
		}
		if(bestIdx!=-1){
			allocation[i]=bestIdx;
			blockSize[bestIdx]-=processorSize[i];
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
	
	bestfit(blockSize,m,processorSize,n);
	return 0;
}
