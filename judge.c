#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(void){
    printf("Judge System\nPlease input your filename without .c:\n");
    char filename[30];
    scanf("%s", filename);

    char command[60] = "gcc ";
    strcat(command, filename);
    strcat(command,  ".c -o ");
    strcat(command,filename);

    system(command); /* compile the program */

    int n;
    printf("Please ensure the format of the file names of test data is correct, and input the number of test data you have:\n");
    scanf("%d", &n);
    
    bool result = true;
    int maxtime = 0;
    for(int i = 0; i < n; i++){
        strcpy(command, "");
        sprintf(command, "%s.exe < %d.in > %dmy.out", filename, i, i);
        
        clock_t t1 = clock();
        system(command); /* run the program */
        clock_t t2 = clock();

        bool AC = true;
        char ans[30]; sprintf(ans, "%d.out", i);
        char my[30]; sprintf(my, "%dmy.out", i);
        FILE *ans_out = fopen(ans, "rt"), *my_out = fopen(my, "rt");
        while(!feof(ans_out) && !feof(my_out)){
            char ans_c = fgetc(ans_out), my_c = fgetc(my_out);
            if(ans_c != my_c){
                result = AC = false;
                break;
            }
        }
        if(!feof(ans_out) || !feof(my_out))
            result = AC = false;

        if(AC) printf("Subtask %d.in : Accepted ", i);
        else printf("Subtask %d.in : Wrong Answer ", i);

        printf("(%d ms)\n", t2 - t1);
        if(t2 - t1 > maxtime) maxtime = t2 - t1;
    }

    printf("Final result : ");
    if(result)
        printf("Accepted ");
    else
        printf("Wrong Answer ");
    printf("(%d ms)\n", maxtime);
    
    return 0;
}