#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A = {3,4,3,1};
vector<int> B = {1,2,2,6};
//use greedy algorithm: though the min requirement meet, it still needs a room(unless the maximum of all the rooms still can not accomodate this meeting ,but if so other meetings can not be accommodated too), so allocate the min size room can ensure that the rest rooms are the biggest in each location in an ordered suquence
//ʹ��̰���㷨�������������������С�Ļ��鶼��Ҫһ�䷿�䣨����û��һ�����㣬�������������������Ҳ�޷��з������㣩�������������С�ķ����ܹ���֤����������У�ָ�������С�������С����������ʣ�෿�������ã����մ�С����ÿ��λ���϶��Ǵ��ڵ���������������λ���ϵķ���Ĵ�С��
int main()
{
	int m = A.size();
	int n = B.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int result = 0;
	int p = 0;
	for (int i = 0;i<m&&p<n;i++)
	{
		for (int j = p;j<n;j++)
		{
			if (A[i]<=B[j])
			{
				result += 1;
				p = j + 1;
				break;
			}
		}
	}
	cout << result << endl;
	system("pause");
}