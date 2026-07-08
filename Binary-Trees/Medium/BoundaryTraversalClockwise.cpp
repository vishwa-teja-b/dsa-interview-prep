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

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root){
        vector<int> ans;

        if(!root) return ans;

        ans.push_back(root->data);

        if(isLeaf(root)) return ans;

        addRightBoundary(root->right, ans);
        addLeaves(root,ans);
        addLeftBoundary(root->left, ans);

        return ans;
    }

  private:
    void addRightBoundary(Node* root, vector<int> &ans){
        if(!root) return;

        while(root && !isLeaf(root)){
            ans.push_back(root->data);

            if(root->right) root = root->right;
            else if(root->left) root = root->left;
        }
    }

    void addLeaves(Node* root, vector<int> &ans){
        // if(!root) return;

        if(root && isLeaf(root)) {ans.push_back(root->data); return;}

        if(root->right) addLeaves(root->right,ans);
        if(root->left) addLeaves(root->left, ans);
    }

    void addLeftBoundary(Node* root, vector<int> &ans){
        if(!root) return;

        stack<Node*> st;

        // st.push(root);

        while(root && !isLeaf(root)){
            st.push(root);

            if(root->left) root = root->left;
            else if(root->right) root = root->right;
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

int main(){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // 5's children
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    Solution* sol = new Solution();
    vector<int> ans = sol->boundaryTraversal(root);

    for(auto val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    delete sol;
}