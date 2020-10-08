#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int>  findPairSumToTarget(vector<int> &nums, int target);

int main() {
    vector<int> nums = {3,2,4};
    vector<int> res = findPairSumToTarget(nums, 6);

    for(int i : res) {
        cout << i << endl;
    }
    return 0;
}

vector<int> findPairSumToTarget(vector<int> &nums, int target) {
    map<int, int> m;
    
    for(int i = 0; i < nums.size(); ++i) {
        int diff = target - nums[i];
        if(m.find(nums[i]) != m.end()) {
            auto j = m.find(nums[i]);
            return vector<int>{ i, j->second };
        }
        m[diff] = i ;
    }
    
    return {};
}
