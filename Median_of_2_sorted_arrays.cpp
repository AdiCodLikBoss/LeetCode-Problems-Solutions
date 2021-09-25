#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double median_even(vector<int>&a){
        int n = a.size();
        int ind = n/2;
        return (a[ind]+a[ind-1])/2.0;
    }
    double median_odd(vector<int>&a){
        int n = a.size();
        return a[n/2];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(n==0 && m==0)
            return 0.00000;
        
        if(n==0){
            if(m%2==0)
                return median_even(nums2);
            
            return median_odd(nums2);
        }
        
        if(m==0){
            if(n%2==0)
                return median_even(nums1);
            
            return median_odd(nums1);
        }
        // Main Idea: 
        // Partition the final array(into 2 halves),
        // formed after merging both the arrays,
        // but we don't merge them using the 2 pointer algorithm,
        // as we are only concerned with one element (if len is odd),
        // or 2 elements (if len is even).
        // A valid partition -> (all elements in left half)<=(all elements in right half)
        // if we know we have taken some elements from the 1st array,
        // we can calculate how many elements to take from 2nd array.
        // Binary Search for the number of elements to be taken from 1st array.
        // Valid partition -> max(l1,l2)<=min(r1,r2)
        // l1 ,l2 = maximum elements from nums1, and nums2,in first half.
        // r1 ,r2 = minimum elements from nums1, and nums2,in second half.
        // if(l1 > r2)  make hi = mid-1
        // if(l2 > r1)  make lo = mid+1
        
        
        // To ensure, we never pick more than the required elements from a given array
        if(n>m){
            swap(nums1,nums2);
            n = nums1.size();
            m = nums2.size();
        }
        
        int lo = 0;
        int hi = n;
        int mid;
        int len = n+m;
        while(lo<=hi){
            mid = (lo+hi)/2;
            int req = ((n+m+1)/2) - mid;
            
            int l1 = mid==0?INT_MIN:nums1[mid-1];
            int l2 = req==0?INT_MIN:nums2[req-1];
            
            int r1 = mid==n?INT_MAX:nums1[mid];
            int r2 = req==m?INT_MAX:nums2[req];
            
            if(l1<=r2 && l2<=r1){
                if(len%2==0)
                    return ((max(l1,l2)) + (min(r1,r2)))/2.0;
                else
                    return (max(l1,l2));
            }
            if(l1>r2){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return 0.0;
    }
};