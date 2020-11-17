#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A = {3,4,3,1};
vector<int> B = {1,2,2,6};
//use greedy algorithm: though the min requirement meet, it still needs a room(unless the maximum of all the rooms still can not accomodate this meeting ,but if so other meetings can not be accommodated too), so allocate the min size room can ensure that the rest rooms are the biggest in each location in an ordered suquence
//使用贪心算法，无论如何需求人数最小的会议都会要一间房间（除非没有一个满足，而这种情况给其他会议也无法有房间满足），而分配给他最小的房间能够保证在所有情况中（指分配给最小会议非最小房间的情况）剩余房间情况最好（按照大小排序，每个位置上都是大于等于其他情况的这个位置上的房间的大小）
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