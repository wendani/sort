class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<int> starts;
		vector<int> ends;

		for (const auto &interval : intervals) {
			starts.emplace_back(interval[0]);
			ends.emplace_back(interval[1]);
		}

		sort(starts.begin(), starts.end());
		sort(ends.begin(), ends.end());

		int min = 0;
		int len = starts.size();
		int j = 0;
		for (int i = 0; i < len; i++) {
			if (starts[i] < ends[j]) {
				min++;
			}
			else {
				// ends[j] <= starts[i]
				j++;
			}
		}
		return min;
	}

	int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<vector<int>> timePoints;

		for (const auto &interval : intervals) {
			// start time, indicated by 1 as the second element
			timePoints.emplace_back(initializer_list<int>{interval[0], 1});
			// end time, indicated by -1 as the second element
			// if start time == end time, end time will always come first
			timePoints.emplace_back(initializer_list<int>{interval[1], -1});
		}

		sort(timePoints.begin(), timePoints.end());

		int min = 0;
		int cnt = 0;
		for (const auto &timePoint : timePoints) {
			cnt += timePoint[1];
			if (cnt > min) {
				min = cnt;
			}
		}
		return min;
	}
};

/*
 * Example 1:
 *
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 *
 * Example 2:
 *
 * Input: [[7,10],[2,4]]
 * Output: 1
 */
