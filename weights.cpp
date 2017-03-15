#include <iostream>

using namespace std;
int main()
{
	int total;
	cin >> total;
	int *weights = new int[total];
	int *number  = new int[total];
	for (int i = 0; i < total; i++)
	{
		cin >> weights[i];
	}
	for (int i = 0; i < total; i++)
	{
		cin >> number[i];
	}
	int totalWeight = 0;
	for (int i = 0; i < total; i++)
	{
		totalWeight = totalWeight + weights[i] * number[i];
	}
	int *dp = new int[totalWeight];
	memset(dp, 0, sizeof(dp));
	//int dp[1000] = {0};
	
	
	dp[0] = 1;
	for (int i = 0; i < total; i++)
	{
		for (int j = 0; j < number[i]; j++)
		{
			for (int z = totalWeight; z >= weights[i]; z--)
			{
				if (dp[z - weights[i]] == 1)
					dp[z] = 1;
			}
		}
	}
	int size = 0;
	for (int n = 0; n <= totalWeight; n++)
	{
		if (dp[n] == 1)
			size++;
	}
	cout << size<<endl;
	system("pause");
	delete[] weights;
	delete[] number;
	delete[] dp;
	return 0;
}

