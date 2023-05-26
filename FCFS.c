#include<stdio.h>

struct FCFS {
  int process_id;
  float arrival_time, burst_time;
}p[3];

int main() {
  int n;
  float start_time[3], waiting_time[3], completion_time[3], turnaround_time[3];
  printf("First Come First Serve Algorithm\n");
  for(int i=0; i<3; i++) {
    p[i].process_id = i+1;
    printf("Enter arrival time of process %d: ", i+1);
    scanf("%f", &p[i].arrival_time);
    printf("Enter burst time of process %d", i+1);
    scanf("%f", &p[i].burst_time);
  }
  // calculating the values
  for(int i=0; i<3; i++) {
    if(i == 0) {
      start_time[i] = p[i].arrival_time; 
      completion_time[i] = p[i].burst_time;
    } else {
      start_time[i] = completion_time[i-1];
      completion_time[i] = start_time[i] + p[i].burst_time;
    }
  }
  return 0;
}