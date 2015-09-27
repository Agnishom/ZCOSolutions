//ZCO 2013 Session 1 Problem 1
//Problem Statement: http://www.iarcs.org.in/inoi/2013/zco2013/zco2013-1a.php

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vi;

int main(){
  int N;
  std::cin >> N;

  vi viStrengths;
  for (int nTemp, iii=0; iii < N; iii++){
    std::cin >> nTemp;
    viStrengths.push_back(nTemp);
  }

  std::sort(viStrengths.begin(),viStrengths.end());

  long long llRevenue=0;

  for (int iii=0; iii < N; iii++){
    //llRevenue += iii*viStrengths[iii]; //This player is superior to iii players
    //llRevenue -= (N - iii - 1)*viStrengths[iii]; // This player is inferior to the rest of the players
    llRevenue += (2*iii - N + 1)*viStrengths[iii];
  }

  std::cout << llRevenue;

  return 0;
}
