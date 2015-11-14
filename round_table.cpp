//ZCO 2012 Session 2 Problem 2
//Problem Statement: http://www.iarcs.org.in/inoi/2012/zco2012/zco2012-2b.php

#include <iostream>
#include <vector>

typedef std::vector<int> vi;

int longtable(vi costs){
	int** memo = new int* [costs.size()];
	for(int iii=0; iii<costs.size(); iii++)
		memo[iii] = new int[2];
	memo[0][0] = 0;	memo[0][1] = costs[0];
	for(int iii=1; iii<costs.size(); iii++){
		memo[iii][0] = memo[iii-1][1];
		memo[iii][1] = costs[iii] + std::min(memo[iii-1][0],memo[iii-1][1]);
	}
	return std::min(memo[costs.size()-1][0],memo[costs.size()-1][1]);
}

int main(){
	int N;
	std::cin >> N;
	
	vi costs;
	for(int tmp,iii=0; iii<N; iii++){
		std::cin >> tmp;
		costs.push_back(tmp);
	}
	
	int minCost;
	vi WithArthur = vi(costs.begin()+1,costs.end()); //Definitely take Arthur
	vi WithLastGuy = vi(costs.begin(),costs.end()-1); //Definitely take the last guy
	minCost = std::min(costs[0]+longtable(WithArthur),longtable(WithLastGuy)+costs[N-1]);
	
	std::cout << minCost;
	
	return 0;
}
