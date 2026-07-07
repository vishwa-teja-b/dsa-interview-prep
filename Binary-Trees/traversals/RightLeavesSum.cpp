#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
// iterative way 
    int sumOfRightLeaves(TreeNode* root) {
        
        int res = 0;

        if(!root) return res;
        
        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()){
            auto current = st.top(); st.pop();

            if(current->right && isLeaf(current->right)) res += current->right->val;

            if(current->left) st.push(current->left);
            if(current->right) st.push(current->right);
        }

        return res;
    }

    int sumOfRightLeavesRecursive(TreeNode* root){
        if(!root) return 0;

        int sum = 0;

        if(root->right && isLeaf(root->right)){
            sum += root->right->val;
        }

        sum += sumOfRightLeavesRecursive(root->left);
        sum += sumOfRightLeavesRecursive(root->right);

        return sum;
    }

private:
    bool isLeaf(TreeNode* node){
        return node->left==nullptr && node->right==nullptr;
    }
};

int main(){
    TreeNode* root=  new TreeNode(3);
    root->left=  new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution* sol = new Solution();
    cout<< sol->sumOfRightLeavesRecursive(root) <<endl;

    delete sol;
}