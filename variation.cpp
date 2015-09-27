//ZCO 2015 Morning Session Problem 2
//Problem Statement: www.iarcs.org.in/inoi/2015/zco2015/zco2015-morning.pdf

#include <iostream>
#include <algorithm>

int* binarysearch(int *nNumbers, int high, int low, int nTarget){
  int mid;
  int begin = low;

  while (high >= low){
    mid = (high + low)/2;
    //std::cout << low << " " << mid << " " << high << std::endl;
    if (*(nNumbers + mid) < nTarget)
      low = mid + 1;
    else if (*(nNumbers + mid) >= nTarget){
      if ((mid -1) < begin)
        return nNumbers+mid;
      else if (*(nNumbers + mid -1) < nTarget)
        return nNumbers+mid;
      else high = mid - 1;
    }
  }
  
  return 0;
}

int main(){
  int N, K;
  std::cin >> N >> K;

  int *nNumbers = new int[N];
  for (int iii=0; iii < N; iii++)
    std::cin >> nNumbers[iii];

  std::sort(nNumbers,nNumbers+N); //pointer magic

  int *jjj, nVCount = 0;
  for (int iii=0; iii < N; iii++){
    jjj = binarysearch(nNumbers, N, iii+1, *(nNumbers+iii)+K);
    if (jjj){
      //std::cout << "Binary Search succesful for " << *(nNumbers+iii) << std::endl << "Search Points at " << *jjj << std::endl;
      nVCount += ((nNumbers + N) - jjj);
    }
  }

  std::cout << nVCount;

  return 0;
}
