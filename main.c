/*****************************************************************
 *  Filename     : main.h
 *  Description  : Define main function
 *  Author       : Ogawa <ocmikanmgmg@gmail.com>
 *  Created      : May 31, 2025
 *  Compiler     : arm-none-eabi-gcc
 *  MCU          : RP2040
 *  License      : MIT License
 *  Note         : コマンド番号を受け取り，これを引数としてhandole関数に渡す．
 *  History      : 2025/05/24 - ファイル作成開始
 *****************************************************************/

 #include <stdio.h>
 #include "database.h"

 int main(void) {
    int command = 0;
    printf("コマンド一覧\n");
    printf("-------------------\n");
    printf("1:ユーザーの追加\n");
    printf("2:ユーザーの削除\n");
    printf("3:ユーザーの検索\n");
    printf("4:ユーザーの一覧表示\n");
    printf("-------------------\n");
    printf("コマンドを入力してください：");
    scanf("%d",&command);
    hundole_command(command);

    return 0;

 }