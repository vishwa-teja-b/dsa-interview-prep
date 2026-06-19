#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template <typename T, typename U>
class Pair{
    public:
        T first;
        U second;
        Pair(T first, U second){
            this->first = first;
            this->second = second;
        }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if(!root) return result;

        queue<Pair<TreeNode*,int>> q;

        q.push(Pair<TreeNode*, int>(root,0));

        int level = 0;

        while(!q.empty()){
            auto current = q.front(); q.pop();

            if(current.second == level){
                result.push_back({});
                level++;
            }

            result[current.second].push_back(current.first->val);

            if(current.first->left) q.push(Pair<TreeNode*, int>(current.first->left,current.second+1));
            if(current.first->right) q.push(Pair<TreeNode*, int>(current.first->right,current.second+1));
        }

        return result;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution* sol = new Solution();

    vector<vector<int>> res = sol->levelOrder(root);

    for(auto &row: res){
        for(auto val : row) cout<<val<<" ";
        cout<<endl;
    }
}