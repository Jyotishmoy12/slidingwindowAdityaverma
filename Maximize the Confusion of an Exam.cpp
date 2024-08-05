class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int maxConsecutive = 0;
        int trueCount = 0;
        int falseCount = 0;
        int left = 0;
        int right = 0;

        while (right < n) {
            if (answerKey[right] == 'T') {
                trueCount++;
            } else {
                falseCount++;
            }

            if (min(trueCount, falseCount) > k) {
                if (answerKey[left] == 'T') {
                    trueCount--;
                } else {
                    falseCount--;
                }
                left++;
            }

            maxConsecutive = max(maxConsecutive, right - left + 1);
            right++;
        }

        trueCount = 0;
        falseCount = 0;
        left = 0;
        right = 0;

        while (right < n) {
            if (answerKey[right] == 'F') {
                falseCount++;
            } else {
                trueCount++;
            }

            if (min(trueCount, falseCount) > k) {
                if (answerKey[left] == 'F') {
                    falseCount--;
                } else {
                    trueCount--;
                }
                left++;
            }

            maxConsecutive = max(maxConsecutive, right - left + 1);
            right++;
        }

        return maxConsecutive;
    }
};


/*
First pass (focusing on 'T'):

Initialize: maxConsecutive = 0, trueCount = 0, falseCount = 0, left = 0, right = 0
Iterate through the string:

right = 0: 'T', trueCount = 1, maxConsecutive = 1
right = 1: 'T', trueCount = 2, maxConsecutive = 2
right = 2: 'F', falseCount = 1, maxConsecutive = 3
right = 3: 'T', trueCount = 3, maxConsecutive = 4
right = 4: 'T', trueCount = 4, maxConsecutive = 5
right = 5: 'F', falseCount = 2
Now, min(trueCount, falseCount) > k, so we move left:
left = 1, trueCount = 3, maxConsecutive stays 5
right = 6: 'T', trueCount = 4, maxConsecutive stays 5
right = 7: 'T', trueCount = 5, maxConsecutive stays 5



Second pass (focusing on 'F'):

Reset: trueCount = 0, falseCount = 0, left = 0, right = 0
Iterate through the string:

right = 0: 'T', trueCount = 1, maxConsecutive stays 5
right = 1: 'T', trueCount = 2, maxConsecutive stays 5
right = 2: 'F', falseCount = 1, maxConsecutive stays 5
right = 3: 'T', trueCount = 3, maxConsecutive stays 5
right = 4: 'T', trueCount = 4, maxConsecutive stays 5
right = 5: 'F', falseCount = 2
Now, min(trueCount, falseCount) > k, so we move left:
left = 1, trueCount = 3, maxConsecutive stays 5
right = 6: 'T', trueCount = 4, maxConsecutive stays 5
right = 7: 'T', trueCount = 5, maxConsecutive stays 5



The final output is maxConsecutive = 5

*/
