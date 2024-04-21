//Bankers Algorithm

#include<stdio.h>

int main()
{
	int max[10][10],alloc[10][10],need[10][10],avail[10],completed[10],safeSequence[10];
	int i,j,p,r,process,count=0;
	printf("\nEnter number of processes : ");
	scanf("%d",&p);
	printf("\nEnter number of resources : ");
	scanf("%d",&r);
	printf("\nEnter Max Matrix for each process : ");
	for(i=0;i<p;i++){
		printf("\nFor process %d :",i+1);
		for(j=0;j<r;j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nEnter Allocation Matrix for each process : ");
	for(i=0;i<p;i++){
		printf("\nFor process %d :",i+1);
		for(j=0;j<r;j++){
			scanf("%d",&alloc[i][j]);
		}
	}
	for(i=0;i<p;i++){
		completed[i]=0; //initializing to 0;
	}
	
	//prompt user to enter available matrix
	printf("\nEnter Available resources : ");
	for(i=0;i<r;i++){
		scanf("%d",&avail[i]);
	}
	
	//Now calculate need matrix
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	do{
		printf("\nMax Matrix : \t\t\tAllocation MAtrix : \n");
		for(i=0;i<p;i++){
			for(j=0;j<r;j++){
				printf("%d ",max[i][j]);
			}
			printf("\t\t\t\t");
			for(j=0;j<r;j++){
				printf("%d ",alloc[i][j]);
			}
			printf("\n");
		}
		process=-1;
		for(i=0;i<p;i++){
			if(completed[i]==0)//if not completed
			{
				process=i;
				for(j=0;j<r;j++)
				{
					if(need[i][j] >avail[j]){
						process=-1;
						break;
					}					
				}
			}
			if(process!=-1)
			break;	
			}
			if(process!=-1){
				printf("\nProcess %d runs to completion state",process+1);
				safeSequence[count]=process+1;
				count++;
				for(j=0;j<r;j++)
				{
					avail[j]+=alloc[process][j];
					max[process][j]=0;
					alloc[process][j]=0;
					completed[process]=1;
				}		
			}
		}while(count!=p && process!=-1);
		
		if(count==p){
			printf("\nSystem is in safe state");
			printf("\nSafe Sequence < ");
			for(i=0;i<p;i++){
				printf("%d\t",safeSequence[i]);
			}
			printf(">\n");
		}
		else{
			printf("\nSystem is not in safe state");
		}
		return 0;	
}
