#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void FCFS(int a[],int tn){
	int trks=0,i;
	printf("\nTrack order\n");
	for(i=1;i<=tn;i++){
		trks+=abs(a[i]-a[i-1]);
		printf("->%d",a[i]);
	}
	printf("\nTotal tracks covered %d",trks);
}
void sort(int a[],int n){
	int i,j,temp;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void SSTF(int a[],int tn){
	int trks=0,i;
	sort(a,tn);
	printf("\nTrack order\n");
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
	printf("\nSSTF");
	SSTF(tracks,tn);
	return 0;
}
