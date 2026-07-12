#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    bool isSymmetric(Node* root) {
        // code here
        if(!root) return false;

        return dfs(root->left, root->right);
    }

    bool dfs(Node* root1, Node* root2){
        if(!root1 && !root2) return true;

        if(!root1 || !root2) return false;

        if(root1->data != root2->data) return false;

        bool left = dfs(root1->left, root2->right);
        bool right = dfs(root1->right, root2->left);

        if(!left || !right) return false;

        return true;
    }
};

int main(){
    Node* node = new Node(10);
    node->left = new Node(5);
    node->right = new Node(5);

    node->left->left = new Node(2);
    node->right->right = new Node(2);
}