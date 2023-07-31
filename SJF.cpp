#include <bits/stdc++.h>

struct SJF {
  int id, at, st, bt, wt, ct, tt;
};

typedef struct SJF sjf;

bool comp(sjf a, sjf b) {
  if(a.at == 0 || b.at == 0) return true;
  else if(a.bt < b.bt) return true;
  else return false;
  //  if(a.bt < b.bt) return true;
  //  else return false;
}
void printTable(sjf process[], int n) {
  std::cout << "ID\tAt\tBT" << std::endl;
  for(int i=0; i<n; i++) {
    std::cout << process[i].id << "\t" << process[i].at << "\t" << process[i].bt << std::endl;
  }
}

int main() {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      // freopen("output.txt","w",stdout);
  #endif

  int n;
  std::cout << "Shortest Job First Scheduling Algorithm" << std::endl;
  std::cout << "Enter number of process: ";
  std::cin >> n;
  sjf process[n];

  for(int i=0; i<n; i++) {
    std::cout << "Enter AT and BT for process " << (i+1) << ": ";
    std::cin >> process[i].at >> process[i].bt;
    process[i].id = i+1;
  }

  // PRINTING THE TABLE
  std::cout << "Table Data" << std::endl;
  printTable(process, n);

  // sorting the process accordingly burst time
  std::sort(process, process+n, comp);

  // SORTED TABLE
  std::cout << "Sorted Table Data" << std::endl;
  printTable(process, n);

  // calculating gantt chart and rest of the calculation
  // for(int i=0; i<N; i++) {
  //   if(i == 0) {
  //     // first process
  //     v[i].st = v[i].at;
  //     v[i].ct = v[i].bt;
  //     v[i].wt =  v[i].st - v[i].at;
  //     v[i].tt = v[i].wt + v[i].bt;
  //   } else {
  //     // rest of the process
  //     v[i].st = v[i-1].ct;
  //     v[i].ct = v[i].st + v[i].bt;
  //     v[i].wt =  v[i].st - v[i].at;
  //     v[i].tt = v[i].wt + v[i].bt;
  //   }
  // }
  // std::cout << "Gantt Chart With Complete Table" << std::endl;
  // std::cout << "ID\tST\tCT\tWT\tTT" << std::endl; 
  // for(int i=0; i<N; i++) {
  //   std::cout << v[i].id << "\t" << v[i].st << "\t" << v[i].ct << "\t" << v[i].wt << "\t" << v[i].tt <<  std::endl;
  // }

  return 0;
}