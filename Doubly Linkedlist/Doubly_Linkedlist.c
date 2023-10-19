/*@Amgad Diploma_C20-Doubly_Linkedlist_17October2023*/
/*Doubly_Linkedlist_Driver*/
/*Auther:     Alaa Ashraf
**Date:       17October2023
**LastUpdate: 17October2023*/

#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "Doubly_Linkedlist.h"


/******************************************************************************************************************************/
/*Function:     Displaying the data of Linkedlist
* Parameters:   -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       void*/
void Display_List(Doubly_Node_t * list){
    if(list==NULL)
	{
		printf("List is empty\n");
	}
	
	else
	{
    Doubly_Node_t * p=list;
    u32 i=1;
    while(p != NULL){
        printf("The node no. %d and its data is %d\n", i++ , p->info);
        p=p->next;
    }
    }
}

/******************************************************************************************************************************/
/*Function:     Insertion a Node at Beginning of a Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       a pointer to the new start of the list after adding the node*/

Doubly_Node_t * Insertion_at_Beginning(u32 info, Doubly_Node_t * list){
    if(list==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
    //Create the inserted node in the list
    Doubly_Node_t * temp =(Doubly_Node_t*) malloc(sizeof(Doubly_Node_t));
    temp->info =info;
    temp->next=list;                  /*Make the new node points to the previous first node*/
    temp->prev=NULL;                  /*Make the prev pointer in temp points to NULL AS now it is the first node*/
    list->prev =temp;                 /*Update the prev pointer of previous first node with node temp address*/
    list=temp;                        /*Update the reference to the list*/
   
    }
    return list;
}



/******************************************************************************************************************************/
/*Function:     Insertion a Node to an Empty Linkedlist
* Parameters:  -info[u32]:     the data wanted to be stored in the node
*              -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       a pointer to the new start of the list after adding the node*/

Doubly_Node_t * Insertion_at_Empty_List(u32 info, Doubly_Node_t * list){
    if(list!=NULL)
	{
		printf("List is NOT empty\n");
	}
	else
	{
    //Create the inserted node in the list
    Doubly_Node_t * temp =(Doubly_Node_t*) malloc(sizeof(Doubly_Node_t));
    
    temp->info =info;
    temp->next=list;             /*Make the new node points to the previous first node[which in empty list is null]*/
    temp->prev=NULL;                  /*Make the prev pointer in temp points to NULL AS now it is the first node*/
    list=temp;                   /*Update the reference to the list*/
    }
    return list;
}




/******************************************************************************************************************************/
/*Function:     Insertion a Node at end of a Linkedlist
* Parameters:  -info[u32]:     the data wanted to be stored in the node
*              -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       void*/

void Insertion_at_End(u32 info, Doubly_Node_t * list){
    Doubly_Node_t * p= list;
    if(list == NULL){
        printf("\nThe list is Empty\n");
    }else{
        while (p->next != NULL)  //p->link (the last Node)
        {
            //Traverse
            p=p->next;
        }
        //Create the inserted node in the list
        Doubly_Node_t * temp =(Doubly_Node_t*) malloc(1*sizeof(Doubly_Node_t));
        temp->info =info;
        //Out of this loop with p points to the last Node
        // p->next=temp;
        // temp ->next =NULL;
        // temp -> prev= p;
        //OR 
        temp->next=p->next;    //makes next pointer in temp points to the next node[which @ end of list is null] 
        temp->prev = p;         //AND previous pointer in temp points to p (selected node[previous last node])
        p->next = temp;         //Update next pointer in p (selected node[previous last node]) points to temp
        
    }
}



/******************************************************************************************************************************/
/*Function:     Insertion after a Node in a Linkedlist
* Parameters:  -info[u32]:     the data of Node wanted to insert after it
*              -new_info[u32]:     the data of Node wanted to be insert 
*              -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       void*/
void Insertion_after_a_Node(u32 info, Doubly_Node_t * list, u32 new_info){
    Doubly_Node_t * p= list;

    if(list == NULL){

        printf("\nThe list is Empty\n");
    }else{
        enum finding_result Check;
        while (p!= NULL)  //p (the NULL)
        {
            //Using enum to check on the reason of break
            Check=NOT_FOUND;
            //Check on position
            if(p->info == info){    //p points the node wanted to insert after
                Check=FOUND;
                break;
            }
            //Traverse
            p=p->next;
        
            
        }

        //Out of this loop with p points to the last Node OR p points to the Node has info
        //Check if the Node has info is found or not
        if(Check == FOUND){
            //the position if found
            /*.... BUT if the next node is NULL?!*/
            //if the next node is NULL
            if(p->next == NULL){
                Insertion_at_End(new_info,list);
            }else{
                //Create the inserted node in the list
                Doubly_Node_t * temp =(Doubly_Node_t*) malloc(1*sizeof(Doubly_Node_t));
                temp->info =new_info;
                temp->prev = p;     //Update previous pointer in temp points to p (selected node)
                temp->next=p->next;    //makes next pointer in temp points to the next node
                p->next = temp;        //Update next pointer of p (selected node) points to temp
                temp->next->prev =temp; //AND make the previous pointer in next node points to temp 
            }

        }
        else{
            printf("\nThe Node has the %d is NOT_FOUND in the list\n",info);
        }
    }
    
}



/******************************************************************************************************************************/
/*Function:     Insertion before a Node in a Linkedlist
* Parameters:  -info[u32]:     the data of Node wanted to insert before it
*              -new_info[u32]:     the data of Node wanted to be insert 
*              -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       void*/
Doubly_Node_t * Insertion_before_a_Node(u32 info, Doubly_Node_t * list, u32 new_info){

    Doubly_Node_t * p= list;

    if(list == NULL){

        printf("\nThe list is Empty\n");
    }else{
        enum finding_result Check;

        /***************/
        // //Note: This Solution doesnot work if the node has info is the frist node ... it is cancelled
        // while (p->next!= NULL)  //p->link (the Node before the NULL)
        // {
        //     //Using enum to check on the reason of break
        //     Check=NOT_FOUND;
        //     //Check on position
        //     if(p->next->info == info){     //p points the node wanted to insert after(this node precedes the node wanted to insert before)
        //         Check=FOUND;
        //         break;
        //     }
        //     //Traverse
        //     p=p->next;
        
            
        // }

        // //Out of this loop with p->next points to the last Node OR p points to the Node before that has info
        // //Check if the Node has info is found or not
        // if(Check == FOUND){
        //     //the position if found
        //     //Create the inserted node in the list
        //     Doubly_Node_t * temp =(Doubly_Node_t*) malloc(1*sizeof(Doubly_Node_t));
        //     temp->info =new_info;
        //     temp->prev = p;     //Update previous pointer in temp points to p (selected node)
        //     temp->next=p->next;    //makes next pointer in temp points to the next node
        //     p->next = temp;        //Update next pointer of p (selected node) points to temp
        //     temp->next->prev =temp; //AND make the previous pointer in next node points to temp
        // }
        // else{
        //     printf("\nThe Node has the %d is NOT_FOUND in the list\n",info);
        // }
        /***************/

        /**************/
        //OR
        while (p!= NULL)  //p (the NULL)
        {
            //Using enum to check on the reason of break
            Check=NOT_FOUND;
            //Check on position
            if(p->info == info){      //p points the node wanted to insert before
                Check=FOUND;
                break;
            }
            //Traverse
            p=p->next;
        }
        //Out of this loop with p points to the last Node OR p points to the Node has info
        //Check if the Node has info is found or not
        if(Check == FOUND){
            //the position if found
            /*.... BUT if the previous node is NULL?! ... this means the node has info is the frist node*/
            //if the previous node is NULL
            if(p->prev == NULL){
                list = Insertion_at_Beginning(new_info,list);
            }else{
                //Create the inserted node in the list
                Doubly_Node_t * temp =(Doubly_Node_t*) malloc(1*sizeof(Doubly_Node_t));
                temp->info =new_info;
                temp->next = p;     //Update next pointer in temp points to p (selected node)
                temp->prev=p->prev;    //makes previous pointer in temp points to the previous node before p
                p->prev->next =temp;  //AND make the next pointer in the node (that precedes p) points to temp
                p->prev = temp;        //Update previous pointer of p (selected node) points to temp
            }
        }
        else{
            printf("\nThe Node has the %d is NOT_FOUND in the list\n",info);
        }
        /**************/
    }

    return list;
    
}



/******************************************************************************************************************************/
/*Function:     Create a Linkedlist
* Parameters:   void
* Return:       a pointer to the start of the created list */

Doubly_Node_t * Create_List(void){
    //Create pointer start points to the empty list
    Doubly_Node_t * start = NULL;

    u32 Node_Count;
    printf("Enter the number of wanted Nodes in the linkedlist : ");
    scanf("%d",&Node_Count);

    if(Node_Count != 0){
        u32 data;
        printf("Enter the data of the node no. %d : " ,1);
        scanf("%d",&data);
    

        //insert it in the empty list
        start = Insertion_at_Empty_List(data,start);     

        // printf("\nNode_Count= %d\n", Node_Count);
        // printf("\ndata= %d\n", data);
        for(u16 i=1; i<Node_Count ; i++){

        printf("Enter the data of the node no. %d : " ,i+1);
        scanf("%d",&data);
        Insertion_at_End(data,start);

        }
    }else{
        /*Do Nothing*/
    }

    
    return start;
}



/******************************************************************************************************************************/
/*Function:     Delete a Node with Particular data in a Linkedlist
* Parameters:  -list[Doubly_Node_t*]: a pointer to the start of the list
*              -position[u16]: the position wanted to delete the node from 
* Return:       a pointer to the start of the list after deletion*/
Doubly_Node_t * Delete_A_Node( Doubly_Node_t * list, u32 data){
    Doubly_Node_t * temp = list;
    if(list == NULL){
        printf("\nThe list is Empty\n");
    }else{

        enum finding_result Check;
        //Using enum to check on the reason of break
        Check=NOT_FOUND;

        //Check if the node wanted to delete is the 1st node or not
        if(list->info == data){
            Check=FOUND;
            //Check if the frist node (that has data) is the ONLY node or not
            if(list->next == NULL){
                list = NULL;
            }else{
                //If the frist node (that has data) but not the only node
                list=list->next;
                list->prev=NULL;
            }
            //In last two cases we free temp 
            free(temp);

        /*The deleted node NOT the ONLY and NOT the 1st*/
        }else{   

            while (temp->next != NULL)   //p->link (the Node before the NULL)
            {
                Check=NOT_FOUND;
                if(temp->info == data){    //temp pionts to node has data
                    Check = FOUND;
                    break;
                }
                //Traverse
                temp=temp->next;
            }

            /*the node has data is found and temp points to it*/
            if(Check == FOUND){
                //Check if temp (the node has data) is the LAST node or not
                //Deletion in between
                temp->prev->next=temp->next;  //Make the next node to temp points to the previous node of temp
                temp->next->prev=temp->prev;        //Make the previous node of temp points to the next node to temp
                free(temp);

            }else{
                /*Check on if the last node has the data or not ,as it is not found in previous nodes before NULL*/
                /*As when Check=NOT_FOUND while loop breaks with temp points to last node*/
                //Delete the last node
                if(temp->info == data){                              
                    temp->prev->next =NULL;      //Make the node precedes the last node points to null [makes it the last node]
                    free(temp);
                }else{
                /*the node has data is not found in the whole list*/
                printf("\nThe node has the data %d is NOT_FOUND\n",data);}
            }            

        }
    }

    return list;
}


/******************************************************************************************************************************/
/*Function:     Reversing a Single Linkedlist
* Parameters:  -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       a pointer to the start of the list after reversing*/
Doubly_Node_t * Reverse_List(Doubly_Node_t* list){
    if(list == NULL){
        printf("\nThe list is Empty\n");
    }else{
        Doubly_Node_t * ptr = list;
        Doubly_Node_t * Next= NULL;
        while(ptr != NULL){
            //Traverse
            Next = ptr->next;
            /*Reverse*/
            ptr->next =ptr->prev;   
            ptr->prev=Next;
            list=ptr;
            //Traverse
            ptr = Next;
        }
       
    }
    return list;
}