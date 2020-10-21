#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
enum TokenType { IDENTIFIER = 34512, CONSTANT = 87232, SPECIAL = 29742 } ;
typedef char * CharPtr ;
struct Column {
  int column ;                  
  Column * next;                
} ; // Column
typedef Column * ColumnPtr ;
struct Line {                   
  int line ;                    
  ColumnPtr firstAppearAt ;     
  ColumnPtr lastAppearAt ;     
  Line *  next;                
} ;
typedef Line * LinePtr ;
struct Token {                  
  CharPtr tokenStr ;            
  TokenType type;               
  LinePtr firstAppearOn ;       
  LinePtr lastAppearOn ;        
  Token * next ;                
} ; // struct Token
typedef Token * TokenPtr ;
TokenPtr gFront = NULL, gRear = NULL ;  
Token * gtoken = NULL;
typedef char Str100[ 100 ] ; 
int gLine = 1 ;              
int gColumn = 0 ;    
// ---------
void addCol( ColumnPtr &c, int col ) {
  if ( c != NULL ) {
    addCol( c->next, col ) ;
  } // if
  else {
    c = new Column ;
    c->column = col;
    c->next = NULL;
  } // else
} // addLine
void addLine( LinePtr &l, int line, int col ) {
  if ( l != NULL ) {
    if ( l->line == line ) {
      addCol( l->firstAppearAt, col );
    } // if
    else {
      addLine( l->next, line, col ) ;
    } // else
  } // if
  else {
    l = new Line ;
    l->line = line ;
    l->firstAppearAt = new Column ;
    l->firstAppearAt->column = col ;
    l->lastAppearAt = NULL ;
    l->next = NULL ;
  } // else
} // addLine
// ----------------------------F1-------------------------------------
void F1 ( char & num ) {
  scanf( "%c", &num );
  gColumn++;
  if ( num == '\n' ) {
    gColumn = 0;
    gLine++;
  } // if
} // F1
// ----------------------------Skip1-------------------------------------
void Skip1 ( char num ) {
  char a = '\0' ;
  F1( num );
  a = cin.peek();
  while ( num != '*' && a != '/' ) {
    F1( num );
    a = cin.peek();    
  } // while
  F1( num );
} // Skip1
// ----------------------------Skip2-------------------------------------
void Skip2 ( char num ) {
  char a = '\0' ;
  F1( num ) ;
  while ( num != '\n' ) {
    F1( num ) ;
  } // while
} // Skip2
// ----------------------------F2-------------------------------------  
void F2 ( char & num ) {
  char a = '\0' ;
  F1( num ) ;
  while ( num == '\n' || num == '\t' || num == ' ' || num == '\r' ) {
    F1( num ) ;
  } // while
} // F2 
// ----------------------------Case1-------------------------------------
void Case1 ( char num, Str100 string ) {
  int i = 0;
  string[i] = num;
  i++;
  char a = '\0' ;
  num = cin.peek();
  while ( num != '\t' && num != '\n' && num != ' ' && num != ';' && num != '+' && 
          num != '-' && num != '*' && num != '/' && num != '>' && num != '<' &&
          num != '=' && num != '!' && num != '?' && num != '%' && num != '&' &&
          num != '|' && num != '^' && num != ',' && num != '(' && num != ')' &&
          num != '[' && num != ']' && num != '{' && num != '}' && num != ':' &&
          num != '#' && num != '.' ) {
    F1( num ) ;
    string[i] = num;
    i++;
    num = cin.peek();
  } // while
} // Case1()
// ----------------------------Case2-------------------------------------
void Case2 ( char num, Str100 string ) {
  int i = 0;
  char a = '\0' ; 
  string[i] = num;
  i++;
  if ( num == '\"' ) {
    F1(num);
    string[i] = num;
    i++;
    while( num != '\"' ) {
      if ( num == '\\' ) {
        F1(num);
        string[i] = num;
        i++;
      } // if
      F1(num);
      string[i] = num;
      i++;
    } // while
    return;
  } // if
  if ( num == '\'' ) {
    F1(num);
    string[i] = num;
    i++;
    while( num != '\'' ) {
      if ( num == '\\' ) {
        F1(num);
        string[i] = num;
        i++;
      } // if
      F1(num);
      string[i] = num;
      i++;
    } // while
    return;
  } // if
  num = cin.peek();
  while ( num != '\t' && num != '\n' && num != ' ' && num != ';' && num != '+' && 
          num != '-' && num != '*' && num != '/' && num != '>' && num != '<' &&
          num != '=' && num != '!' && num != '?' && num != '%' && num != '&' &&
          num != '|' && num != '^' && num != ',' && num != '(' && num != ')' &&
          num != '[' && num != ']' && num != '{' && num != '}' && num != ':' &&
          num != '#' ) {
    if ( num >= '0' && num <= '9' ) {
      F1(num);
      string[i] = num; 
      i++;
    } // if
    if ( num == '.' ) {
      F1(num);
      string[i] = num;
      i++;
    } // if
    num = cin.peek() ;
  } // while     
} // Case2
// ----------------------------Case3-------------------------------------
void Case3 ( char num, Str100 string ) { 
  int i = 0;
  char a = '\0' ;
  string[i] = num;
  i++;
  if ( num == '+' ) {
    a = cin.peek() ;
    if ( a == '+' ) {
      F1( num ) ;
      string[i] = num;
    } // if 
    return;  
  } // if
  if ( num == '-' ) {
    a = cin.peek() ;
    if ( a == '-' ) {
      F1( num ) ;
      string[i] = num;
    } // if
    if ( a == '>' ) {
      F1( num ) ;
      string[i] = num;
    } // if
    return ;
  } // if
  if ( num == '*' ) {
    return;
  } // if
  if ( num == '>' ) {
    a = cin.peek() ;
    if ( a == '=' ) {
      F1( num ) ;
      string[i] = num;
    } // if
    return;
  } // if
  if ( num == '<' ) {
    a = cin.peek() ;
    if ( a == '=' ) {
      F1( num ) ;
      string[i] = num;
    } // if
    return;
  } // if
  if ( num == '=' ) {
    a = cin.peek() ;
    if ( a == '=' ) {
      F1( num ) ;
      string[i] = num;
    } // if
    return;
  } // if
  if ( num == '!' ) {
    a = cin.peek() ;
    if ( a == '=' ) {
      F1( num ) ;
      string[i] = num;
    } // if
    return;
  } // if
  if ( num == '?' ) 
    return ;
  if ( num == '%' ) 
    return ;
  if ( num == '&' ) {
    a = cin.peek() ;
    if ( a == '&' ) {
      F1( num ) ;
      string[i] = num;
    } // if   
    return ;
  } // if
  if ( num == '|' ) {
    a = cin.peek() ;
    if ( a == '|' ) {
      F1( num ) ;
      string[i] = num;
    } // if
    return ;
  } // if
  if ( num == '^' ) 
    return ;
  if ( num == '.' ) 
    return ;
  if ( num == ',' ) 
    return ;
  if ( num == '(' ) 
    return ;
  if ( num == ')' ) 
    return ;
  if ( num == '[' ) 
    return ;
  if ( num == ']' ) 
    return ;
  if ( num == '{' ) 
    return ;
  if ( num == '}' ) 
    return ;
  if ( num == '<' ) {
    a = cin.peek() ;
    if ( a == '<' ) {
      F1( num ) ;
      string[i] = num;
    } // if
    return ;
  } // if
  if ( num == '>' ) {
   a = cin.peek() ;
   if ( a == '>' ) {
     F1( num ) ;
     string[i] = num;
   } // if
   return;
  } // if
  if ( num == ':' ) 
    return ;
  if ( num == ';' ) 
    return ;
  if ( num == '#' ) 
    return ;
} // Case3()
// ------------------------------GetToken------------------------------------
CharPtr GetToken( Str100 string, char num, int & casenum, int & lline, int & ccolumn ) { // GetToken()可能會有一些參數
  for ( int i = 0 ; i < 100 ; i++ )
    string[i] = '\0' ;
  F2( num ) ;
  char a = '\0' ;
  int i = 0;
  ccolumn = gColumn;
  lline = gLine;
  if ( num >= 'a' && num <= 'z' || num >= 'A' && num <= 'Z' || num == '_' ) {
    Case1( num, string ) ;
    casenum = 1; 
  } // if
  else if ( num >= '0' && num <= '9' || num == '\'' || num == '"' ) {
    Case2( num, string ) ;
    casenum = 2;
  } // else if
  else if ( num == '/' ) {
    while ( num == '/' ) {
      a = cin.peek();
      if ( a == '/' ) {
        F1(num);
        while( num != '\n' ) {
         F1(num);
        } // while
        return GetToken( string, num, casenum, lline, ccolumn ) ;
      } // if
      else if ( a == '*' ) {
        F1(num);
        a = cin.peek();
        while( num != '*' || a != '/' ) {
         F1(num);
         a = cin.peek();
        } // while
        F1(num);
        return GetToken( string, num, casenum, lline, ccolumn ) ;
      } // else if
      else {
        string[i] = num;
        i++;
        casenum = 3;
        break;
      } // else
    } // while
  } // else if
  else {
    Case3( num, string ) ;
    casenum = 3;
  } // else
  CharPtr returnTokenStr = NULL ;
  returnTokenStr = new char[ strlen( string ) + 1 ] ;
  strcpy( returnTokenStr, string ) ;
  return returnTokenStr ;
} // GetToken
// ----------------------------OrderInsert-------------------------------------
void OrderInsert ( Str100 string, int casenum, int lline, int ccolumn ) {
  Token * middle1 = NULL ;
  Token * middle2 = NULL ;
  Line * middle3 = NULL ;
  Token * temp1 = NULL ;
  Token * temp2 = NULL ;
  if ( gFront == NULL ) {  //第一個進來的
    middle1 = new Token;
    middle1 -> tokenStr = new char[ strlen( string ) + 1 ] ;
    strcpy( middle1 -> tokenStr, string ) ;
    middle1 -> next = NULL ;
    middle1 -> firstAppearOn = new Line;
    middle1 -> lastAppearOn = new Line;
    middle1 -> lastAppearOn = middle1 -> firstAppearOn;
    middle1 -> firstAppearOn -> firstAppearAt = new Column ;
    middle1 -> lastAppearOn = middle1 -> firstAppearOn ;
    middle1 -> firstAppearOn -> line = lline;
    middle1 -> firstAppearOn -> next = NULL;
    middle1 -> firstAppearOn -> firstAppearAt -> column = ccolumn ;  
    middle1 -> firstAppearOn -> lastAppearAt = middle1 -> firstAppearOn -> firstAppearAt;
    middle1 -> firstAppearOn -> firstAppearAt -> next = NULL;
    middle1 -> firstAppearOn -> lastAppearAt -> next = NULL;
    middle1 -> lastAppearOn -> line = middle1 -> firstAppearOn -> line ;
    gFront = middle1;
    gRear = middle1;
    middle1 -> next = NULL;
    if ( casenum == 1 ) // 看TYPE是哪種類型
      middle1 -> type = IDENTIFIER ;
    else if ( casenum == 2 )
      middle1 -> type = CONSTANT ;
    else if ( casenum == 3 )
      middle1 -> type = SPECIAL ;
  } // if
  else if ( gFront != NULL ) {  // 第2次以後跑進這個
    middle2 = gFront;
    middle1 = new Token;
    middle1 -> tokenStr = new char[ strlen( string ) + 1 ] ;
    strcpy( middle1 -> tokenStr, string ) ;
    middle1 -> firstAppearOn = NULL ;
    middle1 -> lastAppearOn = NULL ;
    middle1 -> next = NULL;
    while ( middle2 != NULL ) {  
      if ( strcmp ( middle1 -> tokenStr, middle2 -> tokenStr ) == 0 ) { // 如果兩個TOKEN一樣 
        addLine( middle2->firstAppearOn, lline, ccolumn );
        return;
      } // if 
      middle2 = middle2->next ;
    } // while
      if ( casenum == 1 ) // 看TYPE是哪種類型
        middle1 -> type = IDENTIFIER ;
      else if ( casenum == 2 )
        middle1 -> type = CONSTANT ;
      else if ( casenum == 3 )
        middle1 -> type = SPECIAL ;
      addLine( middle1->firstAppearOn, lline, ccolumn );
      middle1->next = gFront ;
      gFront = middle1 ;
  // 排序--------------------------------------
      Token * ttemp = new Token;
      ttemp->tokenStr = NULL ;
      for( Token * i = gFront ; i != NULL ; i = i->next ) {
        for( Token * j = i->next ; j != NULL ; j = j->next ) {
          if ( strcmp( i->tokenStr, j->tokenStr ) > 0 ) {
            ttemp->firstAppearOn = i->firstAppearOn;
            i->firstAppearOn = j->firstAppearOn ;
            j->firstAppearOn = ttemp->firstAppearOn;  
            ttemp -> tokenStr = i ->tokenStr ;
            i -> tokenStr = j ->tokenStr ;
            j -> tokenStr = ttemp ->tokenStr ;
            ttemp->type = i->type;
            i->type = j->type ;
            j->type = ttemp->type;
          } // if
        } // for
      } // for
  } // else if  
} // OrderInsert() 
// --------------------------PrintTokenInfo-------------------------------------
void FindTokenInfo( TokenPtr point, Str100 string ) {
	ColumnPtr column1 =NULL ;
	LinePtr line1 =NULL ;
	while( strcmp(point -> tokenStr, string) != 0  ) {
		point = point -> next ;
      if( point == NULL  )
      break ;
	}	
  if ( point == NULL ) {
    printf("END 查無此token : %s\n",string ) ;
  }
  else {
	printf("%s",string ) ;
	line1 = point -> firstAppearOn ;
	while( line1 != NULL ){
		column1 = line1-> firstAppearAt ;
		while(column1 != NULL ){
		printf("( %d,%d )",line1-> line,column1 -> column ) ;
		column1 =  column1 -> next ;
    }
    line1 = line1 ->next ;
	}
  }

} // FindTokenInfo()
// ----------------------------PrintAll-------------------------------------
void PrintAll( TokenPtr temp ) {
	Column * ccolumn = NULL ;
	Line * lline = NULL ;
	while( temp != NULL ) {	
  	printf( "%s", temp -> tokenStr ) ;
  	lline = temp -> firstAppearOn ;
	  while ( lline != NULL ) {
	  	ccolumn = lline-> firstAppearAt ;
		  while( ccolumn != NULL ) {	
        printf("(%d,%d)", lline -> line, ccolumn -> column ) ;
        ccolumn =  ccolumn -> next ;
      } // while
      lline = lline ->next ;
	  } // while
	  printf("\n") ;
	  temp = temp -> next ;
  } // while
} // PrintAll()
// ----------------------------getline-------------------------------------
void getline( TokenPtr temp,int line ){
	LinePtr lline = NULL ;
	while( temp != NULL ) {
	  lline = temp -> firstAppearOn ;
		while(lline != NULL ) {		
	  	if( lline -> line == line) {
			  printf("%s ", temp -> tokenStr ) ;
	  	} // if
	  	lline = lline -> next ;
    } // while
		temp = temp -> next ; 
	} // while
  printf("\n") ;
} // getline()
// ----------------------------Count++-------------------------------------
void countall(TokenPtr point,int & sum){
	sum = 0 ;
	while( point != NULL ){
		sum++ ;
		point = point -> next ;
	}
} // countall
// ----------------------------Count-------------------------------------
  void count(TokenPtr point,int & sum1 ,int & sum2, int & sum3 ){
	sum1 = 0 ;
	sum2 = 0 ;
	sum3 = 0 ;
	while( point != NULL ){
        if( point ->type == IDENTIFIER ){
        	sum1++ ;
		}
		else if(point-> type == CONSTANT ){
			sum2++ ;
		}
		else if( point->type == SPECIAL ){
			sum3++ ;
		}
		point = point -> next ;
	}
}
  
// ----------------------------main-------------------------------------
int main() {
  Str100 string;
  char num = '\0' ;
  int allnum;
  int num1, num2, num3;
  int lline = 0;
  int ccolumn = 0; 
  int casenum = 0;
  CharPtr temp = NULL;
  temp = GetToken( string, num, casenum, lline, ccolumn ) ;
  while ( strcmp( string, "END_OF_FILE" ) != 0 ) { 
    OrderInsert( temp, casenum, lline, ccolumn );
    temp = GetToken( string, num, casenum, lline, ccolumn ) ;
  } // while
  PrintAll( gFront );
  printf("請輸入指令:\n") ;
  printf("1.總共有多少種 token\n") ;
  printf("2.三種case各有多少 token\n") ;
  printf("3.印出指定 token 的位置 (line number,column number) (要排序)\n") ;
  printf("4.印出所指定的那一 line 出現哪些 token (要排序)\n") ;
  printf("5.結束\n") ;
  scanf("%d",&num ) ;
  while ( num == 1 || num == 2 || num == 3 || num == 4 ) {
  	if( num == 1 ){ 
  	  countall( gFront, allnum ) ; 
  	  printf("總共%d種\n", allnum ) ; 
	  }
	  else if( num == 2 ){
		  count ( gFront, num1, num2, num3 ) ; 	
	  	printf("Case1 共有%d種\n",num1) ;
	  	printf("Case2 共有%d種\n",num2) ;
	  	printf("Case3 共有%d種\n",num3) ;		
	  }
	  else if( num == 3 ){
		  printf("請輸入要搜尋的 token :") ;
	   	scanf("%s", string ) ;
	  	FindTokenInfo( gFront, string ) ;
  	}
	  else if( num == 4 ){
      printf("請輸入要指定的 line :") ;
  		scanf("%d",&lline ) ;
  		getline( gFront, lline ) ;
  	}
    scanf( "%d", &num ) ;
  } // while
  printf("byebye") ;
} // main




