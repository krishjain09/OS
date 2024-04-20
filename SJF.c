//SJF(Non -Preemptive)

#include<stdio.h>

int main(){
	int n,wt[20],bt[20],tat[20],p[20],i,j,temp,temp1;
	float avwt=0.0,avtat=0.0;
	printf("\nEnter number of processes : ");
	scanf("%d",&n);
	
	printf("\nEnter Burst Time\n");
	for(i=0;i<n;i++){
		printf("p%d :",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1; //contains process number
	}
	
	//sorting burst time in ascending order
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(bt[j]>bt[j+1]){
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				
				temp1=p[j];
				p[j]=p[j+1];
				p[j+1]=temp1;
				
			}
		}
	}
	
	wt[0]=0;
	//calculating waiting time
	
	for(i=1;i<n;i++){
		wt[i]=0;
		for(j=0;j<i;j++){
			wt[i]+=bt[j];
		}
	}
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurn Around time");
	
	for(i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		printf("\np%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	avwt=(float)avwt/i;
	avtat=(float)avtat/i;
	printf("\nAverage waiting time : %f",avwt);
	printf("\nAverage turn around time : %f",avtat);
}
