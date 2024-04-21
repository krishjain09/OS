//FIFO->program

#include<stdio.h>
#include<stdlib.h>

void fifo(int referenceString[],int numberOfFrames,int size){
	int frames[numberOfFrames],i,j,currentIdx=-1;
	int pageHits=0,pageMiss=0;
	for(i=0;i<numberOfFrames;i++)
	{
		frames[i]=-1;
	}
	
	//Trversing each symbol in refernce string
	for(i=0;i<size;i++){
		int symbol=referenceString[i];
		int flag=0;
		for(j=0;j<numberOfFrames;j++){
			if(symbol==frames[j]){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("\nSymbol : %d Frames : ",symbol);
			for(j=0;j<numberOfFrames;j++){
				printf("%d ",frames[j]);
			}
			pageHits+=1;
		}
		else{
			currentIdx=(currentIdx+1)%numberOfFrames;
			frames[currentIdx]=symbol;
			printf("\nSymbol : %d Frames : ",symbol);
			for(j=0;j<numberOfFrames;j++){
				printf("%d ",frames[j]);
			}
			pageMiss+=1;
		}	
	}
	printf("\nPage Hits : %d",pageHits);
	printf("\nPage Miss : %d",pageMiss);
	
	float totalaccess=(float)(pageHits+pageMiss);
	float hitRatio=(float) pageHits/totalaccess;
	float missRatio=(float) pageMiss/totalaccess;	
	printf("\nHit Ratio : %.2f",hitRatio);
	printf("\nMiss Ratio : %.2f",missRatio);
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
	fifo(referenceString,numberOfFrames,size);
	return 0;
}
