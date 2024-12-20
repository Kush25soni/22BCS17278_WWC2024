
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int writeIndex = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[writeIndex++] = nums[i];
        }
    }
    return writeIndex;
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 5, 5};
    int uniqueCount = removeDuplicates(nums);

    cout << "Number of unique elements: " << uniqueCount << endl;
    cout << "Modified array: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
