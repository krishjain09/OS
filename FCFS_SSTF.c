#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void FCFS(int a[],int tn){
	int trks=0,i;
	printf("\nTrack order\n");
	printf("%d",a[0]);
	for(i=1;i<=tn;i++){
		trks+=abs(a[i]-a[i-1]);
		printf("->%d",a[i]);
	}
	printf("\nTotal tracks covered %d",trks);
}

int main(){
	int tracks[20],tn,i;
	printf("Enter current head position : ");
	scanf("%d",&tracks[0]);
	printf("\nEnter number of tracks : ");
	scanf("%d",&tn);
	for(i=1;i<=tn;i++){
		scanf("%d",&tracks[i]);
	}
	printf("\nFCFS");
	FCFS(tracks,tn);
	return 0;
}
