//Ĭ�����룺password

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct information{
    int num; //���
    char location[80]; //�˺�λ��
    char describe[10]; //�˺�����
    char name[20]; //�˺���
    char password[20]; //����
    struct information *next;
} stu;

int size=sizeof(stu); //����ڵ�Ĵ�С

int select(); //�����˵�
stu* create(); //��Ϣ¼��
void print(stu *head); //���ȫ����Ϣ
void search(stu *head); //�����û�����ѯ��Ϣ
stu* delete(stu *head); //�����û���ɾ����Ϣ
//�����˺����޸���Ϣ
stu* modify(stu *head);
void change(stu *p, int n);
//
void filein(stu *head); //������Ϣ���뵽�ļ�
stu* fileout(stu *head); //���ļ��е�����Ϣ������

int main()
{
    char code[9]="password", in[9];
    int i, n, flag=0;
    stu *head=NULL;
    printf("--------��ӭ������˽��Ϣ����ϵͳ��--------\n\n");
    for(i=3; i>=1; i--){
        printf("���������룺");
        scanf("%s", in);
        if(strcmp(code, in)){
            if(i==1)
                break;
            printf("��������㻹��%d�λ��ᣡ\n\n", i-1);
        }
        else{
            flag = 1;
            printf("������ȷ����ӭ����\n\n\n");
            break;
        }
    }
    if(!flag){
        printf("��������㻹��0�λ��ᣬ���Զ��˳�ϵͳ��\n");
        exit(0);
    }
    while(1){
        n = select();
        switch(n){
            case 1:
                printf("\n--------��Ϣ¼��--------\n");
                head = create();
                break;
            case 2:
                printf("\n--------���ȫ����Ϣ--------\n");
                print(head);
                break;
            case 3:
                printf("\n--------�����˺�����ѯ��Ϣ--------\n");
                search(head);
                break;
            case 4:
                printf("\n--------�����˺���ɾ����Ϣ--------\n");
                head = delete(head);
                break;
            case 5:
                printf("\n--------�����˺���ɾ����Ϣ--------\n");
                head = modify(head);
                break;
            case 6:
                printf("\n--------������Ϣ���뵽�ļ�--------\n");
                filein(head);
                break;
            case 7:
                printf("\n--------���ļ��е�����Ϣ������--------\n");
                head = fileout(head);
                break;
            case 8:
                printf("�ټ�~\n");
                exit(0);
            default:
                printf("ERROR����������ȷ�ı�ţ�\n\n");
        }
    }

    return 0;
}

int select()
{
    int n;
    printf("--------����Ŀ¼--------\n");
    printf("1-��Ϣ¼��\n");
    printf("2-���ȫ����Ϣ\n");
    printf("3-�����˺�����ѯ��Ϣ\n");
    printf("4-�����˺���ɾ����Ϣ\n");
    printf("5-�����˺����޸���Ϣ\n");
    printf("6-������Ϣ���뵽�ļ�\n");
    printf("7-���ļ��е�����Ϣ������\n");
    printf("8-�˳�ϵͳ\n\n");
    printf("�����������ţ�");
    scanf("%d", &n);

    return n;
}

stu* create()
{
    stu *head=NULL, *tail=NULL, *p;
    while(1){
        p = (stu*)malloc(size);
        printf("�������ţ�-1�˳�����");
        scanf("%d", &p->num);
        if(p->num==-1){
            printf("\n");
            break;
        }
        else{
            printf("�������˺�λ�ã�");
            scanf("%s", p->location);
            printf("�������˺�������");
            scanf("%s", p->describe);
            printf("�������˺�����");
            scanf("%s", p->name);
            printf("���������룺");
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
        printf("��δ¼���κ���Ϣ��\n\n");
    else{
        stu *p;
        printf("***********************************************\n");
        printf("���    �˺�λ��    �˺�����    �˺���    ����\n");
        for(p=head; p!=NULL; p=p->next)
            printf("%-4d    %-8s    %-8s    %-8s  %-8s\n", p->num, p->location, p->describe, p->name, p->password);
        printf("***********************************************\n\n");
    }
}

void search(stu *head)
{
    if(head==NULL){
        printf("��δ¼���κ���Ϣ��\n\n");
        return;
    }
    stu *p;
    char a[20], t[2]="#";
    int flag=0;
    while(1){
        printf("�������˺�����#�˳�����");
        scanf("%s", a);
        if(strcmp(a,t)){
            for(p=head; p!=NULL; p=p->next){
                if(!strcmp(p->name,a)){
                    flag = 1;
                    printf("***********************************************\n");
                    printf("���    �˺�λ��    �˺�����    �˺���    ����\n");
                    printf("%-4d    %-8s    %-8s    %-8s  %-8s\n", p->num, p->location, p->describe, p->name, p->password);
                    printf("***********************************************\n\n");
                }
            }
            if(!flag)
                printf("��ѯʧ�ܣ�\n\n");
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
        printf("��δ¼���κ���Ϣ��\n\n");
        return NULL;
    }
    stu *ptr1, *ptr2;
    int flag;
    char a[20], t[2]="#";
    while(1){
        printf("�������˺�����#�˳�����");
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
                printf("�˺��������ڣ�\n\n");
            else{
                printf("ɾ���ɹ���\n\n");
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
        printf("��δ¼���κ���Ϣ��\n\n");
        return head;
    }
    stu *p;
    char a[20], t[2]="#";
    int flag, n;
    while(1){
        printf("�������˺�����#�˳�����");
        scanf("%s", a);
        if(strcmp(a,t)){
            flag = 0;
            for(p=head; p!=NULL; p=p->next){
                if(!strcmp(p->name,a)){
                    printf("\n--------�޸�Ŀ¼--------\n");
                    printf("1-���\n");
                    printf("2-�˺�λ��\n");
                    printf("3-�˺�����\n");
                    printf("4-�˺���\n");
                    printf("5-����\n");
                    printf("�������ţ�");
                    scanf("%d", &n);
                    while(n<1||n>5){
                        printf("ERROR����������ȷ�ı�ţ�");
                        scanf("%d", &n);
                    }
                   change(p, n);
                   flag = 1;
               }
            }
           if(!flag)
              printf("�˺��������ڣ�\n\n");
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
        printf("��������ĺ�ı�ţ�");
        scanf("%d", &p->num);
    }
    else if(n==2){
        printf("��������ĺ���˺�λ�ã�");
        memset(p->location, 0, sizeof(p->location));
        scanf("%s", p->location);
    }
    else if(n==3){
        printf("��������ĺ���˺�������");
        memset(p->describe, 0, sizeof(p->describe));
        scanf("%s", p->describe);
    }
    else if(n==4){
        printf("��������ĺ���˺�����");
        memset(p->name, 0, sizeof(p->name));
        scanf("%s", p->name);
    }
    else if(n==5){
        printf("��������ĺ�����룺");
        memset(p->password, 0, sizeof(p->password));
        scanf("%s", p->password);
    }
    printf("�޸ĳɹ���\n\n");
}

void filein(stu *head)
{
    FILE *fp;
    stu *p;
    int i;
    char file[20];
    printf("�������ļ�����");
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
    printf("����ɹ���\n\n");
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
    printf("�������ļ�����");
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
    printf("�����ɹ���\n\n");
    if(fclose(fp)){
        printf("Can not close the file!\n");
        exit(0);
    }

    return head;
}
