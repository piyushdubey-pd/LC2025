// 2402MeetingRoom.cpp

#include <bits/stdc++.h>

using namespace std;

int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<int> roomCount(n, 0);
    vector<int> roomEndTime(n, 0);
    return 1;
}


int main() {
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3,4}};
    int n1 = 2;

    vector<vector<int>> meetings2 = {{1,20},{2,10},{3,5},{4,9},{6,8}};
    int n2 = 3;
    cout << mostBooked(n1, meetings) << endl;
    cout << mostBooked(n2, meetings2) << endl;
    return 0;
}