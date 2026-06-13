#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
        void mergeSort(vector<int> &nums){
            breakArray(nums,0,nums.size()-1);
        }

        void breakArray(vector<int> &nums, int low, int high){
            if(low >= high) return;

            int mid = low + (high - low)/2 ; // to prevent integer overflow

            breakArray(nums,low,mid);
            breakArray(nums,mid+1,high);

            sortArray(nums,low,mid,high);
        }

        void sortArray(vector<int> &nums, int low, int mid, int high){
            int left = low;
            int right = mid+1;

            vector<int> tempArray;

            while(left <= mid && right <= high){
                if(nums[left] <= nums[right]){
                    tempArray.push_back(nums[left]); left++;
                }
                else {tempArray.push_back(nums[right]); right++;}
            }

            while(left <= mid){
                tempArray.push_back(nums[left]); left++;
            }

            while(right <= high){
                tempArray.push_back(nums[right]); right++;
            }

            for(int i=low; i<=high;i++){
                nums[i] = tempArray[i-low];
            }
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

    sol->mergeSort(nums);

    cout<<"ARRAY AFTER SORTING : "<<endl;
    sol->printArray(nums);

    delete sol;
}