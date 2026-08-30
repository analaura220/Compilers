#include <stdio.h>
#include <string.h>

// This DFA allows: (a | (a*ba*ba*))*

int main(){
    char word [100];
    int p = 0;
    int state = 0;

    printf("Enter a word containing {a, b}: ");
    fgets(word, sizeof(word), stdin);
 
    word[strcspn(word, "\n")] = '\0';

    while(word[p] != '\0'){
    
        switch (state){
            case 0:
                switch(word[p]){
                    case 'a':
                        if(p == 0){
                            state = 0; break;
                        }else{
                            state = 1; break;
                        }    
                    case 'b':
                        state = 2; break;
                } break;
            case 1:
                switch(word[p]){
                    case 'a':
                        state = 1; break;
                    case 'b':
                        state = 2; break;
                } break;
            case 2:
                switch(word[p]){
                    case 'a':
                        state = 2; break;
                    case 'b':
                        state = 3; break;
                } break;
            case 3:
                switch(word[p]){
                    case 'a':
                        state = 3; break;
                    case 'b':
                        state = 4; break;
                } break;
            case 4:
                switch(word[p]){
                    case 'a':
                        state = 4; break;
                    case 'b':
                        state = 4; break;
                } break;
        }

        p++;
    }
    
    if (state == 0 || state == 3 || word[0] == '\0') { // Allows λ too
        printf("Accepted.\n");
    }
    else{
        printf("Rejected.\n");
    }

    return 0;
}