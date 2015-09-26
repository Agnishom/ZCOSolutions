//ZCO 2014 Session 1 Problem 1
//Problem Statement: http://www.iarcs.org.in/inoi/2014/zco2014/zco2014-1a.php

#include <iostream>

int main(){
  int N, H;
  std::cin >> N >> H;

  int *nStacks = new int[N];
  for (int iii=0; iii < N; iii++)
    std::cin >> nStacks[iii];

  int nCommand = -1;
  int nCranePos = 0;
  bool isCraneFull = false;

  while (nCommand){
    std::cin >> nCommand;

    switch(nCommand)
    {
      case 1:
        if (nCranePos > 0)
          nCranePos--;
        break;
      case 2:
        if (nCranePos < N-1)
          nCranePos++;
        break;
      case 3:
        if (!isCraneFull && nStacks[nCranePos] > 0)
        {
          isCraneFull = true;
          nStacks[nCranePos]--;
        }
        break;
      case 4:
        if (isCraneFull && nStacks[nCranePos] < H)
        {
          isCraneFull = false;
          nStacks[nCranePos]++;
        }
        break;
      case 0:
        break;
    }

  }

  for(int iii = 0; iii < N; iii++)
    std::cout << nStacks[iii] << " ";

  return 0;
}
