//ZCO 2015 Afternoon Problem 
//Problem Statement: http://www.iarcs.org.in/inoi/2015/zco2015/zco2015-afternoon.pdf

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int,int> ii;
typedef std::vector<int> vi;
typedef std::vector<ii> vii;


bool compare (const ii& lhs, const ii& rhs)
{
  return lhs.second<rhs.second;
}

int main(){
  int N;
  std::cin >> N;

  vii viiIntervals;

  int nA, nB;
  for (int iii=0; iii < N; iii++)
  {
    std::cin >> nA >> nB;
    viiIntervals.push_back(std::pair<int,int>(nA,nB));
  }

  std::sort(viiIntervals.begin(),viiIntervals.end(),compare);

  vi viChoice;

  int nTemp;
  while(viiIntervals.size()){
    nTemp = viiIntervals.begin()->second;
    viChoice.push_back(nTemp);
    for (vii::iterator it=viiIntervals.begin(); 
      it != viiIntervals.end(); 
      ((nTemp>=it->first) && (nTemp<=it->second)) ? viiIntervals.erase(it) : it++);
  }

  std::cout << viChoice.size();

  return 0;
}
