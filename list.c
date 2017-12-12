#include<stdio.h>
#include<stdlib.h>
#include"h.h"

node *ptr;
void init(void){
        head = tail = NULL;
}
void fifo(int *seq, int no) {
        int i, j;
        node *temp, *check;
        check = head;

        if(cnt_of_page_fault < size_of_frame){
                temp = (node *)malloc(sizeof(node));
                temp->next = NULL;

                if(head == NULL){
                        ptr = head = tail = temp;
                        cnt_of_page_fault++;
                }

                else {
                        while(check != NULL){
                                if(check->val == seq[no])
                                        break;
                                check = check->next;
                        }
                        if(check == NULL){
                                tail->next = temp;
                                cnt_of_page_fault++;
                                tail = tail->next;
                        }
                }

                temp->val = seq[no];
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                for(i = cnt_of_page_fault; i< size_of_frame; i++)
                        printf("\t");
                printf("%d\n", cnt_of_page_fault);
        }

        else {
                while(check != NULL){
                        if(check->val == seq[no])
                                break;
                        check = check->next;
                }
                if(check == NULL){
                        cnt_of_page_fault++;
                        ptr->val = seq[no];
                        ptr = ptr->next;
                        if(ptr == NULL)
                                ptr = head;
                }
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                printf("%d\n", cnt_of_page_fault);
        }
}

void optimal(int *seq, int no) {
        int i, j, k, p, q;
        node *temp, *ptr, *check;
        check = head;

        if(cnt_of_page_fault < size_of_frame){
                temp = (node *)malloc(sizeof(node));
                temp->next = NULL;
                temp->ref = 1000;
                temp->ref2 = 1000;

                if(head == NULL){
                        ptr = head = tail = temp;
                        cnt_of_page_fault++;
                }

                else {
                        while(check != NULL){
                                if(check->val == seq[no])
                                        break;
                                check = check->next;
                        }
                        if(check == NULL){
                                tail->next = temp;
                                cnt_of_page_fault++;
                                tail = tail->next;
                        }
                }

                temp->val = seq[no];
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                for(i = cnt_of_page_fault; i< size_of_frame; i++)
                        printf("\t");
                printf("%d\n", cnt_of_page_fault);
        }

        else {
                while(check != NULL){
                        if(check->val == seq[no])
                                break;
                        check = check->next;
                }
                if(check == NULL){
                        cnt_of_page_fault++;
                        temp = head;
                        for(i = 0; i < size_of_frame; i++){
                                for(j = no + 1; j < tot_pages; j++){
                                        if(seq[j] == temp->val){
                                                temp->ref = j;
                                                break;
                                        }
                                }
                                temp = temp->next;
                        }
                        temp = ptr = head;
                        while(temp != NULL){
                                if(temp->ref > ptr->ref)
                                        ptr = temp;
                                temp = temp->next;
                        }
                        ptr->val = seq[no];
                        temp = head;
                        while(temp != NULL){
                                temp->ref = 1000;
                                temp = temp->next;
                        }

                }
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                printf("%d\n", cnt_of_page_fault);
        }
}

void lru(int *seq, int no) {
        int i, j, k, p, q;
        node *temp, *ptr, *check;
        check = head;

        if(cnt_of_page_fault < size_of_frame){
                temp = (node *)malloc(sizeof(node));
                temp->next = NULL;
                temp->ref = 1000;
                temp->ref2 = 1000;

                if(head == NULL){
                        ptr = head = tail = temp;
                        cnt_of_page_fault++;
                }

                else {
                        while(check != NULL){
                                if(check->val == seq[no])
                                        break;
                                check = check->next;
                        }
                        if(check == NULL){
                                tail->next = temp;
                                cnt_of_page_fault++;
                                tail = tail->next;
                        }
                }

                temp->val = seq[no];
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                for(i = cnt_of_page_fault; i< size_of_frame; i++)
                        printf("\t");
                printf("%d\n", cnt_of_page_fault);
        }

        else {
                while(check != NULL){
                        if(check->val == seq[no])
                                break;
                        check = check->next;
                }
                if(check == NULL){
                        cnt_of_page_fault++;
                        temp = head;
                        for(i = 0; i < size_of_frame; i++){
                                for(j = no  -  1; j >= 0; j--){
                                        if(seq[j] == temp->val){
                                                temp->ref = j;
                                                break;
                                        }
                                }
                                temp = temp->next;
                        }
                        temp = ptr = head;
                        while(temp != NULL){
                                if(temp->ref < ptr->ref)
                                        ptr = temp;
                                temp = temp->next;
                        }
                        ptr->val = seq[no];
                        temp = head;
                        while(temp != NULL){
                                temp->ref = 1000;
                                temp = temp->next;
                        }

                }
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                printf("%d\n", cnt_of_page_fault);
        }
}

void lfu(int *seq, int no) {
        int i, j, k, p, q;
        node *temp, *ptr, *check;
        check = head;

        if(cnt_of_page_fault < size_of_frame){
                temp = (node *)malloc(sizeof(node));
                temp->next = NULL;
                temp->ref = 1000;
                temp->ref2 = 1000;

                if(head == NULL){
                        ptr = head = tail = temp;
                        cnt_of_page_fault++;
                }

                else {
                        while(check != NULL){
                                if(check->val == seq[no])
                                        break;
                                check = check->next;
                        }
                        if(check == NULL){
                                tail->next = temp;
                                cnt_of_page_fault++;
                                tail = tail->next;
                        }
                }

                temp->val = seq[no];
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                for(i = cnt_of_page_fault; i< size_of_frame; i++)
                        printf("\t");
                printf("%d\n", cnt_of_page_fault);
        }

        else {
                while(check != NULL){
                        if(check->val == seq[no])
                                break;
                        check = check->next;
                }
                if(check == NULL){
                        cnt_of_page_fault++;
                        temp = head;
                        for(i = 0; i < size_of_frame; i++){
                                for(j = no  -  1; j >= 0; j--){
                                        if(seq[j] == temp->val){
                                                temp->ref++;
                                        }
                                }
                                temp = temp->next;
                        }
                        temp = ptr = head;
                        while(temp != NULL){
                                if(temp->ref < ptr->ref)
                                        ptr = temp;
                                temp = temp->next;
                        }
                        ptr->val = seq[no];
                        temp = head;
                        while(temp != NULL){
                                temp->ref = 1000;
                                temp = temp->next;
                        }

                }
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                printf("%d\n", cnt_of_page_fault);
        }
}

void mfu(int *seq, int no) {
        int i, j, k, p, q;
        node *temp, *ptr, *check;
        check = head;

        if(cnt_of_page_fault < size_of_frame){
                temp = (node *)malloc(sizeof(node));
                temp->next = NULL;
                temp->ref = 1000;
                temp->ref2 = 1000;

                if(head == NULL){
                        ptr = head = tail = temp;
                        cnt_of_page_fault++;
                }

                else {
                        while(check != NULL){
                                if(check->val == seq[no])
                                        break;
                                check = check->next;
                        }
                        if(check == NULL){
                                tail->next = temp;
                                cnt_of_page_fault++;
                                tail = tail->next;
                        }
                }

                temp->val = seq[no];
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                for(i = cnt_of_page_fault; i< size_of_frame; i++)
                        printf("\t");
                printf("%d\n", cnt_of_page_fault);
        }

        else {
                while(check != NULL){
                        if(check->val == seq[no])
                                break;
                        check = check->next;
                }
                if(check == NULL){
                        cnt_of_page_fault++;
                        temp = head;
                        for(i = 0; i < size_of_frame; i++){
                                for(j = no  -  1; j >= 0; j--){
                                        if(seq[j] == temp->val){
                                                temp->ref++;
                                        }
                                }
                                temp = temp->next;
                        }
                        temp = ptr = head;
                        while(temp != NULL){
                                if(temp->ref > ptr->ref)
                                        ptr = temp;
                                temp = temp->next;
                        }
                        ptr->val = seq[no];
                        temp = head;
                        while(temp != NULL){
                                temp->ref = 1000;
                                temp = temp->next;
                        }

                }
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                printf("%d\n", cnt_of_page_fault);
        }
}

void second_chance(int *seq, int no) {
        int i, j;
        node *temp, *check;
        check = head;

        if(cnt_of_page_fault < size_of_frame){
                temp = (node *)malloc(sizeof(node));
                temp->next = NULL;
                temp->ref = 1;

                if(head == NULL){
                        ptr = head = tail = temp;
                        cnt_of_page_fault++;
                }

                else {
                        while(check != NULL){
                                if(check->val == seq[no])
                                        break;
                                check = check->next;
                        }
                        if(check == NULL){
                                tail->next = temp;
                                cnt_of_page_fault++;
                                tail = tail->next;
                        }
                }

                temp->val = seq[no];
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                for(i = cnt_of_page_fault; i< size_of_frame; i++)
                        printf("\t");
                printf("%d\n", cnt_of_page_fault);
        }

        else {
                while(check != NULL){
                        if(check->val == seq[no]) {
                                check->ref = 1;
                                break;
                        }
                        check = check->next;
                }
                if(check == NULL){
                        cnt_of_page_fault++;
                        while(1){
                                if(ptr == NULL)
                                        ptr = head;
                                if(ptr->ref == 1){
                                        ptr->ref = 0;
                                        ptr = ptr->next;
                                }
                                else if(ptr->ref == 0){
                                        ptr->val = seq[no];
                                        ptr->ref = 1;
                                        ptr = ptr->next;
                                        break;
                                }
                        }
                        if(ptr == NULL)
                                ptr = head;
                }
                temp = head;
                while(temp != NULL){
                        printf("%d\t", temp->val);
                        temp = temp->next;
                }
                printf("%d\n", cnt_of_page_fault);
        }
}

void enhanced_second_chance(int *seq, int no, int dirty) {
        int i, j, k, l;
        node *temp, *check, *ptr2;
        check = head;

        if(cnt_of_page_fault < size_of_frame){
                temp = (node *)malloc(sizeof(node));
                temp->next = NULL;
                temp->ref = 1;
                temp->ref2 = dirty;

                if(head == NULL){
                        ptr = head = tail = temp;
                        cnt_of_page_fault++;
                }

                else {
                        while(check != NULL){
                                if(check->val == seq[no])
                                        break;
                                check = check->next;
                        }
                        if(check == NULL){
                                tail->next = temp;
                                cnt_of_page_fault++;
                                tail = tail->next;
                        }
                }

                temp->val = seq[no];
                temp = head;
                while(temp != NULL){
                        printf("%d\t%d%d\t", temp->val, temp->ref, temp->ref2);
                        temp = temp->next;
                }
                for(i = cnt_of_page_fault; i< size_of_frame; i++)
                        printf("\t  \t");
                printf("%d\n", cnt_of_page_fault);
        }

        else {
                while(check != NULL){
                        if(check->val == seq[no]) {
                                check->ref = 1;
                                break;
                        }
                        check = check->next;
                }
                if(check == NULL){
                        cnt_of_page_fault++;
                        ptr2 = ptr;
                        if(ptr == NULL)
                                ptr = head;

                        for(i = 0; i <= 1; i++){
                                l = 0;
                                for(j = 0; j < 2; j++){
                                        l = 0;
                                        ptr2 = ptr;
                                        while(1){
                                                if(ptr2 == NULL) {
                                                        ptr2 = head;
                                                        if(ptr == head)
                                                                break;
                                                }
                                                if(ptr2->ref == 0 && ptr2->ref2 == j){
                                                        l = 1;
                                                        break;
                                                }
                                                ptr2 = ptr2->next;
                                                if(ptr2 == ptr)
                                                        break;

                                        }
                                        if(l == 1)
                                                break;
                                }
                                if(l == 1)
                                        break;
                                ptr2 = head;
                                while(ptr2 != NULL){
                                        ptr2->ref = 0;
                                        ptr2 = ptr2->next;
                                }
                        }
                        ptr2->val = seq[no];
                        ptr2->ref = 1;
                        ptr2->ref2 = dirty;
                        ptr = ptr2->next;
                        if(ptr == NULL)
                                ptr = head;

                }
                temp = head;
                while(temp != NULL){
                        printf("%d\t%d%d\t", temp->val, temp->ref, temp->ref2);
                        temp = temp->next;
                }
                printf("%d\t\t%d\n", cnt_of_page_fault, ptr->val);
        }
}
