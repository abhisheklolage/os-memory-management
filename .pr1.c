#include<stdio.h>
#include<stdlib.h>
#include"h.h"

int main() {
        int i = 0, j = 0, no = 0;
        int choice, dir_cnt = 0, dir_val = 0;
        init();
        printf(ANSI_COLOR_RED"\n\t\t\tSelect any one option from menu\n"ANSI_COLOR_RESET);
        printf("1) FIFO\n2) OPTIMAL\n3) LRU\n4) LFU\n5) MFU\n6) Second Chance\n7) Enhanced Second chance\n");
        scanf("%d", &choice);
        if(choice < 0 || choice > 7) {
                                system("spd-say \"chutiyee correct option enter ker\"");
                                return 0;
        }
        printf("Enter the total number of pages\n");
        scanf("%d", &no);
        int arr[no], p;
        int dir[no];
        for(i = 0; i < no; i++)
                dir[i] = 0;
        printf("Enter the sequence of pages\n");
        for(i = 0; i < no; i++)
                scanf("%d", &arr[i]);
        printf("Enter the size of page frame\n");
        scanf("%d", &j);
        size_of_frame = j;

        /*For enhanced second chance*/
        if(choice == 7){
                printf("Enter the no of dirty bits\n");
                scanf("%d", &dir_cnt);
                printf("Enter the indexes of dirty bits\n");
                for(i = 0; i < dir_cnt; i++){
                        scanf("%d", &p);
                        dir[p - 1] = 1;
                }
        }
        printf(ANSI_COLOR_RED"\n\nReference String\t");
        for(i = 1; i <= j; i++)
                printf("F%d\t", i);
        printf(ANSI_COLOR_RED"Page Fault\n"ANSI_COLOR_RESET);
        tot_pages = no;
        for(i = 0; i < no; i++) {
                printf("%d\t\t\t", arr[i]);
                switch(choice){
                        case 1:
                                fifo(arr, i);
                                break;
                        case 2:
                                optimal(arr, i);
                                break;
                        case 3:
                                lru(arr, i);
                                break;
                        case 4:
                                lfu(arr, i);
                                break;
                        case 5:
                                mfu(arr, i);
                                break;
                        case 6:
                                second_chance(arr, i);
                                break;
                        case 7:
                                enhanced_second_chance(arr, i, dir[i]);
                                break;
                        default:
                                printf("wrong_option\n");
                }
        }
        return 0;
}
