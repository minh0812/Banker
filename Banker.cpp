#include <iostream>

using namespace std;

void Calculate();
void IMP();
bool Check(int j);
int allocation[100][100], need[100][100], Max[100][100], available[100][100];
int p, n, current[100];
bool executed[100], come;

int main()
{
	cout << "Enter No. of processes: ";
	cin >> p;
	cout << "\n";
	cout << "Enter No. of resources: ";
	cin >> n;
	cout << "\n";
	cout << "Enter the current resources: ";
	for (int i = 0; i < n; i++)
	{
		cin >> current[i];
	}

	for (int i = 0; i < p; ++i)
	{
		cout << "\n\n\t\t\tProcess P" << i + 1 << " Details\n";
		cout << "Enter Allocation : ";
		for (int j = 0; j < n; j++)
		{
			cin >> allocation[i][j];
		}

		cout << "Enter Max : ";
		for (int j = 0; j < n; j++)
		{
			cin >> Max[i][j];
		}

		for (int j = 0; j < n; j++)
		{
			need[i][j] = Max[i][j] - allocation[i][j];
		}
	}

	cout << "\n\n\t\t\tTable for Bankers Algorithm\n\n";
	cout << "Initial Resources: ";
	for (int i = 0; i < n; i++)
	{
		cout << current[i] << " ";
	}
	cout << "\n\n";
	cout << "Process    Max    Allocation    Need\n";
	for (int i = 0; i < p; ++i)
	{
		cout << "  P" << i + 1 << "    ";
		for (int j = 0; j < n; j++)
		{
			cout << " " << Max[i][j];
		}
		cout << "     ";
		for (int j = 0; j < n; j++)
		{
			cout << " " << allocation[i][j];
		}
		cout << "     ";
		for (int j = 0; j < n; j++)
		{
			cout << " " << need[i][j];
		}
		cout << "     ";
		cout << "\n";
	}
	cout << "\n\n";
	Calculate();

	return 0;
}

void Calculate()
{
	IMP();
	int i, j;
	for (i = 0; i < p; ++i)
	{
		for (j = 0; j < p; ++j)
		{
			while (executed[j] && j < p - 1)
			{
				j++;
			}
			if (Check(j))
			{
				if (!executed[j])
				{
					executed[j] = true;
					for (int k = 0; k < n; k++)
					{
						current[k] += allocation[j][k];
					}

					cout << "\nProcess P" << j + 1;
					cout << "\nCurrent: ";
					for (int k = 0; k < n; k++)
					{
						cout << current[k] << " ";
					}
					cout << "\n";
					cout << "\nProcess executed without deadlock";
					come = true;
					break;
				}
			}
		}
		if (!come)
		{
			cout << "\n\t\t\tDead lock\n\n";
			break;
		}
		else
		{
			come = false;
		}
	}
}

void IMP()
{
	come = false;
	for (int i = 0; i < p; ++i)
	{
		executed[i] = false;
	}
}

bool Check(int j)
{
	for (int i = 0; i < n; i++)
	{
		if (need[j][i] > current[i])
		{
			return false;
		}
	}
	return true;
}
