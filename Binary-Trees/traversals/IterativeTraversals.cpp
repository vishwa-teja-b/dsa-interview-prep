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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        if(!root) return res;

        stack<TreeNode*> st;

        st.push(root);

        while (!st.empty())
        {
            /* code */
            TreeNode* current = st.top(); st.pop();

            // cout<<current->val<<" ";
            res.push_back(current->val);

            if(current->right) st.push(current->right);
            if(current->left) st.push(current->left);
        }

        return res;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        if(!root) return res;

        stack<TreeNode*> st;

        // st.push(root);

        TreeNode* current = root;

        while(current || !st.empty()){

            while(current){
                st.push(current);
                current = current->left;
            }
            TreeNode* rootNode = st.top(); st.pop();

            res.push_back(rootNode->val);

            current = rootNode->right;
        }
        return res;
    }

    vector<int> postorderTraversal(TreeNode* root){
        vector<int> res;

        if(!root) return res;

        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()){
            auto current = st.top(); st.pop();

            res.push_back(current->val);

            if(current->left) st.push(current->left);
            if(current->right) st.push(current->right);
        }

        reverse(res);

        return res;
    }
private:
    void reverse(vector<int> &array){
        int start = 0; int end = array.size()-1;

        while(start < end){
            array[start] = array[start]^array[end];
            array[end] = array[start]^array[end];
            array[start] = array[start]^array[end];

            start++;
            end--;
        }
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    root->right->right->left = new TreeNode(9);

    Solution* sol = new Solution();

    vector<int> ans = sol->postorderTraversal(root);

    for(int val : ans) cout<<val<<" ";
    cout<<endl;
}