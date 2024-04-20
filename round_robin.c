//Round Robin Algorithm

#include<stdio.h>
#include<stdlib.h>

int tc;//time quantum->global variable

typedef struct process{
	int process_no;
	int arrival_time;
	int burst_time;
}process;


void arrival_append(process *x,int n,process *queue,int *r,int visited[],int current_time){
	int i=0;
	for(i=0;i<n;i++){
		if(x[i].arrival_time<=current_time && visited[i]==0){
		queue[*r]=x[i];
		visited[i]=1;
		*r=(*r+1)%(n+1);
	}
	}
}

void roundrobin(process *x,int n,int *CT,int *TAT,int *WT){
	int f=0,r=0,visited[20]={0},current_time=0;
	process *queue;
	queue=(process *)malloc((n+1)*sizeof(*queue));
	while(1){
		arrival_append(x,n,queue,&r,visited,current_time);
		if(f==r)
		break;
		if(queue[f].burst_time>tc){
			queue[f].burst_time-=tc;
			current_time+=tc;
			arrival_append(x,n,queue,&r,visited,current_time);
			queue[r]=queue[f];
			f=(f+1)%(n+1);
			r=(r+1)%(n+1);
		}
		else{
			current_time+=queue[f].burst_time;
			arrival_append(x,n,queue,&r,visited,current_time);
			CT[queue[f].process_no-1]=current_time;
			TAT[queue[f].process_no-1]=current_time-x[queue[f].process_no-1].arrival_time;
			WT[queue[f].process_no-1]=TAT[queue[f].process_no-1]-x[queue[f].process_no-1].burst_time;
			f=(f+1)%(n+1);
		}
	}
}

int main(){
	int *CT,*TAT,*WT,n,i;
	float avwt=0.0,avtat=0.0;
	process *x;
	printf("\nEnter number of processes: ");
	scanf("%d",&n);
	
	x=(process *)malloc( n * sizeof(*x));
	CT= (int *) malloc(n * sizeof(*CT));
	TAT= (int *) malloc(n * sizeof(*TAT));
	WT= (int *) malloc(n * sizeof(*WT));
	
	for(i=0;i<n;i++){
		x[i].process_no=i+1;
		printf("\nEnter arrival time of process no. %d :",i+1);
		scanf("%d",&x[i].arrival_time);
		printf("\nEnter burst time of process no. %d : ",i+1);
		scanf("%d",&x[i].burst_time);
	}
	printf("\nEnter time quantum:");
	scanf("%d",&tc);
	roundrobin(x,n,CT,TAT,WT);
	printf("\n%8s%8s%8s%8s%8s%8s\n","Pro_no","AT","BT","CT","TAT","WT");
	for(i=0;i<n;i++){
		printf("\n%8d%8d%8d%8d%8d%8d\n",i+1,x[i].arrival_time,x[i].burst_time,CT[i],TAT[i],WT[i]);
		avwt+=WT[i];
		avtat+=TAT[i];
	}
	avwt=(float) avwt/i;
	avtat=(float) avtat/i;
	
	printf("\nAverage Waiting time %f :",avwt);
	printf("\nAverage Turn Around Time time %f :",avtat);
	free(x);
    free(CT);
    free(TAT);
    free(WT);
	return 0;
	
	
}
