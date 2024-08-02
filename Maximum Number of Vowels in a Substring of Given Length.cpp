class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0, j = 0, maxVows = 0, n = s.size(), cnt = 0;
        while (j < n) {
            // If the current character is a vowel, increment the count
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                cnt++;
            }
            
            // When the window size exceeds k, slide the window
            if (j - i + 1 > k) {
                // Remove the effect of the character going out of the window
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                    cnt--;
                }
                i++; // Move the start of the window to the right
            }
            
            // Update the maximum number of vowels found
            maxVows = max(maxVows, cnt);
            
            // Expand the window by moving the end of the window to the right
            j++;
        }
        
        return maxVows;   
    }
};
