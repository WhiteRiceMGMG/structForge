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
 * 　　　　　　　　　　　2025/5/31:add_user関数の返り値をvoid型に
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

void add_user(Database* db) {
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
}

void delete_user(Database* db) {
    int index = 0;
    int deleteIndex = 0;
    int i = 0;
    printf("INPUT YOU WANNA DELETE USER ID:/n");
    scanf("%d",&deleteIndex);
    index = deleteIndex - 1;
    if(index < 0 || index > db->userCount) {
        printf("THE INDEX IS NOT EXIST...");
    }
    //1,2,3,4,0,6,7,8みたいになる.0のところはindex．i=indexからuserCount-1まで．
    for(i = index; i <= db->userCount-1 ;i++){
        db->userId[i] = db->userId[i + 1];
        strcpy(db->userName[i], db->userName[i + 1]);
        strcpy(db->userJob[i], db->userJob[i + 1]);
        strcpy(db->userBorn[i], db->userBorn[i + 1]);
        db->userAge[i] = db->userAge[i + 1];
    }
    db->userCount--;
}

Database* search_user(Database* db) {

}

void print_user_list(const Database* db){

}

void print_user(const Database* db) {
    
}

