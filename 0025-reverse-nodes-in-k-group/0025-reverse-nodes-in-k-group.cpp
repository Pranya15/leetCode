/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode* temp = head;
    int cnt = 0;

    // Check if k nodes exist
    while (cnt < k)
    {
        if (temp == NULL)
            return head;

        temp = temp->next;
        cnt++;
    }

    // Reverse first k nodes
    temp = head;
    cnt = 0;
    ListNode* prevNode = NULL;

    while (cnt < k)
    {
        ListNode* next = temp->next;

        temp->next = prevNode;
        prevNode = temp;
        temp = next;

        cnt++;
    }

    // Recursively process remaining list
    head->next = reverseKGroup(temp, k);

    return prevNode;
}
};