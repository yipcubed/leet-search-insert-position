#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/search-insert-position/
using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    if (nums.empty()) return 0;
    int lo = 0;
    if (nums.size() == 1) {
      if (target > nums[lo]) return 1;
      return 0;
    }
    int hi = nums.size() - 1;
    if (target == nums[hi])
      return hi;
    if (target > nums[hi])
      return hi + 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (target == nums[mid]) return mid;
      if (hi - lo == 1 && target > nums[lo] && target < nums[hi])
        return lo + 1;
      if (target > nums[mid]) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
};

void test1() {

  vector<int> v2{1,3};
  int target2 = 2;
  cout << "1 ? " << Solution().searchInsert(v2, target2) << endl;

  vector<int> v1{1, 3, 5, 6};
  int target = 5;

  cout << "2 ? " << Solution().searchInsert(v1, target) << endl;

  target = 2;
  cout << "1 ? " << Solution().searchInsert(v1, target) << endl;

  target = 7;
  cout << "4 ? " << Solution().searchInsert(v1, target) << endl;

  target = 0;
  cout << "0 ? " << Solution().searchInsert(v1, target) << endl;

}

void test2() {

}

void test3() {

}