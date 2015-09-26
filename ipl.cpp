//ZCO 2014 Session 2 Problem 2
//Problem Statement: http://www.iarcs.org.in/inoi/2014/zco2014/zco2014-2b.php

#include <iostream>
#include <algorithm>

int main(){
  int N;
  std::cin >> N;

  int *nFees = new int[N];
  for (int iii=0; iii < N; iii++)
    std::cin >> nFees[iii];

  int *nBest = new int[N];
  nBest[0] = nFees[0]; nBest[1] = nFees[1] + nBest[0]; nBest[2] = nFees[2] + std::max({nFees[0],nFees[1]});

  for (int iii=3; iii < N; iii++)
    nBest[iii] = std::max({nBest[iii-1],                   //either do not play this match,
      nFees[iii] + nBest[iii-2],                           //or play this match but not the last one
       nFees[iii] + nFees[iii-1] + nBest[iii-3]});         //or play this match and the last one too

  std::cout << nBest[N-1];

  return 0;
}
