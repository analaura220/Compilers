#include <stdio.h>

// This DFA allows: 1(1 | 0)*1

int main(){
    char word [100];
    int p = 0;
    int state = 0;

    printf("Enter a binary word: ");
    scanf("%99s", word);

    while(word[p] != '\0'){

        switch (state){
            case 0:
                switch(word[p]){
                    case '0':
                        state = 3; break;
                    case '1':
                        state = 1; break;
                } break;
            case 1:
                switch(word[p]){
                    case '0':
                        state = 2; break;
                    case '1':
                        state = 2; break;
                } break;
            case 2:
                switch(word[p]){
                    case '0':
                        state = 2; break;
                    case '1':
                        state = 1; break;
                } break;
        }

        p++;
    }
    
    if (state == 1) {
        printf("Accepted.\n");
    }
    else{
        printf("Rejected.\n");
    }

    return 0;
}