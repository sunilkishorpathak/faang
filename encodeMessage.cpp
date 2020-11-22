#include<vector>
#include<iostream>

using namespace std;

/*
 * Question : next..Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
 * count the number of ways it can bedecoded. For example, the message '111' would give 3,
 * since it could be decoded as 'aaa', 'ka', and 'ak'.
 *
 *  123 : 1-2-3(abc), 12-3(lc), 1-23 (aw)
 *  103 : 1-0-3 (wrong, 0 is not present), 10-3 (jc)
 *
 *   Time: 11/22/2020 7:30AM - 8:03AM
 *
 *  i/p: mapping for encoding : 1 to 26, corresponds to a to z
 *      encoded string containing numbers from 0 to 9
 *  o/p : Decoded string
 *
 * Intuition: Every character can be itself, or can be clubbed with first OR next one (3 cases only)
 *      First and last will make only 1 + 1 count.
 *      Check about the others which can be conbined with previous and next one.
 *  ?? how to check 65 can't be clubbed :
 *  Ans - use converter (int)('1'-48) * 10 + ('2' - 48) must be less than equal to 26
 *
 *  Algo:
 *      If string null or size 0, return count 0
 *      If string size 1 and it's not 0, return 1 else return 0
 *
 *      For index 1 (excluding first char) to size()-1
 *          Add 1,
 *          if prev+current <- valid ? add 1 : 0
 *          if current + next <- valid ? add 1 : 0
 *
 *  Complexity : Time O(n)
 *              Space O(1)
 */

//str will be 2 characters only
//first character can't be 0
bool isValidEncode(char firstChar, char secondChar) {
    if (firstChar == '0') return false;
 
    if (firstChar== '1') {
        if ((int)secondChar >= 48 && (int)secondChar <= 57) return true; //0 to 9
    } else {
        if (firstChar == '2') {
            if ((int)secondChar >= 48 && (int)secondChar <= 54) return true; //0 to 6
        }
    }
    
    return false;
}

int countDecodedString(string encodedMessage) {
    if (encodedMessage.size() == 0)
        return 0;
    if (encodedMessage.size() == 1) {
        if (encodedMessage[0] == '0')
            return 0; //not valid
        else
            return 1; //only 1 character
    }
    
    int count = 0;
    for (int currenctIndex=1; currenctIndex < encodedMessage.size() - 2; ++currenctIndex) {
        count++;
        if (isValidEncode(encodedMessage[currenctIndex-1], encodedMessage[currenctIndex]) == true) {
            count++;
        }
        if (isValidEncode(encodedMessage[currenctIndex], encodedMessage[currenctIndex-1]) == true) {
            count++;
        }
    }
    
    //last char
    count = count + 1;
    
    return count;
}
int main(int argc, char *argv[]){
    
    
}

