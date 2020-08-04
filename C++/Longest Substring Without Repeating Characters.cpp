//
//  main.cpp
//  LeetCode_longest_substring
//
//  Created by Christian on 2020/8/4.
//  Copyright © 2020 Christian. All rights reserved.
//

#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
    
    int string_length = s.length();
    
    if (string_length == 0)
        return 0;
    
    int ascii_table[26] = {0};
    int max_length = 1;
    
    for(int i = 0; i < string_length - 1; i++) {
        
        int length = 1;
        int begin_alphabet_index = int(s[i]) - 97;
        ascii_table[begin_alphabet_index] = 1;
        
        for(int j = i + 1; j < string_length; j++) {
            int alphabet_index = int(s[j]) - 97;
            
            if (ascii_table[alphabet_index] != 1) {
                length++;
                ascii_table[alphabet_index] = 1;
                max_length = max(length, max_length);
            } else {
                
                for (int k = 0; k < 26; k++)
                    ascii_table[k] = 0;
                
                max_length = max(length, max_length);
                break;
            }
        }
    }
    
    return max_length;
}

int main() {
    
    string s = "   ";
    
    cout << lengthOfLongestSubstring(s) << endl;
    
    return 0;
}

