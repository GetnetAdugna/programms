/*   Getnet Adugna Abite 
    ugr/3381/12
    section-3
  
  */


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
/*An enumeration defined to track the state of the given character */
enum State {INSIDE_MAIN_CODE,COMMENT_ENTRY,BACK_SLASH,BACK_SLASH_CHAR,INSIDE_COMMENT,COMMENT_END,INSIDE_STRING,INSIDE_CHAR  
} ;


enum State handleMainCode(enum State,char);
enum State handleCommentEntry(enum State ,char,int *,int *);
enum State handleInsideComment(enum State ,char);
enum State handleCommentEnd(enum State ,char);

enum State handleInsideString(enum State ,char);

enum State handleInsideChar(enum State ,char);
enum State  handleBackSlash(enum State ,char);
enum State handleBackSlashChar(enum State ,char);



/*Main function*/
int main(int argc, char** argv){
    int lineNumber=1;
    char pointed_char;
    

    enum State state=INSIDE_MAIN_CODE;
    int comment_begining_line=1;

    while(( pointed_char=getchar())&&pointed_char!=EOF){
            if(pointed_char=='\n'){
                     lineNumber++;
              }
             if(state==INSIDE_MAIN_CODE){
                 state=handleMainCode(state, pointed_char);
             }
             else if(state==COMMENT_ENTRY){
                 state=handleCommentEntry(state, pointed_char,&comment_begining_line,&lineNumber);
             }
             else if(state==INSIDE_COMMENT){
                   state=handleInsideComment(state, pointed_char);     
             }
             else if(state==COMMENT_END){
                   state=handleCommentEnd(state, pointed_char);   
             }
             else if(state==BACK_SLASH){
                  state=handleBackSlash(state, pointed_char);
                 
             }
             else if(state==BACK_SLASH_CHAR){
                  state=handleBackSlashChar(state, pointed_char);
                 
             }
             else if(state==INSIDE_STRING){
                   state=handleInsideString(state, pointed_char);
                 
             }
             else if(state==INSIDE_CHAR){
                  state=handleInsideChar(state, pointed_char);
               
                 
             }
             else{
                  fprintf(stderr, "ERROR:the pointer is not in the listed states!",comment_begining_line);
             }
             }

      if(pointed_char==EOF){
        if (state == INSIDE_COMMENT || state == COMMENT_END) {
        fprintf(stderr, " Error: line %d  unterminated comment\n",comment_begining_line);
        exit(-1);

    }
        else{
            exit(0);
        }
    }
        
    return 0;
}

//-------------------------------------------------------------

  
  enum State handleBackSlash(enum State state, char pointed_char) {

    state = INSIDE_STRING;
    putchar(pointed_char);
    return state;

}
  enum State handleMainCode(enum State  state,char pointed_char)  {
      switch(pointed_char){
          case '/':
              state = COMMENT_ENTRY;
              
              break;
         
          case '\'':
              state = INSIDE_CHAR;
              break;
          case '\"':
              state = INSIDE_STRING;
              break;     
      }
   
    if( state !=COMMENT_ENTRY){
       
        putchar(pointed_char);
    }
    return state;
  }
//-------------------------------------------------------------
enum State handleCommentEntry(enum State state ,char pointed_char,int * commentLine,int* currentCodeLine){

    if ( pointed_char== '*') {
         
        state = INSIDE_COMMENT;
        *commentLine = *currentCodeLine;
    } 
     else if (( pointed_char== '/') && state == COMMENT_ENTRY) {
         putchar(pointed_char); 
        state = COMMENT_ENTRY;   
    }  
    else if ( pointed_char== '/') {
        state = COMMENT_ENTRY;
    } 
    else {
        state = INSIDE_MAIN_CODE;
    }

    if (state == INSIDE_MAIN_CODE) {
        putchar('/');
        putchar(pointed_char);
    }
    return state;

};
enum State handleInsideComment(enum State  state,char pointed_char){
    

    if (pointed_char== '*') {
        state = COMMENT_END;
    }

    if (pointed_char== '\n') {
        putchar(pointed_char);
    }
    return state;

}
enum State handleCommentEnd(enum State state ,char pointed_char){

    if (pointed_char == '/') {
        state = INSIDE_MAIN_CODE;
    } else if (pointed_char == '*') {
        state = COMMENT_END;
    } else if(pointed_char!='/'||pointed_char!='*') {
        state = INSIDE_COMMENT;
    }
    else{
        state=INSIDE_COMMENT;
    }

    if (state == INSIDE_MAIN_CODE) {
        putchar(' ');
    }

return state;
}
enum State handleInsideString(enum State state ,char pointed_char){
  // LITTLE BIT TO BE HANDLED HERE!
  switch(pointed_char){
      case '\"':
      state=INSIDE_MAIN_CODE;
      break;
      case '\\':
      state = BACK_SLASH;
      break;

  }

    putchar(pointed_char);

return state;
};

enum State handleInsideChar(enum State state ,char pointed_char){
    putchar(pointed_char);
    switch(pointed_char){
      case '\'':
      state=INSIDE_MAIN_CODE;
      
      break;
      case '\\':
      state = BACK_SLASH_CHAR;
      
      break;
      
      }
      return state;
}
        
enum State handleBackSlashChar(enum State state, char pointed_char) {
      putchar(pointed_char);
      state = INSIDE_CHAR;


      return state;
  
}
