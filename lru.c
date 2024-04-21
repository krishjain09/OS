//lru program

#include<stdio.h>
#include<stdlib.h>


void lru(int refernceString[],int numberOfFrames,int size){
	int frames[numberOfFrames],symbol,flag,pageHits=0,pageMisses=0,min,lruIdx,i,j,k;
	for(i=0;i<numberOfFrames;i++){
		frames[i]=-1;
	}
	for(i=0;i<size;i++){
		symbol=refernceString[i];
		flag=0;
		for(j=0;j<numberOfFrames;j++){
			if(symbol==frames[j]){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("\n Symbol : %d Frames : ",symbol);
			for(j=0;j<numberOfFrames;j++){
				printf("%d ",frames[j]);
			}
			pageHits+=1;
		}
		else{
			if(i<numberOfFrames){
				frames[i]=symbol;
				printf("\n Symbol : %d Frames : ",symbol);
				for(j=0;j<numberOfFrames;j++){
				printf("%d ",frames[j]);
				}
				pageMisses+=1;
			}
			else{
				lruIdx=0;
				min=i;
				for(j=0;j<numberOfFrames;j++){
					for(k=i-1;k>=0;k--){
						if(frames[j]==refernceString[k]){
							if(k<min){
							min=k;
							lruIdx=j;
							}
							break;
						}	
					}
					if(k==-1){
						lruIdx=j;
						break;
					}
				}
				frames[lruIdx]=symbol;
				printf("\n Symbol : %d Frames : ",symbol);
				for(j=0;j<numberOfFrames;j++){
				printf("%d ",frames[j]);
				}
				pageMisses+=1;
			}
		}
	}
	
	printf("\nPage Hits : %d",pageHits);
	printf("\nPage Miss : %d",pageMisses);
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
	lru(referenceString,numberOfFrames,size);
	return 0;
}
