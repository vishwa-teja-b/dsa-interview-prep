#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
        void bubbleSort(vector<int> &nums){
            for(int i=0;i<nums.size();i++){
                bool swapped = false;

                for(int j=0;j<nums.size()-1-i;j++){
                    if(nums[j] > nums[j+1]) {
                        swap(nums, j, j+1);
                        swapped = true;
                    }
                }

                if(!swapped) break;
            }
        }

        void swap(vector<int> &nums, int start, int end){
            // if(start == end) return;
            nums[start] = nums[start] ^ nums[end];
            nums[end] = nums[start] ^ nums[end];
            nums[start] = nums[start] ^ nums[end];

            // int temp = nums[start];
            // nums[start] = nums[end];
            // nums[end] = temp;
        }

        void printArray(vector<int> &nums){
            for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
            cout<<endl;
        }
};

int main(){
    int size;
    cout<<"ENTER THE SIZE OF THE ARRAY : "<<endl;
    cin>>size;
    vector<int> nums(size);

    cout<<"ENTER NUMS INTO THE ARRAY : "<<endl;

    for(int i=0;i<size;i++){
        cin>>nums[i];
    }

    Solution* sol = new Solution();

    cout<<"ARRAY BEFORE SORTING : "<<endl;
    sol->printArray(nums);

    sol->bubbleSort(nums);

    cout<<"ARRAY AFTER SORTING : "<<endl;
    sol->printArray(nums);

    delete sol;
}