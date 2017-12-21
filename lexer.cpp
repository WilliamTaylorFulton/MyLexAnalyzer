//*****************************************************************************
// purpose: CSE 4713 / 6713 Assignment 1: Lexical Analyzer
// created: 8-25-2015
//  author: William Fulton
//*****************************************************************************
#include "lexer.h"
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
//*****************************************************************************
// Do the lexical parsing
char lexeme[MAX_LEXEME_LEN];  // Character buffer for lexeme
int yylex()
{
  static char c = -1;         // Have we read the first character yet?
  int char_type;              // Hold the character type

  // Prepare the buffer to hold the lexeme
  for( int i = 0; i < MAX_LEXEME_LEN; i++ )
    lexeme[i] = '\0';
  yytext = lexeme;
  yyleng = 0;
    
  // If the very first character has not yet been read, read it
    if( c < 0 ){
    c = fgetc( yyin );
    }
    int temp;


    // Jump Spaces
//    

    
    if (c == ' ')
    {
        
        do
        {
            c = fgetc( yyin );
        }while ( c == ' ');
        
    }
    // New line at end of lines
    if (c == '\n')
    {


        yyLine++;
        c = fgetc( yyin );

        
    }
    


 
    
    // Check for symbols
    switch (c)
    {

            // Semicolon
        case ';':
            temp = (TOK_SEMICOLON);
            break;

            // Open Parentheses
        case '(':
            temp = (TOK_OPENPAREN);
            break;
            
            // Close Parentheses
        case ')':
            temp = (TOK_CLOSEPAREN);
            break;
            
            // Open Bracket
        case '[':
            temp = (TOK_OPENBRACKET);
            break;
            
            // Close Bracket
        case ']':
            temp = (TOK_CLOSEBRACKET);
            break;
            
            // Open Brace
        case '{':
            temp = (TOK_OPENBRACE);
            break;
            
            // Close Brace
        case '}':
            temp = (TOK_CLOSEBRACE);
            break;
            
            // Comma
        case ',':
            temp = (TOK_COMMA);
            break;
            
            // Slash
        case '\\':
            
            temp = (TOK_SLASH);
            break;
            
            // Divide
        case '/':
            temp = (TOK_DIVIDE);
            break;
            
            // Dot
        case '.':
            temp = (TOK_DOT);
            break;
            
            // Plus
        case '+':
            temp = (TOK_PLUS);
            break;
            
            // Minus
        case '-':
            temp = (TOK_MINUS);
            break;
            
            // Multiply
        case '*':
            temp = (TOK_MULTIPLY);
            break;

            
            // Greater than
        case '>':
            temp = (TOK_GREATERTHAN);
            break;
            
            // Otherwise unknown
        default:
            temp = TOK_UNKNOWN;
            break;
    }
    


    // Jump COMMENT lines
    while (c == '#')
    {
        
        while ((c = fgetc( yyin )) != '\n'){}
        

        
        yyLine++;
        c = fgetc( yyin );
        if (c == '\n')
        {
            yyLine++;
            c = fgetc( yyin );
        }
        
        
        
    }

    
    
    
    // Input begins with letter
    while(isalpha(c))
    {
        
        if (c == 's')
        {
            
            do{
                
                lexeme[yyleng++] = c;
                lexeme[yyleng] = 0;
                c = fgetc( yyin );
                
            }while (c == 's');
            if (c == 't')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 't');
                
            }
            if (c == 'r')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'r');
                
            }
            if (c == 'i')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'i');
                
            }
            if (c == 'n')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'n');
                
            }
            if (c == 'g')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'g');
                
            }
            // if space after g = STRING
            if (c == ' ')
            {
                
                return(TOK_STRING);
                
            }
            
            // SET (s shared with STRING check)
            else if (c == 'e')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'e');
                
            }
            // if space after t = SET
            if (c != ' ')
            {
                
                
                lexeme[yyleng++] = c;
                lexeme[yyleng] = 0;
                c = fgetc( yyin );
                if(c == ' ')
                {
                    
                    return(TOK_SET);
                }
            }
        }
        
        // OR
        if (c == 'o')
        {
            do{
                
                lexeme[yyleng++] = c;
                lexeme[yyleng] = 0;
                c = fgetc( yyin );
                
            }while (c == 'r');
            
            // if space after r = OR
            if (c == ' ')
            {
            return(TOK_OR);
            }
        }
        
        // FLOAT
        if (c == 'f')
        {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'f');
            
                if (c == 'l')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'l');
    
                }
                if (c == 'o')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'o');
                    
                }
                if (c == 'a')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'a');
                    
                }
                if (c == 't')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 't');
                    
                }
                // if space after t = FLOAT
                if (c == ' ')
                {
                    
                    return(TOK_FLOAT);
                    
                }
        }

        // AND
        if (c == 'a')
        {
            do{
                
                lexeme[yyleng++] = c;
                lexeme[yyleng] = 0;
                c = fgetc( yyin );
                
            }while (c == 'a');
            
                if (c == 'n')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'n');
                    
                }
                if (c == 'd')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'd');
                
                    // if nothing after d = AND
                if (c == ' ')
                {
                    
                    return(TOK_AND);
                    
                }
            }
        }
        
        // INT
        if (c == 'i')
        {
            do{
                
                lexeme[yyleng++] = c;
                lexeme[yyleng] = 0;
                c = fgetc( yyin );
                
            }while (c == 'i');
            
            if (c == 'n')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'n');
                
            }
            if (c == 't')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 't');
                
                // if nothing after t = INT
                if (c == ' ')
                {
                    
                    return(TOK_INT);
                    
                }
            }
        }
        
        
        // LENGTH
        if (c == 'l')
        {
            do{
                
                lexeme[yyleng++] = c;
                lexeme[yyleng] = 0;
                c = fgetc( yyin );
                
            }while (c == 'l');
            
            if (c == 'e')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'e');
                
            }
            if (c == 'n')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'n');
                
            }
            if (c == 'g')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'g');
                
            }
            if (c == 't')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 't');
                
            }
            if (c == 'h')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'h');
                
            }
            // if nothing after h = LENGTH
            if (c == ' ')
            {
                
                return(TOK_LENGTH);
                
            }
        }
        
        // NOT
        if (c == 'n')
        {
            do{
                
                lexeme[yyleng++] = c;
                lexeme[yyleng] = 0;
                c = fgetc( yyin );
                
            }while (c == 'n');
            
            if (c == 'o')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'o');
                
            }
            if (c == 't')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 't');
                
                // if nothing after t = NOT
                if (c == ' ')
                {
                    
                    return(TOK_NOT);
                    
                }
            }
        }
        
        // Check for DICTIONARY
        if (c == 'd')
        {
            
            do{
                
                lexeme[yyleng++] = c;
                lexeme[yyleng] = 0;
                c = fgetc( yyin );
                
            }while (c == 'd');
            if (c == 'i')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'i');
                
            }
            if (c == 'c')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'c');
                
            }
            if (c == 't')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 't');
                
            }
            if (c == 'i')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'i');
                
            }
            if (c == 'o')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'o');
                
            }
            
            if (c == 'n')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'n');
                
            }
            
            if (c == 'a')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'a');
                
            }
            
            
            if (c == 'r')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'r');
                
            }
            
            
            if (c == 'y')
            {
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'y');
                
            }
            
            if (c == ' ')
            {
                
                return(TOK_DICTIONARY);
                
            }
        }
        
            // Check for EVALUATOR
            if (c == 'e')
            {
                
                do{
                    
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );
                    
                }while (c == 'e');
                if (c == 'v')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'v');
                    
                }
                if (c == 'a')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'a');
                    
                }
                if (c == 'l')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'l');
                    
                }
                if (c == 'u')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'u');
                    
                }
                if (c == 'a')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'a');
                    
                }
                
                if (c == 't')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 't');
                    
                }
                
                if (c == 'e')
                {
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'e');
                    
                }
                
                if (c == ' ')
                {
                    
                    return(TOK_EVALUATE);
                    
                }
            }
            
                
                
                
                // Combinator
                if (c == 'c')
                {
                    
                    do{
                        
                        lexeme[yyleng++] = c;
                        lexeme[yyleng] = 0;
                        c = fgetc( yyin );
                        
                    }while (c == 'c');
                    if (c == 'o')
                    {
                        do{
                            
                            lexeme[yyleng++] = c;
                            lexeme[yyleng] = 0;
                            c = fgetc( yyin );
                            
                        }while (c == 'o');
                        
                    }
                    if (c == 'm')
                    {
                        do{
                            
                            lexeme[yyleng++] = c;
                            lexeme[yyleng] = 0;
                            c = fgetc( yyin );
                            
                        }while (c == 'm');
                        
                    }
                    if (c == 'b')
                    {
                        do{
                            
                            lexeme[yyleng++] = c;
                            lexeme[yyleng] = 0;
                            c = fgetc( yyin );
                            
                        }while (c == 'b');
                        
                    }
                    if (c == 'i')
                    {
                        do{
                            
                            lexeme[yyleng++] = c;
                            lexeme[yyleng] = 0;
                            c = fgetc( yyin );
                            
                        }while (c == 'i');
                        
                    }
                    if (c == 'n')
                    {
                        do{
                            
                            lexeme[yyleng++] = c;
                            lexeme[yyleng] = 0;
                            c = fgetc( yyin );
                            
                        }while (c == 'n');
                        
                    }
                    
                    if (c == 'a')
                    {
                        do{
                            
                            lexeme[yyleng++] = c;
                            lexeme[yyleng] = 0;
                            c = fgetc( yyin );
                            
                        }while (c == 'a');
                        
                    }
                    
                    if (c == 't')
                    {
                        do{
                            
                            lexeme[yyleng++] = c;
                            lexeme[yyleng] = 0;
                            c = fgetc( yyin );
                            
                        }while (c == 't');
                        
                    }
                    
                    
                    if (c == 'o')
                    {
                        do{
                            
                            lexeme[yyleng++] = c;
                            lexeme[yyleng] = 0;
                            c = fgetc( yyin );
                            
                        }while (c == 'o');
                        
                    }
                    
                    
                    if (c == 'r')
                    {
                        do{
                            
                            lexeme[yyleng++] = c;
                            lexeme[yyleng] = 0;
                            c = fgetc( yyin );
                            
                        }while (c == 'r');
                        
                    }
                    
                    if (c == ' ')
                    {
                        
                        return(TOK_COMBINATOR);
                        
                    }
                }


        // If letter is followed by a letter/number/underscore
        // then we have an identifier
        // IDENTIFIER
        while(isalnum(c) || c == '_')
              {
                  
                  lexeme[yyleng++] = c;
                  lexeme[yyleng] = 0;
                  c = fgetc( yyin );
              }
        
        return(TOK_IDENTIFIER);
        }

    
    // Checks for number
    while (isdigit(c))
    {
        
        do
        {
            
            lexeme[yyleng++] = c;
            lexeme[yyleng] = 0;
            c = fgetc( yyin );
            // If number contains decimal followed by number, FLOAT
            if (c == '.')
            {
                do
                {
                lexeme[yyleng++] = c;
                lexeme[yyleng] = 0;
                c = fgetc( yyin );
                }while(isdigit(c));
                return(TOK_FLOATLIT);
            }

            
                
        }while(isdigit(c));
        // No decimal, integer literal
        return(TOK_INTLIT);
        c = 0;
    }
    
    // String literal
     if(c == '"')
    {
        // stores everything between quotes
        do{
            
            lexeme[yyleng++] = c;
            lexeme[yyleng] = 0;
            c = fgetc( yyin );
            
        }while (c != '"');
        
        temp = (TOK_STRINGLIT);
        
        
    }
    
    // C identifier
    if(c == '$')
    {

        do
        {
            lexeme[yyleng++] = c;
            lexeme[yyleng] = 0;
            c = fgetc( yyin );
            if (!isalpha(c))
            {
                return (TOK_UNKNOWN);
                
            }
            else
            {
                do
                {
                    lexeme[yyleng++] = c;
                    lexeme[yyleng] = 0;
                    c = fgetc( yyin );

                    
                }while(isalnum(c) || c == '_');
            }
        }while(isalnum(c) || c == '_');

        return (TOK_CIDENTIFIER);}
        
        //c = 0;
        
    


    // Less than if < alone
    // Not equal to if <>
    if (c == '<')
    {
        while(c == '<')
        {
            lexeme[yyleng++] = c;
            lexeme[yyleng] = 0;
            c = fgetc( yyin );

            if (c == '>')
            {
                temp = (TOK_NOTEQUALTO);
            }
            else
            {
                return(TOK_LESSTHAN);
            }
        }

    }

    // Equal to
   if (c == '=')
    {
        lexeme[yyleng++] = c;
        lexeme[yyleng] = 0;
        c = fgetc( yyin );
        if (c == '=')
        {
            lexeme[yyleng++] = c;
            lexeme[yyleng] = 0;
            c = fgetc( yyin );
            if (c == ' ')
            {
                return (TOK_EQUALTO);
            }
            
        }
        else
        {
            return (TOK_UNKNOWN);
        }
    }

    
    
    // Assign
    else if (c == ':')
    {
        do
        {
            lexeme[yyleng++] = c;
            lexeme[yyleng] = 0;
            c = fgetc( yyin );
        }while(c == ':');
            if (c == '=')
            {
                temp = (TOK_ASSIGN);
            }
            else
            {
                return(TOK_UNKNOWN);
            }
        
        
        
    }



    

lexeme[yyleng++] = c;
c = fgetc( yyin );
    
    if( feof(yyin) ) {
        // Ready for next time
        c = -1;
        // Done!
        return( TOK_EOF );
    }

return temp;
    
    
}
