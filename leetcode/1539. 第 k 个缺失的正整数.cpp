#include <vector>
using namespace std;
class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    int j = 1, i = 0;
    while (i < arr.size()) {
      if (arr[i] != j) {
        if (--k == 0)
          return j; 
      } else {
        i++;
      }
      j++;
    }
    return j + k - 1;
  }
};