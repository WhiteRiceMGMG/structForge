/*****************************************************************
 *  filename   　 　 : harmonic.c
 *  escription 　 　 : 
 *  Author     　 　 : Ogawa ocmikanmgmg@gmail.com
 *  Created    　　  : jun 1, 2025
 *  Compiler   　　  : arm-none-eabi-gcc
 *  MCU        　　  : RP2040
 *  License    　　  : MIT License
 *  Note       　　  : 
 *  RevisionHistory  :
 * 　　　　　　　　　　　2025/5/24:
 * 　　　　　　　　　　　2025/5/31:
 *                   2025/5/31:
 *****************************************************************/

#include <stdio.h>
#include <string.h>
#include "database.h"

void hundole_command(int command) {
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
        default:
            printf("不正なコマンドです．");
    }
}

void add_user(Database* db) {

    int index = db->userCount;
    while (getchar() != '\n');
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
    scanf("%d", &db->userAge[index]+1);


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

void search_user(const Database* db) {
    int index = db->userCount-1;
    printf("INPUT ID YOU WANNA WANT\n");
    scanf("%d",&index);
    printf("USER NAME:%s\n",db->userName[index]);
    printf("USER JOB:%s\n",db->userJob[index]);
    printf("USER BORN:%s\n",db->userBorn[index]);
    printf("USER AGE:%d\n",db->userAge[index]);
    printf("-------------------\n");

}

void print_user_list(const Database* db){
    int i = 0;
    printf("SHOW ALL DATA\n");
    for(i = 0; i < db->userCount; i++) {
        printf("USER ID:%d\n",db->userId[i]);
        printf("USER NAME:%s\n",db->userName[i]);
        printf("USER JOB:%s\n",db->userJob[i]);
        printf("USER BORN:%s\n",db->userBorn[i]);
        printf("USER AGE:%d\n",db->userAge[i]);
        printf("-------------------\n");
    }
}


