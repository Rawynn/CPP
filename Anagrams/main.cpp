////Checks if pair is an anagram, if it isn't it prints how many letters has to be changed to make it an anagram also when pairs are different size it prints -1.


//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> annagrams(vector<string> a, vector<string> b){
	vector<int> result;

	for (int i = 0; i < a.size(); i++){
		if (a[i].length() != b[i].length()){
			result.push_back(-1);
		}
		else{
			int switches = 0;
			for (int j = 0; j < a[i].length(); j++){
				sort(a[i].begin(), a[i].end());
				sort(b[i].begin(), b[i].end());

				if (a[i][j] != b[i][j]){
					switches++;
				}
			}
			result.push_back(switches);
		}	
	}
	return result;
}

int main(){
	vector<string> A;
	vector<string> B;

	A.push_back("a");
	A.push_back("jk");
	A.push_back("abb");
	A.push_back("mn");
	A.push_back("abc");

	B.push_back("bb");
	B.push_back("kj");
	B.push_back("bbc");
	B.push_back("op");
	B.push_back("def");

	vector<int> wynik = annagrams(A, B);
	for (int i = 0; i < wynik.size(); i++){
		cout << "Pair " << i+1 << " - A: " << A[i] << "; B: " << B[i] << endl;
		cout << "Switches: " << wynik[i] << endl<<endl;
	}

	system("pause");
}