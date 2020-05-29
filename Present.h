#include<iostream>
#include<string>
#pragma once
using namespace std;
class Present
{
protected:
	pair<int,pair<int,int>>Date;
	pair<string, string>Name;
	pair<pair<string, string>, pair<string, int>>Address;
	string Title,Kind;
	double Worth;
public:
	Present():Date(),Name("none","none"),Address(),Title("none"),Kind("none"),Worth(0){}
	Present(pair<int, pair<int, int>> d,pair<string,string>n, pair<pair<string, string>, pair<string, int>> a, string t, string k,double w) :Date(d), Name(n), Address(a), Title(t), Kind(k), Worth(w) {}
	Present(const Present&p):Date(p.Date),Name(p.Name),Address(p.Address),Title(p.Title),Kind(p.Kind),Worth(p.Worth){}

	friend istream& operator>>(istream& is, Present& p)
	{
		int day, month, year;
		is >> day >> month >> year;
		p.Date.first = day;
		p.Date.second.first = month;
		p.Date.second.second = year;
		string name, surname;
		is >> name;
		is >> surname;
		p.Name.first = name;
		p.Name.second = surname;
		string country, city, street;
		int numberHouse;
		is >> country >> city >> street >> numberHouse;
		p.Address.first.first = country;
		p.Address.first.second = city;
		p.Address.second.first = street;
		p.Address.second.second = numberHouse;
		is >> p.Title >> p.Kind >> p.Worth;
		return is;
	}

	friend ostream& operator<<(ostream& os, const Present& p)
	{
		os << p.Date.first<<" "<<p.Date.second.first<<" "<<p.Date.second.second << " " << p.Name.first << " " << p.Name.second << " " << p.Address.first.first<<" "<< p.Address.first.second<<" "<<p.Address.second.first<<" "<< p.Address.second.second << " " << p.Title << " " << p.Kind << " " << p.Worth << endl;
		return os;
	}

	pair<int, pair<int, int>> GetDate()
	{
		return Date;
	}

	pair<string, string> GetName()
	{
		return Name;
	}

	pair<pair<string, string>, pair<string, int>> GetAddress()
	{
		return Address;
	}

	string GetTitle()
	{
		return Title;
	}

	string GetKind()
	{
		return Kind;
	}

	double GetWorth()
	{
		return Worth;
	}

	void Print()
	{
		cout << "Date : " << Date.first << "." << Date.second.first << "." << Date.second.second << endl;
		cout << "Name : " << Name.first << " " << Name.second << endl;
		cout << "Address : " << Address.first.first<<","<<Address.first.second<<","<<Address.second.first<<","<<Address.second.second << endl;
		cout << "Title : " << Title << endl;
		cout << "Kind of present : " << Kind << endl;
		cout << "Worth : " << Worth<<"$" << endl;
	}
};

