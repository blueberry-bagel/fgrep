#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char*, FILE*, char*);


int main(int argc, char* argv[]){
    
    if(argc < 2){
        fprintf(stderr, "Usage: executable string file ...");
        exit(1);
    }

    FILE* open;
    char* val = argv[1];

    for(int i = 2; i < argc; i++){
        open = fopen(argv[i], "r");

        if(open == NULL){
            fprintf(stderr, "%s: No such file or directory", argv[i]);

        }

        if(open != NULL){
            search(argv[i], open, val);
            fclose(open);
        }
        
    }


return 0;
}

void search(char* file, FILE* open, char* val){

    size_t len = 300;
    char* line = malloc(len);
    char* same;

    while(fgets(line, len, open) != NULL){
        char* line2 = line;
        same = strstr(line, val);

        if(same != NULL){
            printf("\n%s:", file);
            printf("%s", line2);
        }
    }
    free(line);



}
