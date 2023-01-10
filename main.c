//默认密码：password

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct information{
    int num; //编号
    char location[80]; //账号位置
    char describe[10]; //账号描述
    char name[20]; //账号名
    char password[20]; //密码
    struct information *next;
} stu;

int size=sizeof(stu); //链表节点的大小

int select(); //操作菜单
stu* create(); //信息录入
void print(stu *head); //浏览全部信息
void search(stu *head); //根据用户名查询信息
stu* delete(stu *head); //根据用户名删除信息
//根据账号名修改信息
stu* modify(stu *head);
void change(stu *p, int n);
//
void filein(stu *head); //缓存信息导入到文件
stu* fileout(stu *head); //从文件中导出信息到缓存

int main()
{
    char code[9]="password", in[9];
    int i, n, flag=0;
    stu *head=NULL;
    printf("--------欢迎来到隐私信息管理系统！--------\n\n");
    for(i=3; i>=1; i--){
        printf("请输入密码：");
        scanf("%s", in);
        if(strcmp(code, in)){
            if(i==1)
                break;
            printf("密码错误，你还有%d次机会！\n\n", i-1);
        }
        else{
            flag = 1;
            printf("密码正确，欢迎您！\n\n\n");
            break;
        }
    }
    if(!flag){
        printf("密码错误，你还有0次机会，将自动退出系统！\n");
        exit(0);
    }
    while(1){
        n = select();
        switch(n){
            case 1:
                printf("\n--------信息录入--------\n");
                head = create();
                break;
            case 2:
                printf("\n--------浏览全部信息--------\n");
                print(head);
                break;
            case 3:
                printf("\n--------根据账号名查询信息--------\n");
                search(head);
                break;
            case 4:
                printf("\n--------根据账号名删除信息--------\n");
                head = delete(head);
                break;
            case 5:
                printf("\n--------根据账号名删除信息--------\n");
                head = modify(head);
                break;
            case 6:
                printf("\n--------缓存信息导入到文件--------\n");
                filein(head);
                break;
            case 7:
                printf("\n--------从文件中导出信息到缓存--------\n");
                head = fileout(head);
                break;
            case 8:
                printf("再见~\n");
                exit(0);
            default:
                printf("ERROR！请输入正确的编号！\n\n");
        }
    }

    return 0;
}

int select()
{
    int n;
    printf("--------操作目录--------\n");
    printf("1-信息录入\n");
    printf("2-浏览全部信息\n");
    printf("3-根据账号名查询信息\n");
    printf("4-根据账号名删除信息\n");
    printf("5-根据账号名修改信息\n");
    printf("6-缓存信息导入到文件\n");
    printf("7-从文件中导出信息到缓存\n");
    printf("8-退出系统\n\n");
    printf("请输入操作编号：");
    scanf("%d", &n);

    return n;
}

stu* create()
{
    stu *head=NULL, *tail=NULL, *p;
    while(1){
        p = (stu*)malloc(size);
        printf("请输入编号（-1退出）：");
        scanf("%d", &p->num);
        if(p->num==-1){
            printf("\n");
            break;
        }
        else{
            printf("请输入账号位置：");
            scanf("%s", p->location);
            printf("请输入账号描述：");
            scanf("%s", p->describe);
            printf("请输入账号名：");
            scanf("%s", p->name);
            printf("请输入密码：");
            scanf("%s", p->password);
            p->next = NULL;
            if(!head)
                head = p;
            else
                tail->next = p;
            tail = p;
            printf("\n");
        }
    }

    return head;
}

void print(stu *head)
{
    if(!head)
        printf("尚未录入任何信息！\n\n");
    else{
        stu *p;
        printf("***********************************************\n");
        printf("编号    账号位置    账号描述    账号名    密码\n");
        for(p=head; p!=NULL; p=p->next)
            printf("%-4d    %-8s    %-8s    %-8s  %-8s\n", p->num, p->location, p->describe, p->name, p->password);
        printf("***********************************************\n\n");
    }
}

void search(stu *head)
{
    if(head==NULL){
        printf("尚未录入任何信息！\n\n");
        return;
    }
    stu *p;
    char a[20], t[2]="#";
    int flag=0;
    while(1){
        printf("请输入账号名（#退出）：");
        scanf("%s", a);
        if(strcmp(a,t)){
            for(p=head; p!=NULL; p=p->next){
                if(!strcmp(p->name,a)){
                    flag = 1;
                    printf("***********************************************\n");
                    printf("编号    账号位置    账号描述    账号名    密码\n");
                    printf("%-4d    %-8s    %-8s    %-8s  %-8s\n", p->num, p->location, p->describe, p->name, p->password);
                    printf("***********************************************\n\n");
                }
            }
            if(!flag)
                printf("查询失败！\n\n");
        }
        else{
            printf("\n");
            break;
        }
    }
}

stu* delete(stu *head)
{
    if(!head){
        printf("尚未录入任何信息！\n\n");
        return NULL;
    }
    stu *ptr1, *ptr2;
    int flag;
    char a[20], t[2]="#";
    while(1){
        printf("请输入账号名（#退出）：");
        scanf("%s", a);
        if(strcmp(a,t)){
            flag = 0;
            while(head!=NULL&&strcmp(head->name,a)==0){
                flag = 1;
                ptr2 = head;
                head = head->next;
                free(ptr2);
            }
            ptr1 = head;
            ptr2 = head->next;
            while(ptr2){
                if(!strcmp(ptr2->name,a)){
                    flag = 1;
                    ptr1->next = ptr2->next;
                    free(ptr2);
                }
                else
                    ptr1 = ptr2;
                ptr2 = ptr1->next;
            }
            if(!flag)
                printf("账号名不存在！\n\n");
            else{
                printf("删除成功！\n\n");
            }
        }
        else{
            printf("\n");
            return head;
        }
    }
}

stu* modify(stu *head)
{
    if(head==NULL){
        printf("尚未录入任何信息！\n\n");
        return head;
    }
    stu *p;
    char a[20], t[2]="#";
    int flag, n;
    while(1){
        printf("请输入账号名（#退出）：");
        scanf("%s", a);
        if(strcmp(a,t)){
            flag = 0;
            for(p=head; p!=NULL; p=p->next){
                if(!strcmp(p->name,a)){
                    printf("\n--------修改目录--------\n");
                    printf("1-编号\n");
                    printf("2-账号位置\n");
                    printf("3-账号描述\n");
                    printf("4-账号名\n");
                    printf("5-密码\n");
                    printf("请输入编号：");
                    scanf("%d", &n);
                    while(n<1||n>5){
                        printf("ERROR！请输入正确的编号：");
                        scanf("%d", &n);
                    }
                   change(p, n);
                   flag = 1;
               }
            }
           if(!flag)
              printf("账号名不存在！\n\n");
           else{
              printf("\n");
              break;
           }
        }
    }

    return head;
}

void change(stu *p, int n)
{
    if(n==1){
        printf("请输入更改后的编号：");
        scanf("%d", &p->num);
    }
    else if(n==2){
        printf("请输入更改后的账号位置：");
        memset(p->location, 0, sizeof(p->location));
        scanf("%s", p->location);
    }
    else if(n==3){
        printf("请输入更改后的账号描述：");
        memset(p->describe, 0, sizeof(p->describe));
        scanf("%s", p->describe);
    }
    else if(n==4){
        printf("请输入更改后的账号名：");
        memset(p->name, 0, sizeof(p->name));
        scanf("%s", p->name);
    }
    else if(n==5){
        printf("请输入更改后的密码：");
        memset(p->password, 0, sizeof(p->password));
        scanf("%s", p->password);
    }
    printf("修改成功！\n\n");
}

void filein(stu *head)
{
    FILE *fp;
    stu *p;
    int i;
    char file[20];
    printf("请输入文件名：");
    scanf("%s", file);
    if((fp=fopen(file, "w"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    for(p=head; p!=NULL; p=p->next){
        for(i=0; p->password[i]!='\0'; i++){
            p->password[i] += 22;
        }
        fprintf(fp, "%d     %s     %s     %s     %s\n", p->num, p->location, p->describe, p->name, p->password);
    }
    printf("导入成功！\n\n");
    for(p=head; p!=NULL; p=p->next){
        for(i=0; p->password[i]!='\0'; i++){
            p->password[i] -= 22;
        }
    }
    if(fclose(fp)){
        printf("Can not close the file!\n");
        exit(0);
    }
}

stu* fileout(stu *head)
{
    FILE *fp;
    stu *p, *tail;
    int i;
    char file[20];
    printf("请输入文件名：");
    scanf("%s", file);
    if((fp=fopen(file, "r"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    head = tail = NULL;
    p = (stu*)malloc(size);
    fscanf(fp, "%d%s%s%s%s", &p->num, p->location, p->describe, p->name, p->password);
    while(!feof(fp)){
        p->next =NULL;
        if(!head)
            head = p;
        else
            tail->next = p;
        tail = p;
        p = (stu*)malloc(size);
        fscanf(fp, "%d%s%s%s%s", &p->num, p->location, p->describe, p->name, p->password);
    }
    for(p=head; p!=NULL; p=p->next){
        for(i=0; p->password[i]!='\0'; i++){
            p->password[i] -= 22;
        }
    }
    printf("导出成功！\n\n");
    if(fclose(fp)){
        printf("Can not close the file!\n");
        exit(0);
    }

    return head;
}
