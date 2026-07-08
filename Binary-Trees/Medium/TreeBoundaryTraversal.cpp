#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// ANTI-CLOCKWISE

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;

        if(!root) return ans;

        ans.push_back(root->data);
        
        if(isLeaf(root)) return ans;
        addLeftBoundary(root->left, ans);
        addLeaves(root, ans);
        addRightBoundary(root->right, ans);

        return ans;
    }

  private:
    void addLeftBoundary(Node* root, vector<int>& ans){

        if(!root) return;

        while(root && !isLeaf(root)){
            ans.push_back(root->data);
            if(root->left) root = root->left;
            else if(root->right) root = root->right;
        }
    }

    void addLeaves(Node* root, vector<int> &ans){
        if(!root) return ;
        
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    void addRightBoundary(Node* root, vector<int> &ans){
        if(!root) return;

        stack<Node*> st;

        while(root && !isLeaf(root)){
            st.push(root);
            
            if(root->right) root = root->right;
            else if(root->left) root = root->left;
        }

        while(!st.empty()){
            ans.push_back(st.top()->data);
            st.pop();
        }
    }

    bool isLeaf(Node* root){
        return !root->left && !root->right; 
    }
};