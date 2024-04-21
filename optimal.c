//optimal program

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void optimal(int referenceString[],int numberOfFrames,int size){
	int i,j,frames[numberOfFrames],symbol,flag,pageHits=0,pageMisses=0,max,optimalIdx,k;
	for(j=0;j<numberOfFrames;j++){
		frames[j]=-1;
	}
	for(i=0;i<size;i++){
		symbol=referenceString[i];
		flag=0;
		for(j=0;j<numberOfFrames;j++){
			if(frames[j]==symbol){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("\nSymbol: %d Frames: ",symbol);
			for(j=0;j<numberOfFrames;j++){
				printf("%d ",frames[j]);
			}
			pageHits+=1;
		}
		else{
			if(i<numberOfFrames){
				frames[i]=symbol;
				printf("\nSymbol: %d Frames: ",symbol);
				for(j=0;j<numberOfFrames;j++){
					printf("%d ",frames[j]);
				}
				pageMisses+=1;
			}
			else{
				optimalIdx=-1;
				max=INT_MIN;
				for(j=0;j<numberOfFrames;j++){
					for(k=i+1;k<size;k++)
					{
						if(frames[j]==referenceString[k]){
							if(k >max){
								max=k;
								optimalIdx=j;
							}
							break;
						}	
					}
					if(k==size){
						optimalIdx=j;
						break;
					}	
				}
				frames[optimalIdx]=symbol;
				printf("\nSymbol: %d Frames: ",symbol);
				for(j=0;j<numberOfFrames;j++){
					printf("%d ",frames[j]);
				}
				pageMisses+=1;
			}
				
		}
	}
	
	printf("\n Total page Miss : %d ",pageMisses);
	printf("\n Total page Hits : %d ",pageHits);
}




int main(){
	int referenceString[20],numberOfFrames,size,i;
	printf("Enter number of symbols in frames : ");
	scanf("%d",&size);
	printf("\nEnter reference string : ");
	for(i=0;i<size;i++){
		scanf("%d",&referenceString[i]);
	}
	printf("\nEnter number of frames : ");
	scanf("%d",&numberOfFrames);
	optimal(referenceString,numberOfFrames,size);
	return 0;
}
