//ZCO 2014 Session 2 Problem 1
//Problem Statement: http://www.iarcs.org.in/inoi/2014/zco2014/zco2014-2a.php

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector <long long unsigned> vll;

int main(){
  int N;
  std::cin >> N;

  vll nBudgets;
  for (long long unsigned nTemp,iii=0; iii < N; iii++){
    std::cin >> nTemp;
    nBudgets.push_back(nTemp);
  }
  std::sort(nBudgets.begin(),nBudgets.end());

  long long unsigned nProfit = 0;

  for (int nPotentialProfit,iii=0; iii < N; iii++)
  {
    nPotentialProfit = nBudgets[iii]*(nBudgets.size()-iii);
    nProfit = (nProfit > nPotentialProfit) ? nProfit : nPotentialProfit;
  }

  std::cout << nProfit;

  return 0;
}
