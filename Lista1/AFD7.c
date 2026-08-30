#include <stdio.h>
#include <string.h>

// This DFA allows: {0,1}* without the 101 sequence

int main(){
    char word [100];
    int p = 0;
    int state = 0;

    printf("Enter a binary word: ");
    fgets(word, sizeof(word), stdin);
 
    word[strcspn(word, "\n")] = '\0';

    while(word[p] != '\0'){
    
        switch (state){
            case 0:
                switch(word[p]){
                    case '0':
                        state = 0; break;
                    case '1':
                        state = 1; break;
                } break;
            case 1:
                switch(word[p]){
                    case '0':
                        state = 2; break;
                    case '1':
                        state = 1; break;
                } break;
            case 2:
                switch(word[p]){
                    case '0':
                        state = 0; break;
                    case '1':
                        state = 3; break;
                } break;
            case 3:
                switch(word[p]){
                    case '0':
                        state = 3; break;
                    case '1':
                        state = 3; break;
                } break;
        }

        p++;
    }
    
    if (state != 3 || word[0] == '\0') { // Allows λ too
        printf("Accepted.\n");
    }
    else{
        printf("Rejected.\n");
    }

    return 0;
}