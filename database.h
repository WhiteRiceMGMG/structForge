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

Database* add_user(Database* db);

Database* delete_user(Database* db);

Database* search_user(Database* db);

void print_user_list(const Database* db);

void print_user(const Database* db);

#endif

/*
それぞれの関数でそれぞれのポインタを定義して，アドレスさえ一致させれば一応構造体を動かせるけど，
一番わかりやすいのはそれぞれの関数で使える共通のポインタを作っといて，それを操作すればいい
+----------------------+
| Database db          | ← 実体（1個しかない）
+----------------------+
         ↑
    &db / ポインタ
         ↓
+-------------------------------+
| Database* ptr                | ← 共通のポインタ
+-------------------------------+
         ↓          ↓         ↓
+----------+   +----------+  +----------+
| add_user |   | del_user |  | print_db |
+----------+   +----------+  +----------+
     ↑             ↑              ↑
     |             |              |
     +-------------+--------------+
            共通のポインタを渡す

構造体をヘッダーに定義しただけではダメ？実体化はどこで？何回？ポインタ渡しの意味は？
　ヘッダーは「設計図（型の定義）」だけ。実体ではない。
　実体化（Database db;）は「箱を作る」こと → メモリ上に構造体ができる。
　実体化は1回だけにして、各関数にはポインタで渡すのが基本。
　static を使えば関数内で一度だけ実体化して、以降も使い回せる。
　実体が複数あると、それぞれ別物なので、変更が「消えたように見える」こともある。

構造体で初期化はできない．宣言だけ．
*/