#include <iostream>
#include <chrono>
#include <fstream>
#define N 1000000
using namespace std;
using namespace std::chrono;

ofstream outfile("outfile.txt", std::fstream::in | std::fstream::out | std::fstream::app);

void Algo1(int n, bool c[])
{
	int i = 2, j;
	c[1] = false;
	while (i <= n)
	{
		if (c[i] == true)
		{
			j = 2 * i;
			while (j <= n)
			{
				c[j] = false;
				j = j + i;
			}
		}
		i = i + 1;
	}
}
void Algo2(int n, bool c[])
{
	c[1] = false;
	int i = 2,j;
	while (i <= n)
	{
		j = 2 * i;
		while (j <= n)
		{
			c[j] = false;
			j = j + i;
		}
		i = i + 1;
	}
	
}
void Algo3(int n, bool c[])
{
	c[1] = false;
	int i = 2, j;
	while (i <= n)
	{
		if (c[i] == true)
		{
			j = i + 1;
			while (j <= n)
			{
				if (j % i == 0)
				{
					c[j] = false;
				}
				j = j + 1;
			}
		}
		i = i + 1;
	}
}
void Algo4(int n, bool c[])
{
	c[1] = false;
	int i = 2, j;
	while (i <= n)
	{
		j = 2;
		while (j < i)
		{
			if (i % j == 0)
			{
				c[i] = false;
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
void Algo5(int n, bool c[])
{
	c[1] = false;
	int i = 2, j;
	while (i <= n) {
		j = 2;
		while (j <= sqrt(i)) {
			if (i % j == 0) {
				c[i] = false;
			}
			j++;
		}
		i++;
	}
}

void reset(int n, bool c[])
{
	for (int i = 0; i < n; i++)
	{
		c[i] = true;
	}
}
void outputMetrics(char f, int n, bool c[])
{
	string s;
	auto sieve_start = high_resolution_clock::now();
	switch (f)
	{
	case '1':
		Algo1(n, c);
		s = "Algorithm 1 ";
		break;
	case '2':
		Algo2(n, c);
		s = "Algorithm 2 ";
		break;
	case '3':
		Algo3(n, c);
		s = "Algorithm 3 ";
		break;
	case '4':
		Algo4(n, c);
		s = "Algorithm 4 ";
		break;
	case '5':
		Algo5(n, c);
		s = "Algorithm 5 ";
		break;
	}
	auto sieve_stop = high_resolution_clock::now();
	auto duration_sieve = duration_cast<milliseconds>(sieve_stop - sieve_start);
	outfile << "\t" << duration_sieve.count() / 1e3f;
}
void display(int n, bool c[])
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << c[i] << "\n ";
	}
	cout << "\n";
}

int main()
{
	bool *c = new bool[N];
	//int n = 100000;
	for (int n = 100000; n < 10000000; n += 1000)
	{
		outfile << n;
		//reset(n, c);
		//outputMetrics('1', n, c);
		//
		//reset(n, c);
		//outputMetrics('2', n, c);
		//
		//reset(n, c);
		//outputMetrics('3', n, c);
		//
		//reset(n, c);
		//outputMetrics('4', n, c);
		
		reset(n, c);
		outputMetrics('5', n, c);
		outfile << "\n";
	}
	delete[]c;
}