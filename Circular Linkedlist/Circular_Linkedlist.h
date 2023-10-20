/*@Amgad Diploma_C21-Circular_Linkedlist_17October2023*/
/*Circular_Linkedlist_Driver*/
/*Auther:     Alaa Ashraf
**Date:       3October2023
**LastUpdate: 11October2023*/

#ifndef    __LINKEDLIST_H__
#define    __LINKEDLIST_H__


enum finding_result{
    EMPTY_LIST=-2,NOT_FOUND=-1,FOUND
};
typedef struct Node
{
    u16 info;
    struct Node * link;
}Circular_Node_t;


/******************************************************************************************************************************/
/*Function:     Insertion a Node at Beginning of a Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       void*/
void Insertion_at_Beginning(u16 info, Circular_Node_t * Last);



/******************************************************************************************************************************/
/*Function:     Insertion a Node to an Empty Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       a pointer to the new end of the list after adding the node*/
Circular_Node_t * Insertion_at_Empty_List(u16 info, Circular_Node_t * Last);

/******************************************************************************************************************************/
/*Function:     Insertion a Node at end of a Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       a pointer to the new end of the list after adding the node*/
Circular_Node_t * Insertion_at_End(u16 info, Circular_Node_t * Last);



/******************************************************************************************************************************/
/*Function:     Create a Linkedlist
* Parameters:   void
* Return:       a pointer to the end of the created list */
Circular_Node_t * Create_List(void);


/******************************************************************************************************************************/
/*Function:     Displaying the data of Linkedlist
* Parameters:   -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       void*/
void Display_List(Circular_Node_t * Last);


/******************************************************************************************************************************/
/*Function:     Insertion after a Node in a Linkedlist
* Parameters:  -info[u16]:     the data of Node wanted to insert after it
*              -new_info[u16]:     the data of Node wanted to be insert 
*              -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       a pointer to the new end of the list*/
Circular_Node_t * Insertion_after_a_Node(u16 info, Circular_Node_t * Last, u16 new_info);


/************************************************************************************************before'******************************/
/*Function:     Insertion before a Node in a Linkedlist
* Parameters:  -info[u16]:     the data of Node wanted to insert before it
*              -new_info[u16]:     the data of Node wanted to be insert 
*              -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       void*/
void Insertion_before_a_Node(u16 info, Circular_Node_t * Last, u16 new_info);



/******************************************************************************************************************************/
/*Function:     Delete a Node with Particular Data in a Linkedlist
* Parameters:  -Last[Circular_Node_t*]: a pointer to the end of the list
*              -data[u16]: the data wanted to delete its node  
* Return:       a pointer to the end of the list after deletion*/
Circular_Node_t* Delete_with_Particular_Data( Circular_Node_t * Last, u16 data);



/******************************************************************************************************************************/
/*Function:     Reversing a Circular Linkedlist
* Parameters:  -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       a pointer to the end of the list after reversing*/
Circular_Node_t * Reverse_List(Circular_Node_t* Last);


/******************************************************************************************************************************/
/*Function:     Concatenate Two Circular Linkedlists
* Parameters:  -First_List_Last[Circular_Node_t*]: a pointer to the end of the first circular linked list
*              -Second_List_Last[Circular_Node_t*]: a pointer to the end of the second circular linked list
* Return:       a pointer to the end of the list generated from concatenating*/
Circular_Node_t * Concatenate_Two_Circular_Linkedlists(Circular_Node_t* First_List_Last, Circular_Node_t* Second_List_Last );



/*************************************************************************/
/**The Following Functions from Single Linkedlist Driver WITHOUT Editing**/
/******************************************************************************************************************************/
/*Function:     Insertion a Node at Particular Position in a Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -list[Circular_Node_t*]: a pointer to the start of the list
*              -position[u16]: the position wanted to add the node in 
* Return:       a pointer to the start of the new list*/
Circular_Node_t* Insertion_at_Particular_Position(u16 info, Circular_Node_t * list, u16 position);



/******************************************************************************************************************************/
/*Function:     Searching for a given data in a Linkedlist
* Parameters:  -data[u16]:    the data wanted to search for in the list
*              -list[Circular_Node_t*]: a pointer to the start of the list
* Return:       [s16] the result of searching [EMPTY_LIST,NOT_FOUND,OR the position of data]*/
s16 Search_for_Node(u16 data , Circular_Node_t * list);



/******************************************************************************************************************************/
/*Function:     Displaying the data of the Particular Position in a Linkedlist
* Parameters:  -list[Circular_Node_t*]: a pointer to the start of the list
*              -position[u16]: the position wanted to display its data 
* Return:       void*/
void Display_Node_at_Particular_Position(Circular_Node_t * list, u16 position);


/******************************************************************************************************************************/
/*Function:     Counting Nodes in a Linkedlist
* Parameters:  -list[Circular_Node_t*]: a pointer to the start of the list
* Return:       Number of Nodes*/
u16 Count_Nodes(Circular_Node_t * list);



#endif
