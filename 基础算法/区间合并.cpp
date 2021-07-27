//1. [1,2] [2,3]==>[1,3]
//1.左端点开始扫描
//2.3种关系 
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int>PII;
int n;
vector<PII>segs;
void merge(vector<PII>& segs)
{
	vector<PII>res;
	sort(segs.begin(), segs.end());//会优先左端点,再又端点

	int st = -2e9, ed = -2e9;
	for (auto seg: segs)
	{
		if (ed < seg.first)
		{
			if (st != -2e9)
			{
				res.push_back({ st, ed });	
			}
			st = seg.first, ed = seg.second;
		}
		else
		{
			ed = max(ed, seg.second);
		}
	}
	if (st != -2e9)res.push_back({ st,ed });//防止为空区间

	segs = res;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		segs.push_back({ start, end });
	}
	merge(segs);
	cout << segs.size() << endl;
	return 0;
}*/