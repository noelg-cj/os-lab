#include <stdio.h>

typedef struct p {
	int pid;
	int arrival;
	int burst;
	int priority;
	int wt;
	int tt;
} process;

void sort_by_arrival(process *p_arr, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (p_arr[j].arrival > p_arr[j+1].arrival) {
				process temp = p_arr[j];
				p_arr[j] = p_arr[j+1];
				p_arr[j+1] = temp;
			}
		}
	}
}

void sort_by_priority(process *p_arr, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (p_arr[j].priority > p_arr[j+1].priority) {
				process temp = p_arr[j];
				p_arr[j] = p_arr[j+1];
				p_arr[j+1] = temp;
			}
		}
	}
}

void sort_by_id(process *p_arr, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (p_arr[j].pid > p_arr[j+1].pid) {
				process temp = p_arr[j];
				p_arr[j] = p_arr[j+1];
				p_arr[j+1] = temp;
			}
		}
	}
}	

void sort_by_burst(process *p_arr, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (p_arr[j].burst > p_arr[j+1].burst) {
				process temp = p_arr[j];
				p_arr[j] = p_arr[j+1];
				p_arr[j+1] = temp;
			}
		}
	}
}

void display(process *p_arr, int n) {
	sort_by_id(p_arr, n);

	printf("PROCESS\tWAITING TIME\tTURNAROUND TIME\n");
	for (int i = 0; i < n; i++) {
		printf("P%d\t%d\t%d\n", i, p_arr[i].wt, p_arr[i].tt);
	}
}


void FCFS(process *p_arr, int n) {
	sort_by_arrival(p_arr, n);

	int sum_of_prev = 0;
	for (int i = 0; i < n; i++) {
		p_arr[i].wt = sum_of_prev;
		p_arr[i].tt = p_arr[i].wt + p_arr[i].burst;
		sum_of_prev += p_arr[i].burst;
		printf("P%d  | ", p_arr[i].pid);
	}
	printf("\n");
	display(p_arr, n);
}

void SJF(process *p_arr, int n) {
	sort_by_burst(p_arr, n);

	int sum_of_prev = 0;
	for (int i = 0; i < n; i++) {
		p_arr[i].wt = sum_of_prev;
		p_arr[i].tt = p_arr[i].wt + p_arr[i].burst;
		sum_of_prev += p_arr[i].burst;
		printf("P%d  | ", p_arr[i].pid);
	}
	printf("\n");

	display(p_arr, n);
}

void Priority(process *p_arr, int n) {
	sort_by_priority(p_arr, n);

	int sum_of_prev = 0;
	for (int i = 0; i < n; i++) {
		p_arr[i].wt = sum_of_prev;
		p_arr[i].tt = p_arr[i].wt + p_arr[i].burst;
		sum_of_prev += p_arr[i].burst;
		printf("P%d  | ", p_arr[i].pid);
	}
	printf("\n");

	display(p_arr, n);
}

void roundRobin(process *p_arr, int n) {
	printf("Enter time quantum: ");
	int q;
	scanf("%d", &q);

	
}

int main(void) {
	int N;
	printf("Enter the number of processes: ");
	scanf("%d", &N);

	process p_arr[N];

	for (int i = 0; i < N; i++) {
		printf("Enter arrival time and burst time and prioriy for process P%d: ", i);
		p_arr[i].pid = i;
		scanf("%d %d %d", &p_arr[i].arrival, &p_arr[i].burst, &p_arr[i].priority);
	}

	printf("FCFS Algorithm:\n");
	FCFS(p_arr, N);
	printf("\n\nSJF Algorithm:\n");
	SJF(p_arr, N);
	Priority(p_arr, N);
}
