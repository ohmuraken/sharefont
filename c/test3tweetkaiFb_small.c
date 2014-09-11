#include <stdio.h>  //printf,scanf,fopen,fgetc,fcloseに必要なヘッダファイル
#include <stdlib.h> //exitに必要なヘッダファイル
#define MAX 128 //　ファイル名の長さはMAX-1
#define YOKO 48
#define TATE 60

int main(void) {


  char in_fn[MAX]; //入力ファイル名
  char out_fn[MAX]; //出力ファイル名
  FILE *in_fp; //入力ファイルポインタ
  FILE *out_fp; //出力ファイルポインタ

  int letter; //読み込んだ文字を入れる
  int count;//文字数をカウント
  int count_zero;
  int count_ichi;
  int count_kaigyo;
  int count_retsu;
  int count_gyo;

  printf("入力ファイル名 = ");
  scanf("%s", in_fn); //入力ファイル名をchar型配列in_fnに入力

  in_fp = fopen(in_fn, "r"); //読み出しモードでファイルを開く
  //大きな箱としてのファイルのアドレスを入れている

  //fgetc(fp)でファイルの先頭の一つ一つを見ていく
  //fget関数が一回終わった時点で標的は一つ横にずれている

  //アドレスがNULLの時,つまりファイルがないとき
  if(in_fp == NULL) { //fopenに失敗したら、その旨を出力
    printf("ファイル「%s」が開けない\n", in_fn);
    exit(1);
  }


  /*
  printf("出力ファイル名 = ");
  scanf("%s", out_fn); //出力ファイル名を入れる
  out_fp = fopen(out_fn, "w"); //書き込みモードでファイルを開く
  if(out_fp == NULL){ //fopenに失敗したら
    printf("ファイル:%sが開けない\n", out_fn); //
    fclose(in_fp);  //既に開いている入力ファイルを閉じる
    exit(2);  //エラー終了
  }
  */


  count = 0;
  count_retsu=0;
  count_gyo=0;
  //count_kaigyo =
  //count_retsu = 
  //count_gyo = 0;

  int letter0;
  int before_kaigyo;
  before_kaigyo=0;


  while(before_kaigyo<=2){
    if((letter0 =fgetc(in_fp))=='\n'){
      before_kaigyo++;
    }
  }


  printf("$img = $(\"<div class='letters transform' id='mu'>");
  //入力ファイルの終わりに達するまで
  //入力ファイルから１文字ずつ読み込みそれを出力ファイルrに書き込む
  while((letter = fgetc(in_fp)) != EOF){
    //fputc(letter, out_fp);
    count++;
    


    if(count_gyo >=6){
    //if(letter=='\n'){
      count_retsu++;
      count_gyo=0;
      //printf("====================================\n");
    }

    if(letter==' '){

      count_gyo--;
    }

    if(letter=='0'){
      //printf("<div class='twBtn' style='left:%dpx; top:%dpx'><img src='img/plain1.png'/></div>\n", (count_gyo)*YOKO, count_retsu*TATE);
    }else if(letter=='1'){
      //printf("<div class='twBtn' style='left:%dpx; top:%dpx'><img src='img/twitter1kai.png'/></div>", (count_gyo)*YOKO, count_retsu*TATE);
      
      printf("<div class='twBtn' style='left:%dpx; top:%dpx'><div class='like'></div></div>", (count_gyo)*YOKO, count_retsu*TATE);
      printf("<div class='twBtn' style='left:%dpx; top:%dpx'><div class='like'></div></div>", (count_gyo)*YOKO, count_retsu*TATE+20);
      printf("<div class='twBtn' style='left:%dpx; top:%dpx'><div class='like'></div></div>", (count_gyo)*YOKO, count_retsu*TATE+40);

      //printf("<div class='twBtn' style='left:%dpx; top:%dpx'><img src='img/twitter1kai.png'/></div>", (count_gyo)*YOKO, count_retsu*TATE+TATE);
            //printf("<div class='twBtn' style='left:%dpx; top:%dpx'><img src='img/twitter1kai.png'/></div>", (count_gyo)*YOKO, count_retsu*TATE+TATE+TATE);

    }
    
    count_gyo++;


  }


  printf("</div>\");\n");
  printf("break;\n\n");

  fclose(in_fp);
  fclose(out_fp);

  exit(0);
}