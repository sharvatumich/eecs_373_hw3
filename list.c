#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

    list_t * cur = head;
    
    if (new_element->index < head->index)
    {
        list_t * temp = head;
        head = new_element;
        new_element->next = temp;
    }
    else
    {
        while (cur->next != NULL && cur->next->index < new_element->index)
        {
            cur = cur->next;
        }
        
        if (cur->next == NULL)
        {
            cur->next = new_element;
            new_element->next = NULL;
        }
        else
        {
            list_t * temp = cur->next;
            cur->next = new_element;
            new_element->next = temp;
        }
    }
    
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
    assert(head != NULL);
    
    if (head->next != NULL)
    {
        list_t * current = head;
        current = head->next;
        
        list_t * previous = head;
        list_t * next = current->next;
        
        previous->next = NULL;
        
        while (current != NULL)
        {
            current->next = previous;
            previous = current;
            current = next;
            
            if (next != NULL)
            {
                next = next->next;
            }
        }
        head = previous;
    }
    return head;
}

