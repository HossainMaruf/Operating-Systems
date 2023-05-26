#include <bits/stdc++.h>

struct FCFS {
  int pid, at, bt, st, wt, ct, tt;
};

typedef struct FCFS fcfs;

bool comp(fcfs a, fcfs b) {
  if(a.at < b.at) return true;
  else if(a.at > b.bt) return false;
  else {
    // Arrival time is same  
    return a.pid < b.pid;
  }
}

void printProcess(fcfs p[], int n) {
  for(int i=0; i<n; i++) {
    printf("%d : %d\t%d\n", p[i].pid, p[i].at, p[i].bt);
  }
  printf("\n\n");
}

void printTable(fcfs p[], int n) {
  printf("ID\tAT\tBT\tST\tCT\tWT\tTT\n");
  for(int i=0; i<n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].wt, p[i].tt);
  }
}

int main() {
  int n;
  printf("First Come First Serve Algorithm\n");
  printf("Enter number of processes: ");
  scanf("%d", &n);
  fcfs p[n];
  for(int i=0; i<n; i++) {
    p[i].pid = i+1;
    printf("Enter at and bt of process %d: ", i+1);
    scanf("%d%d", &p[i].at, &p[i].bt);
  }
  // PRINTING THE PROCESSES
  printProcess(p, n);
  // SORTING THE PROCESSES
  std::sort(p, p+n, comp);
  // PRINTING THE SORTED PROCESSES
  printProcess(p, n);

  // CALCULATING THE VALUES
  for(int i=0; i<n; i++) {
    if(i == 0) {
      p[i].st = p[i].at; 
      p[i].ct = p[i].bt;
    } else {
      if(p[i].at > p[i-1].ct) p[i].st = p[i].at;
      else p[i].st = p[i-1].ct;
      p[i].ct = p[i].st + p[i].bt;
    }
    p[i].wt = p[i].st - p[i].at;
    p[i].tt = p[i].wt + p[i].bt;
  }

  // PRINTING THE TABLE
  printTable(p, n);
  return 0;
}