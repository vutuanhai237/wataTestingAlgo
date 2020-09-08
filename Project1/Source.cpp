#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
int checkCondition(vector<int> a) {
	int isPushBack = true;
	if (a.size() == 0) return 0;
	for (int i = 0; i < a.size() - 1; i++) {
		for (int j = i; j < a.size(); j++) {
			if (abs(a[i] - a[j]) > 1) {
				isPushBack = false;
			}
		}
	}
	if (isPushBack == false) {
		return 0;
	}
	return a.size();
}

vector< vector<int> > getAllSubsets(vector<int> set)
{
	vector< vector<int> > subset;
	vector<int> empty;
	subset.push_back(empty);

	for (int i = 0; i < set.size(); i++)
	{
		vector< vector<int> > subsetTemp = subset;

		for (int j = 0; j < subsetTemp.size(); j++)
			subsetTemp[j].push_back(set[i]);

		for (int j = 0; j < subsetTemp.size(); j++)
			subset.push_back(subsetTemp[j]);
	}
	return subset;
}


int fineLargestGroup(int a[], int n) {
	vector<int> empty;
	for (int i = 0; i < n; i++) {
		empty.push_back(a[i]);
	}
	vector< vector<int> > subsets = getAllSubsets(empty);
	int maxx = -1;
	for (int i = 0; i < subsets.size(); i++)
	{
		if (checkCondition(subsets[i]) > maxx) {
			maxx = checkCondition(subsets[i]);
		}
	}
	return maxx;
}








int main() {
	int n;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "Input: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "Result: " << fineLargestGroup(a, n) << endl;
	system("pause");
	return 0;
}