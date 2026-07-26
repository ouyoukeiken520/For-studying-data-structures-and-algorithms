#include <vector>
using namespace std;
class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    if (arr[0] > k)
      return k;
    int l = 0, r = arr.size();
    while (l < r) {
      int mid = (l + r) / 2;
      if (arr[mid] - mid - 1 >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return k + l;
  }
};