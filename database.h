/*****************************************************************
 *  filename   　　 : database.h
 *  escription 　　 : define struct, fsunction
 *  Author     　　 : Ogawa ocmikanmgmg@gmail.com
 *  Created    　　 : May 31, 2025
 *  Compiler   　　 : arm-none-eabi-gcc
 *  MCU        　　 : RP2040
 *  License    　　 : MIT License
 *  Note       　　 : 構造体，関数定義
 * Revision History:
 * 　　　　　　　　　　　2025/5/24:ファイル作成開始
 * 　　　　　　　　　　　
 *****************************************************************/

#ifndef DATABASE_H
#define DATABASE_H

#define ARRAY_MAX 63
#define NAME_MAX 23
#define BORN_MAX 23
#define JOB_MAX 23

typedef struct {
    int userId[ARRAY_MAX+ 1];
    char userName[ARRAY_MAX + 1][NAME_MAX + 1];
    char userJob[ARRAY_MAX + 1][NAME_MAX + 1];
    char userBorn[ARRAY_MAX + 1][NAME_MAX + 1];
    int userAge[ARRAY_MAX + 1];
    int userCount;
} Database;

int hundole_command(int command);

void add_user(Database* db);

void delete_user(Database* db);

void search_user(const Database* db);

void print_user_list(const Database* db);

#endif

