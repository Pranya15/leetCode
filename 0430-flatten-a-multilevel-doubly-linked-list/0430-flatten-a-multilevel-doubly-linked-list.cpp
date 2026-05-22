/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
    if (head == NULL)
        return head;

    Node* curr = head;

    while (curr != NULL)
    {
        if (curr->child != NULL)
        {
            // Flatten the child list
            Node* next = curr->next;

            flatten(curr->child);

            curr->next = curr->child;
            curr->next->prev = curr;

            curr->child = NULL;

            // Find tail of flattened child list
            while (curr->next != NULL)
            {
                curr = curr->next;
            }

            // Attach tail with next node
            if (next != NULL)
            {
                curr->next = next;
                next->prev = curr;
            }
        }

        curr = curr->next;
    }

    return head;

    }
};