#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
// ʵ��getint����
int getint(int x, int y) {
    char inputStr[11]; // �㹻������������
    InputBox(inputStr, 10, NULL, NULL, NULL, x, y, false); // ��ʾ����򲢻�ȡ����
    return atoi(inputStr); // ���ַ���ת��Ϊ����������
}

// ���ɵ�����Ŀ
void generate_single_question(int grade, int* num1, int* num2, int* num3, int* num4, char* op1, char* op2, char* op3, int* answer) {
    int max_number = (grade == 1) ? 20 : (grade == 2) ? 50 : 1000;
    char ops[] = { '+', '-', '*', '/' };
    *num1 = rand() % max_number + 1;
    *num2 = rand() % max_number + 1;
    *num3 = (grade >= 2) ? rand() % max_number + 1 : NULL;
    *num4 = (grade >= 3) ? rand() % max_number + 1 : NULL;
    if (grade == 1) {
        
        *op1 = ops[rand() % 2];
        *answer = (*op1 == '+') ? (*num1 + *num2) : (*num1 - *num2);
    }
    else if (grade == 2) {
        do {
            do {
                *op1 = ops[rand() % 2];
                *op2 = ops[rand() % 2];
            } while (*op1 == *op2);

            if (*op1 == '+' && *op2 == '-') {
                *answer = *num1 + *num2 - *num3;
            }
            else {
                *answer = *num1 - *num2 + *num3;
            }
        } while (*answer <= 0);
    }
    else if (grade==3){
         do {
            do {
                *op1 = ops[rand() % 3];
                *op2 = ops[rand() % 3];
                *op3 = ops[rand() % 3];
            } while ((*op1 == *op2) || (*op2 == *op3) || (*op1 == *op3));
            if (*op1 == '+' && *op2 == '*' && *op3 == '-') {
                *answer = *num1 + *num2 * *num3 - *num4;
            }
            else if (*op1 == '*' && *op2 == '+' && *op3 == '-') {
                *answer = *num1 * *num2 + *num3 - *num4;
            }
            else if (*op1 == '*' && *op2 == '-' && *op3 == '+') {
                *answer = *num1 * *num2 - *num3 + *num4;
            }
            else if (*op1 == '+' && *op2 == '-' && *op3 == '*') {
                *answer = *num1 + *num2 - *num3 * *num4;
            }
            else if (*op1 == '+' && *op2 == '*' && *op3 == '-') {
                *answer = *num1 + *num2 * *num3 - *num4;
            }
            else {
                *answer = *num1 - *num2 * *num3 + *num4;
            }
         } while (*answer <= 0);
     }
    else {
        do {
            do {
                *op1 = ops[rand() % 4];
                *op2 = ops[rand() % 4];
                *op3 = ops[rand() % 4];
            } while ((*op1 == *op2) || (*op2 == *op3) || (*op1 == *op3));
            if (*op1 == '-' && *op2 == '+' && *op3 == '*') {
                *answer = *num1 - *num2 + *num3 * *num4;
            }
            else if (*op1 == '*' && *op2 == '+' && *op3 == '-') {
                *answer = *num1 * *num2 + *num3 - *num4;
            }
            else if (*op1 == '*' && *op2 == '-' && *op3 == '+') {
                *answer = *num1 * *num2 - *num3 + *num4;
            }
            else if (*op1 == '+' && *op2 == '-' && *op3 == '*') {
                *answer = *num1 + *num2 - *num3 * *num4;
            }
            else if (*op1 == '+' && *op2 == '*' && *op3 == '-') {
                *answer = *num1 + *num2 * *num3 - *num4;
            }
            else if (*op1 == '-' && *op2 == '*' && *op3 == '+') {
                *answer = *num1 - *num2 * *num3 + *num4;
            }                                                     //��һ��
            else if (*op1 == '+' && *op2 == '*' && *op3 == '/') {
                *answer = *num1 + *num2 * *num3 / *num4;
            }
            else if (*op1 == '+' && *op2 == '/' && *op3 == '*') {
                *answer = *num1 + *num2 / *num3 * *num4;
            }
            else if (*op1 == '*' && *op2 == '/' && *op3 == '+') {
                *answer = *num1 * *num2 / *num3 + *num4;
            }
            else if (*op1 == '/' && *op2 == '*' && *op3 == '+') {
                *answer = *num1 / *num2 * *num3 + *num4;
            }
            else if (*op1 == '*' && *op2 == '+' && *op3 == '/') {
                *answer = *num1 * *num2 + *num3 / *num4;
            }
            else if (*op1 == '/' && *op2 == '+' && *op3 == '*') {
                *answer = *num1 / *num2 + *num3 * *num4;
            }                                                    //�ڶ���
            else if (*op1 == '/' && *op2 == '+' && *op3 == '-') {
                *answer = *num1 / *num2 + *num3 - *num4;
            }
            else if (*op1 == '/' && *op2 == '-' && *op3 == '+') {
                *answer = *num1 / *num2 - *num3 + *num4;
            }
            else if (*op1 == '+' && *op2 == '-' && *op3 == '/') {
                *answer = *num1 + *num2 - *num3 / *num4;
            }
            else if (*op1 == '-' && *op2 == '+' && *op3 == '/') {
                *answer = *num1 - *num2 + *num3 / *num4;
            }
            else if (*op1 == '+' && *op2 == '/' && *op3 == '-') {
                *answer = *num1 + *num2 / *num3 - *num4;
            }
            else if (*op1 == '-' && *op2 == '/' && *op3 == '+') {
                *answer = *num1 - *num2 / *num3 + *num4;
            }                                                     //������
            else if (*op1 == '-' && *op2 == '*' && *op3 == '/') {
                *answer = *num1 + *num2 * *num3 / *num4;
            }
            else if (*op1 == '-' && *op2 == '/' && *op3 == '*') {
                *answer = *num1 + *num2 / *num3 * *num4;
            }
            else if (*op1 == '*' && *op2 == '/' && *op3 == '-') {
                *answer = *num1 * *num2 / *num3 + *num4;
            }
            else if (*op1 == '/' && *op2 == '*' && *op3 == '-') {
                *answer = *num1 / *num2 * *num3 + *num4;
            }
            else if (*op1 == '*' && *op2 == '-' && *op3 == '/') {
                *answer = *num1 * *num2 + *num3 / *num4;
            }
            else {
                *answer = *num1 / *num2 - *num3 * *num4;
            }
        } while (*answer <= 0);
    }
 }

 // ����������Ŀ
void generate_questions(int grade, int num_questions, int* answers) {
    int num1, num2, num3, num4, answer;
    char op1, op2, op3;
    for (int i = 0; i < num_questions; i++) {
        generate_single_question(grade, &num1, &num2, &num3, &num4, &op1, &op2, &op3, &answer);
        answers[i] = answer;
        TCHAR question_str[50];
        if (grade == 1) {
            _stprintf_s(question_str, _T(" % d.%d %c %d=  "), i + 1, num1, op1, num2);
        }
        else if (grade == 2) {
            _stprintf_s(question_str, _T(" % d.%d %c %d %c %d=  "), i + 1, num1, op1, num2, op2, num3);
        }
        else if (grade == 3) {
                _stprintf_s(question_str, _T(" % d.%d %c %d %c %d %c %d=  "), i + 1, num1, op1, num2, op2, num3, op3, num4);  
        }
        else {
            _stprintf_s(question_str, _T(" % d.%d %c %d %c %d %c %d=  "), i + 1, num1, op1, num2, op2, num3, op3, num4);
        }      
        outtextxy(10, 38 + i * 28, question_str);

    }
}
// ��ȡ�û���
void get_user_answers(int num_questions, int* user_answers) {
    char answer_str[20];
    for (int i = 0; i < num_questions; i++) {

        user_answers[i] = getint(300, 30);
        char user_answer_str[10];
        sprintf_s(user_answer_str, "%d", user_answers[i]);
        outtextxy(436, 38 + i * 28, user_answer_str);
    }
}

// ����
void check_answers(int num_questions, int* correct_answers, int* user_answers) {
    int score = 0;
    char answer_str[20];
    for (int i = 0; i < num_questions; i++) {

        sprintf_s(answer_str, "��ȷ��: ", i + 1);
        outtextxy(650, 38 + i * 28, answer_str);
        char correct_answer_str[20];
        sprintf_s(correct_answer_str, "%d", correct_answers[i]);
        outtextxy(774, 38 + i * 28, correct_answer_str);

        if (user_answers[i] == correct_answers[i]) {
            score++;
            outtextxy(1215, 38 + i * 28, "��ȷ");
        }
        else {
            outtextxy(1215, 38 + i * 28, "����");
        }
    }
    char score_str[20];
    sprintf_s(score_str, "�÷�: %d/%d", score, num_questions);
    outtextxy(10, 38 + num_questions * 28, score_str);
}

int main() {

    initgraph(1280, 800);
    setbkcolor(WHITE);
    settextcolor(BLACK);
    cleardevice();
    srand((unsigned int)time(NULL));
    
    LOGFONT f;
    gettextstyle(&f);						// ��ȡ��ǰ��������
    f.lfHeight = 26;						// ���������С
    _tcscpy_s(f.lfFaceName, _T("����"));	// ��������
    f.lfQuality = ANTIALIASED_QUALITY;		
    settextstyle(&f);						

    outtextxy(562, 10, "����������ϰ");
    rectangle(100, 100, 1076, 674);
    outtextxy(110, 110, "��ʼ��ϰ");
    
    setfillcolor(RED);
    bar(1210, 730, 1270, 790); // ����һ����ɫ�ľ�����Ϊ�رհ�ť
    outtextxy(1214, 747, "�˳�");

    MOUSEMSG m;
    while (true) {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN) {
            if (m.x >= 105 && m.x <= 205 && m.y >= 105 && m.y <= 140) {
             
                setfillcolor(WHITE);
                solidrectangle(10, 30, 500, 400);
                int grade, num_questions;
                while (true) {
                    outtextxy(10, 38, "�������꼶(1-6): ");
                    grade = getint(160, 10);
                    if (grade > 0 && grade <= 6) {
                        true;
                    }
                    else {
                        MessageBox(GetHWnd(), _T("����꼶����̫���ˣ���ҪΪ��С�����ˡ�"), _T("��ܰ��ʾ"), MB_OK | MB_ICONERROR);
                        cleardevice();
                    }
                    break;
                }//��ֹ�������꼶�������÷ɷ��ַ����롣
                outtextxy(10, 66, "��������Ŀ����: ");
                num_questions = getint(220, 30);
                setfillcolor(WHITE);
                solidrectangle(10, 30, 500, 400);

                int* correct_answers = (int*)malloc(num_questions * sizeof(int));
                int* user_answers = (int*)malloc(num_questions * sizeof(int));
                generate_questions(grade, num_questions, correct_answers);
                get_user_answers(num_questions, user_answers);
                check_answers(num_questions, correct_answers, user_answers);
                free(correct_answers);
                free(user_answers);
            }
            if(m.x >= 1205 && m.x <= 1275 && m.y >= 170 && m.y <= 790){
                closegraph();
                return 0;
            }
        }
    }
    getchar();// �ȴ��û������ر�ͼ�δ���
    closegraph();
    return 0;
}