/* 
                        Long Pressed Name
                        =================

Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed output.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.size()>typed.size()){
            return false;
        }
        int i=0,j=0;
        while(i<name.size() && j<typed.size()){
            if(name[i]==typed[j]){
                i++;
                j++;
            }else if(i>0 && typed[j]==name[i-1]){
                j++;
            }else{
                return false;
            }
        }
        while(j<typed.size()){
            if(typed[j]!=name[i-1]){
                return false;
            }
            j++;
        }
        return i==name.size();
    }
};