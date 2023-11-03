#include <stdio.h>
#include <stdlib.h>

// this shows the structure of a node
struct TreeNode {
    int dataPoint;
    struct TreeNode* next;
};

// this will insert a value into the sorted list 
void insert( struct TreeNode** head , int Nodevalue ) {

    // this creates a new node
    struct TreeNode* newTreeNode = ( struct TreeNode* )malloc( sizeof( struct TreeNode ) );
   
   if ( newTreeNode == NULL ) {
        fprintf( stderr , "Memory allocation = failed \n");
        exit( 1 );
    }

    newTreeNode -> next = NULL;
    newTreeNode -> dataPoint = Nodevalue;
    
    // this will show if the nodes in the list are empty/ less than the first element 
    if ( *head == NULL || Nodevalue < ( *head ) -> dataPoint ) {

        newTreeNode -> next = *head;
        *head = newTreeNode;

        return;
    }

    // will find the right position to insert
    struct TreeNode* current = *head;
    for (; current->next != NULL && current->next->dataPoint < Nodevalue; current = current->next) {
    }

    newTreeNode -> next = current -> next;
    current -> next = newTreeNode;
}

// this will delete a node/value from the sorted list 
void delete( struct TreeNode** head , int Nodevalue ) {

    if ( *head == NULL ) {
        return;
    }

    // this will find out if it is the first in the list to be deleted 
    if ( ( *head ) -> dataPoint == Nodevalue ) {
        struct TreeNode* temp = *head;
        *head = ( *head ) -> next;
        free( temp );
        return;
    }

    struct TreeNode* current = *head;
    
    for ( ; current -> next != NULL && current -> next -> dataPoint != Nodevalue; current = current -> next ) {
    
    }

    // if there is nothing / value in the list is not there 
    if ( current -> next == NULL ) {
        return;
    }

    // this will take the node with a specific value and delete it 
    struct TreeNode* tempNode = current -> next;
    current -> next = current -> next -> next;
    free( tempNode );
}

// this prints the whole sorted list 
void printList( struct TreeNode* head ) {

    for ( ; head != NULL; head = head -> next ) {
    printf( "%d" , head -> dataPoint );
    
    if ( head -> next != NULL ) {
        printf( " " );
    }
}
    printf( "\n" );
}

int main() {

    struct TreeNode* head = NULL;
    int Nodevalue;
    char operation;

    while ( scanf( " %c%d" , &operation , &Nodevalue ) != EOF ) {
        if ( operation == 'd' ) {

            delete( &head , Nodevalue );

        } else if ( operation == 'i') {

            insert( &head , Nodevalue );
        }

        // this will systematically count the nodes/elements and pring out the final list 
        
        struct TreeNode* current = head;
        int add = 0;

        while ( current != NULL ) {
            current = current -> next;
            add++;
        }
        if( add == 0 ){

            printf( "0 :" );

        } else {
            
            printf( "%d : " , add );
               
        } 

        printList( head );
    }

    // this will release the memory that the linked list used 
    while ( head != NULL ) {
        
        struct TreeNode* temp = head;
        head = head -> next;
        free( temp );
    }
    return 0;
}