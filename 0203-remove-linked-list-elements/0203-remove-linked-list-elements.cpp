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

    void deleteAtHead(ListNode* &head)
    {
        if (head == NULL)
            return;
        else
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
    ListNode* removeElements(ListNode* head, int val) 
    {
        // Handle the case where the head needs to be removed (if multiple elements at head match val)
        while (head != nullptr && head->val == val) 
        {
            deleteAtHead(head);
        }

        // If list is empty after removing elements at the head
        if (head == nullptr) 
        {
            return head;
        }

        // Handle remaining list
        ListNode *curr = head;
        while (curr->next != nullptr)
        {
            if (curr->next->val == val) 
            {
                ListNode *toDelete = curr->next;
                curr->next = toDelete->next;
                delete toDelete;
            }
            else
            {
                curr = curr->next;
            }
        }

        return head; // Return the modified list
    }
};