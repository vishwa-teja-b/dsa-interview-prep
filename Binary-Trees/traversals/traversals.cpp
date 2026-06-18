#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

class Solution{
    public:
        void inOrder(Node* root){
            if(!root) return;

            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }

        void preOrder(Node* root){
            if(!root) return;

            cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }

        void postOrder(Node* root){
            if(!root) return;

            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }

        void levelOrder(Node* root){
            queue<Node*> q;
            q.push(root);

            cout<<"LEVEL ORDER TRAVERSAL : "<<endl;

            while(!q.empty()){
                Node* curr = q.front(); q.pop();
                cout<<curr->data<<" ";
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
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

    Solution* sol = new Solution();

    cout<<"INORDER TRAVERSAL : "<<endl;

    sol->inOrder(root);

    cout<<endl;
    cout<<"POSTORDER TRAVERSAL : "<<endl;

    sol->postOrder(root);

    cout<<endl;
    cout<<"PREORDER TRAVERSAL : "<<endl;
    sol->preOrder(root);

    sol->levelOrder(root);
}