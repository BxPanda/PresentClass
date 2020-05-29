#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<iterator>
#include<algorithm>
#include"Present.h"

using namespace std;

void Print(vector<Present>& v)
{
	for (auto el : v)
	{
		el.Print();
		cout << "-------------------------------------------------------------------------------" << endl;
	}
}

bool comp1(Present f, Present s)
{
	if (f.GetDate().second.second != s.GetDate().second.second)
	{
		return f.GetDate().second.second < s.GetDate().second.second;
	}
	else
	{
		if (f.GetDate().second.first != s.GetDate().second.first)
		{
			return f.GetDate().second.first < s.GetDate().second.first;
		}
		else
		{
			if (f.GetDate().first != s.GetDate().first)
			{
				return f.GetDate().first < s.GetDate().first;
			}
			else
			{
				if (f.GetAddress() != s.GetAddress())
				{
					return f.GetAddress() < s.GetAddress();
				}
				else
				{
					if (f.GetTitle() != s.GetTitle())
					{
						return f.GetTitle() < s.GetTitle();
					}
					else
					{
						return f.GetKind() < s.GetKind();
					}
				}
			}
		}
	}
}

void Sort(vector<Present>& v)
{
	sort(v.begin(), v.end(), comp1);
	cout << "Sorted : " << endl << endl;
	Print(v);
}

void GeneralSumm(vector<Present>& v)
{
	set<string>kinds;
	for (auto el : v)
	{
		kinds.insert(el.GetKind());
	}
	for (auto el : kinds)
	{
		double sum = accumulate(v.begin(), v.end(), 0.0, [&el](double a,Present&p) 
		{
				if (el == p.GetKind())
				{
					return a+p.GetWorth();
			    }
				else
				{
					return a;
				}
		});
		cout << "General sum of " << el << " kind = " << sum << "$" << endl;
	}
	
}

void PopularPresent(vector<Present>& v)
{
	set<string>names_present;
	map<int, string,greater<int>>rating;
	for (auto el : v)
	{
		names_present.insert(el.GetTitle());
	}
	for (auto el : names_present)
	{
		auto count = count_if(v.begin(), v.end(), [&rating, &el](Present& p) { return el == p.GetTitle(); });
		rating.insert(make_pair(count, el));
	}
	auto first = rating.begin();
	cout << "The most popular present is : " << first->second << endl;
}

void CountryPresent(vector<Present>& v)
{
	set<pair<pair<string, string>, pair<string, int>>>names_address;
	map<int, pair<pair<string, string>, pair<string, int>>, greater<int>>rating;
	for (auto el : v)
	{
		names_address.insert(el.GetAddress());
	}
	for (auto el : names_address)
	{
		auto count = count_if(v.begin(), v.end(), [&rating, &el](Present& p) { return el == p.GetAddress(); });
		rating.insert(make_pair(count, el));
	}
	auto first = rating.begin();
	cout << "The largest number of gifts purchased in : " << first->second.first.first<<","<< first->second.first.second << endl;
}

int main()
{
	ifstream ifs("Text.txt");
	vector<Present>v1;
	copy(istream_iterator<Present>(ifs), istream_iterator<Present>(), inserter(v1, v1.end()));
	//Print(v1);

	Sort(v1);
	GeneralSumm(v1);

	PopularPresent(v1);
	CountryPresent(v1);

	return 0;
}