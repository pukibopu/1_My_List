
#include<iostream>
#include<list>
using namespace std;
void stladd(list<int>& a, list<int>& b, list<int>& c)
{
	if (b.empty())
	{
		a = c;
		return;
	}
	if (c.empty())
	{
		a = b;
		return;
	}

	list<int>::iterator it1 = b.begin();
	list<int>::iterator it2 = c.begin();
	int temp = (*it2 + *it1) / 10;

	a.push_back((*it1 + *it2) % 10);
	it1++;
	it2++;

	while (it1 != b.end() && it2 != c.end())
	{
		int tmp = *it1 + *it2 + temp;
		temp = tmp/10;
		a.push_back(tmp % 10);

		it1++;
		it2++;
	}

	while (it1 != b.end())
	{
		int tmp = *it1 + temp;
		temp = tmp / 10;
		a.push_back(tmp % 10);
		it1++;
	}

	while (it2 != c.end())
	{
		int tmp = *it2 + temp;
		temp = tmp / 10;
		a.push_back(tmp % 10);
		it2++;
	}

	if (temp)
	{
		a.push_back(temp);
	}

}
void stringToList(const string& s, list<int>& l)
{
	for (int i = 0; i < s.size(); i++)
		l.push_front(s[i] - '0');
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
	list<int> a, b, c;

	string s1, s2;
	cin >> s1 >> s2;

	stringToList(s1, a);
	stringToList(s2, b);

	stladd(c, a, b);

	for (list<int>::reverse_iterator it = c.rbegin(); it != c.rend(); it++)
	{
		cout << *it;
	}
	cout << endl;
	}
	
	
	return 0;
	
}