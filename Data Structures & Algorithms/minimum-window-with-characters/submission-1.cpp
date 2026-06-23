#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Define a Node to store the character and its original index in 's'
struct ListNode {
    char ch;
    int index;
    ListNode* next;
    ListNode(char c, int i) : ch(c), index(i), next(nullptr) {}
};

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }

        // 1. Build a Linked List of relevant characters
        ListNode* head = new ListNode('#', -1); // Dummy head
        ListNode* tail = head;
        
        for (int i = 0; i < s.length(); i++) {
            // Only add characters that exist in 't'
            if (targetFreq.count(s[i])) {
                tail->next = new ListNode(s[i], i);
                tail = tail->next;
            }
        }

        // 2. Sliding Window over the Linked List
        ListNode* left = head->next;
        ListNode* right = head->next;
        
        unordered_map<char, int> windowFreq;
        int required = targetFreq.size();
        int formed = 0;
        
        int minLen = INT_MAX;
        int minStart = 0;

        while (right != nullptr) {
            char c = right->ch;
            windowFreq[c]++;
            
            // If the current character's frequency matches the required frequency
            if (windowFreq[c] == targetFreq[c]) {
                formed++;
            }

            // Shrink the window from the left as long as it remains valid
            while (left != nullptr && formed == required) {
                // Check if we found a smaller window
                int currentLen = right->index - left->index + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    minStart = left->index;
                }

                // Remove the leftmost character from the window
                char leftChar = left->ch;
                windowFreq[leftChar]--;
                if (windowFreq[leftChar] < targetFreq[leftChar]) {
                    formed--;
                }
                
                // Move the left pointer forward
                left = left->next;
            }
            
            // Move the right pointer forward
            right = right->next;
        }

        // Freeing the linked list memory is good practice in C++
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};