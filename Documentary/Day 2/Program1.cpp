#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = sortedArrayToBSTHelper(nums, left, mid - 1);
    node->right = sortedArrayToBSTHelper(nums, mid + 1, right);
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }
    TreeNode* root = sortedArrayToBST(nums);
    cout << "In-order traversal of BST: ";
    printInOrder(root);
    cout << endl;
    return 0;
}




/**************************************************************************************

Output:

5
1
2
3
4
5
In-order traversal of BST: 1 2 3 4 5 


******************************************************************************************/
