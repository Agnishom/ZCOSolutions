//ZCO 2015 Morning Session Problem 1
//Problem Statement: http://www.iarcs.org.in/inoi/2015/zco2015/zco2015-morning.pdf

#include <iostream>

bool isPallindrome(int *nNumbers, int iii, int jjj);

int main(){

  int N;
  std::cin >> N;
  int *nNumbers = new int[N];
  for (int iii = 0; iii < N; iii++){
    std::cin >> nNumbers[iii];
  }

  int *nGroups = new int[N]; //nGroup[i] gives the group in which i is
  int *nMembers = new int[N] {0}; //nMembers[i] gives the number of members in group i
  int nGroupLabel;
  for (int iii = 0; iii < N; iii++){
    for (int jjj = 0; jjj < iii; jjj++){
      if ( isPallindrome(nNumbers, iii, jjj) && ((iii - jjj + 1) > nMembers[jjj]) ){
        nGroupLabel = (nGroups[jjj] == 0) ? 0 : (nGroups[jjj - 1] + 1);
        for (int kkk = jjj; kkk <= iii; kkk++)
          nGroups[kkk] = nGroupLabel;
        nMembers[nGroupLabel] = (iii - jjj);
      }
    }
    nGroups[iii] = nGroupLabel;
    nGroupLabel++;
    nMembers[nGroupLabel]++;
  }

  std::cout << nGroups[N-1]+1; //The number of groups is the answer

  return 0;
}

bool isPallindrome(int *nNumbers, int iii, int jjj){
  for (; iii >= jjj; iii--,jjj++){
     if (nNumbers[iii] != nNumbers[jjj])
      return false;
  }
  return true;
}
