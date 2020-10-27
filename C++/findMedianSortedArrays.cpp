//
//  main.cpp
//  leetCode_testing
//
//  Created by Christian on 2020/8/5.
//  Copyright © 2020 Christian. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    if (nums1.size() == 0) {
        unsigned long int nums2_size = nums2.size();
        unsigned long int index = nums2_size / 2;
        
        if (nums2_size % 2 == 0) {
            return double(nums2[index - 1] + nums2[index]) / 2;
        } else {
            return double(nums2[index]);
        }
        
    } else if (nums2.size() == 0) {
        unsigned long int nums1_size = nums1.size();
        unsigned long int index = nums1_size / 2;
        
        if (nums1_size % 2 == 0) {
            return double(nums1[index - 1] + nums1[index]) / 2;
        } else {
            return double(nums1[index]);
        }
    }
    
    unsigned long int total_combine_array_size = nums1.size() + nums2.size();
    unsigned long int detect_index = total_combine_array_size / 2;
        
    int nums1_index = 0;
    int nums2_index = 0;
    
    vector<int> new_nums;
    
    while (new_nums.size() <= detect_index) {
        if (nums1[nums1_index] < nums2[nums2_index]) {
            new_nums.push_back(nums1[nums1_index]);
            nums1_index++;
        } else {
            new_nums.push_back(nums2[nums2_index]);
            nums2_index++;
        }
    }
    
    double result;
    
    if (total_combine_array_size % 2 == 0) {
        int last_value = new_nums.back();
        new_nums.pop_back();
        int second_last_value = new_nums.back();
        
        result = double(last_value + second_last_value) / 2;
    } else {
        int last_value = new_nums.back();
        
        result = double(last_value);
    }
    
    return result;
}

int main() {
    
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    
    clock_t s, e;

    s = clock();
    
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    
    e = clock();
    
    cout << double(e - s) / double(CLOCKS_PER_SEC) << endl;
    
    return 0;
}
