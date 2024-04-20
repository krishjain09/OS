//FCFS Programs:

#include<stdio.h>
int main(){
	int n,bt[20],wt[20],tat[20],i,j,avwt=0,avtat=0;
	printf("Enter number of processes(maximum 20)");
	scanf("%d",&n);
	
	printf("\nEnter Process Burst Time\n");
	
	//calculating burst time
	for(i=0;i<n;i++){
		printf("P[%d]: ",i+1);
		scanf("%d",&bt[i]);
	}
	
	wt[0]=0;//waiting time for first process is 0
	
	//calculating waiting time
	for(i=1;i<n;i++){
		wt[i]=0;
		for(j=0;j<i;j++){
			wt[i]+=bt[j];
		}
	}
	
	printf("\nProcess\t\tBurst Time\tWaiting time\tTurn Around Time");
	for(i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
	}
	
	avwt=avwt/i;
	avtat=avtat/i;
	printf("\nAverage waiting time: %d",avwt);
	printf("\nAverage turn around time: %d",avtat);
}
