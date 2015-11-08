//ZCO 2012 Session 1 Problem 1
//Problem Statement: http://www.iarcs.org.in/inoi/2012/zco2012/zco2012-1a.php

#include <iostream>
#include <stack>

int main(){
  int N;
  std::cin >> N;

  int *Data = new int[N];
  for (int iii=0; iii < N; iii++)
    std::cin >> Data[iii];

  std::stack<int> stackPos;
  int maxDepth = 0, maxDepthStart = 0, maxSymbols = 0, maxSymbolsStart = 0;

  for (int iii=0; iii < N; iii++){
    if (Data[iii] == 1){
      stackPos.push(iii);
      if (stackPos.size() > maxDepth){
        maxDepth = stackPos.size();
        maxDepthStart = iii;
      }
    }
    else{
      if ((iii - stackPos.top() + 1) > maxSymbols){
        maxSymbols = (iii - stackPos.top() + 1);
        maxSymbolsStart = stackPos.top();
      }
      stackPos.pop();
    }
  }

  std::cout << maxDepth << " " << maxDepthStart+1 << " " << maxSymbols << " " << maxSymbolsStart+1 << std::endl;

  return 0;
}
