#include <bits/stdc++.h>
#define N 5

struct SJF {
  int id, at, st, bt, wt, ct, tt;
} process[N];

typedef struct SJF sjf;

bool comp(sjf a, sjf b) {
   if(a.at < b.at) return true;
   return a.bt < b.bt;
}

int main() {
  std::cout << "Shortest Job First Scheduling Algorithm" << std::endl;
  std::vector<sjf> v;
  for(int i=0; i<N; i++) {
    std::cout << "Enter AT and BT for process " << (i+1) << ": ";
    std::cin >> process[i].at >> process[i].bt;
    process[i].id = i+1;
    v.push_back(process[i]);
  }

  std::cout << "ID\tAt\tBT" << std::endl;
  for(int i=0; i<N; i++) {
    std::cout << process[i].id << "\t" << process[i].at << "\t" << process[i].bt << std::endl;
  }

  // sorting the process accordingly burst time
  std::sort(v.begin()+1, v.end(), comp);

  std::cout << "\nAfter sorting the table" << std::endl;
  std::cout << "ID\tAt\tBT" << std::endl;
  for(int i=0; i<N; i++) {
    std::cout << v[i].id << "\t" << v[i].at << "\t" << v[i].bt << std::endl;
  }

  // calculating gantt chart and rest of the calculation
  for(int i=0; i<N; i++) {
    if(i == 0) {
      // first process
      v[i].st = v[i].at;
      v[i].ct = v[i].bt;
      v[i].wt =  v[i].st - v[i].at;
      v[i].tt = v[i].wt + v[i].bt;
    } else {
      // rest of the process
      v[i].st = v[i-1].ct;
      v[i].ct = v[i].st + v[i].bt;
      v[i].wt =  v[i].st - v[i].at;
      v[i].tt = v[i].wt + v[i].bt;
    }
  }
  std::cout << "Gantt Chart With Complete Table" << std::endl;
  std::cout << "ID\tST\tCT\tWT\tTT" << std::endl; 
  for(int i=0; i<N; i++) {
    std::cout << v[i].id << "\t" << v[i].st << "\t" << v[i].ct << "\t" << v[i].wt << "\t" << v[i].tt <<  std::endl;
  }

  return 0;
}