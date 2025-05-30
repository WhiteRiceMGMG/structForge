/*****************************************************************
 *  filename   　　 : database.c
 *  escription 　　 : add, delete, and list data
 *  Author     　　 : Ogawa ocmikanmgmg@gmail.com
 *  Created    　　 : May 31, 2025
 *  Compiler   　　 : arm-none-eabi-gcc
 *  MCU        　　 : RP2040
 *  License    　　 : MIT License
 *  Note       　　 : ・main関数でコマンドナンバーを引数として受け取る
 * 　　　　　　　　　　　　　hundole_command関数が呼び出され，コマンドナンバーによって
 * 　　　　　　　　　　　　　追加や削除，一覧表示などの関数を呼び出す．
 * 　　　　　　　　　　　・handole_command内で構造体を初期化し，各関数にポインタ渡しする．
 * Revision History:
 * 　　　　　　　　　　　2025/5/24:ファイル作成開始
 * 　　　　　　　　　　　
 *****************************************************************/

#include <stdio.h>
#include <string.h>
#include "database.h"

int hundole_command(int command) {
    static Database db = {0};
    switch (command) {
        case 1:
            add_user(&db);
            break;
        case 2:
            delete_user(&db);
            break;
        case 3:
            search_user(&db);
            break;
        case 4:
            print_user_list(&db);
            break;
        case 5:
            print_user(&db);
            break;
        default:
            printf("不正なコマンドです．");
    }
}

Database* add_user(Database* db) {
    int index = db->userCount;

    printf("INPUT YOUR NAME:\n");
    fgets(db->userName[index], NAME_MAX, stdin);
    db->userName[index][strcspn(db->userName[index], "\n")] = '\0';

    printf("INPUT YOUR JOB:\n");
    fgets(db->userJob[index], NAME_MAX, stdin);
    db->userJob[index][strcspn(db->userJob[index], "\n")] = '\0';

    printf("INPUT YOUR BORN:\n");
    fgets(db->userBorn[index], NAME_MAX, stdin);
    db->userBorn[index][strcspn(db->userBorn[index], "\n")] = '\0';

    printf("INPUT YOUR AGE:\n");
    while (getchar() != '\n');
    scanf("%d", &db->userAge[index]);

    db->userId[index] = index + 1;

    db->userCount++;

    return db;
}

Database* delete_user(Database* db) {

}

Database* search_user(Database* db) {

}

void print_user_list(const Database* db){

}

void print_user(const Database* db) {
    
}

